/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFE60[];
extern void func_00100440(int, int, int, int);
extern int func_00278250(int, int);

void func_00278230(void) {
    func_00100440((int)D_004FFE60, (int)func_00278250, 336, 50);
}
