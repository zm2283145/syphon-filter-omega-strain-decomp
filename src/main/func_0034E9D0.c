#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004BAA40[]; /* "GuiOmegaStrain" */

/* GuiOmegaStrain type check: true when name equals the class name "GuiOmegaStrain". */
int GuiOmegaStrain_IsType(void* self, const char* name) {
    return strcmp(D_004BAA40, name) == 0;
}
