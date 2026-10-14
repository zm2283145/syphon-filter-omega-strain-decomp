#include "types.h"

extern int strtol(int, int, int);

int atol(int a0) {
    return strtol(a0, 0, 10);
}
