#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiEquipmentSetup". */
int func_002A1CF0(void)
{
    return strcmp("GuiEquipmentSetup") == 0;
}
