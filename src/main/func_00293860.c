#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiAgentLoad" yields null. */
int func_00293860(void) {
    return strcmp("GuiAgentLoad") == 0;
}
