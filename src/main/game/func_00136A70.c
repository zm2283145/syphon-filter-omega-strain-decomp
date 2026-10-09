/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001457C0(int, int, int);

/* Forwards (a1, a2) to func_001457C0 on the object at +0x1E0; always returns 1. */
int func_00136A70(char* self, int a1, int a2) {
    func_001457C0(*(int*)(self + 0x1E0), a1, a2);
    return 1;
}
