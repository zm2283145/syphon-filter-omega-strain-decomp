#include "types.h"

extern char D_004BBC28[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004BBC28. */
int func_003604E0(void* self, const char* name)
{
    return strcmp(D_004BBC28, name) == 0;
}
