#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); extern char D_004DA410[]; extern char D_004DA3B0[]; extern char D_004DA440[]; extern char D_004DA350[]; }
struct M_1B4D50 { void* vt; };
static inline void B1_1B4D50(M_1B4D50* m) { if (m) m->vt = D_004DA3B0; }
static inline void D1_1B4D50(M_1B4D50* m) { if (m) { m->vt = D_004DA410; B1_1B4D50(m); } }
static inline void B2_1B4D50(M_1B4D50* m) { if (m) m->vt = D_004DA350; }
static inline void D2_1B4D50(M_1B4D50* m) { if (m) { m->vt = D_004DA440; B2_1B4D50(m); } }
struct O_1B4D50 { char pad[0x30]; M_1B4D50 a; char pad34[0x100 - 0x34]; M_1B4D50 b; };
extern "C" void* func_001B4D50(O_1B4D50* self, short deleteFlag)
{
    if (self) {
        D1_1B4D50(&self->b);
        D2_1B4D50(&self->a);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}