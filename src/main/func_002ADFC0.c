/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DDC20[];
extern int func_0033F480(int);

int func_002ADFC0(int a0) {
    func_0033F480(a0);
    *(int*)((char*)a0) = (int)D_004DDC20;
    *(int*)((char*)a0 + 132) = 4;
    *(int*)((char*)a0 + 352) = 0;
    *(int*)((char*)a0 + 356) = 0;
    return a0;
}
