#include "procs.h"
#include <stdio.h>
#include <stdlib.h>

void irakurri_fitxategia(char *fitx_izena) {

	FILE *fd;
	long ticks;

	if((fd = fopen(fitx_izena, "r")) == NULL){
		printf("Fitxategia irekitzerakoan errore bat gertatu da.\n");
		exit(-1);
	}
	
	while (fscanf(fd, "%ld", &ticks) != EOF){
                sortu_prozesu_berria(ticks);
		printf("Ticks %ld\n", ticks);
	}

	fclose(fd);
}
