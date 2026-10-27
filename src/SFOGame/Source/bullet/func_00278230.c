/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFE60[];
extern void __destroy_array(void*, void*, int, int);
extern int cBullet_dtor(int, int);

/* Constructs the static array D_004FFE60: 50 elements of 0x150 bytes with cBullet_dtor. */
void func_00278230(void) {
    __destroy_array(D_004FFE60, cBullet_dtor, 336, 50);
}
