#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAgentSave". */
int func_002927F0(void)
{
    return strcmp("GuiAgentSave") == 0;
}
