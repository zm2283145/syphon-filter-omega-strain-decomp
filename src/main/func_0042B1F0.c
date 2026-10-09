/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00494178[];
extern char D_00494180[];
extern char D_00494198[];
extern char D_00497540[];
extern char D_005721A8[];
extern char D_005721B8[];
extern char D_005721C0[];
extern char D_005721D0[];
extern char D_005721D8[];
extern char D_005723B8[];
extern char D_005723F0[];
extern char D_005723F8[];
extern char D_00572400[];
extern char D_00572408[];
extern char D_00572410[];
extern char D_00572418[];
extern char D_00572419[];
extern char D_0057241A[];
extern char D_0057241B[];
extern char D_00572428[];
extern char D_0057242C[];
extern char D_00572430[];
extern char D_00572468[];
extern void Net_ResetSession(void);
extern int func_002EC340(void);
extern int func_002EC6A0(int);
extern int func_002EC738(int);
extern int func_00437BF0(void);

void func_0042B1F0(void) {
    *(char*)D_00497540 = 1;
    func_00437BF0();
    func_002EC6A0(0);
    func_002EC738(0);
    Net_ResetSession();
}

void Net_ResetSession(void) {
    *(char*)D_005721D8 = 0;
    *(char*)D_005723B8 = 0;
    *(int*)D_005721A8 = -1;
    *(int*)D_00494180 = 4;
    *(int*)D_00494178 = -1;
    *(int*)D_00494198 = -1;
    *(char*)D_005721C0 = 0;
    *(char*)D_00572410 = 0;
    *(int*)D_005723F0 = 0;
    *(char*)D_00572418 = 0;
    *(char*)D_00572419 = 0;
    *(char*)D_0057241A = 0;
    *(char*)D_0057241B = 0;
    *(char*)D_00572468 = 0;
    *(int*)D_00572428 = 0;
    *(int*)D_0057242C = 0;
    *(int*)D_00572430 = 0;
}

int func_0042B2D0(void) {
    int tmp0;

    *(char*)D_005721D0 = 0;
    *(char*)D_005723F8 = 0;
    *(char*)D_00572408 = 1;
    *(char*)D_00572400 = 0;
    *(char*)D_00497540 = 0;
    tmp0 = func_002EC340();
    *(char*)D_005721B8 = 1;
    return tmp0;
}
