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
int readfile(char* file_name, Customer** customers);



int main(int argc, char *argv[])
{
	if(argc!=5) // ./a.out 10 5 7 8 (5 args)
	{
		printf("Need 4 values\n");
		return -1;
	}

	Customer* customers;
	int customercount = readfile(FILE_NAME, &customers); 
	// printf("%d\n",customercount);
	// printf("%d",customers->resource4);

	typedef int tbl[100][100];
	int max[100][100];
	tbl *pt;
	pt = &max;

	for(int i = 0; i < customercount; i++){
		for(int j = 0; j < 4; j++){
			(*pt)[i][0] = customers[i].resource1;
			(*pt)[i][1] = customers[i].resource2;
			(*pt)[i][2] = customers[i].resource3;
			(*pt)[i][3] = customers[i].resource4;
		// printf("%d",i);
		}
	}
	// int temp = (*pt)[1][0];
	// printf("%d",temp);

	for(int i = 0; i < customercount; i++){
		for(int j = 0; j < 4; j++){
			printf("%d",(*pt)[i][j]);
			
		// printf("%d",i);
		}
		printf("\n");
	}


	// int max[100][100];
	// for(int i = 0; i < customercount; i++){
	// 	max[i][0] = customers[i].resource1;
	// 	max[i][1] = customers[i].resource2;
	// 	max[i][2] = customers[i].resource3;
	// 	max[i][3] = customers[i].resource4;
	// }

	// // printf("%d",customers[1].resource1);
	// // printf("%d",max[2][0]);
	// for(int i = 0; i < customercount; i++){
	// 		// printf("%d",max[i][j]);
	// 	printf("%d",max[i][0]);
	// 	printf("%d",max[i][1]);
	// 	printf("%d",max[i][2]);
	// 	printf("%d",max[i][3]);
	// 	printf("\n");
	// }
	

	printf("\n");
		// printf("\n");
	// read file

	// print Max rescourses from file

	// interactive loop for user to enter requests RQ, RL or *
	// while (command != EXIT) {
	// 		fgets(line, stdin); split line 	
	//}

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
			// printf("%s",token);
			if(j==0){
				(*customers)[k].resource1 = atoi(token);
				// printf("%s",token);
				}
			if(j==1){
				(*customers)[k].resource2 = atoi(token);
				// printf("%s",token);
				}
			if(j==2){
				(*customers)[k].resource3 = atoi(token);
				// printf("%s",token);
				}
			if(j==3){
				(*customers)[k].resource4 = atoi(token);
				// printf("%s",token);
				}
			j++;
			token = strtok(NULL,",");
		}
		// printf("\n");
	}
	// printf("%d",customers.resource[0][0]);
	return customerCount;
}