#include "types.h"

extern char D_004B8920[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004B8920. */
int func_00326DB0(void* self, const char* name)
{
    return strcmp(D_004B8920, name) == 0;
}
