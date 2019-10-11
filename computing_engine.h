#ifndef _computing_engine
#define _computing_engine

#include "proc.h"

typedef struct hardware_thread_t{

	struct pcb *proc;
        struct pcb *null_process;

} hardware_thread_t;

typedef struct core_t{
    int nhthreads;
    struct hardware_thread_t *hthreads;

} core_t;

typedef struct cpu_t{
    int ncores;
    struct core_t *cores;
} cpu_t;

typedef struct gpu_t{

} gpu_t;

typedef struct computing_engine_t{

    int ncpus;
    int ngpus;
    struct cpu_t *cpus;
    struct gpu_t *gpus;

} computing_engine_t;

void create_computing_engine(int ncpus, int ncores, int nhthreads, int ngpus);

void save_null_process(int cpu, int core, int hthread);

void restore_null_process(int cpu, int core, int hthread);

void assign_process_to_hthread(int cpu, int core, int hthread, struct pcb *proc);

void init_computing_engine(int ncpus, int ncores, int nhthreads, int ngpus);

#endif
