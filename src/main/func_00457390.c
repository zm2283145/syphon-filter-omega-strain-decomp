#include "types.h"

extern char D_004C1DD0[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string D_004C1DD0. */
int func_00457390(void* self, const char* name)
{
    return strcmp(D_004C1DD0, name) == 0;
}
