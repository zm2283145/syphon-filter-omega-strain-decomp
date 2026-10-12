#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiOnlineConnect". */
int func_0029CB60(void* self, const char* name)
{
    return strcmp("GuiOnlineConnect", name) == 0;
}
