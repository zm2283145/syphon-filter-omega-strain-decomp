/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005061D0[];
extern int GObj_IdentityB(int);
extern int Global_SpawnParticle(int, int, int);
extern int Global_Shatter(int, int, int);
extern void func_00282020(int);
extern int func_00282160(int);

int func_00230CE0(int a0) {
    int tmp2;
    signed char tmp3;
    signed char tmp4;
    int tmp5;
    int tmp6;

    func_00282160((a0 + 36));
    tmp2 = *(int*)D_005061D0;
    tmp3 = *(signed char*)(char*)tmp2;
    *(int*)D_005061D0 = (tmp2 + 1);
    *(char*)((char*)a0 + 40) = tmp3;
    tmp4 = *(signed char*)((char*)a0 + 40);
    tmp5 = *(int*)((char*)a0 + 36);
    tmp6 = Global_SpawnParticle(tmp4, tmp5, 0);
    return tmp6;
}

void cNetSpawnParticleMsg_v04(int a0) {
    int tmp0;
    signed char tmp3;
    int tmp4;
    int tmp5;

    tmp0 = *(int*)((char*)a0 + 36);
    func_00282020(tmp0);
    tmp3 = *(signed char*)((char*)a0 + 40);
    tmp4 = *(int*)D_005061D0;
    *(char*)((char*)tmp4) = tmp3;
    tmp5 = *(int*)D_005061D0;
    *(int*)D_005061D0 = (tmp5 + 1);
}

int Script_Shatter(int a0) {
    int a1, a2, s0, v0;

    s0 = a0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a0 = *(int*)(char*)(s0 + 4);
    s0 = v0;
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = v0;
    a2 = 0;
    v0 = Global_Shatter(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
