#include <stdio.h>
#include <stdlib.h>
//#include "parking.h"
//#include "billing.h"
//#include "fileio.h"
//#include "report.h"
//#include "utils.h"

void displayMenu(){        
		printf("\n--- PARKING MANAGEMENT SYSTEM ---");
		printf("1. Them xe vao bai\n");
		printf("2. Cho xe ra va tinh tien\n");
		printf("3. Tim kiem thong tin xe\n");
		printf("4. Bao cao thong ke doanh thu\n");
		printf("5. Luu du lieu va thoat\n");
		printf("-----------------------------------\n");
		printf("Chon chuc nang(1-5): ");
}

int main(){
	int choice;
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
            	// (bo sung) ham trong parking.h
            	break;
            case 2:
            	printf("\n--- CHO XE RA & TINH TIEN---\n");
            	// (bo sung) ham trong parking.h & billing.h
            	break;
            case 3:
            	printf("\n--- TIM KIEM XE ---");
            	// (bo sung) ham trong parking.h
            	break;
            case 4:
            	printf("\n--- BAO CAO DOANH THU ---");
            	// (bo sung) ham trong report.h
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