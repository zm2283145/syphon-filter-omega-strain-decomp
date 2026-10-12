#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the class name string "GuiGameOptions". */
int func_002996A0(void* self, const char* name)
{
    return strcmp("GuiGameOptions", name) == 0;
}
