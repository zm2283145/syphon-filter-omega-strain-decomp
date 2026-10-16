#include "types.h"
typedef struct { char pad[0x48]; char m48[0x9C]; char mE4[4]; } M326CC0;
typedef struct { void* vt; char pad[0x44]; char m48[0x24]; char m6C[0xC]; char m78[0x18]; M326CC0 m90; } O326CC0;
extern void func_00326DA0();
extern void func_00326DB0();
extern void func_00327910();
extern void func_00327960();
extern void func_00327CF0();
extern void func_00327D90();
extern void func_00327FD0();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041D8C0();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E3B0();
extern void func_0041EF10();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void * const D_004DE710[];
extern void FileMan_Release(void* p, int f);
extern void String_Dtor(void* p, int f);
extern void func_0032A2F0(void* p, int f);
extern void func_0041F370(void* p, int f);
extern void operator_delete(void* p);
static inline void M326CC0_dtor(M326CC0* m)
{
    if (m) {
        FileMan_Release(m->mE4, -1);
        FileMan_Release(m->m48, -1);
    }
}
static inline void C326CC0(void* p) { if (p) func_0032A2F0(p, 0); }
static inline void B326CC0(void* p) { if (p) C326CC0(p); }
static inline void A326CC0(void* p) { if (p) B326CC0(p); }
O326CC0* func_00326CC0(O326CC0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004DE710);
        M326CC0_dtor(&self->m90);
        if (self->m78)
            String_Dtor(self->m78, 0);
        if (self->m6C)
            String_Dtor(self->m6C, 0);
        A326CC0(self->m48);
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DE710[24] = { (void*)0x0, (void*)0x0, (void*)func_00326CC0, (void*)func_00327FD0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00327D90, (void*)func_00327CF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00327960, (void*)func_00327910, (void*)func_0041E230, (void*)func_0041E3B0, (void*)func_0041EF10, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00326DA0, (void*)func_00326DB0, (void*)0x0 };
