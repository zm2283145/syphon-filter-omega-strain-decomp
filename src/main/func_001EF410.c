/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001EF450(int);

int func_001EF410(int a0, int a1) {
    unsigned char tmp2;

    func_001EF450(a0);
    tmp2 = *(unsigned char*)((char*)a1 + 12);
    *(char*)((char*)a0 + 12) = tmp2;
    return a0;
}
