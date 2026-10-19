#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiMapScreen_IsType(void) { return strcmp("GuiMapScreen") == 0; }
