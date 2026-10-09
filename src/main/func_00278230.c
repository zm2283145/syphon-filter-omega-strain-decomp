/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFE60[];
extern void func_00100440(void*, void*, int, int);
extern int func_00278250(int, int);

/* Constructs the static array D_004FFE60: 50 elements of 0x150 bytes with func_00278250. */
void func_00278230(void) {
    func_00100440(D_004FFE60, func_00278250, 336, 50);
}
