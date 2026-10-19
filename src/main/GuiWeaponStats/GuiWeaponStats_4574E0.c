#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiStartMenuBackdrop". */
int GuiStartMenuBackdrop_IsType(void* self, const char* name)
{
    return strcmp("GuiStartMenuBackdrop", name) == 0;
}
