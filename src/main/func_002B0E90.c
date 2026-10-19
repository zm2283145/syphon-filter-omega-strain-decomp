#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiQuickChat" yields null. */
int GuiQuickChat_IsType(void) {
    return strcmp("GuiQuickChat") == 0;
}
