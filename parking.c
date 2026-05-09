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
	printf("--- Type: 0:Motorcycle, 1:Car, 2:Truck ---\n");
	scanf("%d", &newVehicle.vehicleType);
	clearBuffer();
	
	newVehicle.status = 0; // dang do
	
	vehicles[*count] = newVehicle;
	(*count)++;
	
	printf(" Them xe %s vao bai thanh cong luc: ", newVehicle.licensePlate);
	printTime(newVehicle.entryTime);
	printf("\n");
}

void searchVehicle(Vehicle *vehicles, int count) {
    char plate[20];
    printf("Nhap bien so xe can tim: ");
    scanf("%19s", plate);
    clearBuffer();

    printf("\nKet qua tim kiem cho '%s':\n", plate);
    int found = 0;
    for (int i = 0; i < count; i++) {
        // tim kiem chuoi con (ho tro tim mot phan bien so)
        if (strstr(vehicles[i].licensePlate, plate) != NULL) {
            printf("- Bien so: %s | Trang thai: %s | Vao: ", 
                   vehicles[i].licensePlate, 
                   vehicles[i].status == 0 ? "Dang do" : "Da ra");
            printTime(vehicles[i].entryTime);
            printf("\n");
            found++;
        }
    }
    if (found == 0) printf("Khong tim thay lich su nao.\n");
}


void listParkedVehicles(Vehicle *vehicles, int count) {


    printf("\n=========== List of Vehicle =========== \n");
    printf("%-15s %-10s %-20s\n", "Bien So", "Loai Xe", "Gio Vao");
    int found = 0;
    for (int i = 0; i < count; i++) {
		if (vehicles[i].status == 0) {
			printf("%-15s %-10d ", vehicles[i].licensePlate, vehicles[i].vehicleType);
			printTime(vehicles[i].entryTime);
			printf("\n");
			found++;
		}
    }
    if (found == 0) printf("No vehicles in parking lot.\n");
    printf("========================================\n");
}


