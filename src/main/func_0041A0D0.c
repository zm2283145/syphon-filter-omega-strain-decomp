#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiTextEditWidget". */
int func_0041A0D0(void* self, const char* name)
{
    return strcmp("GuiTextEditWidget", name) == 0;
}
