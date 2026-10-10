#include "types.h"
#pragma optimization_level 1

extern void func_001F3240(void*, int*);

/* Calls func_001F3240(self, &value) and returns self. */
void* func_001F3200(void* self, int value) {
    func_001F3240(self, &value);
    return self;
}
