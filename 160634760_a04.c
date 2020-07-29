#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <semaphore.h>

#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 4
#define FILE_NAME "sample4_in.txt"

typedef struct customer { // not sure if this is needed
	int customerID;
	int resource1;
	int resource2;
	int resource3;
	int resource4;
} Customer;

int available[NUMBER_OF_RESOURCES]; // what else am I missing?
int maximum[NUMBER_OF_CUSTOMERS];
int allocated[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
int request_resources(int customer_num, int request[]); // RQ
int release_resoucres(int customer_num, int release[]); // RL
int safety_algo(customer_num);
int readfile(char* file_name);

int main(int argc, char *argv[])
{
	if(argc!=5) // ./a.out 10 5 7 8 (5 args)
	{
		printf("Need 4 values\n");
		return -1;
	}
	
	int resources[4], counter;
	for(counter=1;counter<argc;counter++){
		resources[counter] = atoi(argv[counter]);
		// printf("%d\n", resources[counter]);
	}

	// read file

	// print Max rescourses from file

	// interactive loop for user to enter requests RQ, RL or *
	// while (command != EXIT) {
	// 		fgets(line, stdin); split line 	
	//}

}