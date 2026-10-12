#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiMissionStatList". */
int func_00350570(void)
{
    return strcmp("GuiMissionStatList") == 0;
}
