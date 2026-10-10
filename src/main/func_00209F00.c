#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int* func_00209F30(void* obj);

/* Returns the int pointed to by func_00209F30's result. */
int func_00209F00(void* obj) {
    return *func_00209F30(obj);
}

#pragma pop
