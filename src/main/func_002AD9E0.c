#include "types.h"

extern char D_004ABBE8[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004ABBE8. */
int func_002AD9E0(void* self, const char* name)
{
    return strcmp(D_004ABBE8, name) == 0;
}
