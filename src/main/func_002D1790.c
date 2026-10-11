#include "types.h"
typedef struct { char pad[0x2C]; int a; int b; } Ev1790;
typedef struct { char pad[8]; int a; int b; } Buf1790;
extern int D_0051F070;
extern void Event_PackHeader(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int func_002D1790(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x10 && buf) {
        Buf1790* b = (Buf1790*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a;
        b->b = e->b;
        if (type) {
            r = 0x10;
            *type = D_0051F070;
        }
    }
    return r;
}