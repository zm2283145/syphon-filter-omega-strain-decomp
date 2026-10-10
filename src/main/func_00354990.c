#include "types.h"

extern char D_004BB220[]; /* "GuiPersonnelMenu" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiPersonnelMenu::IsA: returns 1 if the given class name is "GuiPersonnelMenu". */
int GuiPersonnelMenu_IsType(void* self, const char* name)
{
    return strcmp(D_004BB220, name) == 0;
}
