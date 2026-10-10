#include "types.h"

extern int D_004C2450;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004C2450) returned 0. */
int func_0045BCD0(void) {
    return strcmp(&D_004C2450) == 0;
}
