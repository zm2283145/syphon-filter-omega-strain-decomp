#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_001F44B0(void* obj);

/* Runs func_001F44B0 on obj and returns obj. */
void* func_001F4470(void* obj) {
    func_001F44B0(obj);
    return obj;
}

#pragma pop
