#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiButtonWidget")) returned 0. */
int func_00420BB0(void) {
    return strcmp(((int*)"GuiButtonWidget")) == 0;
}
