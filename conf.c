#include "literal.h"
#include "conf.h"
#include <stdio.h>
#include <stdlib.h>

configuration_t conf;

static literal_t scheduling_policies_l[] = {
    {0, "fifo"},
    {1, "rr"},
    {2, "priority"}
};

static literal_t execution_policies_l[] = {
    {0, "preemptive"},
    {1, "nonpreemptive"},
};



void get_conf(int kop, char *argv[]){

    if (kop != 7){
		    printf("Use: ./sim queue_policy execution_policy file_name cpu core hthread gpu\n");
		    exit(-1);
    }
    if(!literal_value(scheduling_policies_l, argv[1], (int *) &conf.scheduling_policy)) {
        printf("Unknown scheduling policy\n");
        exit(-1);
    }
    if(!literal_value(execution_policies_l, argv[2], (int *) &conf.execution_policy)) {
        printf("Unknown execution policy\n");
        exit(-1);
    }

    conf.file_name = argv[3];
    conf.ncpus = atoi(argv[4]);
    conf.ncores = atoi(argv[5]);
    conf.nhthreads = atoi(argv[6]);
    conf.ngpus = atoi(argv[7]);


}
