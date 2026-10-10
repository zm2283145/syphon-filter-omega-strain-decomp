#include "types.h"

extern char D_004A7530[]; /* "GuiWidget" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiWidget::IsA: returns 1 if the given class name is "GuiWidget". */
int GuiWidget_IsType(void* self, const char* name)
{
    return strcmp(D_004A7530, name) == 0;
}
