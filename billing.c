#include"billing.h"
#include"utils.h"
#include<time.h>
#include<math.h>
#include<stdio.h>

PriceConfig table[3] = {
{"Xe may", 3000.0, 3000.0, 0},
{"O to", 10000.0, 10000.0, 1},
{"Xe tai", 15000.0, 15000.0, 2},
};

void calculateInvoice(Vehicle *v){

v->exitTime = time(NULL);

double seconds = difftime(v->exitTime, v->entryTime);

double total_hours = seconds/3600.0;
int charged_hours = (int)ceil(total_hours);

double price = table[v->vehicleType].pricePerHour;
v->fee = (double)charged_hours * price;

if (v->fee < table[v->vehicleType].minimumFee){
v->fee = table[v->vehicleType].minimumFee;
}

v->status = 1;

printf("\n--- Hoá Đơn Thanh Toán ---\n");
printf("Bien so      : %s\n", v->licensePlate);
printf("Loai xe      : %s\n", table[v->vehicleType].typeName);
printf("Thoi gian gui: %d gio\n", charged_hours);
printf("Tong tien phi: %.0f VND\n", v->fee);


}


