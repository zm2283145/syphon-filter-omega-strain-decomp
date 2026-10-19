#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiObjectives". */
int GuiObjectives_IsType(void)
{
    return strcmp("GuiObjectives") == 0;
}
