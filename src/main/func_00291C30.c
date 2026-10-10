#include "types.h"
extern void func_001BECC0(void* p, int x);
void func_00291C30(char* p, int n, int x)
{
    for (; n != 0; n--) {
        func_001BECC0(p, x);
        p += 0x3C;
    }
}