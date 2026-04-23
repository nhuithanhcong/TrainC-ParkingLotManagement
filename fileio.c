# include "fileio.h"
# include <stdio.h>

void saveToFile( struct Vehicle list[], int count){
	FILE *f;
	f = fopen(FILE_PATH, "w");
	if (f == NULL){
		printf("ERROR: Can Not Open The File To Save!\n"); // f == NULL se kiem tra xem chuong trinh co mo duoc file khong hay file bi loi 
	}

// count la bien dem so luong xe hien tai trong bai do xe. (Do khong biet ham main dung bien ten gi de dem so luong xe nen tam thoi de bien
// nay)
for (int i = 0; i < count; i++){
	fprintf(f, "%s, %d, %ld, %ld, %.2f, %d\n", //luu cac du lieu cach nhau bang dau phay
	        list[i].licensePlate,
	        list[i].vehicleType,
	        (long)list[i].entryTime,
	        (long)list[i].exitTime,
	        list[i].fee,
	        list[i].status);
}
fclose(f);
printf("Save %d vehicles.\n", count);
}

int saveToFile ( struct Vehicle list[]){
	FILE *f;
	f = fopen(FILE_PATH, "r");
	if (f == NULL){
		printf("ERROR: Can Not Open The File To Save!\n");
		return 0;
	}
	int count = 0; //Bien count nay dung de dem so luong xe trong ham nay (bien nay ko lien quan den các ham khac)
	// ham while duoi giup doc tung dong du lieu trong file de dem so luong xe cho bien count cho den het file (EOF)
	while (fscanf(f, "%[^,], %d, %ld, %ld, %lf, %d\n",
	        list[i].licensePlate,
	        &list[i].vehicleType,
	        &list[i].entryTime,
	        &list[i].exitTime,
	        &list[i].fee,
	        &list[i].status) != EOF){
	count++;
	// Gioi han suc chua cua bai xe
	if (count >= 3636){
		break;}    	
	}
	fclose(f);
	printf("Load the data of %d vehicles.\n", count);
	return count;
}
