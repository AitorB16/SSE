#include "list.h"
#include "procs.h"
#include "sched.h"
#include <stdlib.h>
#include <stdio.h>

list_t allprocs;

void sortu_allprocs_ilara(){

        list_initialize(&allprocs);

}

void sortu_prozesu_berria(long iraupena){

    struct pcb *proz = malloc(sizeof(pcb));
    proz->cycles = iraupena;
    list_append(&allprocs, proz);
    printf("Prozesu berri bat sortuta\n");
    sartu_prozesua_prest_ilaran(proz);
}


void sortu_prozesu_nulua(struct pcb **proz_nulua){

    *proz_nulua = malloc(sizeof(struct pcb));
    (*proz_nulua)->pid = 0;
    (*proz_nulua)->cycles = 0;

}
