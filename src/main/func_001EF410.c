/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001C50A0(int, int);
extern int func_001EF450(int);

int func_001EF410(int a0, int a1) {
    int s0, s1, v0, v1;

    s1 = a0;
    s0 = a1;
    v0 = func_001EF450(a0);
    v1 = *(unsigned char*)(char*)(s0 + 12);
    v0 = s1;
    *(char*)(char*)(s1 + 12) = v1;
    goto ret;
ret:
    return v0;
}

int func_001EF450(int a0, int a1) {
    func_001C50A0(a0, a1);
    return a0;
}
