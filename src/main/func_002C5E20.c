/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Rec1C copy (assignment). */
Rec1C* func_002C5E20(Rec1C* dst, Rec1C* src) {
    Q q;
    int unk10;
    int unk14;
    int unk18;

    q = src->q;
    dst->q = q;
    unk10 = src->unk10;
    dst->unk10 = unk10;
    unk14 = src->unk14;
    dst->unk14 = unk14;
    unk18 = src->unk18;
    dst->unk18 = unk18;
    return dst;
}
