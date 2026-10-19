#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiStartMenu". */
int GuiStartMenu_IsType(void* self, const char* name)
{
    return strcmp("GuiStartMenu", name) == 0;
}
