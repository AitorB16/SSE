#ifndef _konfigurazioa
#define _konfigurazioa

#include "misc.h"

typedef struct konfigurazioa_t{

    int cpu_k;
    int gpu_k;
    int core_k;
    int hhari_k;
    char * fitx_izena;
    planifikazio_politika_t planifikazio_politika;
    kanporaketa_politika_t kanporaketa_politika;

} konfigurazioa_t;

void sortu_konfigurazioa(int kop, char *argv[]);

#endif
