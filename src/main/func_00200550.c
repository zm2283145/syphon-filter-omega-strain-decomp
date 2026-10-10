#include "types.h"
extern void func_001ADB90(void* p, int n);
extern void operator_delete(void* p);
void* func_00200550(void* p, short flag)
{
    if (p) {
        func_001ADB90(p, -1);
        if (flag > 0) {
            operator_delete(p);
        }
    }
    return p;
}