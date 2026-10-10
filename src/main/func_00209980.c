#include "types.h"
#pragma optimization_level 1

extern int func_00201E80(void);
extern void func_002099B0(int);

/* Passes the result of func_00201E80 to func_002099B0. */
void func_00209980(void) {
    func_002099B0(func_00201E80());
}
