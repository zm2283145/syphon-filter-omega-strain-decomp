#include "types.h"

extern char D_004A3F40[];
extern void func_0013D5C0(int size, int a1, const char* name, int line);

/* Allocates count 12-byte entries (tagged with D_004A3F40, line 0x5C). */
#pragma optimization_level 1
void func_002098E0(void* self, int count)
{
    func_0013D5C0(count * 12, 0, D_004A3F40, 0x5C);
}
#pragma optimization_level reset
