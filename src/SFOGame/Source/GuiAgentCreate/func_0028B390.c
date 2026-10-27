#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentCreate")) returned 0. */
int GuiAgentCreate_IsClass(void) {
    return strcmp(((int*)"GuiAgentCreate")) == 0;
}
