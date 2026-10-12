#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiPersonnelScreen". */
int func_00356820(void* self, const char* name)
{
    return strcmp("GuiPersonnelScreen", name) == 0;
}
