#include "types.h"

extern int D_004BF520;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004BF520) returned 0. */
int func_00420BB0(void) {
    return strcmp(&D_004BF520) == 0;
}
