#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 2

extern char D_004A3F10[];
extern void func_00209D70(void* obj, int a1, int a2, const char* name, int a4);

/* Calls func_00209D70(obj, 0, 0, D_004A3F10, 100) when obj is non-null. */
void func_00209D30(void* self, void* obj)
{
    if (obj)
        func_00209D70(obj, 0, 0, D_004A3F10, 100);
}
