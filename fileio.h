#ifndef FILEIO_H
#define FILEIO_H

#include "parking.h" 

#include <stdio.h>

#define FILE_PATH "data/vehicles.dat" //phan nay se giup chuong trình tranh gap loi khi chuong trinh doc file (ghi chu: FILE_PATH khong phai la 
                                      // bien ma la mot marco).

//Luu danh sach xe hien tai vao file text
void saveToFile ( Vehicle list[], int count );

//Doc du lieu tu file khi khoi dong chuong trinh
int loadFromFile( Vehicle list[] );

#endif