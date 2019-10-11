/**
 * Scheduler v1 SE/SO
 */

#include "io.h"
#include "proc.h"
#include "scheduling.h"
#include "computing_engine.h"
#include "system.h"
#include "misc.h"
#include "literal.h"
#include "conf.h"
#include "globals.h"
#include "literal.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){


  get_conf(argc - 1, argv);
	create_allprocs_queue();
        init_pid_array();
	create_ready_queue();
	create_computing_engine(conf.ncpus, conf.ncores, conf.nhthreads, conf.ngpus);

	read_file(conf.file_name);

  start_simulation();

}
