#pragma peephole off
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
static inline void UnitMtx(void* m) {
    int t;
    asm {
        .set noreorder
        sqc2 vf0, 0x30(m)
        qmfc2.ni t, vf0
        pcpyud t, t, zero
        sq t, 0x10(m)
        pexcw t, t
        sq t, 0x20(m)
        pcpyud t, t, zero
        sq t, 0(m)
        .set reorder
    }
}

typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;

typedef struct Obj4411F0 {
    void* vtable;
    char pad04[0x44];
    int unk48;
    int unk4C;
    int unk50;
    float unk54;
    char pad58[0x8];
    Mtx mtx;
    int unkA0;
    unsigned char unkA4;
} Obj4411F0;

extern "C" {
void GuiWidget_ctor(void*);
extern void* const D_004E11A0[];
char D_004C03D8[];
void* Mem_Alloc(int pool, int size, char* file, int line);
}

extern "C" Obj4411F0* GuiWeaponDisplay_Create(void) {
    Obj4411F0* self;
    {
        AllocGuard guard;
        self = (Obj4411F0*)Mem_Alloc(0, 0xB0, D_004C03D8, 0x2A);
    }
    if (self) {
        GuiWidget_ctor(self);
        self->vtable = (void*)D_004E11A0;
        self->unk48 = -1;
        self->unk4C = 0;
        self->unk50 = 0;
        UnitMtx(&self->mtx);
        self->unkA0 = 0;
        self->unk54 = 0.0f;
        self->unkA4 = 1;
    }
    return self;
}
