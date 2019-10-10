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

void context_switch(struct pcb *proc){
	
	if(proc->cycles == 0){
		list_rem_head_data(&all_procs);
	}

        list_head(&ready_queue,&proc);
	assign_proc_to_hthread(int cpu, int core, int hthread, proc);
	remove_proc_ready_queue(&ready_queue);
}

void dispatcher(int cpu, int core, int hthread, struct pcb *proc){

    context_switch(proc);    
    save_null_process(cpu, core, hthread);

}

void schedule(int cpu, int core, int hthread){
    
    struct pcb *proc;

    if(process_to_be_scheduled()){
        proc = scheduler();
        printf("%d\n", proc->cycles);
        dispatcher(cpu, core, hthread, proc);
    }

}


void create_ready_queue(){
    struct pcb *null_process;
	    
    list_initialize(&ready_queue); 
    create_null_process(&null_process);
    insert_process_ready_queue(null_process);

}

void insert_process_ready_queue(struct pcb* proc){

    list_append(&ready_queue, proc);

}

void remove_process_ready_queue(struct pcb* proc){

    list_append(&ready_queue, proc);

}

long process_to_be_scheduled(){

    return(!list_empty(&ready_queue));
}

