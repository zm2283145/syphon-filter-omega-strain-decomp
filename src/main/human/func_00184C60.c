/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void func_00184C60(Actor* actor, int value) {
    ActorLink3584* link = actor->unk3584;

    if (link != 0) {
        link->unk32 = value;
    }
}
