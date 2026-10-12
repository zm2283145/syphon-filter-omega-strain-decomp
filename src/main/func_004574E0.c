#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiStartMenuBackdrop". */
int func_004574E0(void* self, const char* name)
{
    return strcmp("GuiStartMenuBackdrop", name) == 0;
}
