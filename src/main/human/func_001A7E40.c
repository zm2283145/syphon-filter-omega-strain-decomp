/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void* cHuman_GetLedgeAnchor_void_2(Actor* actor) {
    return actor->edgeRoot;
}

void* cHuman_GetFloorAnchor_void(Actor* actor) {
    return actor->floorRoot;
}
