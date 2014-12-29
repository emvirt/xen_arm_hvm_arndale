//YSB

#ifndef _TRUSTZONE_COMMUNICATION_H_
#define _TRUSTZONE_COMMUNICATION_H_

#include <os/lib.h>

//#define TRUSTZONE_SHARED_REGION_ADDRESS	0x20000000
#define TRUSTZONE_SHARED_REGION_ADDRESS	0x00037000
#define TRUSTZONE_SHARED_REGION_SIZE	0x00001000

struct trustzone_nt_to_t_buffer {
	unsigned int size;
	union {
		unsigned int id;
		unsigned int ret;
	} desc;
	unsigned char buf[1];
};

#define Nt_to_T (*((struct trustzone_nt_to_t_buffer*)TRUSTZONE_SHARED_REGION_ADDRESS))

#define tz_communication_init() { Nt_to_T.size = 0; }

#define tz_communication_clear() {					\
		memset(Nt_to_T.buf, 0x0, Nt_to_T.size);		\
		Nt_to_T.size = 0;							\
	}

#define tz_communication_get_size()		Nt_to_T.size
#define tz_communication_get_id()		Nt_to_T.desc.id
#define tz_communication_get_buffer()	Nt_to_T.buf

#define tz_communication_set_ret_value(a)		{ Nt_to_T.desc.ret = a; }

#endif