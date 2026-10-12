#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiGameScreen")) returned 0. */
int func_0045BCD0(void) {
    return strcmp(((int*)"GuiGameScreen")) == 0;
}
