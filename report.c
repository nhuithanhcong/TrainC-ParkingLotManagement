#include <stdio.h>
#include "report.h"


double totalRevenue(Vehicle list[],int n); {
	double total = 0;		//xe may 2k, oto 5k, xe tai 10k
	
	for(int i=0; i<n; i++) {
		if(list[i].status==1) {
			switch (ds[i].vehicleType) {
				case 0: total += 2000; break;   // xe máy
                case 1: total += 5000; break;   // ô tô
                case 2: total += 10000; break;  // xe tải
			}
        }
    }
	return total;
}



//!!!!!!!!!!!!!!xuất báo cáo là do AI làm, chỉ mang tính tham khảo chứ ko đưa vào bài thật tế!!!!!!!!!!!!!!!!
void xuatBaoCao(Vehicle list[], int n)
{
    FILE *f = fopen("report.txt", "w");
    if (!f)
    {
        printf("Khong the tao file report.txt\n");
        return;
    }

    fprintf(f, "==== BAO CAO BAI DO XE ====\n\n");

    int xeMay = 0, oto = 0, xeTai = 0;
    int doanhThu = 0;

    for (int i = 0; i < n; i++)
    {
        // Đếm số lượng
        if (list[i].vehicleType == 0) xeMay++;
        else if (list[i].vehicleType == 1) oto++;
        else if (list[i].vehicleType == 2) xeTai++;

        // Tính doanh thu chỉ xe OUT
        if (list[i].status == 1)
        {
            switch (list[i].vehicleType)
            {
            case 0: doanhThu += 2000; break;   // Xe máy
            case 1: doanhThu += 5000; break;   // Ô tô
            case 2: doanhThu += 10000; break;  // Xe tải
            }
        }
    }

    fprintf(f, "So xe hien co trong he thong: %d\n", n);
    fprintf(f, " - Xe may : %d\n", xeMay);
    fprintf(f, " - Oto    : %d\n", oto);
    fprintf(f, " - Xe tai : %d\n", xeTai);

    fprintf(f, "\nTong doanh thu: %d VND\n", doanhThu);

    fprintf(f, "\n--- Danh sach xe ---\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d. Bien so: %s | Loai: %d | Status: %d\n",
            i + 1, list[i].licensePlate, list[i].vehicleType, list[i].status);
    }

    fclose(f);
    printf("Da xuat bao cao vao file report.txt!\n");