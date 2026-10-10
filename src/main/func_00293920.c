#include "types.h"

extern char D_004A9E90[]; /* "GuiSaveAgentWidget" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiSaveAgentWidget::IsA: returns 1 if the given class name is "GuiSaveAgentWidget". */
int GuiSaveAgentWidget_IsType(void* self, const char* name)
{
    return strcmp(D_004A9E90, name) == 0;
}
