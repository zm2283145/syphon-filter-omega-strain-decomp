#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiNetMessages" yields null. */
int func_00346D30(void) {
    return strcmp("GuiNetMessages") == 0;
}
