#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "v4_asm_copy.h"
struct V3 { float x, y, z; } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" {
char D_004DF530[];
char D_004BBB00[];
void GuiWidget_ctor(S364590* self);
void* Mem_Alloc(int pool, int size, char* file, int line);
}
#pragma opt_propagation off
extern "C" S364590* func_003678E0(void) {
    S364590* p;
    {
        AllocGuard guard;
        p = (S364590*)Mem_Alloc(0, 0x4F0, D_004BBB00, 0x2A);
    }
    if (p) {
        V3 t;
        float z;
        __int128 q;
        V3* d;
        GuiWidget_ctor(p);
        p->vtable = D_004DF530;
        t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
        d = &p->v80;
        q = V4Load(&t);
        asm { mtc1 zero, z }
        V4Store(d, q);
        p->unk48 = 0;
        p->f4E0 = z;
    }
    return p;
}

