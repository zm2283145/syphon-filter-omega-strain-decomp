#include "types.h"

extern int strcmp(void*);

/* Returns whether strcmp(((int*)"GuiMissionStatistics")) returned 0. */
int GuiMissionStatistics_IsType(void) {
    return strcmp(((int*)"GuiMissionStatistics")) == 0;
}
