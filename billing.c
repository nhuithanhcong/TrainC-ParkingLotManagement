#include"billing.h"
#include"utils.h"
#include<time.h>
#include<math.h>
#include<stdio.h>

PriceConfig table[3] = {
{"Motorbike", 3000.0, 3000.0, 0},
{"Car", 10000.0, 10000.0, 1},
{"Truck", 15000.0, 15000.0, 2},
};

void calculateInvoice(Vehicle *v){

v->exitTime = time(NULL);

double seconds = difftime(v->exitTime, v->entryTime);

double total_hours = seconds/3600.0;
int charged_hours = ceil(total_hours);

double price = table[v->vehicleType].pricePerHour;
v->fee = charged_hours * price;
v->fee = ceil(v->fee / 1000.0)*1000.0;

if (v->fee < table[v->vehicleType].minimumFee){
v->fee = table[v->vehicleType].minimumFee;
}

v->status = 1;

printf("\n--- Payment Invoice ---\n");
printf("License Plate: %s\n", v->licensePlate);
printf("Vehicle Type : %s\n", table[v->vehicleType].typeName);
printf("Duration     : %d hour(s)\n", charged_hours);
printf("Total Fee    : %.0f VND\n", v->fee);

}


