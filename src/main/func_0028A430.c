/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int D_004FFC04;
extern int func_002CA160(int);

/* If the pending flag is set, call func_002CA160 on the global at D_004FFC04 and clear it. */
void func_0028A430(Unk28A430* self) {
    if (self->pending != 0) {
        func_002CA160(D_004FFC04);
        self->pending = 0;
    }
}
