#include "types.h"

extern char D_004A9680[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004A9680. */
int func_00287DD0(void* self, const char* name)
{
    return strcmp(D_004A9680, name) == 0;
}
