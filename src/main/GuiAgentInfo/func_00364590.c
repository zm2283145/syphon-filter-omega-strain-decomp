#pragma cplusplus on
#include "types.h"
#include "vc_copy.h"
struct V3 { float x, y, z; V3() {} V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" char D_004DF530[];
extern "C" void GuiWidget_ctor(S364590* self);
extern "C" S364590* func_00364590(S364590* self) {
    V3 t;
    float z;
    GuiWidget_ctor(self);
    self->vtable = D_004DF530;
    t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
    VCopyF(&self->v80, &t);
    z = 0.0f;
    self->unk48 = 0;
    self->f4E0 = z;
    return self;
}
