#include "list.h"
#include "sched.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

void planifikatzailea(int cpu, int core, int hharia){

    if(list_empty(&prest_ilara)){
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
              proz->pid=rand() % 32769;
              computation_engine.cpuak[cpu].coreak[core].h_haria[hharia].proc=(struct pcb *)proz;
              printf("pid %d duen prozesua CPU_%d, core_%d, h_haria_%d-ra mugitu da.\n", proz->pid, cpu, core, hharia);
              list_rem_head(&prest_ilara);
              break;
          default:
              printf("Planikazio-politika ez ezaguna\n");
              exit(-1);
      }
    }
}
