#include "types.h"

extern char D_004C1D50[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004C1D50 yields null. */
int func_00457250(void) {
    return strcmp(D_004C1D50) == 0;
}
