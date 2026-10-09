/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_002232C0(int, int);

int func_003D1700(Unk3D1700* self) {
    int ret = func_002232C0(0, 1);

    self->unk02 = 0;
    return ret;
}

int func_003D1730(Unk3D1700* self) {
    int ret = func_002232C0(0, 0);

    self->unk02 = 1;
    return ret;
}
