#ifndef PARKING_H
#define PARKING_H

#include <time.h>
#include <string.h>
int addlicensePlate(char licensePlate[3636][16],int n,int vehicleType[3636],time_t entryTime[3636]); //Thêm biển số

int isDuplicateLicensePlate(char licensePlate[][16], int n, char tempPlate[]); //Kiểm tra trùng biển số

char findlicensePlate(char licensePlate[3636][16], int n); //Tìm biển số

int display(char licensePlate[3636][16], int n,int vehicleType[3636],time_t entryTime[3636]);      // Hiển thị danh sách

#endif