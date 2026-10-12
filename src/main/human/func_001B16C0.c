/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

int Actor_IsArmed(Actor* actor) {
    return actor->unk3524->state != 6;
}
