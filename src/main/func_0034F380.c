#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiMissionStatistics")) returned 0. */
int func_0034F380(void) {
    return strcmp(((int*)"GuiMissionStatistics")) == 0;
}
