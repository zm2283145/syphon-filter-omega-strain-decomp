/*
 * main/GuiNetMessages: 4 files, 00346180-003462A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346180 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3C]; } G3E_00346180;
extern void func_001BECC0(G3E_00346180* p, int x);
void func_00346180(G3E_00346180* p, int n, int x) {
    for (; n != 0; n--) {
        func_001BECC0(p, x);
        p++;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00346180 */

/* merge_units: begin func_003461E0 */
#pragma push /* merge_units */
typedef struct Rec3C {
    char b[0x3C];
} Rec3C;

#if 0 /* merge_units */
extern void func_001BECC0(Rec3C*, Rec3C*);
#endif /* merge_units */
#define func_001BECC0(a0, a1) (func_001BECC0((G3E_00346180 *)(a0), (int)(a1))) /* merge_units */


/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec3C* func_003461E0(Rec3C* first, Rec3C* last, Rec3C* destEnd) {
    while (last > first) {
        Rec3C* src = --last;
        Rec3C* dst = --destEnd;
        func_001BECC0(dst, src);
    }
    return destEnd;
}
#undef func_001BECC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003461E0 */

/* merge_units: begin func_00346250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int AnimChannelBase_CopyCtor(L3AnimChannel* self, L3AnimChannel* src);
extern char D_004DA840[];       /* AnimChannel vtable */

/* AnimChannel copy constructor. */
L3AnimChannel* func_00346250(L3AnimChannel* self, L3AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00346250 */

/* merge_units: begin func_003462A0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int func_003462A0(int arg0, int arg1) {
    int temp_a2;
    int var_v1;

    temp_a2 = arg0 + 0x18;
    var_v1 = temp_a2;
    F_(arg0, 0x0, int) = (int)(&D_004DA380);
    F_(arg0, 0x4, float) = F_(arg1, 0x4, float);
    F_(arg0, 0x8, float) = F_(arg1, 0x8, float);
    F_(arg0, 0xC, float) = F_(arg1, 0xC, float);
    F_(arg0, 0x10, float) = F_(arg1, 0x10, float);
    F_(arg0, 0x14, float) = F_(arg1, 0x14, float);
    do {
        var_v1 += 8;
    } while (var_v1 != (temp_a2 + 0x10));
    F_(temp_a2, 0x0, float) = F_(arg1, 0x18, float);
    F_(temp_a2, 0x4, float) = F_(arg1, 0x1C, float);
    F_(temp_a2, 0x8, float) = F_(arg1, 0x20, float);
    F_(temp_a2, 0xC, float) = F_(arg1, 0x24, float);
    F_(temp_a2, 0x10, float) = F_(arg1, 0x28, float);
    F_(temp_a2, 0x14, float) = F_(arg1, 0x2C, float);
    F_(arg0, 0x30, int) = (int ) (arg0 + 0x18);
    F_(arg0, 0x34, int) = 0;
    return arg0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003462A0 */
