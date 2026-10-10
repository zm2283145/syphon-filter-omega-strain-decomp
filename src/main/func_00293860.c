#include "types.h"

extern char D_004A9E60[];
extern void* strcmp(void* key);

/* Returns whether the lookup of D_004A9E60 yields null. */
int func_00293860(void) {
    return strcmp(D_004A9E60) == 0;
}
