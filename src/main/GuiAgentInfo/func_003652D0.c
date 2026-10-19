#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentDisplay")) returned 0. */
int GuiAgentDisplay_IsType(void) {
    return strcmp(((int*)"GuiAgentDisplay")) == 0;
}
