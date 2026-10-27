#include "types.h"

char D_004C1D78[] = "GuiWeaponStats"; /* "GuiWeaponStats" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiWeaponStats::IsA: returns 1 if the given class name is "GuiWeaponStats". */
int GuiWeaponStats_IsClass(void* self, const char* name)
{
    return strcmp(D_004C1D78, name) == 0;
}
