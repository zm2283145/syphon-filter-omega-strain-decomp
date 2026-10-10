#include "types.h"

extern int D_004ABE00;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004ABE00) returned 0. */
int func_002AF010(void) {
    return strcmp(&D_004ABE00) == 0;
}
