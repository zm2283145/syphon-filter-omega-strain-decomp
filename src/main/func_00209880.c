#include "types.h"
#pragma optimization_level 1

extern int* func_001F4150(void);

/* Returns the first word of the object returned by func_001F4150. */
int func_00209880(void) {
    return *func_001F4150();
}
