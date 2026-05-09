#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "parking.h"
//#include "billing.h"
//#include "fileio.h"
//#include "report.h"

#define MAX_VEHICLES 3636

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
	Vehicle vehicles[MAX_VEHICLES]; //mang quan ly bo nho tap chung
	int vehicleCount = 0;
	int choice;
	
	// (bo sung) ham load DATA từ file luu tru
	
    while(1) {
    	displayMenu();
    	if (scanf("%d", &choice) != 1){
    		printf("Vui chi nhap so");
			clearBuffer();
			continue;
		}

		switch(choice) {
            case 1:
            	printf("\n--- THEM XE MOI ---\n");
            	addVehicle(vehicles, &vehicleCount);
            	break;
            case 2:
            	printf("\n--- CHO XE RA & TINH TIEN---\n");

            	break;
            case 3:
            	printf("\n--- TIM KIEM XE ---\n");
            	searchVehicle(vehicles, vehicleCount);
            	break;
            case 4:
            	printf("\n=========== List of Vehicle =========== \n");
				listParkedVehicles(vehicles, vehicleCount);
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