#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004C1FB0[]; /* "GuiSubTitleDisplay" */

/* GuiSubTitleDisplay type check: true when name equals the class name "GuiSubTitleDisplay". */
int GuiSubTitleDisplay_IsType(void* self, const char* name) {
    return strcmp(D_004C1FB0, name) == 0;
}
