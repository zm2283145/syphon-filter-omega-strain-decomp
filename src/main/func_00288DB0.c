#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004A98C0[]; /* "GuiAccountLogin" */

/* GuiAccountLogin type check: true when name equals the class name "GuiAccountLogin". */
int GuiAccountLogin_IsType(void* self, const char* name) {
    return strcmp(D_004A98C0, name) == 0;
}
