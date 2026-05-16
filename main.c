#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "parking.h"
#include "fileio.h"
#include "report.h"

#define MAX_VEHICLES 3636

void displayMenu(){
printf("\n--- PARKING MANAGEMENT SYSTEM ---\n");
		printf("1. Add vehicle to parking lot\n");
		printf("2. Checkout and payment\n");
		printf("3. Search vehicle information\n");
		printf("4. Check vehicles in parking lot\n");
		printf("5. Export revenue report\n");
		printf("6. Save data\n");
		printf("7. Exit\n");
		printf("-----------------------------------\n");
		printf("Select an option (1-7): ");
}

int main(){
	Vehicle vehicles[MAX_VEHICLES]; //mang quan ly bo nho tap chung
	int vehicleCount = 0;
	int choice;
	
	vehicleCount = loadFromFile(vehicles); //load vehicles.dat from data folder
	
    while(1) {
    	displayMenu();
    	if (scanf("%d", &choice) != 1){
    		printf("Please enter a number only!");
			clearBuffer();
			continue;
		}

		switch(choice) {
            case 1:
            	printf("\n=========== ADD NEW VEHICLE ===========\n");
            	addVehicle(vehicles, &vehicleCount);
            	break;
            case 2:
            	printf("\n=========== VEHICLE CHECKOUT & BILLING ===========\n");
				checkoutVehicle(vehicles, vehicleCount);
            	break;
            case 3:
            	printf("\n=========== SEARCH VEHICLE ===========\n");
            	searchVehicle(vehicles, vehicleCount);
            	break;
            case 4:
            	printf("\n=========== LIST OF VEHICLES ===========\n");
				listParkedVehicles(vehicles, vehicleCount);
            	break;
			case 5:
            	printf("\n=========== REVENUE REPORT ===========\n");
				exportReport(vehicles, vehicleCount);
            	break;
            case 6:
            	printf("\n=========== SAVE DATA ===========\n");
            	saveToFile(vehicles, vehicleCount); //save(overwrite) vehicles.dat from data folder
            	break;
            case 7:
            	printf("\n=========== PRESS ANYTHING TO EXIT ===========\n");
            	exit(0);
            	break;
            default:
            	printf("Invalid choice. Please try again!\n");
        }
    }

    return 0;
}
