/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern unsigned char D_005721C8;

unsigned char func_001B8740(Actor* actor) {
    return actor->unk33A4;
}

/* Set unk33A4 and mirror it to the linked object when the global gate is on. */
void func_001B8750(Actor* actor, int value) {
    ActorLink3584* link;

    actor->unk33A4 = value;
    if (D_005721C8 != 0 && actor->unk14 != 0) {
        link = actor->unk3584;
        if (link != 0) {
            link->unk34 = value;
        }
    }
}
