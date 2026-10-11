#include "types.h"
extern unsigned char D_005721C8;
extern void Transport_Send(void* a, void* b, int c, void* d);
void func_003FF650(void* a0, void* a1, void* a2)
{
    if (D_005721C8)
        Transport_Send(a1, a0, -1, a2);
}