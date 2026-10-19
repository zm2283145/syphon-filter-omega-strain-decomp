#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiEquipmentPane" yields null. */
int GuiEquipmentPane_IsType(void) {
    return strcmp("GuiEquipmentPane") == 0;
}
