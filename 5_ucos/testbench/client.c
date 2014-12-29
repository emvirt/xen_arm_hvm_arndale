#include <os/os.h>
#include <os/irq.h>
#include <os/traps.h>
#include <os/evtchn.h>
#include <os/time.h>
#include <os/sched.h>
#include <os/lib.h>
#include <os/mm.h> 
#include <os/xmalloc.h>
#include <os/hypervisor.h>
#include <os/gnttab.h>
#include <os/blowfish.h>

#define GNTTAB_REF_NUM				9

#define MAX_RING_SIZE				1024
#define MAX_MESSAGE_LENGTH			8
#define MAX_SHARED_KEY_LENGTH		128

#define THREAD_STATE_IDLE			0
#define THREAD_STATE_READ_READY		1
#define THREAD_STATE_WRITE_READY	2

int flags = 0;
int state = -1;

typedef struct shared_ring {
	unsigned long start;
	unsigned long end;
	unsigned long message_no;
	char ring[MAX_RING_SIZE];
}shared_ring_t;

unsigned long message_no = 0;

shared_ring_t *shared_ring;

/*
BYTE *id_pool[10] = {
	"semicoma",
	"sadmovie",
	"heartbit",
	"mukaebee",
	"sikchung",
	"balnamse",
	"nandakim",
	"yojung-9",
	"domangga",
	"O-dengdu"
};
*/
BYTE *id_pool[10] = {
	"\x9f\xc7\x8f\x97\xba\xf4\x2c\x24",
	"\x38\x3b\x23\xbf\x35\x4d\xa2\xb9",
	"\x64\x87\x14\x7d\x10\xb6\x7c\xe6",
	"\x44\x5d\x20\xb1\x3d\xef\x5e\xfe",
	"\xbb\x73\x7\xf\x9b\x86\xdc\x80",
	"\x6d\xe8\x5c\xce\xd1\x69\xb7\x73",
	"\x56\x29\x94\xaa\x97\x15\xd2\x72",
	"\xca\x95\xd7\xe3\x5d\x69\x9\xc4",
	"\xf2\x98\xf0\x23\xe1\x23\x9\x55",
	"\xef\xc2\xdc\x7e\xba\xab\x5b\xe4"
};

int id_selection = 0;

int busy_waitting(int count)
{
	int i, k, j = 0;
	
	for(i=0; i <count; i++) {
		for(k=0; k < count; k++) {
			j += i;
		}
	}
	
	return j;		
}

int gnttable_init(void)
{
	int				dom0_id = 0;
	unsigned long	vaddr;
	unsigned long	mfn;
	
	vaddr = alloc_pages(0);
	mfn   = pfn_to_mfn(virt_to_pfn(vaddr));

//	printf("[gnttab_test_dom1] set grant table entry %d\n", GNTTAB_REF_NUM);
//	printf("[gnttab_test_dom1] vaddr = 0x%lx, mfn = 0x%lx\n", vaddr, mfn);
	gnttab_grant_foreign_access_ref(GNTTAB_REF_NUM, dom0_id, mfn, 1);

	shared_ring = (shared_ring_t *) vaddr;
	
	shared_ring->start = 0;
	shared_ring->end = 0;
	
	return 0;
}


void write_data()
{	
	int count;
	
	printk("============== TRANSACTION BEGINS ==============\n");

	id_selection++;
	
	if(id_selection == 10) {
		id_selection = 0;
	}

	printk("> Sending Encrypted MSG #%d : 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n", message_no, 
		id_pool[id_selection][0], 
		id_pool[id_selection][1],
		id_pool[id_selection][2],
		id_pool[id_selection][3],
		id_pool[id_selection][4],
		id_pool[id_selection][5],
		id_pool[id_selection][6],
		id_pool[id_selection][7]
	);
	
	for(count = 0; count < MAX_MESSAGE_LENGTH; count++) {
		shared_ring->ring[count] = id_pool[id_selection][count];
	}

	shared_ring->message_no = message_no;
	shared_ring->ring[MAX_MESSAGE_LENGTH] = '\0';
	
	message_no+=2;
			
	notify_remote_via_evtchn(3);
}

void read_data()
{
	printk("> Received and Encrypted MSG #%d : 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n", shared_ring->message_no,
		shared_ring->ring[0], shared_ring->ring[1], shared_ring->ring[2], shared_ring->ring[3], shared_ring->ring[4], shared_ring->ring[5], shared_ring->ring[6], shared_ring->ring[7],
		shared_ring->ring[8], shared_ring->ring[9], shared_ring->ring[10], shared_ring->ring[11], shared_ring->ring[12], shared_ring->ring[13], shared_ring->ring[14], shared_ring->ring[15],
		shared_ring->ring[16], shared_ring->ring[17], shared_ring->ring[18], shared_ring->ring[19], shared_ring->ring[20], shared_ring->ring[21], shared_ring->ring[22], shared_ring->ring[23]
	);

	printk("================ TRANSACTION ENDS===============\n\n");
	
}

void client_thread(void *unused)
{	
	while(1) {
		switch(state) {
			case THREAD_STATE_IDLE :
				break;
			case THREAD_STATE_READ_READY :
				read_data();
				//busy_waitting(10000);
				state = THREAD_STATE_WRITE_READY;
				break;
			case THREAD_STATE_WRITE_READY :
				write_data();
				state = THREAD_STATE_IDLE;
				break;
		}
	}
}

void service_consumer(int ev, struct pt_regs *regs)
{   
	state = THREAD_STATE_READ_READY;
}

void grant_map(int ev, struct pt_regs *regs)
{	
	state = THREAD_STATE_WRITE_READY;
}

void crash_domain(int ev, struct pt_regs *regs)
{	
	int i;
		
	busy_waitting(100);
	
	for(i=0; i <50; i++) {
		printk(">>>>>>>>>> REBOOTING DOMAIN-1 <<<<<<<<<<<\n");
	}

	
	busy_waitting(100);
	
	*(int *)0 = 0;
}

void create_client()
{
	state = THREAD_STATE_IDLE;
	
	bind_interdomain(0x0, 0x03, &service_consumer);
	bind_interdomain(0x0, 0x04, &grant_map);
	
	alloc_unbound_port(0x00, &crash_domain);
	
	notify_remote_via_evtchn(4);
	
	create_thread("ClientThread", client_thread, NULL);
}

void testbench_init(void)
{
	gnttable_init();
	create_client();
}  
