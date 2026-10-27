/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiEquipmentSetup.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiEquipmentSetup_types.h"

float func_002A5EF0(char* self) {
    return *(float*)(self + 4);
}

Float6* func_002A5F00(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
