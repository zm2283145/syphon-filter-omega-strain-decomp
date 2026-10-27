#include "types.h"
typedef struct { char pad[0xC]; unsigned char aC; } M34DF40;
typedef struct { void* vtable; char pad4[0x60]; int a64; int pad68; int a6C[24]; M34DF40 mCC; } S34DF40;
extern char D_004DECC0[];
extern void GuiPersonnelScreen_ctor(S34DF40* self);
extern void func_00296FA0(M34DF40* m);
S34DF40* GuiRatings_ctor(S34DF40* self)
{
    int i;
    M34DF40* m;
    GuiPersonnelScreen_ctor(self);
    self->vtable = D_004DECC0;
    m = &self->mCC;
    func_00296FA0(m);
    m->aC = 1;
    for (i = 0; i < 24; i++) self->a6C[i] = 0;
    self->a64 = 3;
    return self;
}