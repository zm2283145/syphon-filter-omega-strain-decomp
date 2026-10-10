#include "types.h"

extern int D_004BBBA0;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004BBBA0) returned 0. */
int func_003652D0(void) {
    return strcmp(&D_004BBBA0) == 0;
}
