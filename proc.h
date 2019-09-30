#ifndef _proc
#define _proc

typedef struct pcb {

	int pid;
	long cycles;

} pcb;

void create_allprocs_queue();

void create_new_process(long duration);

void create_null_process(struct pcb **null_process);

#endif
