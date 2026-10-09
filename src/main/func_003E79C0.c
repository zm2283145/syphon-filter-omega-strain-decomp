/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_003EE610(int handle, float frames);

/* Forwards a time in seconds to func_003EE610 as 30 Hz frames. */
int func_003E79C0(Word* self, float seconds) {
    func_003EE610(self->value, 30.0f * seconds);
    return 1;
}
