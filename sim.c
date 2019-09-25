/**
 * Planifikatzailea v1 SE/SO
 */

#include "si.h"
#include "procs.h"
#include "sched.h"
#include "computation_engine.h"
#include "sistema.h"
#include "misc.h"
#include "literal.h"
#include "konfigurazioa.h"
#include "globals.h"
#include "literal.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	

        sortu_konfigurazioa(argc - 1, argv);	
        sortu_allprocs_ilara();
	sortu_prest_ilara();
	sortu_computation_engine(konf.cpu_k, konf.core_k, konf.hhari_k, konf.gpu_k);

	irakurri_fitxategia(konf.fitx_izena);

        hasi_sistema();

}
