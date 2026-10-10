#include "types.h"

extern char D_004C2760[]; /* "GuiEndGameObjectives" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiEndGameObjectives::IsA: returns 1 if the given class name is "GuiEndGameObjectives". */
int GuiEndGameObjectives_IsType(void* self, const char* name)
{
    return strcmp(D_004C2760, name) == 0;
}
