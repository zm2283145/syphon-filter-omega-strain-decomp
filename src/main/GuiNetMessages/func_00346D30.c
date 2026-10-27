#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiNetMessages" yields null. */
int GuiNetMessages_IsClass(void) {
    return strcmp("GuiNetMessages") == 0;
}
