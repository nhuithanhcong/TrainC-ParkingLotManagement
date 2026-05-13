#include <stdio.h>
#include <string.h>
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
        printf("Chua ra");
        return;
    }
    struct tm *tm_info = localtime(&t);
    char buffer[26];
    strftime(buffer, 26, "%d/%m/%Y %H:%M", tm_info);
    printf("%s", buffer);
}


// Tim vi tri xe theo bien so (tra ve index, neu khong thay tra ve -1)

int findVehicleIndex(Vehicle *vehicles, int count, const char *plate) {
    for (int i = 0; i < count; i++) {
        if (strcmp(vehicles[i].licensePlate, plate) == 0 && vehicles[i].status == 0) {
            return i;
        }
    }
    return -1;
}
				