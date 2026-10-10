#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 2

extern char D_004A3F20[];
extern void func_0013D5C0(int size, int a1, const char* name, int a3);

/* Calls func_0013D5C0 for count entries of 20 bytes, tagged with D_004A3F20. */
void func_0020BB70(void* self, int count)
{
    func_0013D5C0(count * 20, 0, D_004A3F20, 0x5C);
}
