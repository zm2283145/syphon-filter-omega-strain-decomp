/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA7B0[];
extern void func_00100440(int, int, int, int);
extern int func_00165270(int, int);

void func_00165250(void) {
    func_00100440((int)D_004EA7B0, (int)func_00165270, 32, 400);
}
