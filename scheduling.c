#include "list.h"
#include "scheduling.h"
#include "proc.h"
#include "globals.h"
#include "dispatcher.h"
#include "computing_engine.h"
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

void remove_process_from_execution(int cpu, int core, int hthread){

    struct pcb *proc;

    proc = computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc;
    if(proc->pid > 0 && proc->cycles == 0){
        
        remove_process_allprocs_queue(proc);
    }
    else if(proc->pid == 0){
        insert_process_ready_queue(proc);
    }


}

void context_switch(int cpu, int core, int hthread, struct pcb *proc){
	
        remove_process_from_execution(cpu, core, hthread);
	assign_process_to_hthread(cpu, core, hthread, proc);
	remove_process_ready_queue(&ready_queue);
}

void dispatcher(int cpu, int core, int hthread, struct pcb *proc){

    context_switch(cpu, core, hthread, proc);    

}

void schedule(int cpu, int core, int hthread){
    
    struct pcb *proc;

    if(process_to_be_scheduled()){
        proc = scheduler();
        dispatcher(cpu, core, hthread, proc);
    }

}


void create_ready_queue(){

    list_initialize(&ready_queue); 

}

void insert_process_ready_queue(struct pcb* proc){

    list_append(&ready_queue, proc);

}

void remove_process_ready_queue(){

    list_rem_head(&ready_queue);

}

long process_to_be_scheduled(){

    return(!list_empty(&ready_queue));
}


