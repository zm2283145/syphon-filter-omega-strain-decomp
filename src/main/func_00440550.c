#include "types.h"

extern int D_004C0420;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004C0420) returned 0. */
int func_00440550(void) {
    return strcmp(&D_004C0420) == 0;
}
