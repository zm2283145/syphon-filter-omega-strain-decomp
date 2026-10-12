#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiOmegaStrain" */

/* GuiOmegaStrain type check: true when name equals the class name "GuiOmegaStrain". */
int GuiOmegaStrain_IsType(void* self, const char* name) {
    return strcmp("GuiOmegaStrain", name) == 0;
}
