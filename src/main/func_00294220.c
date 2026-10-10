#include "types.h"

extern char D_004AA620[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string D_004AA620. */
int func_00294220(void* self, const char* name)
{
    return strcmp(D_004AA620, name) == 0;
}
