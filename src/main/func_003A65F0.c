/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00537F80[];
extern char D_0053BBB0[];
extern int func_0036B630(void);
extern int func_00375E50(int, int, int, int);
extern int LibInitModules(int);
extern int Overlay_Load(int);

int func_003A65F0(int a0) {
    int tmp6;

    func_0036B630();
    LibInitModules(a0);
    func_00375E50((int)D_00537F80, 13312, 1075200, 204800);
    tmp6 = Overlay_Load(1);
    return tmp6;
}

int func_003A6650(int a0) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)D_0053BBB0;
    *(char*)D_0053BBB0 = a0;
    return tmp0;
}

int func_003A6670(int a0) {
    return Overlay_Load(a0);
}
