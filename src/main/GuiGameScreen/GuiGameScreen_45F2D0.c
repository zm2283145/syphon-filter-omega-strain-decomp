#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAutoSaver". */
int func_0045F2D0(void)
{
    return strcmp("GuiAutoSaver") == 0;
}
