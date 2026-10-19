#include "types.h"
typedef struct { char pad[0x1C]; int flags; char pad2[4]; int a; signed char b; char pad3[3]; int c; int d; } Ev2920;
typedef struct { char pad[8]; signed char b; char pad2[3]; int a; int c; int d; } Buf2920;
extern int D_0051F090;
extern void Event_PackHeader(Ev2920* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int cNetLabelMsg_Serialize(Ev2920* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x18 && buf) {
        Buf2920* b = (Buf2920*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a; b->b = e->b; b->c = e->c; b->d = e->d;
        e->flags = 0x40;
        if (type) { r = 0x18; *type = D_0051F090; }
    }
    return r;
}