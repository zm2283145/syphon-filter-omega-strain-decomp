/*
 * SFOGame/Source/GuiWeaponDisplay: 1 file, 004411F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004411F0 */
#pragma push /* merge_units */
#pragma peephole off
#pragma cplusplus on
#include "types.h"
/* VU0 identity-matrix store (vf0/qmfc2/pexcw): no C equivalent. gcc-style asm
   (not asm{}) so the trailing stores schedule like retail. */
static inline void UnitMtx(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

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
}
extern "C" Obj4411F0* GuiWeaponDisplay_ctor(Obj4411F0* self) {
    GuiWidget_ctor(self);
    self->vtable = (void*)D_004E11A0;
    self->unk48 = -1;
    self->unk4C = 0;
    self->unk50 = 0;
    UnitMtx(&self->mtx);
    self->unkA0 = 0;
    self->unk54 = 0.0f;
    self->unkA4 = 1;
    return self;
}
static inline void merge_flush_func_004411F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004411F0 */
