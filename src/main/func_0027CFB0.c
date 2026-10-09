/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504080[];
extern char D_005040C0[];
extern int func_0027C3D0(void);
extern int func_0027D3A8(void*, void*, int);

int func_0027CFB0(void) {
    func_0027C3D0();
    return func_0027D3A8(D_00504080, D_005040C0, 102);
}
