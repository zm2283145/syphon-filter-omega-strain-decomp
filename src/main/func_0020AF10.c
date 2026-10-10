#include "types.h"
extern char D_004A3F30[];
extern void func_0013D5C0(int size, int a, char* name, int b);
/* Allocates count 36-byte records. */
#pragma optimization_level 1
void func_0020AF10(void* unused, int count) { func_0013D5C0(count * 36, 0, D_004A3F30, 0x5C); }
#pragma optimization_level reset
