#define mb()	asm volatile ("": : :"memory")
#define rmb()	mb()
#define __iormb()		rmb()

#define u32 unsigned int

#define __raw_readl(a)		( *(volatile unsigned int *)(a))
#define readl_relaxed(c) ({ u32 __v = __raw_readl(c); __v; })
#define readl(c)		({ u32 __v = readl_relaxed(c); __iormb(); __v; })


#define __raw_writel(v,a)	(*(volatile unsigned int *)(a) = (v))
#define writel_relaxed(v,c)	((void)__raw_writel(v,c))

#define wmb()	asm volatile ("": : :"memory")
#define __iowmb()		wmb()


#define writel(v,c)		({ __iowmb(); writel_relaxed(v,c); })