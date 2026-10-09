/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001D0CF0(int self, int a1, int a2, int a3);
extern int func_001D1140(int self, int a1, int a2, int a3);

/* Run func_001D1140 with the first argument, then func_001D0CF0 with the second. */
int func_001D0C80(int self, int first, int second, int a3, int t0) {
    int result;

    func_001D1140(self, first, a3, t0);
    result = func_001D0CF0(self, second, a3, t0);
    return result;
}
