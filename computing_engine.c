#include "computing_engine.h"
#include "proc.h"
#include <stdlib.h>

struct computing_engine_t computing_engine;

void create_computing_engine(int ncpus, int ncores, int nhthreads, int ngpus){

   int i, j, k;
   computing_engine.cpus = malloc(ncpus * sizeof(struct cpu_t));
   computing_engine.ncpus = ncpus;
   computing_engine.gpus = malloc(ngpus * sizeof(struct gpu_t));
   computing_engine.ngpus = ngpus;
   struct pcb *null_process;

   for(i = 0; i < ncpus; i++){
        computing_engine.cpus[i].cores = malloc(ncores * sizeof(struct core_t));
        computing_engine.cpus[i].ncores = ncores;
        for(j = 0; j < ncores; j++){
            computing_engine.cpus[i].cores[j].hthreads =  malloc(nhthreads * sizeof(struct hardware_thread_t));
            computing_engine.cpus[i].cores[j].nhthreads = nhthreads;
            for(k = 0; k < computing_engine.cpus[i].cores[j].nhthreads; k++){
                create_null_process(&null_process);
                computing_engine.cpus[i].cores[j].hthreads[k].proc = null_process;
            }
        }

   }
}
