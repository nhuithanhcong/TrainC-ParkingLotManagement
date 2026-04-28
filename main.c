#include <stdio.h>
#include <stdlib.h>
#include "parking.h"
//#include "billing.h"
//#include "fileio.h"
//#include "report.h"
#include "utils.h"

void displayMenu(){        
		printf("\n--- PARKING MANAGEMENT SYSTEM ---\n");
		printf("1. Them xe vao bai\n");
		printf("2. Cho xe ra va tinh tien\n");
		printf("3. Tim kiem thong tin xe\n");
		printf("4. Kiem tra phuong tien trong bai\n");
		printf("5. Luu du lieu va thoat\n");
		printf("-----------------------------------\n");
		printf("Chon chuc nang(1-5): ");
}

int main(){
	int choice;
	char licensePlate[3636][16];
    int n = 0;
    int vehicleType[3636];
    time_t entryTime[3636];
    int status[3636];
	// (bo sung) ham load DATA từ file luu tru
    while(1) {
    	displayMenu();
    	if (scanf("%d", &choice) != 1){
    		printf("Vui chi nhap so");
    		while(getchar() != '\n'); //clear (BUFFER) tranh loi
    		continue;
		}

		switch(choice) {
            case 1:
            	printf("\n--- THEM XE MOI ---\n");
            	n = addlicensePlate(licensePlate, n, vehicleType, entryTime, status);
            	break;
            case 2:
            	printf("\n--- CHO XE RA & TINH TIEN---\n");
            	// (bo sung) ham trong parking.h & billing.h
            	break;
            case 3:
            	printf("\n--- TIM KIEM XE ---");
            	findlicensePlate(licensePlate, n, vehicleType, entryTime, status);
            	break;
            case 4:
            	printf("\n--- Danh Sach Xe ---");
            	display(licensePlate, n, vehicleType, entryTime, status);
            	break;
            case 5:
            	printf("Dang luu du lieu va thoat chuong trinh...\n");
            	// (bo sung) ham save DATA vao file luu tru
                exit(0);
            default:
            	printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }

    return 0;
}