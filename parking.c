#include <stdio.h>
#include <string.h>
#include "parking.h"
//#include "billing.h"

void addVehicle(Vehicle *vehicles, int *count){
	Vehicle newVehicle;
	printf("Nhap bien so xe: ");
	scanf("%15s", newVehicle.licensePlate);
	clearBuffer();
	
	//kiem tra bien so trung
	if(findVehicleIndex(vehicles, *count, newVehicle.licensePlate) != -1){
		printf("Loi: xe co bien so %s dang do trong bai!\n", newVehicle.licensePlate);
		return;
	}
	newVehicle.entryTime = time (NULL); // de ghi lai thoi gian hien tai
	newVehicle.exitTime = 0;
	newVehicle.fee = 0.0;
	
	//printPriceConfig();
	//printf("--- Type: 0:Motorcycle, 1:Car, 2:Truck ---\n");
	//scanf("%d", &newVehicle.vehicleType);
	//clearBuffer();
	
	newVehicle.status = 0 // dang do
	
	vehicles[*count] = newVehicle;
	(*count)++;
	
	printf(" Them xe %s vao bai thanh cong luc: ", newVehicle.licensePlate);
	printfTime(newVehicle.entryTime);
	printf("\n")
}

/*int findlicensePlate(char licensePlate[3636][16], int n, int vehicleType[3636], time_t entryTime[3636], int status[3636]) {
    char find[16];
    int found = 0;
    printf("\nEnter license plate to find: ");
    scanf("%15s", find);
    for (int i = 0; i < n; i++) {
        if (strcmp(find, licensePlate[i]) == 0) {
            found = 1;
            printf("Found!\n");
            printf("Type of vehicle: %d\n", vehicleType[i]); 
            printf("License Plate: %s\n", licensePlate[i]);
            printf("Entry Time: %s", ctime(&entryTime[i]));
            printf("Status: %d\n", status[i]);
            break;
        }
    }
    if (found == 0) printf("Not found!\n");
    return 0;        
}
*/
/*
int display(char licensePlate[3636][16], int n, int vehicleType[3636], time_t entryTime[3636], int status[3636]) {
    if (n == 0) {
        printf("\nNo vehicles in parking lot.\n");
        return 0;
    }
    printf("\n=========== List of Vehicle =========== \n");
    for (int i = 0; i < n; i++) {
        printf("[%d] Plate: %s | Type: %d | Status: %d | In: %s", 
                i + 1, licensePlate[i], vehicleType[i], status[i], ctime(&entryTime[i]));
    }
    printf("========================================\n");
    return 0;
}
*/

