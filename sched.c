#include "list.h"
#include "procs.h"

list_t prest_ilara;

void sortu_prest_ilara(){
    
    list_initialize(&prest_ilara); 

}

void sartu_prozesua_prest_ilaran(struct pcb* proz){

    list_append(&prest_ilara, proz);

}

long prozesuak_planifikatzeko(){

    return(!list_empty(&prest_ilara));
}


