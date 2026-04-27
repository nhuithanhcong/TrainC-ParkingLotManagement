#ifndef PARKING_H
#define PARKING_H

#include <time.h>
#include <string.h>
int addlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636], int status[3636]); //Thêm biển số

int findlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636],int status[3636]); //Tìm biển số

int display(char licensePlate[3636][16], int n,int vehicleType[3636],time_t entryTime[3636], int status[3636]);      // Hiển thị danh sách

#endif