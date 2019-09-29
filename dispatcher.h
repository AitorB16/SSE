#ifndef _dispatcher
#define _dispatcher
#include "procs.h"

//hurrengo inplementazioetarako dispatcherretik schedeko sartu_prozesua_prest_ilaran funtzioari deituko diogu.

void dispatcher_sartu_CPU(struct pcb *proz,int cpu, int core, int hharia);

void dispatcher_atera_CPU(struct pcb *proz,int cpu, int core, int hharia);

#endif

