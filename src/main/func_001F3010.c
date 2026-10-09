/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3030(void);
extern int func_0020C2A0(int, int);

int func_001F3010(int a0, int a1) {
    return func_0020C2A0(a0, a1);
}

int func_001F3020(void) {
    return func_001F3030();
}
