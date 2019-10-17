#ifndef _conf
#define _conf

#include "misc.h"

typedef struct configuration_t{

    int ncpus;
    int ngpus;
    int ncores;
    int nhthreads;
    char *file_name;
    scheduling_policy_t scheduling_policy;
    execution_policy_t execution_policy;
    int quantum;

} configuration_t;

void get_conf(int num, char *argv[]);


#endif
