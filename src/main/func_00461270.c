#include "types.h"

extern char D_004C25E0[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004C25E0 yields null. */
int func_00461270(void) {
    return strcmp(D_004C25E0) == 0;
}
