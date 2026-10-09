/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int LosRegion_FindLocal(void* position, int cachedRegion);

/* Find the region containing position, starting from the cached region (+0x08). */
int func_0013E1A0(RegionCache* self, void* position) {
    int cached;

    cached = self->region;
    return LosRegion_FindLocal(position, cached);
}
