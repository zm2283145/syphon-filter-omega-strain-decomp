#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiGameCanvas". */
int GuiGameCanvas_IsClass(void* self, const char* name)
{
    return strcmp("GuiGameCanvas", name) == 0;
}
