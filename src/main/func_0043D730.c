#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiMLTextWidget". */
int func_0043D730(void* self, const char* name)
{
    return strcmp("GuiMLTextWidget", name) == 0;
}
