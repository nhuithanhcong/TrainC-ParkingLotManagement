#include<billing.h>
#include<time.h>
#include<math.h>
#include<stdio.h>

PriceConfig table[3]={
{0, "Xe may", 3000.0, 3000.0},
{1, "O to", 10000.0, 10000.0 },
{2, "Xe tai", 15000.0, 15000.0 },
};

void calculateInvoice(Vehicle *v){
v-> exitTime= time(NULL);
double total_hours= (double)(v->exitTime - v->entryTime) / 3600.0;
int charged_hours = (int)ceil(total_hours);
double price = table[v-> vehicleType].pricePerHour;
v->fee = (double)charged_hours * price;

if(v->fee < table[v->vehicleType].minimumFee){
v->fee = table[v->vehicleType].minimumFee;
}

v->status = 1;

printf("Vehicle type: %s | Hours: %d | Fee: %.0f VND", table[v->vehicleType].typeName, charged_hours, v->fee);
}