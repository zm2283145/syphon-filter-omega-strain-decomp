#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiAgentInfo". */
int func_003604E0(void* self, const char* name)
{
    return strcmp("GuiAgentInfo", name) == 0;
}
