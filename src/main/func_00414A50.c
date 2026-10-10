#include "types.h"

extern char D_004BF018[];
extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string D_004BF018. */
int func_00414A50(void* self, const char* name)
{
    return strcmp(D_004BF018, name) == 0;
}
