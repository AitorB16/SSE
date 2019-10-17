#include "list.h"
#include "proc.h"
#include "scheduling.h"
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_PID 1000000

int pid_array[MAX_PID];

list_t allprocs;

void init_pid_array(){

    int i;

    for (i = 0; i < MAX_PID;i++)
        pid_array[i] = 0;
}

void create_allprocs_queue(){

   list_initialize(&allprocs);

}

void create_new_process(long duration, int priority, long quantum){

    struct pcb *proc = malloc(sizeof(pcb));
    int pid;

    proc->cycles = duration;
    pid = generate_pid();
    proc->pid = pid;
    proc->priority=priority;
    //Exekuzio politika kanporatzailea bada, quantum finkatu. Bestela quantum=iraupena
    if (!conf.execution_policy)
    {
    	proc->quantum=quantum;
    }
    else{
    	proc->quantum=duration;
    }
    insert_process_allprocs_queue(proc);
    printf("New process created with pid %d\n", proc->pid);
    insert_process_ready_queue(proc);
}


void create_null_process(struct pcb **null_process){

    *null_process = malloc(sizeof(struct pcb));
    (*null_process)->pid = 0;
    (*null_process)->cycles = 0;
    (*null_process)->quantum = 0;
    (*null_process)->priority = 0;

}

int generate_pid(){

    int i;
    int pid = -1;

    for(i = 0; i < MAX_PID; i++){
       if(pid_array[i] == 0){
            pid = i + 1;
            pid_array[i] = 1;
            break;
       }
    }
    return(pid);
}

void release_pid(int pid){

    pid_array[pid - 1] = 0;
}

void insert_process_allprocs_queue(struct pcb *proc){

	list_append(&allprocs, proc);
}

void remove_process_allprocs_queue(struct pcb *proc){

    release_pid(proc->pid);
    list_rem_elem(&allprocs, proc);
}
