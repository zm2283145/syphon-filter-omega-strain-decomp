/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_0055A300[];
extern char D_0055A700[];
extern int func_004153F0(Unk415870*, void*);
extern int func_00415510(Unk415870*, void*);

/* If flag bit 2 is set, calls func_00415510 and, when byte +0x51 is set, func_004153F0. */
void func_00415870(Unk415870* self) {
    if ((self->flags & 4) != 0) {
        func_00415510(self, D_0055A300);
        if (self->unk51 != 0) {
            func_004153F0(self, D_0055A700);
        }
    }
}
