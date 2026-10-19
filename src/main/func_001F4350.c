/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F3030(void);
extern int Vector_Reserve_20A790(int, int);

int Vector_Reserve_20A790_Thunk_1F4350(int a0, int a1) {
    return Vector_Reserve_20A790(a0, a1);
}

int func_001F4360(void) {
    return func_001F3030();
}
