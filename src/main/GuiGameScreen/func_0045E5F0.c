/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int Global_ClearInteract(int);
extern void Global_DisplayInteract(int, int);
extern int Global_DisplayInteract_2(int, int, int);
extern void func_0045EC60(void);

int Script_ClearInteract_2(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = GObj_IdentityB(tmp0);
    Global_ClearInteract(tmp1);
    return 0;
}

int Script_ClearInteract(void) {
    func_0045EC60();
    return 0;
}

int Script_DisplayInteract_4(int a0) {
    int loc[1];
    int a1, a2, s0, v0;

    s0 = *(unsigned char*)(char*)(a0 + 8);
    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = s0;
    v0 = Global_DisplayInteract_2(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_DisplayInteract_3(int a0) {
    int loc[1];
    int a1, a2, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)a0;
    v0 = GObj_IdentityB(a0);
    a1 = *(int*)(char*)loc;
    a0 = v0;
    a2 = 0 + 1;
    v0 = Global_DisplayInteract_2(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_DisplayInteract_2(int a0) {
    int loc[1];
    int a1, v0;

    a1 = *(unsigned char*)(char*)(a0 + 4);
    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    Global_DisplayInteract(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_DisplayInteract(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    a1 = 0 + 1;
    Global_DisplayInteract(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
