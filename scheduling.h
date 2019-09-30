#ifndef _scheduling
#define _scheduling

#include "proc.h"

void scheduler(int cpu, int core, int hthread);

void create_ready_queue();

void insert_process_ready_queue(struct pcb *proc);

long process_to_schedule();

#endif
