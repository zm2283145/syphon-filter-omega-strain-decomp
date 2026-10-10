#include "types.h"

extern char D_004AC810[]; /* "GuiEquipmentModify" */
extern int strcmp(const char* a, const char* b); /* strcmp */

/* GuiEquipmentModify::IsA: returns 1 if the given class name is "GuiEquipmentModify". */
int GuiEquipmentModify_IsType(void* self, const char* name)
{
    return strcmp(D_004AC810, name) == 0;
}
