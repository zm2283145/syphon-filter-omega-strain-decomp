#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiZeusShell". */
int func_002B0C20(void)
{
    return strcmp("GuiZeusShell") == 0;
}
