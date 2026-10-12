#include "types.h"

/* "GuiEquipmentModify" */
/* strcmp */
extern int strcmp(const char* a, const char* b);

/* GuiEquipmentModify::IsA: returns 1 if the given class name is "GuiEquipmentModify". */
int GuiEquipmentModify_IsType(void* self, const char* name)
{
    return strcmp("GuiEquipmentModify", name) == 0;
}
