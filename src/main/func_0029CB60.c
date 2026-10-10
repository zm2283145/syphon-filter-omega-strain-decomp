#include "types.h"

extern char D_004AADE0[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004AADE0. */
int func_0029CB60(void* self, const char* name)
{
    return strcmp(D_004AADE0, name) == 0;
}
