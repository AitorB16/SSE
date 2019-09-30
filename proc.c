#include "list.h"
#include "proc.h"
#include "scheduling.h"
#include <stdlib.h>
#include <stdio.h>

list_t allprocs;

void create_allprocs_queue(){

        list_initialize(&allprocs);

}

void create_new_process(long duration){

    struct pcb *proc = malloc(sizeof(pcb));
    proc->cycles = duration;
    list_append(&allprocs, proc);
    printf("New process created\n");
    insert_process_ready_queue(proc);
}


void create_null_process(struct pcb **null_process){

    *null_process = malloc(sizeof(struct pcb));
    (*null_process)->pid = 0;
    (*null_process)->cycles = 0;

}
