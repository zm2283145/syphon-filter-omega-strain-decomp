/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_00282020(void*);

void cBeamMsg_v04(PtrMsg* self) {
    func_00282020(self->who);
}
