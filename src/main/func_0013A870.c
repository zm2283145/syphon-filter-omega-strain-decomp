#include "types.h"
typedef struct { __int128 q; } Q_A870;
typedef struct S_A870 {
    Q_A870 a;
    Q_A870 b;
    unsigned char on;
    int id;
    void* buf;
    char inl[0xD0 - 0x2C];
    int d0;
    int d4;
    int d8;
    int dc;
} S_A870;
#pragma peephole off
void cLosRequest_cCollisionModelList_Game_Reset(S_A870* self, Q_A870* a, Q_A870* b, int id, void* buf, int d0, int d4, int d8, int dc)
{
    self->a = *a;
    self->b = *b;
    self->on = 1;
    self->id = id;
    if (buf) asm { .set reorder } /* barrier: keep the empty then-block (b; nop) */ else buf = self->inl + 4;
    self->buf = buf;
    self->d0 = d0;
    self->d4 = d4;
    self->d8 = d8;
    self->dc = dc;
}
#pragma peephole reset
