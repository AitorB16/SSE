#include "list.h"
#include "sched.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

void planifikatzailea(int cpu, int core, int hharia){
    
    struct pcb *proz;

    switch(konf.planifikazio_politika){

        case FIFO:
            break;
        default:
            printf("Planikazio-politika ez ezaguna\n");
            exit(-1);
    }


}
