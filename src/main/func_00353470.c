#include "types.h"

extern char D_004BB070[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004BB070 yields null. */
int func_00353470(void) {
    return strcmp(D_004BB070) == 0;
}
