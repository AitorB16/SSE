#ifndef _procs
#define _procs

typedef struct pcb {

	int pid;
	long cycles;

} pcb;

void sortu_allprocs_ilara();

void sortu_prozesu_berria(long iraupena);

void sortu_prozesu_nulua(struct pcb **proz_nulua);

#endif
