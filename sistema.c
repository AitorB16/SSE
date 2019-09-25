#include "globals.h"
#include "planifikatzailea.h"
#include <stdio.h>
#include <stdlib.h>

void hasi_sistema(){

    int i, j, k;

    while(1){

        for(i = 0; i < computation_engine.cpu_kopurua; i++){
            for(j = 0; j <  computation_engine.cpuak[i].core_kopurua; j++){
                for(k = 0; k < computation_engine.cpuak[i].coreak[j].hhari_kopurua; k++){
                    if(computation_engine.cpuak[i].coreak[j].h_haria[k].proc->pid == 0){
                        planifikatzailea(i, j, k);
                    }
                    else{
                        computation_engine.cpuak[i].coreak[j].h_haria[k].proc->cycles--;
                        if(computation_engine.cpuak[i].coreak[j].h_haria[k].proc->cycles == 0){
                          list_rem_head(&allprocs);
                          printf("pid %d: Exekuzioaren amaiera.\n",computation_engine.cpuak[i].coreak[j].h_haria[k].proc->pid );
                          if(list_empty(&allprocs)){
                            printf("Prozesu guztiak amaituta\n");
                            exit(0);
                          }
                          planifikatzailea(i, j, k);
                        }
                    }
                }
            }
        }
    }
}
