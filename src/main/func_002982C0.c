/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048B7A0[];
extern char D_0048B7A4[];
extern char D_0048B7A8[];
extern char D_0048B7C8[];
extern char D_0048B7E8[];
extern char D_0048B808[];
extern char D_0048B828[];
extern char D_0048B848[];
extern void func_00298310(void);

void func_002982C0(int a0) {
    func_00298310();
    *(int*)((char*)a0 + 460) = -1;
    *(int*)((char*)a0 + 720) = 0;
    *(int*)((char*)a0 + 724) = 0;
    *(int*)((char*)a0 + 728) = 0;
    *(int*)((char*)a0 + 732) = 0;
    *(int*)((char*)a0 + 736) = 0;
    *(int*)((char*)a0 + 740) = 0;
}

void func_00298310(void) {
    *(char*)D_0048B7A0 = 0;
    *(char*)D_0048B7A8 = 0;
    *(int*)D_0048B7A4 = -1;
    *(char*)D_0048B7C8 = 0;
    *(char*)D_0048B7E8 = 0;
    *(char*)D_0048B808 = 0;
    *(char*)D_0048B828 = 0;
    *(char*)D_0048B848 = 0;
}
