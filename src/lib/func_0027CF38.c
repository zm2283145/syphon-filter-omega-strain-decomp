/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504080[];
extern char D_005040C0[];
extern int func_0027C3D0(void);
extern int func_0027D3A8(int, int, int);

int func_0027CF38(void) {
    int tmp2;

    func_0027C3D0();
    tmp2 = func_0027D3A8((int)D_00504080, (int)D_005040C0, 100);
    return tmp2;
}
