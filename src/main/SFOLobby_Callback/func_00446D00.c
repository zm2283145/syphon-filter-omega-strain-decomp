/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00585E60[];
extern int String_Copy(int, int);
extern int func_004505C0(void);

int func_00446D00(int a0, int a1, int a2, int a3) {
    int s0, v0, v1;
    int cond;

    s0 = a3;
    v0 = func_004505C0();
    cond = v0 != 0;
    if (cond) goto L00446D48;
    a0 = 0 + 1;
    v1 = *(int*)(char*)D_00585E60;
    *(int*)(char*)(v1 + 516) = a0;
    v1 = *(int*)(char*)(s0 + 44);
    cond = v1 != 0;
    if (cond) goto L00446D48;
    a1 = s0 + 21;
    v0 = *(int*)(char*)D_00585E60;
    a0 = v0 + 9257;
    v0 = String_Copy(a0, a1);
L00446D48:;
    goto ret;
ret:
    return v0;
}
