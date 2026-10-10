#include "types.h"

extern char D_004C1E30[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004C1E30. */
int func_004574E0(void* self, const char* name)
{
    return strcmp(D_004C1E30, name) == 0;
}
