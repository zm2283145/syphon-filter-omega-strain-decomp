#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void cMessage_dtor(void* m, int f); void __destroy_array(void* p, void* dtor, int size, int n);
void func_001B4D50(void); void func_001906B0(void); void func_001B4C70(void);
extern char D_004DACF0[];
extern char D_004DA930[];
extern char D_004DA440[];
extern char D_004DA350[];
extern "C" void func_001B8DF0();
void * const D_004DA830[4] = { (void*)0x0, (void*)0x0, (void*)func_001B8DF0, (void*)0x0 };
}
struct M_1B4B10 { void* vt; };
static inline void Msg_1B4B10(M_1B4B10* m) { if (m) { m->vt = D_004DA930; cMessage_dtor(m, 0); } }
static inline void B2_1B4B10(M_1B4B10* m) { if (m) m->vt = D_004DA350; }
static inline void D2_1B4B10(M_1B4B10* m) { if (m) { m->vt = D_004DA440; B2_1B4B10(m); } }
static inline void Arr_1B4B10(void* p, void* dtor, int size, int n) { if (p) __destroy_array(p, dtor, size, n); }
struct O_1B4B10 { M_1B4B10 vt; char pad4[0x10]; char a14[0xE0 - 0x14]; char aE0[0x160 - 0xE0]; M_1B4B10 m160; char pad164[0x230 - 0x164];
  M_1B4B10 m230; char pad234[0x32C - 0x234]; M_1B4B10 m32C; char pad330[0x364 - 0x330]; M_1B4B10 m364; char pad368[0x4A0 - 0x368]; char a4A0[0x380]; };
extern "C" void* func_001B4B10(O_1B4B10* self, short deleteFlag)
{
    if (self) {
        self->vt.vt = D_004DACF0;
        if (self->a4A0) Arr_1B4B10(self->a4A0, (void*)func_001B4D50, 0x1C0, 2);
        Msg_1B4B10(&self->m364);
        Msg_1B4B10(&self->m32C);
        D2_1B4B10(&self->m230);
        D2_1B4B10(&self->m160);
        __destroy_array(self->aE0, (void*)func_001906B0, 0x30, 2);
        if (self->a14) Arr_1B4B10(self->a14, (void*)func_001B4C70, 8, 0x19);
        if (self) self->vt.vt = ((char*)D_004DA830);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}