#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

// Xoa bo dem ban phim tranh troi lenh
void clearBuffer() {
    int c;
    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break; 
        }
    }
}

// In thoi gian theo dinh dang de nhin

void printTime(time_t t) {
    if (t == 0) {
        printf("Not checked out yet");
        return;
    }
    struct tm *tm_info = localtime(&t);
    char buffer[26];
    strftime(buffer, 26, "%d/%m/%Y %H:%M", tm_info);
    printf("%s", buffer);
}


// Tim vi tri xe theo bien so (tra ve index, neu khong thay tra ve -1)

int findVehicleIndex(Vehicle *vehicles, int count, const char *plate) {
    for (int i = count - 1; i >= 0; i--) {
        if (strcmp(vehicles[i].licensePlate, plate) == 0 && vehicles[i].status == 0) {
            return i;
        }
    }
    return -1;
}

// kiem tra bie so xe

int plateChecker(const char *plate) {
    int len = strlen(plate);
    //DK1
    if (len < 5) {
        return 0;
    }
    //DK2
    if (!isdigit(plate[0]) || !isdigit(plate[1])) {
        return 0; 
    }
    //DK3
    for (int i = 0; i < len; i++) {
        if (!isalnum(plate[i]) && plate[i] != '-' && plate[i] != '.') {
            return 0; 
        }
    }
    //DK4
	int upper = 0; 
    for (int i = 0; i < len; i++) {
        if (isupper(plate[i])) {
            upper = 1; 
            break;        
        }
    }
    if (upper == 0) {
        return 0; 
    }
    return 1; 
}	