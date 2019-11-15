#ifndef _scheduling
#define _scheduling

#include "proc.h"
#include "list.h"

struct pcb *scheduler(int priority,int cpu, int core);

void remove_process_from_execution(int cpu, int core, int hthread);

void balance (int *cpu, int *core);

void context_switch(int cpu, int core, int hthread, struct pcb *proc);

void dispatcher(int cpu, int core, int hthread, struct pcb *proc);

void schedule(int cpu, int core, int hthread);

void create_ready_queue();

void balance_process_ready_queue(struct pcb* proc);

void insert_process_ready_queue(struct pcb *proc, int cpu, int core);

void remove_process_ready_queue(int priority,int cpu, int core);

int process_to_be_scheduled(int cpu, int core);

#endif
