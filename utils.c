#include "utils.h"
#include <string.h>
int isDuplicatelicensePlate(char plates[3636][16], int n, char* newPlate) {
    for (int i = 0; i < n; i++) {
        if (strcmp(plates[i], newPlate) == 0) return 1;
    }
    return 0;
}
