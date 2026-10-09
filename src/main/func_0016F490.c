/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004ED9B0[];
extern char D_004FFB50[];
extern char D_005721C8[];
extern int func_001589D0(void);
extern int func_00158A80(void);
extern int func_00164330(int);
extern int func_001644B0(int);
extern int func_003CAA50(int, int);

void func_0016F490(int a0, int a1) {
    int v1;
    int cond;

    *(int*)(char*)(a0 + 84) = a1;
    v1 = *(unsigned char*)(char*)D_005721C8;
    cond = v1 == 0;
    if (cond) goto L0016F4C0;
    v1 = *(int*)(char*)(a0 + 48);
    cond = v1 == 0;
    if (cond) goto L0016F4C0;
    v1 = *(int*)(char*)(v1 + 13700);
    cond = v1 == 0;
    if (cond) goto L0016F4C0;
    *(short*)(char*)(v1 + 48) = a1;
L0016F4C0:;
    goto ret;
ret:;
}

int func_0016F4D0(void) {
    int tmp2;
    int tmp4;

    func_001589D0();
    tmp2 = func_003CAA50((int)D_004FFB50, (int)D_004ED9B0);
    tmp4 = func_00164330(tmp2);
    return tmp4;
}

int func_0016F510(void) {
    int tmp0;
    int tmp4;

    tmp0 = func_003CAA50((int)D_004FFB50, (int)D_004ED9B0);
    func_001644B0(tmp0);
    tmp4 = func_00158A80();
    return tmp4;
}
