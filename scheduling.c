#include "list.h"
#include "scheduling.h"
#include "proc.h"
#include "globals.h"
#include "dispatcher.h"
#include <stdio.h>
#include <stdlib.h>

list_t ready_queue;

void scheduler(int cpu, int core, int hthread){
    if(list_empty(&ready_queue)){
      //oraingoz kasu berezitzat hartu eta dispatcherrak egingo dituen esleipenetatik kanpo
      struct pcb* null_process;
      create_null_process(&null_process);
      computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc=null_process;
      free(null_process);
    }
    else{
      struct pcb *proc;
      switch(conf.scheduling_policy){

          case FIFO:
              list_head(&ready_queue,(void*) &proc);
              dispatcher_CPU_in(proc,cpu,core,hthread);
              break;
          default:
              printf("Unknown scheduling policy\n");
              exit(-1);
      }
    }
}


void create_ready_queue(){

    list_initialize(&ready_queue);

}

void insert_process_ready_queue(struct pcb* proc){

    list_append(&ready_queue, proc);

}

long process_to_schedule(){

    return(!list_empty(&ready_queue));
}
