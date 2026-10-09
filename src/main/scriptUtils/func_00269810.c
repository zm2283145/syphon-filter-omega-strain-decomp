/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F83F8[];
extern char D_00555070[];
extern int ScriptFilter_Dispatch(int, int, int);
extern int func_00269830(void);

void* func_00269810(void* self) {
    return self;
}

int func_00269820(void) {
    return func_00269830();
}

int func_00269830(void) {
    return (int)D_004F83F8;
}

int cNodeList_v0B(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_00269830();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}

int cNodeList_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}
