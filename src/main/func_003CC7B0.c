/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005436C0[];
extern int func_003CB1D0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_004080E0(void);

int func_003CC7B0(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp10;

    tmp0 = func_003CB1D0();
    tmp2 = *(int*)D_005436C0;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_004080E0();
    tmp8 = *(int*)D_005436C0;
    tmp9 = *(int*)(char*)tmp6;
    tmp10 = func_003D9400(tmp8, tmp9);
    return tmp10;
}
