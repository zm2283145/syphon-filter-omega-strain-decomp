#include "types.h"

extern int strcmp(const char* a, const char* b);

/* Returns whether name equals the string "GuiBriefingPane". */
int func_00457390(void* self, const char* name)
{
    return strcmp("GuiBriefingPane", name) == 0;
}
