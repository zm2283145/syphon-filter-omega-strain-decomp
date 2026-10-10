#include "types.h"

extern int D_004AB080;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004AB080) returned 0. */
int func_002A0D90(void) {
    return strcmp(&D_004AB080) == 0;
}
