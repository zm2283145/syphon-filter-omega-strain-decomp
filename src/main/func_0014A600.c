/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004EA3D0[];
extern char D_004EA3F8[];
extern int func_0016AD70(void);
extern int func_00210CB0(void);
extern int func_003D9400(int, int);
extern void func_003D9440(int, int);
extern int func_004080E0(void);

int func_0014A600(void) {
    int tmp0;
    int tmp2;
    int tmp3;
    int tmp6;
    int tmp8;
    int tmp9;
    int tmp12;
    int tmp13;
    int tmp16;
    int tmp18;
    int tmp19;
    int tmp20;

    tmp0 = func_0016AD70();
    tmp2 = *(int*)D_004EA3F8;
    tmp3 = *(int*)(char*)tmp0;
    func_003D9440(tmp2, tmp3);
    tmp6 = func_00210CB0();
    tmp8 = *(int*)D_004EA3F8;
    tmp9 = *(int*)(char*)tmp6;
    func_003D9400(tmp8, tmp9);
    tmp12 = *(int*)D_004EA3F8;
    tmp13 = *(int*)D_004EA3D0;
    func_003D9400(tmp12, tmp13);
    tmp16 = func_004080E0();
    tmp18 = *(int*)D_004EA3F8;
    tmp19 = *(int*)(char*)tmp16;
    tmp20 = func_003D9400(tmp18, tmp19);
    return tmp20;
}
