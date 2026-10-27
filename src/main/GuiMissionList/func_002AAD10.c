#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiMissionList_IsClass(void) { return strcmp("GuiMissionList") == 0; }
