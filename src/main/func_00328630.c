/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void func_0032A280(void* rec);

void GuiSlideShow_Clear(Obj328630* self) {
    func_0032A280(self->unk48);
    self->unk58 = -1;
}
