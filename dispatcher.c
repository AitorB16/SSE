#include "list.h"
#include "scheduling.h"
#include "globals.h"
#include "dispatcher.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dispatcher_CPU_in(struct pcb *proc,int cpu, int core, int hthread){
    proc->pid=rand() % 32769;
    computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc=(struct pcb *)proc;
    printf("The process with pid %d has been moved to CPU_%d, core_%d, hthread_%d.\n", proc->pid, cpu, core, hthread);
    list_rem_head(&ready_queue);

}

void dispatcher_CPU_out(int cpu, int core, int hthread){
    list_rem_head(&allprocs);
    printf("pid %d: Execution finished.\n",computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc->pid );
    free(computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc);
    if(list_empty(&allprocs)){
      printf("No more processes to execute\n");
      exit(0);
    }
    scheduler(cpu,core,hthread);
}
