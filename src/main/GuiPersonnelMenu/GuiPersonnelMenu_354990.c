#include "types.h"

/* "GuiPersonnelMenu" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiPersonnelMenu::IsA: returns 1 if the given class name is "GuiPersonnelMenu". */
int GuiPersonnelMenu_IsType(void* self, const char* name)
{
    return strcmp("GuiPersonnelMenu", name) == 0;
}
