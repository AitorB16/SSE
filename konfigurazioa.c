#include "literal.h"
#include "konfigurazioa.h"
#include <stdio.h>
#include <stdlib.h>

konfigurazioa_t konf;

static literal_t planifikazio_politikak_l[] = {
    {0, "fifo"},
    {1, "rr"},
    {2, "lehentasuna"}
};

static literal_t kanporaketa_politikak_l[] = {
    {0, "kanporatzailea"},
    {1, "ez-kanporatzailea"},
};



void sortu_konfigurazioa(int kop, char *argv[]){

        int cpu_k, core_k, hhariak_k, gpu_k;

        if (kop != 7){
		printf("Erabilera: planifikatzailea politika politika fitxategia cpu core hhariak gpu\n");
		exit(-1);
	}
    if(!literal_value(planifikazio_politikak_l, argv[1], (int *) &konf.planifikazio_politika)) {
        printf("Errorea 1\n");
        exit(-1);
 }
    if(!literal_value(kanporaketa_politikak_l, argv[2], (int *) &konf.kanporaketa_politika)) {
        printf("Errorea 2\n");
        exit(-1);
 }

    konf.fitx_izena = argv[3];
    konf.cpu_k = atoi(argv[4]);
    konf.core_k = atoi(argv[5]);
    konf.hhari_k = atoi(argv[6]);
    konf.gpu_k = atoi(argv[7]);


}
