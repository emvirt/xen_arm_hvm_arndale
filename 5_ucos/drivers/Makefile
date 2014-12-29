include $(CURDIR)/../Config.mk

#OBJS 	+= $(patsubst %.c,%.o,$(wildcard net/*.c))
#OBJS 	+= $(patsubst %.S,%.o,$(wildcard net/*.S))

#OBJS 	+= $(patsubst %.c,%.o,$(wildcard xen/xenconsole/*.c))
#OBJS 	+= $(patsubst %.c,%.o,$(wildcard xen/xenbus/*.c))

#OBJS 	+= $(patsubst %.c,%.o,$(wildcard android/binder/xen/*.c))

OBJS 	+= $(patsubst %.c,%.o,$(wildcard serial/*.c))
OBJS 	+= $(patsubst %.c,%.o,$(wildcard timer/*.c))

default: $(OBJS)
	$(LD) $(LDFLAGS) -r -o built_in.o $^



clean:


%.o: %.c $(HDRS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S $(HDRS) Makefile
	$(CC) $(CFLAGS) $(AFLAGS) -D__ASSEMBLY__ -c $< -o $@



