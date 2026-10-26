/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int sce_sync(int);

int sceNetcnfifCheck(void) {
    return sce_sync(1);
}
