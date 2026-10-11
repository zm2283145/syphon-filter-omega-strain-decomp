#include "types.h"
extern unsigned char D_005721C8;
extern void Transport_Send(int a, int b, int c, int d);
void func_003FF930(int a, int b)
{
    if (D_005721C8)
        Transport_Send(b, a, -1, -1);
}