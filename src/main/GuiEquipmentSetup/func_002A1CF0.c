#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiEquipmentSetup". */
int GuiEquipmentSetup_IsType(void)
{
    return strcmp("GuiEquipmentSetup") == 0;
}
