/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int IeNode_Update(int handle, float frames);

/* Forwards a time in seconds to IeNode_Update as 30 Hz frames. */
int IeScreen_Update(Word* self, float seconds) {
    IeNode_Update(self->value, 30.0f * seconds);
    return 1;
}
