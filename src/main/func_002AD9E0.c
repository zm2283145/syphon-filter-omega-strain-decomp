#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiNetContacts". */
int func_002AD9E0(void* self, const char* name)
{
    return strcmp("GuiNetContacts", name) == 0;
}
