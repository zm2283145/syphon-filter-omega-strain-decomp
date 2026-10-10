#include "types.h"

extern char D_004BA520[]; /* "GuiNetMessageArray" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiNetMessageArray::IsA: returns 1 if the given class name is "GuiNetMessageArray". */
int GuiNetMessageArray_IsType(void* self, const char* name)
{
    return strcmp(D_004BA520, name) == 0;
}
