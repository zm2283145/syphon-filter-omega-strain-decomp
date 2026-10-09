/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Rec22 copy (assignment). */
Rec22* func_002C5EE0(Rec22* dst, Rec22* src) {
    Q q;
    float unk10;
    float unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char unk21;

    q = src->q;
    dst->q = q;
    unk10 = src->unk10;
    dst->unk10 = unk10;
    unk14 = src->unk14;
    dst->unk14 = unk14;
    unk18 = src->unk18;
    dst->unk18 = unk18;
    unk1C = src->unk1C;
    dst->unk1C = unk1C;
    unk20 = src->unk20;
    dst->unk20 = unk20;
    unk21 = src->unk21;
    dst->unk21 = unk21;
    return dst;
}
