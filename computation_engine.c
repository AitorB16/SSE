#include "computation_engine.h"
#include "procs.h"
#include <stdlib.h>

struct computation_engine_t computation_engine;

void sortu_computation_engine(int cpu_k, int core_k, int hhariak_k, int gpu_k){

   int i, j, k;
   computation_engine.cpuak = malloc(cpu_k * sizeof(struct cpuak_t)); 
   computation_engine.cpu_kopurua = cpu_k;
   computation_engine.gpuak = malloc(gpu_k * sizeof(struct gpuak_t)); 
   computation_engine.gpu_kopurua = gpu_k; 
   struct pcb *prozesu_nulua;

   for(i = 0; i < cpu_k; i++){
        computation_engine.cpuak[i].coreak = malloc(core_k * sizeof(struct coreak_t));
        computation_engine.cpuak[i].core_kopurua = core_k;
        for(j = 0; j < core_k; j++){
            computation_engine.cpuak[i].coreak[j].h_haria =  malloc(hhariak_k * sizeof(struct hardware_hariak_t));
            computation_engine.cpuak[i].coreak[j].hhari_kopurua = hhariak_k;
            for(k = 0; k < computation_engine.cpuak[i].coreak[j].hhari_kopurua; k++){
                //prozesu_nulua = malloc(sizeof(struct pcb));
                //prozesu_nulua->pid = 0;
                //prozesu_nulua->cycles = 0;
                sortu_prozesu_nulua(&prozesu_nulua);
                computation_engine.cpuak[i].coreak[j].h_haria[k].proc = prozesu_nulua; 
            }
        }

   } 
}
