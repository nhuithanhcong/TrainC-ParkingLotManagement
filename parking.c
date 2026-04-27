#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "parking.h"
#include "utils.h"


int findlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636],int status[3636]){
	char find[16];
	int found=0;
	printf("Find license plate:");
	scanf("%15s",find);
	for(int i=0;i< n;i++){
		if(strcmp(find,licensePlate[i])==0){   //strcmp: ss 2 chuỗi find và license, giống thì = 0
			found=1;
			printf("Existed\n");
			printf("Type of vehicle: %d\n",vehicleType[i]); 
			printf("License Plate: %s\n",licensePlate[i]);
			printf("Entry Time: %s",ctime(&entryTime[i]));
			printf("Status: %d\n",status[i]);
			break;
	}}
	if(found==0){
			printf("Not found");
	}
	return 0;		
	}
	
int addlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636],int status[3636]){
	char tempPlate[16];
	int count =0;
	while(count<n){
	 	while(1){
			printf("Enter license plate:");
			scanf("%15s",tempPlate);
				if(isDuplicatelicensePlate(licensePlate,count,tempPlate)){
					printf("Duplicate plate! Try again.\n");
		}
				else{ break;}
		}
			strcpy(licensePlate[count], tempPlate); // Copy nội dung từ tempPlate(biến tạm) qua licensePlate[i]
			printf("Add successful!\n");
			printf("------Menu------\n Type of vehicle\n 0:motorbycle\n 1:car\n 2:truck\n ..................\n Status\n 0:in\n 1:out\n");
			do{ printf("Enter type of vehicle:");
				scanf("%d",&vehicleType[count]);
				if(vehicleType[count]!=0 && vehicleType[count]!=1 && vehicleType[count]!=2){
					printf("Invalid value! Please try again\n");
			}
		}	while(vehicleType[count]!=0 && vehicleType[count]!=1 && vehicleType[count]!=2);
				printf("Add successful!\n");
		do {printf("Status:");
			scanf("%d",&status[count]);
			if (status[count]!=0 && status[count]!=1){
				printf("Invalid value! Please try again\n");
			}
		}
		while(status[count]!=0 && status[count]!=1);
			printf("Add successful!\n");
		entryTime[count] = time(NULL);                  // lưu thời gian hiện tại (dạng số)
		printf("%s", ctime(&entryTime[count]));         // in ra dạng người đọc được
		count++;
}
	return count;
}
int display(char licensePlate[3636][16], int n,int vehicleType[3636],time_t entryTime[3636], int status[3636]){
	printf("=========== List of Vehicle =========== \n");
	for(int i= 0; i<n; i++){
	
		printf("Type of vehicle: %d\n",vehicleType[i]); 
		printf("License Plate: %s\n",licensePlate[i]);
		printf("Status: %d\n",status[i]);
		printf("Entry Time: %s",ctime(&entryTime[i]));
	}                                         
	printf("========================================\n");	
	}	

















