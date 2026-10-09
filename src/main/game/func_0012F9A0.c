/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern int func_0012F9C0(void);
extern int func_0012FA60(int, int);

int func_0012F9A0(void) {
    func_0012F9C0();
    return 0;
}

int func_0012F9C0(void) {
    return func_0012FA60((int)D_004FFB50, 0);
}
