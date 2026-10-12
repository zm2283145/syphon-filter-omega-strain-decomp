#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiTitleScreen". */
int func_00287DD0(void* self, const char* name)
{
    return strcmp("GuiTitleScreen", name) == 0;
}
