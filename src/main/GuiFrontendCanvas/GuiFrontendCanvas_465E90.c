#include "types.h"

/* strcmp */
extern int strcmp(const char* a, const char* b);
/* "GuiFrontendCanvas" */

/* GuiFrontendCanvas type check: true when name equals the class name "GuiFrontendCanvas". */
int GuiFrontendCanvas_IsType(void* self, const char* name) {
    return strcmp("GuiFrontendCanvas", name) == 0;
}
