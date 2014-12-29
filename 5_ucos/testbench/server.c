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
#define THREAD_STATE_ACK			4

int flags = 0;
int count = 0;
int state = -1;

unsigned long *shared_page;

typedef struct shared_ring {
	unsigned long start;
	unsigned long end;
	unsigned long message_no;
	char ring[MAX_RING_SIZE];
}shared_ring_t;

shared_ring_t *shared_ring;

char keyData[ BLOWFISH_EXPANDED_KEYSIZE ];
char *encryption_key = ( char * ) "abcdefghijklmnopqrstuvwxyz";

int transaction_count = 0;
unsigned long message_no = 0;
char *password_pool[10] = {
	"tkcjsaks",
	"Eodruwnt",
	"tpdyskse",
	"ekrladld",
	"djTtmqsl",
	"ekdntckt",
	"qkqehwna",
	"ehsehwna",
	"wlqdmsah",
	"ahtrkspd"
};

char *credit_pool[10] = {
	"40932343",
	"32342342",
	"42342342",
	"75236345",
	"12333415",
	"34893489",
	"23469823",
	"34099034",
	"32389344",
	"45364345"
};
	
int item_selection = 0;

char message[MAX_MESSAGE_LENGTH + 1];
char password[MAX_MESSAGE_LENGTH + 1];
char credit[MAX_MESSAGE_LENGTH + 1];

void crash_domain(int ev, struct pt_regs *regs)
{
}

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
	unsigned long			mmap_vstart;
	gnttab_map_grant_ref_t	aop;
	grant_ref_t				mapped_handle;
	int						dom1_id = 1;

	mmap_vstart = alloc_pages(0);
	//printf("[gnttab_test_dom0] real mmap_vstart = 0x%lx\n", mmap_vstart);

	
	aop.host_addr = mmap_vstart;
	aop.dom       = dom1_id;
	aop.ref       = GNTTAB_REF_NUM;
	aop.flags     = (GNTMAP_host_map | GNTMAP_readonly);

	//printf("[gnttab_test_dom0] map grant table entry %d\n", GNTTAB_REF_NUM);

	HYPERVISOR_grant_table_op(GNTTABOP_map_grant_ref, &aop, 1);
	
	//if( HYPERVISOR_grant_table_op(GNTTABOP_map_grant_ref, &aop, 1) )
	//{
		//printf("***** HYPERVISOR_grant_table_op failed\n");
	//}
	mapped_handle = aop.handle;

	//printf("[gnttab_test_dom0] mmap_vstart = 0x%lx, aop.handle = 0x%lx, aop.dev_bus_addr = 0x%lx\n",
	//	   mmap_vstart, aop.handle, aop.dev_bus_addr);

	phys_to_machine_mapping[to_phys(mmap_vstart) >> PAGE_SHIFT] = FOREIGN_FRAME(aop.dev_bus_addr >> PAGE_SHIFT);

	shared_ring = (shared_ring_t *) mmap_vstart;
	
	shared_ring->start = 0;
	shared_ring->end = 0;
	
	return mapped_handle;
}
	
void write_data()
{
	int count;
	
	item_selection++;
	
	if(item_selection == 10) {
		item_selection = 0;
	}

	for(count = 0; count < MAX_MESSAGE_LENGTH; count++) {
		password[count] = password_pool[item_selection][count];
		credit[count] = credit_pool[item_selection][count];
	}

	password[MAX_MESSAGE_LENGTH] = '\0';
	credit[MAX_MESSAGE_LENGTH] = '\0';
	printk("> User Input \n");
	printk("  - ID             : %s\n", message);
	printk("  - Password       : %s\n", password);
	printk("  - Credit Card No : %s\n", credit);
	printk("> Encrypting and Sending MSG #%d\n", shared_ring->message_no + 1);
	
	BF_encrypt((BF_LONG *)message, (BF_KEY *)keyData);
	BF_encrypt((BF_LONG *)password, (BF_KEY *)keyData);
	BF_encrypt((BF_LONG *)credit, (BF_KEY *)keyData);

	/*
	printk("Sending Message 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n", 
		message[0],	message[1],	message[2],	message[3],	message[4],	message[5],	message[6],	message[7],
		password[0], password[1],password[2],password[3],password[4],password[5],password[6],password[7],
		password[0], credit[1],credit[2],credit[3],credit[4],credit[5],credit[6],credit[7]
	);
	*/
	
	for(count = 0; count < MAX_MESSAGE_LENGTH; count++) {
		shared_ring->ring[count] = message[count];
		shared_ring->ring[count + MAX_MESSAGE_LENGTH] = password[count];
		shared_ring->ring[count + (MAX_MESSAGE_LENGTH * 2)] = credit[count];
	}
	
	shared_ring->ring[MAX_MESSAGE_LENGTH * 3] = '\0';
	
	printk("================ TRANSACTION ENDS===============\n\n");
	
	shared_ring->message_no += 1;
	transaction_count++;
	
	if(transaction_count == 4) {
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		printk(">>>>>>>> DOMAIN-1 IS NOT RESPONDING <<<<<<<<\n");
		bind_interdomain(0x1, 0x05, &crash_domain);
		notify_remote_via_evtchn(5);
	}
}

void read_data()
{
	int count;
	
	for(count = 0; count < MAX_MESSAGE_LENGTH; count++) {
		message[count] = shared_ring->ring[count];
	}
	printk("============== TRANSACTION BEGINS ==============\n");
	/*
	printk("* Received Message #%d : 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n", item_selection,
		message[0], 
		message[1],
		message[2],
		message[3],
		message[4],
		message[5],
		message[6],
		message[7]
	);
	*/
	
	BF_decrypt((BF_LONG *)message, (BF_KEY *)keyData);
	
	message[MAX_MESSAGE_LENGTH] = '\0';
	
	printk("> Received and Decrypted MSG #%d : %s\n", shared_ring->message_no, message);
}

void server_thread(void *unused)
{	
	while(1) {
		switch(state) {
			case THREAD_STATE_IDLE :
				break;
			case THREAD_STATE_ACK :
				notify_remote_via_evtchn(4);
				state = THREAD_STATE_IDLE;
				break;
			case THREAD_STATE_READ_READY :
				read_data();
				//busy_waitting(10000);
				state = THREAD_STATE_WRITE_READY;
				break;
			case THREAD_STATE_WRITE_READY :
				write_data();
				state = THREAD_STATE_IDLE;
				notify_remote_via_evtchn(3);
				break;
		}
	}
}

void service_provider(int ev, struct pt_regs *regs)
{   
    state = THREAD_STATE_READ_READY;
}

void grant_map(int ev, struct pt_regs *regs)
{
}

void create_server()
{
	create_thread("ServerThread", server_thread, NULL);
}

void testbench_init(void)
{
	create_server();
}  
