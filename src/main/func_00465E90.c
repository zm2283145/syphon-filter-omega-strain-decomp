#include "types.h"

extern int strcmp(const char* a, const char* b); /* strcmp */
extern char D_004C2BB0[]; /* "GuiFrontendCanvas" */

/* GuiFrontendCanvas type check: true when name equals the class name "GuiFrontendCanvas". */
int GuiFrontendCanvas_IsType(void* self, const char* name) {
    return strcmp(D_004C2BB0, name) == 0;
}
