#include "types.h"

/* "GuiNetJoinMission" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiNetJoinMission::IsA: returns 1 if the given class name is "GuiNetJoinMission". */
int GuiNetJoinMission_IsType(void* self, const char* name)
{
    return strcmp("GuiNetJoinMission", name) == 0;
}
