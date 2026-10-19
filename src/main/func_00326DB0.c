#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */

/* Returns 1 if name equals the string "GuiSlideShow". */
int GuiSlideShow_IsType(void* self, const char* name)
{
    return strcmp("GuiSlideShow", name) == 0;
}
