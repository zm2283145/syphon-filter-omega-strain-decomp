#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiQuickChat" yields null. */
int func_002B0E90(void) {
    return strcmp("GuiQuickChat") == 0;
}
