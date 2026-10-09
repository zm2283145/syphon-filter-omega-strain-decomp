/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between DME.cc (ends 0x0042ACD0) and nellymoser_wrapper.c; network session state.
 */

#include "types.h"

extern int D_00494178;
extern int D_00494180;
extern int D_00494198;
extern char D_00497540;
extern int D_005721A8;
extern char D_005721B8;
extern char D_005721C0;
extern char D_005721D0;
extern char D_005721D8;
extern char D_005723B8;
extern int D_005723F0;
extern char D_005723F8;
extern char D_00572400;
extern char D_00572408;
extern char D_00572410;
extern char D_00572418;
extern char D_00572419;
extern char D_0057241A;
extern char D_0057241B;
extern int D_00572428;
extern int D_0057242C;
extern int D_00572430;
extern char D_00572468;
extern void Net_ResetSession(void);
extern int func_002EC340(void);
extern int func_002EC6A0(int);
extern int func_002EC738(int);
extern int func_00437BF0(void);

void func_0042B1F0(void) {
    D_00497540 = 1;
    func_00437BF0();
    func_002EC6A0(0);
    func_002EC738(0);
    Net_ResetSession();
}

/* Clears the session flags and ids back to their defaults. */
void Net_ResetSession(void) {
    D_005721D8 = 0;
    D_005723B8 = 0;
    D_005721A8 = -1;
    D_00494180 = 4;
    D_00494178 = -1;
    D_00494198 = -1;
    D_005721C0 = 0;
    D_00572410 = 0;
    D_005723F0 = 0;
    D_00572418 = 0;
    D_00572419 = 0;
    D_0057241A = 0;
    D_0057241B = 0;
    D_00572468 = 0;
    D_00572428 = 0;
    D_0057242C = 0;
    D_00572430 = 0;
}

int func_0042B2D0(void) {
    int ret;

    D_005721D0 = 0;
    D_005723F8 = 0;
    D_00572408 = 1;
    D_00572400 = 0;
    D_00497540 = 0;
    ret = func_002EC340();
    D_005721B8 = 1;
    return ret;
}
