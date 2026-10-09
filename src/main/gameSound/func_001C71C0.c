/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GObj_IdentityB(int);
extern int Global_PlayMusic(int, int);
extern int Global_PlaySnd(int, int);
extern int Global_PlaySnd_2(int, int, int);
extern int Global_StopMusic(int, int);
extern int Global_StopSnd(int, int);
extern int Sound_StopForObject(int, int, int);

int Script_StopMusic(int a0) {
    int loc[1];
    int a1, s0, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    s0 = *(int*)(char*)loc;
    a0 = *(int*)(char*)(a0 + 4);
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = v0;
    v0 = Global_StopMusic(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_PlayMusic(int a0) {
    int loc[1];
    int a1, s0, v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    s0 = *(int*)(char*)loc;
    a0 = *(int*)(char*)(a0 + 4);
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = v0;
    v0 = Global_PlayMusic(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_StopSnd(int a0) {
    int loc[1];
    int a1, a2, s0, s1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    s0 = *(signed char*)(char*)a0;
    a0 = *(int*)(char*)(a0 + 8);
    s1 = *(int*)(char*)loc;
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = s1;
    a2 = v0;
    v0 = Sound_StopForObject(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_PlaySnd(int a0) {
    int loc[1];
    int a1, a2, s0, s1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    s0 = *(signed char*)(char*)a0;
    a0 = *(int*)(char*)(a0 + 8);
    s1 = *(int*)(char*)loc;
    v0 = GObj_IdentityB(a0);
    a0 = s0;
    a1 = s1;
    a2 = v0;
    v0 = Global_PlaySnd_2(a0, a1, a2);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_StopSnd_2(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(signed char*)(char*)a0;
    v0 = Global_StopSnd(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}

int Script_PlaySnd_2(int a0) {
    int loc[1];
    int a1, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    a1 = *(int*)(char*)loc;
    a0 = *(signed char*)(char*)a0;
    v0 = Global_PlaySnd(a0, a1);
    v0 = 0;
    goto ret;
ret:
    return v0;
}
