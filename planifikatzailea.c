#include "list.h"
#include "sched.h"
#include "globals.h"
#include "dispatcher.h"
#include <stdio.h>
#include <stdlib.h>

void planifikatzailea(int cpu, int core, int hharia){ 
    if(list_empty(&prest_ilara)){
      //oraingoz kasu berezitzat hartu eta dispatcherrak egingo dituen esleipenetatik kanpo
      struct pcb* proz_nulua;
      sortu_prozesu_nulua(&proz_nulua);
      computation_engine.cpuak[cpu].coreak[core].h_haria[hharia].proc=proz_nulua;
      free(proz_nulua);
    }
    else{
      struct pcb *proz;
      switch(konf.planifikazio_politika){

          case FIFO:
              list_head(&prest_ilara,(void*) &proz);
              dispatcher_sartu_CPU(proz,cpu,core,hharia);
              break;
          default:
              printf("Planikazio-politika ez ezaguna\n");
              exit(-1);
      }
    }
}
