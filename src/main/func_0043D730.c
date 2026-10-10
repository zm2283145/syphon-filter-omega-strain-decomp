#include "types.h"

extern char D_004C01B0[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004C01B0. */
int func_0043D730(void* self, const char* name)
{
    return strcmp(D_004C01B0, name) == 0;
}
