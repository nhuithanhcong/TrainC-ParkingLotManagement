#include <stdio.h>
#include <time.h>
#include "report.h"

double totalRevenue(Vehicle list[], int n) {
    double total = 0;

    for(int i = 0; i < n; i++) {
        if(list[i].status == 1) {
            total += list[i].fee; 
        }
    }
    return total;
}


void exportReport(Vehicle list[], int n) {
	double total = totalRevenue(list, n);
	int xemay = 0, oto = 0, xetai = 0;
	
	
	FILE *f = fopen("report.txt", "w");
	if(!f) {
		printf("Cannot create file. \n");
		return;
	}
	
	fprintf(f, "===================== REPORT REVENUE OF PARKING LOT =====================\n\n");
	    fprintf(f, "%-15s %-25s %-25s %-15s %-25s\n",
        "Plate", "Entry Time", "Exit Time", "Type", "Fee");

    fprintf(f, "---------------------------------------------------------------------------------------------------\n");
	
	for(int i = 0; i < n; i++) {
		if(list[i].status == 1) {

			char entry[32], exit[32];
			strftime(entry, sizeof(entry), "%H:%M:%S %d/%m/%y", localtime(&list[i].entryTime)); //strftime: biến tg thành string 
			strftime(exit, sizeof(exit), "%H:%M:%S %d/%m/%y", localtime(&list[i].exitTime));
			
			
			//vehicle type
			const char *typeName = (list[i].vehicleType == 0)? "Xe may" : (list[i].vehicleType == 1)? "Oto" : "Xe tai";
			
			fprintf(f, "%-15s %-25s %-25s %-15s %-25.0f\n",
				list[i].licensePlate,
				entry,
				exit,
				typeName,
				list[i].fee);
		
		
			if(list[i].vehicleType == 0) xemay++;
		        else if (list[i].vehicleType == 1) oto++;
		            else xetai++;
		}
	}
	

		
		
	fprintf(f, "---------------------------------------------------------------------------------------------------\n\n");
	fprintf(f, "===== TOTAL VEHICLES ====\n");
	fprintf(f, "  Motorbike : %d\n", xemay);
    fprintf(f, "  Car   	: %d\n", oto);
    fprintf(f, "  Truck 	: %d\n", xetai);
	fprintf(f, "Total Revenue: %.1f\n", total);
	
	fclose(f);
	printf("Report is exported successfully!");
}