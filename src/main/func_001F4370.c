#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern void func_001F43B0(void* obj, int* value);

/* Passes value by reference to func_001F43B0; returns obj. */
void* func_001F4370(void* obj, int value) {
    func_001F43B0(obj, &value);
    return obj;
}

#pragma pop
