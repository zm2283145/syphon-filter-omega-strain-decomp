#include "types.h"
typedef struct { char pad[0x30]; float v[6]; unsigned char state; } Msg;
typedef struct { char pad[0xC]; float v[6]; unsigned char isOne; } Buf;
extern int D_0055A208;
extern int func_003FF330(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf);
/* Serialises six floats and a state flag into buf; returns the size written (0x28) or -1. */
int func_003E5F20(Msg* m, int p1, int* type, int p3, int p4, unsigned int size, void* buf)
{
    Buf* out;
    int result = -1;
    if (size >= 0x28 && (out = (Buf*)buf) != 0) {
        func_003FF330(m, p1, 0, p3, p4, size, buf);
        out->v[0] = m->v[0];
        out->v[1] = m->v[1];
        out->v[2] = m->v[2];
        out->v[3] = m->v[3];
        out->v[4] = m->v[4];
        out->v[5] = m->v[5];
        out->isOne = m->state == 1;
        if (type) {
            result = 0x28;
            *type = D_0055A208;
        }
    }
    return result;
}
