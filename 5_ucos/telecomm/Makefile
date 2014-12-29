include $(CURDIR)/../Config.mk

#OBJS 	+= $(patsubst %.c,%.o,$(wildcard CRC32/*.c))
#OBJS 	+= $(patsubst %.S,%.o,$(wildcard CRC32/*.S))

#OBJS    += libm.a 
#OBJS    += $(patsubst %.c,%.o,$(wildcard FFT/*.c))
#OBJS    += $(patsubst %.S,%.o,$(wildcard FFT/*.S))

#OBJS    += $(patsubst %.c,%.o,$(wildcard adpcm/src/*.c))
#OBJS    += $(patsubst %.S,%.o,$(wildcard adpcm/src/*.S))

#OBJS    += $(patsubst %.c,%.o,$(wildcard gsm/src/*.c))
#OBJS    += $(patsubst %.S,%.o,$(wildcard gsm/src/*.S))


default: $(OBJS)
	$(LD) $(LDFLAGS) -r -o built_in.o $^



clean:


%.o: %.c $(HDRS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S $(HDRS) Makefile
	$(CC) $(CFLAGS) $(AFLAGS) -D__ASSEMBLY__ -c $< -o $@



