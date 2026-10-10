#include "types.h"
typedef struct { char pad[0x24]; int a; int b; float x; float y; float z; int c; int d; } Msg;
typedef struct { int h0, h1; int a; int b; float x; float y; float z; int c; int d; } Buf;
extern int D_0051EE60;
extern int Event_PackHeader(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf);
/* Serialises the message's fields into buf; returns the size written (0x24) or -1. */
int func_002C65E0(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf)
{
    Buf* out;
    int result = -1;
    if (size >= 0x24 && (out = (Buf*)buf) != 0) {
        Event_PackHeader(m, p1, type, p3, p4, size, buf);
        out->a = m->a;
        out->b = m->b;
        out->x = m->x;
        out->y = m->y;
        out->z = m->z;
        out->c = m->c;
        out->d = m->d;
        if (type) {
            result = 0x24;
            *type = D_0051EE60;
        }
    }
    return result;
}
