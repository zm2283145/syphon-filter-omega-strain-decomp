#include "types.h"

extern char D_004ABF50[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004ABF50 yields null. */
int func_002B0E90(void) {
    return strcmp(D_004ABF50) == 0;
}
