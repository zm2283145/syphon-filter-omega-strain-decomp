#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiAgentModify". */
int GuiAgentModify_IsClass(void)
{
    return strcmp("GuiAgentModify") == 0;
}
