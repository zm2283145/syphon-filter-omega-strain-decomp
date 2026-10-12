#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiAgentDisplay")) returned 0. */
int func_003652D0(void) {
    return strcmp(((int*)"GuiAgentDisplay")) == 0;
}
