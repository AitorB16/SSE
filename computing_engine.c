#include "computing_engine.h"
#include "proc.h"
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>


struct computing_engine_t computing_engine;

void create_computing_engine(int ncpus, int ncores, int nhthreads, int ngpus){

   int i, j, k;
   computing_engine.cpus = malloc(ncpus * sizeof(struct cpu_t));
   computing_engine.ncpus = ncpus;
   computing_engine.gpus = malloc(ngpus * sizeof(struct gpu_t)); 
   computing_engine.ngpus = ngpus; 

   for(i = 0; i < ncpus; i++){
        computing_engine.cpus[i].cores = malloc(ncores * sizeof(struct core_t));
        computing_engine.cpus[i].ncores = ncores;
        for(j = 0; j < ncores; j++){
            computing_engine.cpus[i].cores[j].hthreads =  malloc(nhthreads * sizeof(struct hardware_thread_t));
            computing_engine.cpus[i].cores[j].nhthreads = nhthreads;
            computing_engine.cpus[i].cores[j].nprocesses_rq=0;
            for(k = 0; k < computing_engine.cpus[i].cores[j].nhthreads; k++){
                computing_engine.cpus[i].cores[j].hthreads[k].proc = NULL; 
            }
        }

   } 

   init_computing_engine(ncpus, ncores, nhthreads, ngpus);
}

void init_computing_engine(int ncpus, int ncores, int nhthreads, int ngpus){

    int i, j, k;
    struct pcb *null_process;

    for(i = 0; i < computing_engine.ncpus; i++){
        for(j = 0; j <  computing_engine.cpus[i].ncores; j++){
            for(k = 0; k < computing_engine.cpus[i].cores[j].nhthreads; k++){
                create_null_process(&null_process);
                computing_engine.cpus[i].cores[j].hthreads[k].proc = null_process;
                printf("%p\n",null_process);
            }
        }
    }
}

void save_null_process(int cpu, int core, int hthread){

    computing_engine.cpus[cpu].cores[core].hthreads[hthread].null_process = computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc;
    computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc = NULL;
}

void restore_null_process(int cpu, int core, int hthread){

    computing_engine.cpus[cpu].cores[core].hthreads[hthread].null_process = computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc;
    computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc = NULL;

}


void assign_process_to_hthread(int cpu, int core, int hthread, struct pcb *proc){

    computing_engine.cpus[cpu].cores[core].hthreads[hthread].proc = proc;
}
