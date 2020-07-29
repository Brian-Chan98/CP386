#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc!=5)
	{
		printf("Need 4 values\n");
		return -1;
	}
	
	int resources[4], counter;
	for(counter=1;counter<argc;counter++){
		resources[counter] = atoi(argv[counter]);
		// printf("%d\n", resources[counter]);
	}

}