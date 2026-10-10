#include "types.h"

extern char D_004C1E88[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string D_004C1E88. */
int func_00457440(void* self, const char* name)
{
    return strcmp(D_004C1E88, name) == 0;
}
