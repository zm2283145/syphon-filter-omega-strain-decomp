#include "types.h"
#pragma optimization_level 1

extern int D_004A3EF0;
extern void func_0020CA30(void*, int, int, void*, int);

/* Calls func_0020CA30(obj, 0, 0, &D_004A3EF0, 100) when obj is set. */
void func_0020C9F0(void* self, void* obj) {
    if (obj != 0) func_0020CA30(obj, 0, 0, &D_004A3EF0, 100);
}
