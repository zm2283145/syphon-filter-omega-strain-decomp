#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_0020B1B0(void* obj);

/* Thin wrapper around func_0020B1B0. */
void func_0020B190(void* obj) {
    func_0020B1B0(obj);
}

#pragma pop
