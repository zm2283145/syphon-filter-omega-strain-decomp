/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "MovieSubtitles_types.h"

/* True while the current row is below unk64. */
int func_00412210(SubtitleBlock* b) {
    return b->unk68 < b->unk64;
}
