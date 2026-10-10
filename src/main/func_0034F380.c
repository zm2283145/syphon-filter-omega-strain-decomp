#include "types.h"

extern int D_004BAD20;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004BAD20) returned 0. */
int func_0034F380(void) {
    return strcmp(&D_004BAD20) == 0;
}
