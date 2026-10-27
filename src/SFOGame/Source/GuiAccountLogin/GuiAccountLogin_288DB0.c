#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiAccountLogin" */

/* GuiAccountLogin type check: true when name equals the class name "GuiAccountLogin". */
int GuiAccountLogin_IsClass(void* self, const char* name) {
    return strcmp("GuiAccountLogin", name) == 0;
}
