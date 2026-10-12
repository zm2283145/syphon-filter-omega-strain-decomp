#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string "GuiCommandCenter". */
int func_00294220(void* self, const char* name)
{
    return strcmp("GuiCommandCenter", name) == 0;
}
