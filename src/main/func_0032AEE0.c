#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiKeyboard" */

/* GuiKeyboard type check: true when name equals the class name "GuiKeyboard". */
int GuiKeyboard_IsType(void* self, const char* name) {
    return strcmp("GuiKeyboard", name) == 0;
}
