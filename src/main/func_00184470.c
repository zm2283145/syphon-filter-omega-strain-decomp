/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* True when the type byte at +0x24 is 3. */
int cMoveMsg_Template_HasDeltaPosition(Unk00184470* self) {
    return self->type == 3;
}
