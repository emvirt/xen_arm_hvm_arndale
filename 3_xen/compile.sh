#!/bin/bash

make clean


make dist-xen XEN_TARGET_ARCH=arm32 CROSS_COMPILE=arm-linux-gnueabihf- CONFIG_DTB_FILE=/home/tkkim/arm/2_dom0_linux/linux/arch/arm/boot/dts/exynos5250-arndale.dtb

mkimage -A arm -T kernel -a 0x80200000 -e 0x80200000 -C none -d "/home/tkkim/arm/3_xen/xen/xen/xen" xen-uImage
