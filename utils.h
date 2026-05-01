#ifndef UTILS_H
#define UTILS_H

#include <time.h>


typedef struct {
    char licensePlate[16];
    time_t entryTime;
    time_t exitTime;  
    double fee;
    int vehicleType;       
    int status;      
} Vehicle;


typedef struct {
    char typeName[16];
    double pricePerHour;
    double minimumFee;
    int vehicleType;
} PriceConfig;


void clearBuffer();
void printTime(time_t t);
int findVehicleIndex(Vehicle *vehicles, int count, const char *plate);

#endif