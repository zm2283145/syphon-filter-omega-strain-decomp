/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sceMpegDemuxPssRing(int, int, int, int, int);

int sceMpegDemuxPss(int a0, int a1, int a2) {
    int tmp0;

    tmp0 = sceMpegDemuxPssRing(a0, a1, a2, 0, -1);
    return tmp0;
}
