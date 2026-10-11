#pragma cplusplus on
#include "types.h"
extern "C" { void operator_delete(void* p); void __destroy_array(void* p, void* dtor, int size, int n); void func_001B4EF0(void);
extern char D_004DAD00[]; extern char D_004DA820[]; extern char D_004DA810[]; extern char D_004DA800[]; extern char D_004DA3E0[]; extern char D_004DA380[]; extern char D_004DA330[]; }
struct M_1B4DE0 { void* vt; };
static inline void Vt2_1B4DE0(M_1B4DE0* m, char* a, char* b) { if (m) { m->vt = a; if (m) m->vt = b; } }
struct Inner_1B4DE0 { M_1B4DE0 m; char pad[0x1C]; M_1B4DE0 n; };
static inline void InnerDtor_1B4DE0(Inner_1B4DE0* p) { if (p) { Vt2_1B4DE0(&p->n, D_004DA820, D_004DA810); Vt2_1B4DE0(&p->m, D_004DA800, D_004DA810); } }
struct O_1B4DE0 { M_1B4DE0 vt; char pad4[0x9C]; M_1B4DE0 mA0; char padA4[0x3E0 - 0xA4]; char arr[0x9E0 - 0x3E0]; Inner_1B4DE0 inner; };
extern "C" void* func_001B4DE0(O_1B4DE0* self, short deleteFlag)
{
    if (self) {
        self->vt.vt = D_004DAD00;
        InnerDtor_1B4DE0(&self->inner);
        if (self->arr) __destroy_array(self->arr, (void*)func_001B4EF0, 0xA0, 9);
        Vt2_1B4DE0(&self->mA0, D_004DA3E0, D_004DA380);
        if (self) self->vt.vt = D_004DA330;
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}