#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "parking.h"
#include "utils.h"

int findlicensePlate(char licensePlate[3636][16], int n, int vehicleType[3636], time_t entryTime[3636], int status[3636]) {
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

int addlicensePlate(char licensePlate[3636][16], int n, int vehicleType[3636], time_t entryTime[3636], int status[3636]) {
    if (n >= 3636) {
        printf("Error: Parking lot is full!\n");
        return n;
    }

    char tempPlate[16];
    while (1) {
        printf("Enter license plate: ");
        scanf("%15s", tempPlate);
        if (isDuplicatelicensePlate(licensePlate, n, tempPlate)) {
            printf("Duplicate plate! Try again.\n");
        } else { 
            break; 
        }
    }
    
    strcpy(licensePlate[n], tempPlate);

    printf("--- Type: 0:Motorcycle, 1:Car, 2:Truck ---\n");
    do {
        printf("Enter type of vehicle: ");
        scanf("%d", &vehicleType[n]);
    } while (vehicleType[n] < 0 || vehicleType[n] > 2);

    do {
        printf("Status (0:In, 1:Out): ");
        scanf("%d", &status[n]);
    } while (status[n] != 0 && status[n] != 1);
    
    entryTime[n] = time(NULL);
    printf("Add successful at: %s", ctime(&entryTime[n]));
    return n + 1; 
}

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


