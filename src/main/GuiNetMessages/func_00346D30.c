#include "types.h"

extern char D_004BA4E8[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004BA4E8 yields null. */
int func_00346D30(void) {
    return strcmp(D_004BA4E8) == 0;
}
