#ifndef REPORT_H
#define REPORT_H

typedef struct {
	char licensePlate[50];
	char vehicleType[50]; //0:xe may, 1:oto, 2:xe tai
	double revenue;
	int status;			//0:in, 1:out
} Vehicle;



double totalRevenue(Vehicle list[], int n, int *xemay, int *oto, int *xetai); 	//thống kê doanh thu
void exportReport(Vehicle list[], int n); 										//xuất báo cáo .txt
#endif
