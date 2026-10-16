#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiStartMenu". */
int func_00457440(void* self, const char* name)
{
    return strcmp("GuiStartMenu", name) == 0;
}
