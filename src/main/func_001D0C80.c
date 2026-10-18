/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int UpperBody_FootRotation(int self, int a1, int a2, int a3);
extern int UpperBody_LegReach(int self, int a1, int a2, int a3);

/* Run UpperBody_LegReach with the first argument, then UpperBody_FootRotation with the second. */
int UpperBodyIk_Legs(int self, int first, int second, int a3, int t0) {
    int result;

    UpperBody_LegReach(self, first, a3, t0);
    result = UpperBody_FootRotation(self, second, a3, t0);
    return result;
}
