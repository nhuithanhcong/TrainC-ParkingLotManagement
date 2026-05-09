#ifndef PARKING_H
#define PARKING_H

#include "utils.h"

void addVehicle(Vehicle *vehicles, int *count); //them xe moi

void searchVehicle(Vehicle *vehicles, int count); //Tìm biển số

void listParkedVehicles(Vehicle *vehicles, int count); //hien thi danh sach xe

#endif