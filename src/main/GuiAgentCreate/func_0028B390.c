#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentCreate")) returned 0. */
int GuiAgentCreate_IsType(void) {
    return strcmp(((int*)"GuiAgentCreate")) == 0;
}
