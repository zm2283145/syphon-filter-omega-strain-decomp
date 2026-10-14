/*
 * main/GuiEquipmentModify: 3 files, 002C38A0-002C3960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C38A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_backward_assign.h"

/* Copy a range of 60-byte elements backward by assignment. */
DEFINE_COPY_BACKWARD_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_BACKWARD_ASSIGN(func_002C38A0, Elem60, func_001BECC0)
#pragma pop /* merge_units */
/* merge_units: end func_002C38A0 */

/* merge_units: begin func_002C3910 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

extern AnimChannel* AnimChannelBase_CopyCtor(AnimChannel* self, AnimChannel* src);
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel copy constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_CopyCtor_2C3910(AnimChannel* self, AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->base.vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C3910 */

/* merge_units: begin func_002C3960 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
extern int D_004DA380;

int func_002C3960(int arg0, int arg1) {
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
/* merge_units: end func_002C3960 */
