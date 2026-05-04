#include "utils.h"
#include <string.h>
int isDuplicatelicensePlate(char licensePlate[3636][16],int count, char tempPlate[16]){
	for(int i=0;i<count;i++){
		if (strcmp(tempPlate,licensePlate[i])==0){
			return 1;
		}
	}
	return 0;
}


//tinh tong loi nhuan [report]
double totalRevenue(Vehicle list[],int n); {
	double total = 0;		//xe may 2k, oto 5k, xe tai 10k
	
	for(int i=0; i<n; i++) {
		if(list[i].status==1) {		// 0: in, 1: out
			switch (list[i].vehicleType) {
				case 0: total += 2000; break;   // xe máy
                case 1: total += 5000; break;   // ô tô
                case 2: total += 10000; break;  // xe tải
			}
        }
    }
	return total;
}
