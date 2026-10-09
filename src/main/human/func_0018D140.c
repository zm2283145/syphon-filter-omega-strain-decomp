/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void func_001CAE10(void*);

/* Release the secondary component if flagged (bit 8 of flags324C), then clear the flag. */
void Actor_ReleaseSecondary(Actor* actor) {
    void* secondary = actor->secondary;

    if (secondary != 0 && ((actor->flags324C >> 8) & 1) != 0) {
        func_001CAE10(secondary);
        actor->flags324C &= ~0x100;
    }
}
