#include "types.h"
typedef struct { int a[4]; } Q_7880;
typedef struct { char pad[0x2C0]; Q_7880 e[16]; short x3C0; char pad2[0x40C - 0x3C2]; unsigned char count; } T_7880;
typedef struct { char pad[0xCC]; T_7880* t; } S_7880;
extern signed char D_00489CE0[];
extern int D_0055DE90;
Q_7880* func_00147880(S_7880* self, int id)
{
    signed char k;
    T_7880* t;
    if (id < 0)
        return 0;
    k = D_00489CE0[id];
    if (k < 0)
        return 0;
    t = self->t;
    if (t) {
        if (!(k < t->count))
            return 0;
        D_0055DE90 = t->x3C0;
        return &t->e[k];
    }
    return 0;
}