#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004BF3A8[]; /* "GuiTextWidget" */

/* GuiTextWidget type check: true when name equals the class name "GuiTextWidget". */
int GuiTextWidget_IsType(void* self, const char* name) {
    return strcmp(D_004BF3A8, name) == 0;
}
