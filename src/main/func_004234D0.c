#include "types.h"

extern char D_004BF768[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004BF768 yields null. */
int func_004234D0(void) {
    return strcmp(D_004BF768) == 0;
}
