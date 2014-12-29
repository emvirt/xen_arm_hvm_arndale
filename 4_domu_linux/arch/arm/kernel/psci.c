/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Copyright (C) 2012 ARM Limited
 *
 * Author: Will Deacon <will.deacon@arm.com>
 */

#define pr_fmt(fmt) "psci: " fmt

#include <linux/init.h>
#include <linux/irqchip/arm-gic.h>
#include <linux/of.h>

#include <asm/compiler.h>
#include <asm/errno.h>
#include <asm/opcodes-sec.h>
#include <asm/opcodes-virt.h>
#include <asm/psci.h>
#include <asm/smp_plat.h>

extern void secondary_startup(void);

static int (*invoke_psci_fn)(u32, u32, u32, u32);

enum psci_function {
	PSCI_FN_CPU_SUSPEND,
	PSCI_FN_CPU_ON,
	PSCI_FN_CPU_OFF,
	PSCI_FN_MIGRATE,
	PSCI_FN_MAX,
};

struct psci_function_desc {
	enum psci_function func;
	bool valid;
};
static struct psci_function_desc psci_function_id[PSCI_FN_MAX];

#define PSCI_RET_SUCCESS		0
#define PSCI_RET_EOPNOTSUPP		-1
#define PSCI_RET_EINVAL			-2
#define PSCI_RET_EPERM			-3

static int psci_to_linux_errno(int errno)
{
	switch (errno) {
	case PSCI_RET_SUCCESS:
		return 0;
	case PSCI_RET_EOPNOTSUPP:
		return -EOPNOTSUPP;
	case PSCI_RET_EINVAL:
		return -EINVAL;
	case PSCI_RET_EPERM:
		return -EPERM;
	};

	return -EINVAL;
}

#define PSCI_POWER_STATE_ID_MASK	0xffff
#define PSCI_POWER_STATE_ID_SHIFT	0
#define PSCI_POWER_STATE_TYPE_MASK	0x1
#define PSCI_POWER_STATE_TYPE_SHIFT	16
#define PSCI_POWER_STATE_AFFL_MASK	0x3
#define PSCI_POWER_STATE_AFFL_SHIFT	24

static u32 psci_power_state_pack(struct psci_power_state state)
{
	return	((state.id & PSCI_POWER_STATE_ID_MASK)
			<< PSCI_POWER_STATE_ID_SHIFT)	|
		((state.type & PSCI_POWER_STATE_TYPE_MASK)
			<< PSCI_POWER_STATE_TYPE_SHIFT)	|
		((state.affinity_level & PSCI_POWER_STATE_AFFL_MASK)
			<< PSCI_POWER_STATE_AFFL_SHIFT);
}

/*
 * The following two functions are invoked via the invoke_psci_fn pointer
 * and will not be inlined, allowing us to piggyback on the AAPCS.
 */
static noinline int __invoke_psci_fn_hvc(u32 function_id, u32 arg0, u32 arg1,
					 u32 arg2)
{
	asm volatile(
			__asmeq("%0", "r0")
			__asmeq("%1", "r1")
			__asmeq("%2", "r2")
			__asmeq("%3", "r3")
			__HVC(0)
		: "+r" (function_id)
		: "r" (arg0), "r" (arg1), "r" (arg2));

	return function_id;
}

static noinline int __invoke_psci_fn_smc(u32 function_id, u32 arg0, u32 arg1,
					 u32 arg2)
{
	asm volatile(
			__asmeq("%0", "r0")
			__asmeq("%1", "r1")
			__asmeq("%2", "r2")
			__asmeq("%3", "r3")
			__SMC(0)
		: "+r" (function_id)
		: "r" (arg0), "r" (arg1), "r" (arg2));

	return function_id;
}

static int psci_cpu_suspend(struct psci_power_state state,
			    unsigned long entry_point)
{
	int err;
	u32 fn, power_state;

	if (!psci_function_id[PSCI_FN_CPU_SUSPEND].valid)
		return -ENOSYS;

	fn = psci_function_id[PSCI_FN_CPU_SUSPEND].func;
	power_state = psci_power_state_pack(state);
	err = invoke_psci_fn(fn, power_state, entry_point, 0);
	return psci_to_linux_errno(err);
}

static int psci_cpu_off(struct psci_power_state state)
{
	int err;
	u32 fn, power_state;

	if (!psci_function_id[PSCI_FN_CPU_OFF].valid)
		return -ENOSYS;

	fn = psci_function_id[PSCI_FN_CPU_OFF].func;
	power_state = psci_power_state_pack(state);
	err = invoke_psci_fn(fn, power_state, 0, 0);
	return psci_to_linux_errno(err);
}

static int psci_cpu_on(unsigned long cpuid, unsigned long entry_point)
{
	int err;
	u32 fn;

	if (!psci_function_id[PSCI_FN_CPU_ON].valid)
		return -ENOSYS;

	fn = psci_function_id[PSCI_FN_CPU_ON].func;
	err = invoke_psci_fn(fn, cpuid, entry_point, 0);
	return psci_to_linux_errno(err);
}

static int psci_migrate(unsigned long cpuid)
{
	int err;
	u32 fn;

	if (!psci_function_id[PSCI_FN_MIGRATE].valid)
		return -ENOSYS;

	fn = psci_function_id[PSCI_FN_MIGRATE].func;
	err = invoke_psci_fn(fn, cpuid, 0, 0);
	return psci_to_linux_errno(err);
}

struct psci_operations psci_ops = {
	.cpu_suspend = psci_cpu_suspend,
	.cpu_off     = psci_cpu_off,
	.cpu_on      = psci_cpu_on,
	.migrate     = psci_migrate,
};

#ifdef CONFIG_SMP
static void __init psci_smp_init_cpus(void)
{
}

static void __init psci_smp_prepare_cpus(unsigned int max_cpus)
{
}

static int __cpuinit psci_boot_secondary(unsigned int cpu,
					 struct task_struct *idle)
{
	return psci_cpu_on(cpu_logical_map(cpu), __pa(secondary_startup));
}

static void __cpuinit psci_secondary_init(unsigned int cpu)
{
	gic_secondary_init(0);
}

struct smp_operations __initdata psci_smp_ops = {
	.smp_init_cpus		= psci_smp_init_cpus,
	.smp_prepare_cpus	= psci_smp_prepare_cpus,
	.smp_secondary_init	= psci_secondary_init,
	.smp_boot_secondary	= psci_boot_secondary,
};
#endif

static const struct of_device_id psci_of_match[] __initconst = {
	{ .compatible = "arm,psci",	},
	{},
};

int __init psci_init(void)
{
	struct device_node *np;
	const char *method;
	u32 id;
	int rc = -EINVAL;

	np = of_find_matching_node(NULL, psci_of_match);
	if (!np)
		return -ENODEV;

	pr_info("probing function IDs from device-tree\n");

	if (of_property_read_string(np, "method", &method)) {
		pr_warning("missing \"method\" property\n");
		goto out_put_node;
	}

	if (!strcmp("hvc", method)) {
		invoke_psci_fn = __invoke_psci_fn_hvc;
	} else if (!strcmp("smc", method)) {
		invoke_psci_fn = __invoke_psci_fn_smc;
	} else {
		pr_warning("invalid \"method\" property: %s\n", method);
		goto out_put_node;
	}

	if (!of_property_read_u32(np, "cpu_suspend", &id)) {
		psci_function_id[PSCI_FN_CPU_SUSPEND].func = id;
		psci_function_id[PSCI_FN_CPU_SUSPEND].valid = true;
	}

	if (!of_property_read_u32(np, "cpu_off", &id)) {
		psci_function_id[PSCI_FN_CPU_OFF].func = id;
		psci_function_id[PSCI_FN_CPU_OFF].valid = true;
	}

	if (!of_property_read_u32(np, "cpu_on", &id)) {
		psci_function_id[PSCI_FN_CPU_ON].func = id;
		psci_function_id[PSCI_FN_CPU_ON].valid = true;
	}

	if (!of_property_read_u32(np, "migrate", &id)) {
		psci_function_id[PSCI_FN_MIGRATE].func = id;
		psci_function_id[PSCI_FN_MIGRATE].valid = true;
	}

	rc = 0;

out_put_node:
	of_node_put(np);
	return rc;
}

bool __init psci_smp_available(void)
{
	/* is cpu_on available at least? */
	return psci_function_id[PSCI_FN_CPU_ON].valid;
}
