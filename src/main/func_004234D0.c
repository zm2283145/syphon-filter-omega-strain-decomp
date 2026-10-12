#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiArrayWidget" yields null. */
int func_004234D0(void) {
    return strcmp("GuiArrayWidget") == 0;
}
