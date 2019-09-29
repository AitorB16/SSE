#include "list.h"
#include "sched.h"
#include "globals.h"
#include "dispatcher.h"
#include "planifikatzailea.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dispatcher_sartu_CPU(struct pcb *proz,int cpu, int core, int hharia){
    proz->pid=rand() % 32769;
    computation_engine.cpuak[cpu].coreak[core].h_haria[hharia].proc=(struct pcb *)proz;
    printf("pid %d duen prozesua CPU_%d, core_%d, h_haria_%d-ra mugitu da.\n", proz->pid, cpu, core, hharia);
    list_rem_head(&prest_ilara);

}

void dispatcher_atera_CPU(int cpu, int core, int hharia){
    list_rem_head(&allprocs);
    printf("pid %d: Exekuzioaren amaiera.\n",computation_engine.cpuak[cpu].coreak[core].h_haria[hharia].proc->pid );
    free(computation_engine.cpuak[cpu].coreak[core].h_haria[hharia].proc);
    if(list_empty(&allprocs)){
      printf("Prozesu guztiak amaituta\n");
      exit(0);
    }
    planifikatzailea(cpu,core,hharia);
}
