/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int nActivation_FindBestSectorInActivation(void* position, int cachedRegion);

/* Find the region containing position, starting from the cached region (+0x08). */
int cScene_FindBestSectorInActivation(RegionCache* self, void* position) {
    int cached;

    cached = self->region;
    return nActivation_FindBestSectorInActivation(position, cached);
}
