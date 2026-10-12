#pragma push
#pragma opt_propagation off
#include "types.h"
#include "vc_copy.h"
typedef struct {
    __int128 pad0;
    __int128 q10;
    char pad20[0x4C - 0x20];
    int x4C; int x50; int x54; int x58; int x5C;
    unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1;
    unsigned char b4 : 1; unsigned char b5 : 1; unsigned char b6 : 1; unsigned char b7 : 1;
    char pad61[0x70 - 0x61];
    int x70; int x74; int x78;
} S_1840;
S_1840* NpcPath_Construct(S_1840* self, int a, int b, int c)
{
    self->x4C = c;
    self->x70 = a;
    self->x78 = b;
    self->x74 = 0;
    self->x5C = -1;
    self->x50 = -1;
    self->x54 = -1;
    self->x58 = -1;
    { int z = 0; self->b0 = z; self->b1 = z; self->b2 = z; }
    self->b3 = 1;
    self->b4 = 1;
    self->b5 = 1;
    self->b6 = 1;
    VZeroF(&self->q10);
    return self;
}
#pragma pop
