#include "types.h"

extern char D_004AAA68[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string D_004AAA68. */
int func_002996A0(void* self, const char* name)
{
    return strcmp(D_004AAA68, name) == 0;
}
