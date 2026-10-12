#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiRanks". */
int func_0034E4A0(void* self, const char* name)
{
    return strcmp("GuiRanks", name) == 0;
}
