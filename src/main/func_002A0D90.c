#include "types.h"

int D_004AB080 = 0x4D697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004AB080) returned 0. */
int func_002A0D90(void) {
    return strcmp(&D_004AB080) == 0;
}
