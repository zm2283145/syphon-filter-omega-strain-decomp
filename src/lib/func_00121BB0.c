#include "types.h"

extern int strtod(int, int);

int atof(int a0) {
    return strtod(a0, 0);
}
