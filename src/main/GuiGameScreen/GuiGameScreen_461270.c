#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiEndGameAwards" yields null. */
int GuiEndGameAwards_IsType(void) {
    return strcmp("GuiEndGameAwards") == 0;
}
