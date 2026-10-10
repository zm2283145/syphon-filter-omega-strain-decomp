#include "types.h"

extern char D_004AB720[]; /* "GuiNetJoinMission" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiNetJoinMission::IsA: returns 1 if the given class name is "GuiNetJoinMission". */
int GuiNetJoinMission_IsType(void* self, const char* name)
{
    return strcmp(D_004AB720, name) == 0;
}
