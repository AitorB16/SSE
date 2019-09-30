#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

void read_file(char *file_name) {

	FILE *fd;
	long ticks;

	if((fd = fopen(file_name, "r")) == NULL){
		printf("Error while opening file.\n");
		exit(-1);
	}

	while (fscanf(fd, "%ld", &ticks) != EOF){
                create_new_process(ticks);
		printf("Ticks %ld\n", ticks);
	}

	fclose(fd);
}
