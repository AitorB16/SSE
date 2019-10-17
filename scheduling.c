#include "list.h"
#include "scheduling.h"
#include "proc.h"
#include "globals.h"
#include "computing_engine.h"
#include <stdio.h>
#include <stdlib.h>

list_t ready_queue[P_MAX];

struct pcb *scheduler(int priority){

    struct pcb *proc;

    switch(conf.scheduling_policy){

        case FIFO:
            list_head(&ready_queue[0],&proc);
            break;
        case PRIORITY:
            list_head(&ready_queue[priority], &proc);
            break;
        default:
            printf("Unknown scheduling policy\n");
            exit(-1);
    }
    return(proc);
}


void remove_process_from_execution(int cpu, int core, int hthread){

    struct pcb *proc;

    proc = computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc;
    if(proc->pid > 0 && proc->cycles == 0){
        printf("Process with pid %d ended\n", proc->pid);
        remove_process_allprocs_queue(proc);
    }
    else if(proc->pid == 0){
        insert_process_ready_queue(proc);
    }


}

void context_switch(int cpu, int core, int hthread, struct pcb *proc){

  remove_process_from_execution(cpu, core, hthread);
	assign_process_to_hthread(cpu, core, hthread, proc);
	remove_process_ready_queue(proc->priority);
}

void dispatcher(int cpu, int core, int hthread, struct pcb *proc){

    context_switch(cpu, core, hthread, proc);

}

void schedule(int cpu, int core, int hthread){

    struct pcb *proc;
    int priority=process_to_be_scheduled();
    if(priority>-1){
        proc = scheduler(priority);
        dispatcher(cpu, core, hthread, proc);
    }

}


void create_ready_queue(){
  int i;
    for (i=0;i<P_MAX;i++){
      list_initialize(&ready_queue[i]);
    }


}

void insert_process_ready_queue(struct pcb* proc){

    list_append(&ready_queue[proc->priority], proc);

}

void remove_process_ready_queue(int priority){

    list_rem_head(&ready_queue[priority]);

}

int process_to_be_scheduled(){
  int i;
  for (i=P_MAX;i>-1;i--){
      if(!list_empty(&ready_queue[i])){
        return i;
      }
  }
  return -1;
}
