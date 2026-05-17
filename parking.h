#ifndef PARKING_H
#define PARKING_H

#include "utils.h"

void addVehicle(Vehicle *vehicles, int *count); //them xe moi

void checkoutVehicle(Vehicle *vehicles, int count); //cho xe ra tinh tien

void searchVehicle(Vehicle *vehicles, int count); //Tim bien so

void listParkedVehicles(Vehicle *vehicles, int count); //hien thi danh sach xe

#endif