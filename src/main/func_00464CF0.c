#include "types.h"

extern char D_004C2B78[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004C2B78. */
int func_00464CF0(void* self, const char* name)
{
    return strcmp(D_004C2B78, name) == 0;
}
