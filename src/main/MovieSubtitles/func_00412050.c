/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

/* Resets the block to its default state. */
void func_00412050(SubtitleBlock* b) {
    b->base = 0;
    b->unk90 = 0;
    b->unk6C = 0;
    b->unk64 = 0;
    b->unk94 = 0;
    b->unk70 = 0;
    b->unk68 = 0;
    b->unk98 = 0;
    b->unk74 = 0;
    b->color.x = 1.0f;
    b->color.y = 1.0f;
    b->color.z = 1.0f;
    b->color.w = 1.0f;
    b->unk9C = 0x749dc5ae;
    b->unkA0 = -1.0f;
    b->unkA4 = 3;
    b->unkA8 = 1;
    b->unkAC = 0;
}
