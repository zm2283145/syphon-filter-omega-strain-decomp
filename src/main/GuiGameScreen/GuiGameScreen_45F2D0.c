#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAutoSaver". */
int GuiAutoSaver_IsType(void)
{
    return strcmp("GuiAutoSaver") == 0;
}
