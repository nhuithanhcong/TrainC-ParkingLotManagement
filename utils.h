#ifndef UTILS_H
#define UTILS_H
#define MAX_VEHICLES 3636
#include <time.h>

typedef struct {
	double fee;
	time_t exitTime[3636];
	time_t entryTime[3636];
	int vehicleType[3636]; 	// 0: xe may, 1: oto, 2: xe tai
	int status[3636];     // 0: in, 1: out
	char licensePlate[3636][16];  // khong trung bien so
} Vehicle;
#endif
