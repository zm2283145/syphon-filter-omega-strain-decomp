#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M326CC0;
typedef struct { void* vt; char pad[0x44]; char m48[0x24]; char m6C[0xC]; char m78[0x18]; M326CC0 m90; } O326CC0;
extern char D_004DE710[];
extern void func_0036E220(void* p, int f);
extern void func_00138B70(void* p, int f);
extern void func_0032A2F0(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
static inline void M326CC0_dtor(M326CC0* m)
{
    if (m) {
        func_0036E220(m->mE4, -1);
        func_0036E220(m->m48, -1);
    }
}
static inline void C326CC0(void* p) { if (p) func_0032A2F0(p, 0); }
static inline void B326CC0(void* p) { if (p) C326CC0(p); }
static inline void A326CC0(void* p) { if (p) B326CC0(p); }
O326CC0* func_00326CC0(O326CC0* self, short del)
{
    if (self) {
        self->vt = D_004DE710;
        M326CC0_dtor(&self->m90);
        if (self->m78)
            func_00138B70(self->m78, 0);
        if (self->m6C)
            func_00138B70(self->m6C, 0);
        A326CC0(self->m48);
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}