#include "utils.h"
#include <string.h>
int isDuplicatelicensePlate(char licensePlate[3636][16],int count, char tempPlate[16]){
	for(int i=0;i<count;i++){
		if (strcmp(tempPlate,licensePlate[i])==0){
			return 1;
		}
	}
	return 0;}
