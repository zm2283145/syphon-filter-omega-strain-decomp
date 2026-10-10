#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004B8D90[]; /* "GuiKeyboard" */

/* GuiKeyboard type check: true when name equals the class name "GuiKeyboard". */
int GuiKeyboard_IsType(void* self, const char* name) {
    return strcmp(D_004B8D90, name) == 0;
}
