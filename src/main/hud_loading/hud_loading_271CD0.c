/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void func_00272280(int);
extern int IeNode_SetShown(int, int, int);

/* Releases all 14 slots, then calls IeNode_SetShown on the owner's handle. */
int LoadingScreen_Release(SlotTable14* self) {
    func_00272280(self->slots[0]);
    func_00272280(self->slots[1]);
    func_00272280(self->slots[2]);
    func_00272280(self->slots[3]);
    func_00272280(self->slots[4]);
    func_00272280(self->slots[5]);
    func_00272280(self->slots[6]);
    func_00272280(self->slots[7]);
    func_00272280(self->slots[8]);
    func_00272280(self->slots[9]);
    func_00272280(self->slots[10]);
    func_00272280(self->slots[11]);
    func_00272280(self->slots[12]);
    func_00272280(self->slots[13]);
    return IeNode_SetShown(*self->handle, 0, 1);
}
