/*
 * main/GuiAgentInfo: 4 files, 00366E50-00366F70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00366E50 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char b[0x3C]; } E366;
extern void func_001BECC0(E366* d, void* s);
void func_00366E50(E366* d, int n, void* s)
{
    while (n != 0) {
        func_001BECC0(d, s);
        n--;
        d++;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00366E50 */

/* merge_units: begin func_00366EB0 */
#pragma push /* merge_units */
typedef struct Rec3C {
    char b[0x3C];
} Rec3C;

#if 0 /* merge_units */
extern void func_001BECC0(Rec3C*, Rec3C*);
#endif /* merge_units */
#define func_001BECC0(a0, a1) (func_001BECC0((E366 *)(a0), (void *)(a1))) /* merge_units */


/* Copies [first, last) backwards ending at destEnd; returns the new destination begin. */
Rec3C* func_00366EB0(Rec3C* first, Rec3C* last, Rec3C* destEnd) {
    while (last > first) {
        Rec3C* src = --last;
        Rec3C* dst = --destEnd;
        func_001BECC0(dst, src);
    }
    return destEnd;
}
#undef func_001BECC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00366EB0 */

/* merge_units: begin func_00366F20 */
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
L3AnimChannel* func_00366F20(L3AnimChannel* self, L3AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00366F20 */

/* merge_units: begin func_00366F70 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int func_00366F70(int arg0, int arg1) {
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
/* merge_units: end func_00366F70 */
