#pragma cplusplus on
#include "types.h"
struct W_002ACB70 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct S_002ACB70 : W_002ACB70 {
    char pad4[0x48 - 4]; int f48; int f4C; int f50; unsigned int f54; char pad58[0x74 - 0x58];
    int f74; char pad78[0x7C - 0x78]; unsigned int f7C; char pad80[0xCC - 0x80];
    int fCC; char padD0[0x110 - 0xD0]; int count; char pad114[0x11C - 0x114]; void* p11C;
};
extern "C" {
void func_002AC070(S_002ACB70* self);
void func_00424430(S_002ACB70* self, int a, int b);
int func_004245D0(S_002ACB70* self, int a, unsigned int b);
void func_00424670(S_002ACB70* self, int a, unsigned int b);
void func_0044F280(void* p, int a);
}
static inline void Upd_(S_002ACB70* s, int n) { s->SetCount(s->f48, n); }
#pragma opt_dead_assignments off
extern "C" void func_002ACB70(S_002ACB70* self)
{
    unsigned int old = 0;
    if (self->f54 > self->f7C)
        old = self->f54 - self->f7C;
    func_002AC070(self);
    Upd_(self, self->count);
    func_00424430(self, 0, self->fCC);
    if (self->f54 >= self->f7C) {
        unsigned int d = self->f54 - self->f7C;
        if (d != old) {
            int v;
            d -= old;
            v = d + self->f7C;
            int lim = self->f4C - self->f74;
            if (v >= lim)
                v = lim;
            if (v < 0)
                v = 0;
            self->f7C = v;
        }
    }
    if (!func_004245D0(self, self->f50, self->f54))
        func_00424670(self, self->f50, self->f54);
    if (self->p11C)
        func_0044F280(self->p11C, 0);
}



#pragma opt_dead_assignments reset


