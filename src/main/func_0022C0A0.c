/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern void func_0022C0D0(int);
extern int func_0022C120(int);
extern void func_00272D10(int, int);
extern int ObjMarkerMgr_Remove(int, int, int);
extern int GObj_IdentityB(int);

int func_0022C0A0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    func_0022C0D0(tmp1);
    return 0;
}

void func_0022C0D0(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    func_00272D10((tmp0 + 144), a0);
}

int func_0022C0F0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    func_0022C120(tmp1);
    return 0;
}

int func_0022C120(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return ObjMarkerMgr_Remove((tmp0 + 144), (a0 + 12), 0);
}
