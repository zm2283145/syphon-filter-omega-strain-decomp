#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiNetMessages" yields null. */
int GuiNetMessages_IsType(void) {
    return strcmp("GuiNetMessages") == 0;
}
