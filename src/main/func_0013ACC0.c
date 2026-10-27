/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern void* D_004EA0B8; /* LOS collision provider (research LOS_QUERY_NATIVE.md) */

void* cLosRequest_cCollisionModelList_Game_GetCollisionModelList(void) {
    void* provider;

    provider = D_004EA0B8;
    return provider;
}
