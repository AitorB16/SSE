#ifndef _scheduling
#define _scheduling

#include "proc.h"

struct pcb *scheduler();

void remove_process_from_execution(int cpu, int core, int hthread);

void context_switch(int cpu, int core, int hthread, struct pcb *proc);

void dispatcher(int cpu, int core, int hthread, struct pcb *proc);

void schedule(int cpu, int core, int hthread);

void create_ready_queue();

void insert_process_ready_queue(struct pcb *proc);

void remove_process_ready_queue();

long process_to_be_scheduled();

#endif
