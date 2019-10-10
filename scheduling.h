#ifndef _scheduling
#define _scheduling

#include "proc.h"

void schedule(int cpu, int core, int hthread);

struct pcb *scheduler();

void dispatcher(int cpu, int core, int hthread, struct pcb *proc);

void create_ready_queue();

void insert_process_ready_queue(struct pcb *proc);

long process_to_schedule();

#endif
