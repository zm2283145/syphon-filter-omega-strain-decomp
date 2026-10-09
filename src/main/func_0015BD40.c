/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA1D0[];
extern void func_00100440(int, int, int, int);
extern int func_0015BD60(int, int);

void func_0015BD40(void) {
    func_00100440((int)D_004EA1D0, (int)func_0015BD60, 24, 16);
}
