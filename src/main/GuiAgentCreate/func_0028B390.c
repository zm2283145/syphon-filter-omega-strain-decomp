#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentCreate")) returned 0. */
int func_0028B390(void) {
    return strcmp(((int*)"GuiAgentCreate")) == 0;
}
