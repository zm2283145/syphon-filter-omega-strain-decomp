#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiGameScreen")) returned 0. */
int GuiGameScreen_IsType(void) {
    return strcmp(((int*)"GuiGameScreen")) == 0;
}
