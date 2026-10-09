/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_0010A6E0(int, int, int, int, int);
extern int func_003F5350(void*, int);
extern int func_003F53B0(void*, int, int, int, int);

int func_003F5D40(Unk3F5D40* self, int a1) {
    return func_003F5350(self->unk48, a1);
}

int func_003F5D50(Unk3F5D40* self, int a1, int a2, int a3, int a4) {
    return func_003F53B0(self->unk48, a1, a2, a3, a4);
}

int func_003F5D60(int a0, int a1, int a2, int a3, int a4) {
    func_0010A6E0(a0, a1 & 255, a2, a3, a4);
    return 1;
}
