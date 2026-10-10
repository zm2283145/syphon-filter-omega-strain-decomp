#include "types.h"

extern char D_004BA990[];
extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string D_004BA990. */
int func_0034E4A0(void* self, const char* name)
{
    return strcmp(D_004BA990, name) == 0;
}
