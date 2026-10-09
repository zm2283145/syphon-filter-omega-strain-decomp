/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Reset the timer from the definition's +0x40 value. */
void func_001CF520(TimedRef* self) {
    self->timer = self->def->unk40;
}
