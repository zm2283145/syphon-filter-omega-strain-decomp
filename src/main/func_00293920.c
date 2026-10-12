#include "types.h"

/* "GuiSaveAgentWidget" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiSaveAgentWidget::IsA: returns 1 if the given class name is "GuiSaveAgentWidget". */
int GuiSaveAgentWidget_IsType(void* self, const char* name)
{
    return strcmp("GuiSaveAgentWidget", name) == 0;
}
