#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiCanvas". */
int func_00414A50(void* self, const char* name)
{
    return strcmp("GuiCanvas", name) == 0;
}
