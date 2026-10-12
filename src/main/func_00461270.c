#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiEndGameAwards" yields null. */
int func_00461270(void) {
    return strcmp("GuiEndGameAwards") == 0;
}
