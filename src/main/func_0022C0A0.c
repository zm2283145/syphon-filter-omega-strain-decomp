/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC2C[];
extern int GObj_IdentityB(int);
extern int ObjMarkerMgr_Remove(int, int, int);
extern void Global_SetWaypoint(int);
extern int Global_ClearRadarBlip(int);
extern void func_00272D10(int, int);

int Script_SetWaypoint(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    Global_SetWaypoint(tmp1);
    return 0;
}

void Global_SetWaypoint(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    func_00272D10((tmp0 + 144), a0);
}

int Script_ClearRadarBlip(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    Global_ClearRadarBlip(tmp1);
    return 0;
}

int Global_ClearRadarBlip(int a0) {
    int tmp0;

    tmp0 = *(int*)D_004FFC2C;
    return ObjMarkerMgr_Remove((tmp0 + 144), (a0 + 12), 0);
}
