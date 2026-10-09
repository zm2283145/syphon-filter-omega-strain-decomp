/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_00369870(void*);

/* Constructor: builds the sub-object at +0x80 and clears the remaining state. */
Obj36D630* func_0036D630(Obj36D630* self) {
    func_00369870(self->unk80);
    self->unk148 = 0;
    self->unk158 = 0;
    self->unk15C = 0;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk14C = 0;
    return self;
}
