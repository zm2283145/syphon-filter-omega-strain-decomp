#include "types.h"
typedef struct { char pad[0x24]; int a; short b; } Ev1790;
typedef struct { char pad[8]; int a; short b; } Buf1790;
extern int D_00582768;
extern void Event_PackHeader(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int func_00432150(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x10 && buf) {
        Buf1790* b = (Buf1790*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a;
        b->b = e->b;
        if (type) {
            r = 0x10;
            *type = D_00582768;
        }
    }
    return r;
}