#include "types.h"
typedef struct { __int128 r[4]; } M_D250;
typedef struct { char pad[0xA74]; int top; char flag; char pad2[7]; M_D250 m[8]; } S_D250;
void IeDraw_LoadViewMatrix(S_D250* s, M_D250* src) {
    M_D250* d; __int128 qa, qb; int one;
    int t = s->top;
    asm { .set reorder; lq qa, 0x0(src) }
    asm { .set reorder; lq qb, 0x10(src) }
    d = &s->m[t];
    
    asm { .set reorder; sq qa, 0x0(d) }
    one = 1;
    asm { .set reorder; lq qa, 0x20(src) }
    asm { .set reorder; sq qb, 0x10(d) }
    asm { .set reorder; lq qb, 0x30(src) }
    asm { .set reorder; sq qa, 0x20(d) }
    asm { .set reorder; sq qb, 0x30(d) }
    s->flag = one;
}