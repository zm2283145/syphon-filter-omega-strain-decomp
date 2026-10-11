#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M2995D0;
typedef struct { void* vt; char pad[0xDC]; M2995D0 mE0; char pad2[0x270 - 0xE0 - sizeof(M2995D0)]; M2995D0 m270; } O2995D0;
extern char D_004DD580[];
extern char D_004E1220[];
extern void func_0036E220(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
static inline void M2995D0_dtor(M2995D0* m)
{
    if (m) {
        func_0036E220(m->mE4, -1);
        func_0036E220(m->m48, -1);
    }
}
static inline void Base2995D0(O2995D0* p)
{
    if (p) {
        p->vt = D_004E1220;
        func_0041F370(p, 0);
    }
}
O2995D0* func_002995D0(O2995D0* self, short del)
{
    if (self) {
        self->vt = D_004DD580;
        M2995D0_dtor(&self->m270);
        M2995D0_dtor(&self->mE0);
        Base2995D0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}