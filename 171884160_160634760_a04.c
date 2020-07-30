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
int safety_algo(int customer_num);
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

	int customercount = readfile(FILE_NAME);

	Customer* customers;
	while(customercount != 0){
		printf("hi\n");
		customercount--;
	}
	// read file

	// print Max rescourses from file

	// interactive loop for user to enter requests RQ, RL or *
	// while (command != EXIT) {
	// 		fgets(line, stdin); split line 	
	//}

}

int readfile(char* filename) {

	FILE *in = fopen(filename, "r");
	if(!in)
	{
		printf("Error in opening input file...exiting with error code -1\n");
		return -1;
	}
	struct stat st;
	fstat(fileno(in), &st);
	char* fileContent = (char*)malloc(((int)st.st_size+1)* sizeof(char));
	fileContent[0]='\0';	
	while(!feof(in))
	{
		char line[100];
		if(fgets(line,100,in)!=NULL)
		{
			strncat(fileContent,line,strlen(line));
		}
	}
	fclose(in);
	char* command = NULL;
	int customerCount = 0;
	char* fileCopy = (char*)malloc((strlen(fileContent)+1)*sizeof(char));
	strcpy(fileCopy,fileContent);
	command = strtok(fileCopy,"\r\n");
	while(command!=NULL)
	{
		customerCount++;
		command = strtok(NULL,"\r\n");
	}

	char* lines[customerCount];
	command = NULL;
	int i=0;
	command = strtok(fileContent,"\r\n");
	while(command!=NULL)
	{
		lines[i] = malloc(sizeof(command)*sizeof(char));
		strcpy(lines[i],command);
		i++;
		command = strtok(NULL,"\r\n");
	}

	for(int k=0; k<customerCount; k++)
	{
		char* token = NULL;
		int j = 0;
		token =  strtok(lines[k],";");
		while(token!=NULL)
		{
//this loop tokenizes each line of input file
//write your code here to populate instances of Thread to build a collection
			Customer customer;
			customer.customerID = k;
			if(j==0)
				customer.resource1 = atoi(token);
				printf("%s\n",token);
				printf("%d\n",customer.resource1);
			if(j==1)
				customer.resource2 = atoi(token);
			if(j==2)
				customer.resource3 = atoi(token);
			if(j==3)
				customer.resource4 = atoi(token);
			j++;
			token = strtok(NULL,";");
		}
	}
	return customerCount;
}