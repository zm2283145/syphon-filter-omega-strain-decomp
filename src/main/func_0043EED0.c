#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004C0220[]; /* "GuiSliderWidget" */

/* GuiSliderWidget type check: true when name equals the class name "GuiSliderWidget". */
int GuiSliderWidget_IsType(void* self, const char* name) {
    return strcmp(D_004C0220, name) == 0;
}
