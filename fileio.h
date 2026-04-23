#indef FILEIO_H
#define FILEIO_H

#include "parking.h" //Toi chua biet nen dung file struct.h hay file parking.h vi ca hai file nay chua du lieu ma toi can cho bai code nay den de 
                     // tam la parking.h nha.:))))))))))))))))))
#include <stdio.h>

#define FILE_PATH "data/vehicles.dat" //phan nay se giup chuong trình tranh gap loi khi chuong trinh doc file (ghi chu: FILE_PATH khong phai la 
                                      // bien ma la mot marco).
                                      
//Luu danh sach xe hien tai vao file text
void saveToFile (struct Vehicle list[], int count );

//Doc du lieu tu file khi khoi dong chuong trinh
int loadFromFile(struct Vehicle list[]);

#endif