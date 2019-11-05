#include "list.h"
#include "scheduling.h"
#include "proc.h"
#include "globals.h"
#include "computing_engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//list_t ready_queue[P_MAX];

struct pcb *scheduler(int priority){

    struct pcb *proc;
    //printf("BBB\n");
    //printf("PUNT: %d %p\n",priority, &computing_engine.cpus[1].cores[1].ready_queue[priority]);
    list_head(&computing_engine.cpus[1].cores[1].ready_queue[priority], &proc);
    //list_head(&ready_queue[priority], &proc);

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
    //Berriro sartu proz ilaran; quantuma agortu delako atera da
    else if (proc->cycles > 0)
    {
    	printf("Process: %d removed due to time out\n", proc->pid);
    	proc->quantum=conf.quantum;
    	insert_process_ready_queue(proc);
    }


}

void context_switch(int cpu, int core, int hthread, struct pcb *proc){

	remove_process_from_execution(cpu, core, hthread);
	assign_process_to_hthread(cpu, core, hthread, proc);
	if(proc->pid==0){
		printf("IDLE STATE FOR CPU %d CORE %d HTHREAD %d \n",cpu,core,hthread);
	}else{
		printf("Assigned new process: %d to CPU %d CORE %d HTHREAD %d \n", proc->pid,cpu,core,hthread);
	}
	remove_process_ready_queue(proc->priority);
}

void dispatcher(int cpu, int core, int hthread, struct pcb *proc){

    context_switch(cpu, core, hthread, proc);

}

void schedule(int cpu, int core, int hthread){
    struct pcb *proc;
    int priority=process_to_be_scheduled();
    //lehen -1 zegoen
    if(priority>0){
        proc = scheduler(priority);
        dispatcher(cpu, core, hthread, proc);
        //Orain CPU-ak idle egoran sartzen direnean ez dute prozesu nulua deskartatuko bestelako prozesurik ilaran ez dagoen bitartean
    }else if(priority==0){
    	if(computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc->pid!=0){
    		proc = scheduler(priority);
        	dispatcher(cpu, core, hthread, proc);
    	}
    }else{
    	printf("Sleep\n");
    	sleep(5);
    }

}


void create_ready_queue(){
  int i,j,k;

 for(i=0;i<conf.ncpus;i++){
   	for (j=0;j<conf.ncores;j++){
   		for(k=0;k<P_MAX;k++){
    		list_initialize(&computing_engine.cpus[i].cores[j].ready_queue[k]);
   		}
    }
}

}

void insert_process_ready_queue(struct pcb* proc){

    list_append(&computing_engine.cpus[1].cores[1].ready_queue[proc->priority], proc);
    //list_append(&ready_queue[proc->priority], proc);

}

void remove_process_ready_queue(int priority){

	list_rem_head(&computing_engine.cpus[1].cores[1].ready_queue[priority]);
    //list_rem_head(&ready_queue[priority]);

}

int process_to_be_scheduled(){
  int i;
  for (i=P_MAX-1;i>-1;i--){
      if(!list_empty(&computing_engine.cpus[1].cores[1].ready_queue[i])){
        return i;
      }
  }
  return -1;
}
