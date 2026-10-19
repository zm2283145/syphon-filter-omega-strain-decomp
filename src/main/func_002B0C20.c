#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiZeusShell". */
int GuiZeusShell_IsType(void)
{
    return strcmp("GuiZeusShell") == 0;
}
