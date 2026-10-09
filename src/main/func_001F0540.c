/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DFC10;
extern Vec4* Vec4_Assign(Vec4*, Vec4*);
extern int func_003B2950(Unk1F0540*, int, int, int, int);

Unk1F0540* func_001F0540(Unk1F0540* self, int a1, int a2, Vec4* a3, int t0, float f12, float f13) {
    func_003B2950(self, 1, a2, 0, t0);
    self->vtable = &D_004DFC10;
    self->unk50 = a1;
    self->unk54 = f12;
    self->unk58 = f13;
    Vec4_Assign(&self->unk60, a3);
    return self;
}
