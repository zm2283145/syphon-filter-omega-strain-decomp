#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiGameOptions". */
int GuiGameOptions_IsType(void* self, const char* name)
{
    return strcmp("GuiGameOptions", name) == 0;
}
