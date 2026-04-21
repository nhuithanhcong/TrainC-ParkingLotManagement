#ifndef STRUCTS_H
#define STRUCTS_H

#include <time.h>

#define MAX_VEHICLES 3636

typedef struct {
	double fee;
	time_t exitTime;
	time_t entryTime;
	int vehicleType; 	// 0: xe may, 1: oto, 2: xe tai
	int status;     // 0: in, 1: out
	char licensePlate[16];  // khong trung bien so
} Vehicle;
#endif
