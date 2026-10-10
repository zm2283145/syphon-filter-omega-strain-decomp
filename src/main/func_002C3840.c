#include "types.h"
extern void func_001BECC0(void* p, int a);
void func_002C3840(char* p, int n, int a)
{
    while (n != 0) {
        func_001BECC0(p, a);
        n--;
        p += 0x3C;
    }
}