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

typedef struct customer {
	int resource1;
	int resource2;
	int resource3;
	int resource4;
} Customer;

int request_resources(int max[][100], int allocated[], int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES], int customerID); // RQ
int release_resources(int max[][100], int allocated[], int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES], int customerID); // RL
int safety_algo(int customer_num);
int readfile(char* file_name, Customer** customers);

int main(int argc, char *argv[])
{
	if(argc!=5) // ./a.out 10 5 7 8 (5 args)
	{
		printf("Need 4 values\n");
		return -1;
	}

	Customer* customers;
	//read the file and put them into the customer structure
	int customercount = readfile(FILE_NAME, &customers); 

	//declare available, allocated, need, and max array
	int available[NUMBER_OF_RESOURCES];
	int allocated[NUMBER_OF_RESOURCES];
	int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
	int max[NUMBER_OF_CUSTOMERS][100];


	for(int i = 0; i < customercount; i++){
		max[i][0] = customers[i].resource1;
		max[i][1] = customers[i].resource2;
		max[i][2] = customers[i].resource3;
		max[i][3] = customers[i].resource4;
	}

	printf("Number of Customers: %d\n", customercount);
	for(int i = 1; i < 5; i++){
		available[i] = atoi(argv[i]);
	}
	printf("Available Resources: ");
	for(int i = 1; i < 5; i++){
		printf("%d ",available[i]);
	}
	printf("\n");
	printf("Maximum resources from file:\n");
	for(int i = 0; i < customercount; i++){
		for(int j = 0; j < 4; j++){
			printf("%d",max[i][j]);
			if (j != 3){
				printf(",");
			}
		}
		printf("\n");
	}
	
	// interactive loop for user to enter requests RQ, RL or *
	char command[100];
	printf("Enter Command: ");
	while(fgets(command, 100, stdin) != NULL){
	// printf("%s",command);
		
		if (command == NULL) {
			printf("Error: Enter a proper command");
			return -1;
		}

		char* token = strtok(command, " ");
		int array[100];
		int i = 0;
		while(token!=NULL){
			array[i++] = atoi(token);
			token = strtok(NULL, " ");
		}

		int customerID;
		customerID = array[1];
		memcpy(allocated, &array[2], sizeof(array)+1);
		// for(int i = 0; i < 4; i++){
		// 	printf("%d",available[i]);
		// }
		printf("Request is unstatisfied\n");
		if(strstr(command,"RQ") != NULL){
			int request = request_resources(max, allocated, need, customerID);

			if(request == 1){
				printf("Request is satisfied\n");
			}else{
				printf("Request is unstatisfied\n");
			}
		}

		if(strstr(command,"RL") != NULL){
			printf("release");
		}

		if(strstr(command,"*") != NULL){
			printf("current state");
		}

		if(strstr(command,"run") != NULL){
			printf("safe sequence");
		}
		
		printf("\nEnter Command: ");
	}


	printf("\n");
}

int release_resources(int max[][100], int allocated[], int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES], int customerID){
	
	int satisfied = 1;



	return satisfied;
}

int request_resources(int max[][100], int allocated[], int need[][NUMBER_OF_RESOURCES], int customerID){

	// printf("customer ID:%d -> max resource:", customerID);
	// for(int i = 0; i < 4; i++){
	// 	printf("%d",max[customerID][i]);
	// }

	// printf("\nallocated requested resource:");
	// for(int i=0; i<4; i++){
	// 	printf("%d",allocated[i]);
	// }
	int satisfied = 1;

	for(int i=0; i<4; i++){
		if(max[customerID][i] - allocated [i] < 0){
			satisfied = 0;
		}
	}

	if(satisfied == 1){
		for(int i=0; i<4; i++){
			need[customerID][i] = max[customerID][i] - allocated [i];
			printf("%d",need[customerID][i]);
		}

		for(int i=0; i<4; i++){
			max[customerID][i] = need[customerID][i];
		}
	}

	// printf("\ncustomer ID:%d -> max resource:", customerID);
	// for(int i = 0; i < 4; i++){
	// 	printf("%d",max[customerID][i]);
	// }
	printf("\n");

	return satisfied;
}

int readfile(char* filename, Customer** customers) {

	FILE *in = fopen(filename, "r");
	if(!in)
	{
		printf("Child A: Error in opening input file...exiting with error code -1\n");
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
	
	*customers = (Customer*) malloc(sizeof(Customer)*customerCount);

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
		token =  strtok(lines[k],",");
		while(token!=NULL)
		{
			if(j==0){
				(*customers)[k].resource1 = atoi(token);
				}
			if(j==1){
				(*customers)[k].resource2 = atoi(token);
				}
			if(j==2){
				(*customers)[k].resource3 = atoi(token);
				}
			if(j==3){
				(*customers)[k].resource4 = atoi(token);
				}
			j++;
			token = strtok(NULL,",");
		}
	}
	return customerCount;
}