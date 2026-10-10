#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_0020A690(void* obj);

/* Thin wrapper around func_0020A690. */
void func_0020A670(void* obj) {
    func_0020A690(obj);
}

#pragma pop
