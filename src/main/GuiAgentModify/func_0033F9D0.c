#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAgentModify". */
int GuiAgentModify_IsType(void)
{
    return strcmp("GuiAgentModify") == 0;
}
