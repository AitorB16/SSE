#include "globals.h"
#include "scheduling.h"
#include "dispatcher.h"
#include <stdio.h>
#include <stdlib.h>

void start_simulation(){

    int i, j, k;

    

        while(1){

        for(i = 0; i < computing_engine.ncpus; i++){
            for(j = 0; j <  computing_engine.cpus[i].ncores; j++){
                for(k = 0; k < computing_engine.cpus[i].cores[j].nhthreads; k++){
                    if(computing_engine.cpus[i].cores[j].hthreads[k].proc->pid == 0){
                        schedule(i, j, k);
                    }
                    else{
                        computing_engine.cpus[i].cores[j].hthreads[k].proc->cycles--;
                        if(computing_engine.cpus[i].cores[j].hthreads[k].proc->cycles == 0)
                            schedule(i, j, k);
                    }
                }
            }
        }
    }
}
