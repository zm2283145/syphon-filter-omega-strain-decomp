#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiRadioLog". */
int GuiRadioLog_IsClass(void)
{
    return strcmp("GuiRadioLog") == 0;
}
