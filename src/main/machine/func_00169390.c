/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC04[];
extern char D_005721C8[];
extern int NetMsgThrottle_SendMsg(void);
extern void func_002CA580(int);
extern int func_004294C0(void);
extern int func_00429D30(void);

void func_00169390(void) {
    int a0, v0, v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005721C8;
    cond = v1 == 0;
    if (cond) goto L001693B8;
    v0 = NetMsgThrottle_SendMsg();
    v0 = func_00429D30();
L001693B8:;
    v1 = *(int*)(char*)D_004FFC04;
    cond = v1 == 0;
    if (cond) goto L001693E0;
    v0 = func_004294C0();
    cond = v0 == 0;
    if (cond) goto L001693E0;
    a0 = *(int*)(char*)D_004FFC04;
    func_002CA580(a0);
L001693E0:;
    goto ret;
ret:;
}
