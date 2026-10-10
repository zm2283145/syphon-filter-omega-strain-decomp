#include "types.h"

extern char D_004BA900[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string D_004BA900. */
int func_0034D280(void* self, const char* name)
{
    return strcmp(D_004BA900, name) == 0;
}
