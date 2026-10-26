/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_0055C4C8[];
extern int printf(void*, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int viBufRestartDMA(void*);
extern int viBufStopDMA(void*);
extern int viBufAddDMA(void*);
extern void cMoviePlayer_SwitchThread(void);

int mpegRestartDMA(void) {
    viBufRestartDMA(D_0055C4C8);
    return 1;
}

int mpegStopDMA(void) {
    viBufStopDMA(D_0055C4C8);
    return 1;
}

int mpegNodata(void) {
    cMoviePlayer_SwitchThread();
    viBufAddDMA(D_0055C4C8);
    return 1;
}

/* Forwards its arguments to printf, replacing the first two with "%s\n" and the second word of *a1. */
int mpegError(int a0, int* a1, int a2, int a3, int a4, int a5, int a6, int a7, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7) {
    printf("%s\n", a1[1], a2, a3, a4, a5, a6, a7, f0, f1, f2, f3, f4, f5, f6, f7);
    return 1;
}
