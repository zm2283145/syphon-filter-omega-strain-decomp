#include "types.h"

extern char D_004BB450[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string D_004BB450. */
int func_00356820(void* self, const char* name)
{
    return strcmp(D_004BB450, name) == 0;
}
