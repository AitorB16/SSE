#include "proc.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

void read_file(char *file_name) {

	FILE *fd;
	long ticks;
	int priority;

	if((fd = fopen(file_name, "r")) == NULL){
		printf("Error while opening file.\n");
		exit(-1);
	}

	switch (conf.scheduling_policy) {
		case FIFO:
			while (fscanf(fd, "%ld", &ticks) != EOF){
				fscanf(fd, "%d", &priority);
				create_new_process(ticks, 1, conf.quantum);
				printf("Ticks %ld\n", ticks);
			}
			break;
		case PRIORITY:
			while (fscanf(fd, "%ld", &ticks) != EOF){
				fscanf(fd, "%d", &priority);
				create_new_process(ticks, priority, conf.quantum);
				printf("Ticks %ld\n", ticks);
			}
			break;
	}
	
	fclose(fd);
}
