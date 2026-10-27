/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int cInterfaceModel_NextFrame(int handle, float frames);

/* Forwards a time in seconds to cInterfaceModel_NextFrame as 30 Hz frames. */
int cInterface_NextFrame(Word* self, float seconds) {
    cInterfaceModel_NextFrame(self->value, 30.0f * seconds);
    return 1;
}
