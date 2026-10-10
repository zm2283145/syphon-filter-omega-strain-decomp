#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int func_00207210(void* obj);
extern void func_0013D710(void* obj, int value, int zero, int arg);

/* Forwards func_00207210's result to func_0013D710. */
void func_00209620(void* obj, int arg) {
    func_0013D710(obj, func_00207210(obj), 0, arg);
}

#pragma pop
