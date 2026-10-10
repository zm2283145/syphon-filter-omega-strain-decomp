#include "types.h"

extern char D_004AB628[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004AB628 yields null. */
int func_002A7AD0(void) {
    return strcmp(D_004AB628) == 0;
}
