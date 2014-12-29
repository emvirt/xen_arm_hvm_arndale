/*
 * shyoo added
 * IMX reg. definition
 */

#define IMX_IO_BASE             0xe0000000
#define IMX_TIM1_BASE              (0x03000 + IMX_IO_BASE)
#define TIMER_BASE IMX_TIM1_BASE
#define IMX_TCN(x)         ( 0x10 + (x))
#define IMX_TSTAT(x)       ( 0x14 + (x))
#define IMX_TCMP(x)        ( 0x08 + (x))
#define HZ  100
#define LATCH  ((CLOCK_TICK_RATE + HZ/2) / HZ)
#define CLOCK_TICK_RATE         (CLK32)
#define CLK32 32768
#define TSTAT_COMP         (1<<0)
