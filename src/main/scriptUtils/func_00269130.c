/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Global_Randomize(void);

int Script_Randomize(void) {
    Global_Randomize();
    return 0;
}
