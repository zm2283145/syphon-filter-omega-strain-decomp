#include "types.h"

extern char D_004BF900[]; /* "GuiTextArrayWidget" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiTextArrayWidget::IsA: returns 1 if the given class name is "GuiTextArrayWidget". */
int GuiTextArrayWidget_IsType(void* self, const char* name)
{
    return strcmp(D_004BF900, name) == 0;
}
