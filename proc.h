#ifndef _proc
#define _proc

typedef struct pcb {

	int pid;
	long cycles;
	int priority;
	long quantum;

} pcb;

void init_pid_array();

void create_allprocs_queue();

void create_new_process(long duration, int priority, long quantum);

void create_null_process(struct pcb **null_process);

int generate_pid();

void insert_process_allprocs_queue(struct pcb *proc);

void remove_process_allprocs_queue(struct pcb *proc);

#endif
