#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiMessageBox" yields null. */
int func_002A7AD0(void) {
    return strcmp("GuiMessageBox") == 0;
}
