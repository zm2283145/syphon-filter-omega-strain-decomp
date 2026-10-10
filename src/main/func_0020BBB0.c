#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_0020BBD0(void* obj);

/* Thin wrapper around func_0020BBD0. */
void func_0020BBB0(void* obj) {
    func_0020BBD0(obj);
}

#pragma pop
