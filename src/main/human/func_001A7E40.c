/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void* Actor_GetEdgeRoot(Actor* actor) {
    return actor->edgeRoot;
}

void* Actor_GetFloorRoot(Actor* actor) {
    return actor->floorRoot;
}
