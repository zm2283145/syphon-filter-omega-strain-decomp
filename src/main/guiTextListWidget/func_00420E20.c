#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiTextListWidget". */
int func_00420E20(void)
{
    return strcmp("GuiTextListWidget") == 0;
}
