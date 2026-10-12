#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiRadioLog". */
int func_00454120(void)
{
    return strcmp("GuiRadioLog") == 0;
}
