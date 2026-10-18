#include "types.h"
typedef struct { __int128 r[4]; } M_D290;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D290 m[8]; } S_D290;
void IeDraw_PushMatrix(S_D290* s) {
    M_D290* d; M_D290* p; __int128 qa; __int128 qb; S_D290* b;
    int t = s->top; p = &s->m[t];
    b = (S_D290*)((char*)s + (t + 1) * 64);
    asm { .set reorder; lq qa, 0x0(p) }
    d = &b->m[0];
    asm { .set reorder; lq qb, 0x10(p) }
    asm { .set reorder; sq qa, 0x0(d) }
    asm { .set reorder; lq qa, 0x20(p) }
    asm { .set reorder; sq qb, 0x10(d) }
    asm { .set reorder; lq qb, 0x30(p) }
    asm { .set reorder; sq qa, 0x20(d) }
    asm { .set reorder; sq qb, 0x30(d) }
    s->top++;
}