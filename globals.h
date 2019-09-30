#ifndef _globals
#define _globals

#include "computing_engine.h"
#include "conf.h"
#include "list.h"

extern struct computing_engine_t computing_engine;
extern list_t allprocs;
extern list_t ready_queue;
extern configuration_t conf;

#endif
