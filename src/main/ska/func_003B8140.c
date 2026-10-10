#include "types.h"
extern void func_003B6F70(void* p, void* q);
extern void func_003B6DC0(void* p, void* q);
void func_003B8140(char* p, int n, char* x)
{
    for (; n != 0; n--) {
        func_003B6F70(p, x);
        func_003B6DC0(p + 0x10, x + 0x10);
        p += 0x180;
    }
}