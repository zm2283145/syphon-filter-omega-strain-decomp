#include "types.h"
typedef struct { char pad[0x2C]; int a; int b; } Msg;
typedef struct { int h0, h1; int a; int b; } Buf;
extern int D_004F80B0;
extern int Event_PackHeader(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf);
/* Serialises the message's two fields into buf; returns the size written (16) or -1. */
int func_0025E3E0(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf)
{
    Buf* out;
    int result = -1;
    if (size >= 16 && (out = (Buf*)buf) != 0) {
        Event_PackHeader(m, p1, type, p3, p4, size, buf);
        out->a = m->a;
        out->b = m->b;
        if (type) {
            result = 16;
            *type = D_004F80B0;
        }
    }
    return result;
}
