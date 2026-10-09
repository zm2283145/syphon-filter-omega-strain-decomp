/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char D_005381F0[];
extern int D_00538C60;
extern int func_003E7670(int*);

/* Resets the current slot record (index D_00538C60) and calls func_003E7670 on the handle. */
int func_0027A7F0(HandleHolder* self) {
    Slot110View* slot = (Slot110View*)(D_005381F0 + D_00538C60 * 272);

    slot->unk2E0 = 0;
    slot->unk2E8 = 100.0f;
    slot->unk2F6 = 1;
    slot->unk2F4 = 1;
    return func_003E7670(self->handle);
}
