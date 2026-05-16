#include <stdio.h>
#include <string.h>
#include "parking.h"
#include "billing.h"

void addVehicle(Vehicle *vehicles, int *count){
	Vehicle newVehicle;
	
	//kiem tra so luong xe trong bai
	if (*count >= 3636) {
    printf("Error: Parking lot is full! Cannot add more vehicles.\n");
    return;
	}

	printf("Enter license plate: ");
	scanf(" %15[^\n]", newVehicle.licensePlate);
	clearBuffer();
	
	//kiem tra bien so trung
	if(findVehicleIndex(vehicles, *count, newVehicle.licensePlate) != -1){
		printf("Error: Vehicle with plate %s is already in the parking lot!\n", newVehicle.licensePlate);
		return;
	}
	newVehicle.entryTime = time (NULL); //ghi lai thoi gian hien tai
	newVehicle.exitTime = 0;
	newVehicle.fee = 0.0;
	
	//PriceConfig
	printf("--- Type: 0:Motorcycle, 1:Car, 2:Truck ---\n");
	printf("Select vehicle type: ");
	scanf("%d", &newVehicle.vehicleType);
	clearBuffer();
	
	newVehicle.status = 0;
	
	vehicles[*count] = newVehicle;
	(*count)++;
	
	printf(" Vehicle %s added successfully at: ", newVehicle.licensePlate);
	printTime(newVehicle.entryTime);
	printf("\n");
}


void checkoutVehicle(Vehicle *vehicles, int count){
	char plate[16];
	printf("Enter license plate for checkout: ");
	scanf(" %15[^\n]", plate);
	clearBuffer();
	
	int index = findVehicleIndex(vehicles, count, plate);
	if (index != -1) {
		calculateInvoice(&vehicles[index]);
        printf("Vehicle %s has paid and left the parking lot.\n", plate);
    } else {
        printf("Error: Could not find vehicle with plate %s currently in the lot!\n", plate);
    }
}


void searchVehicle(Vehicle *vehicles, int count) {
    char plate[16];
    printf("Enter license plate to search: ");
    scanf(" %15[^\n]", plate);
    clearBuffer();

    printf("\nSearch results for '%s':\n", plate);
    int found = 0;
    for (int i = 0; i < count; i++) {
        // tim kiem chuoi con (ho tro tim mot phan bien so)
        if (strstr(vehicles[i].licensePlate, plate) != NULL) {
            printf("- Plate: %s | Status: %s | Entry: ", 
                   vehicles[i].licensePlate, 
                   vehicles[i].status == 0 ? "Parked" : "Checked out");
            printTime(vehicles[i].entryTime);
            printf("\n");
            found++;
        }
    }
    if (found == 0) printf("No history found.\n");
}


void listParkedVehicles(Vehicle *vehicles, int count) {

    printf("%-15s %-15s %-20s\n", "License Plate", "Vehicle Type", "Entry Time");
    int found = 0;
    for (int i = 0; i < count; i++) {
		if (vehicles[i].status == 0) {
			printf("%-15s %-15d ", vehicles[i].licensePlate, vehicles[i].vehicleType);
			printTime(vehicles[i].entryTime);
			printf("\n");
			found++;
		}
    }
    if (found == 0) printf("No vehicles in parking lot.\n");
    printf("========================================\n");
}