#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "parking.h"
char findlicensePlate(char licensePlate[3636][16], int n){
	char find[16];
	printf("Find license plate:\n");
	scanf("%15s",find);
	for(int i=0;i< n;i++){
		if(strcmp(find,licensePlate[i])==0){   //strcmp: ss 2 chuỗi find và license, giống thì = 0
			printf("Existed");
			break; 
	}}
	printf("Not found");
	return 0;		
	}
	
	
	
int isDuplicatelicensePlate(char licensePlate[3636][16],int n, char tempPlate[]){
	for(int i=0;i<n;i++){
		if (strcmp(tempPlate,licensePlate[i])==0){
			return 1;
		}
	}
	return 0;
}



int addlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636]){
	char tempPlate[16];
	for(int i=0; i<n ; i++){
		printf("Enter license plate:");
		scanf("%15s",tempPlate);
		if(isDuplicatelicensePlate(licensePlate,n,tempPlate)){
			printf("Duplicate plate! Try again.\n");
			i--;
			continue;
		}
		strcpy(licensePlate[i], tempPlate); // Copy nội dung từ tempPlate(biến tạm) qua licensePlate[i]
		printf("Add successful!\n");
		printf("---Menu---\n 0:motorbycle\n 1:car\n 2:truck\n");
		do{
			printf("Enter type of vehicle:");
			scanf("%d",&vehicleType[i]);
		if(vehicleType[i]!=0 && vehicleType[i]!=1 && vehicleType[i]!=2){
			printf("Invalid value! Please try again\n");
			}
		}while(vehicleType[i]!=0 && vehicleType[i]!=1 && vehicleType[i]!=2);
		printf("Add successful!\n");
		entryTime[i] = time(NULL);                  // lưu thời gian hiện tại (dạng số)
		printf("%s", ctime(&entryTime[i]));         // in ra dạng người đọc được
	
	return 0;
}}



int display(char licensePlate[3636][16], int n,int vehicleType[3636],time_t entryTime[3636]){
	printf("=========== List of Vehicle =========== \n");
	for (int i=0; i<n;i++){
		entryTime[i] = time(NULL);
		printf("Type of vehicle: %d\n",vehicleType[i]); 
		printf("License Plate: %s\n",licensePlate[i]);
		printf("Entry Time: %s",ctime(&entryTime[i]));
	}
	printf("========================================\n");	
	}
	
	
	
int main (){
	char licensePlate[3636][16]; //Tối đa 3636 xe và mỗi biển số dưới 16 ký tự
	int n;
	time_t entryTime[3636];
	int vehicleType[3636];
	printf("Enter number of vehicles to add to the list:");
	scanf("%d",&n);
	addlicensePlate(licensePlate,n,vehicleType,entryTime); 	
	display(licensePlate,n,vehicleType,entryTime);
	findlicensePlate(licensePlate,n);	
	return 0;
}
















