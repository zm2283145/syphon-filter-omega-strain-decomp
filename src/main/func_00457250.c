#include "types.h"

extern void* strcmp(void* key);

/* Returns whether the lookup of "GuiEquipmentPane" yields null. */
int func_00457250(void) {
    return strcmp("GuiEquipmentPane") == 0;
}
