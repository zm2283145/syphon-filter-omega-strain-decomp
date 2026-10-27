#include "types.h"
extern int strcmp(void* p);
/* Returns whether the test on the global object fails. */
int GuiMapScreen_IsClass(void) { return strcmp("GuiMapScreen") == 0; }
