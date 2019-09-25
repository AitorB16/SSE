#ifndef _cpu
#define _cpu

#include "procs.h"

typedef struct hardware_hariak_t{

	struct pcb *proc;

} hardware_hariak_t;

typedef struct coreak_t{
    int hhari_kopurua;
    struct hardware_hariak_t *h_haria;

} coreak_t;

typedef struct cpuak_t{
    int core_kopurua;
    struct coreak_t *coreak;
} cpuak_t;

typedef struct gpuak_t{

} gpuak_t;

typedef struct computation_engine_t{
     
    int cpu_kopurua;
    int gpu_kopurua;
    struct cpuak_t *cpuak;
    struct gpuak_t *gpuak;

} computation_engine_t;

void sortu_computation_engine(int cpu_k, int core_k, int hhariak_k, int gpu_k);

#endif
