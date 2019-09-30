#ifndef _dispatcher
#define _dispatcher
#include "proc.h"

//hurrengo inplementazioetarako dispatcherretik schedeko sartu_prozesua_prest_ilaran funtzioari deituko diogu.

void dispatcher_CPU_in(struct pcb *proz,int cpu, int core, int hthread);

void dispatcher_CPU_out(int cpu, int core, int hthread);

#endif
