#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_002098D0(void* obj);

/* Thin wrapper around func_002098D0. */
void func_002098B0(void* obj) {
    func_002098D0(obj);
}

#pragma pop
