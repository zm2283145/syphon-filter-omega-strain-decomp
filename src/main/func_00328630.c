/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void std_vector_deleter_Section_clear(void* rec);

void GuiSlideShow_Clear(Obj328630* self) {
    std_vector_deleter_Section_clear(self->unk48);
    self->unk58 = -1;
}
