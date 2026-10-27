/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "map_types.h"

void cMap_StartSeekCountdown(MapView* self) {
    self->unk94 = 0.25f;
}
