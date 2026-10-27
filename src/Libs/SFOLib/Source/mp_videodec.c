/*
 * Libs/SFOLib/Source/mp_videodec: 2 files, 003F56D0-003F5720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F56D0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { long a; long b; long unk10; } Pair64; /* 24 bytes; only a and b are used here */
typedef struct { char pad[8]; long a; long b; } Pair64Out;

extern char D_0055C4C8[];
extern void func_003F45C0(void* src, Pair64* out);

/* Fetches a 24-byte record and copies its first 16 bytes from D_0055C4C8 into out+8; returns 1. */
int mpegTS(void* self, Pair64Out* out)
{
    Pair64 tmp;
    func_003F45C0(D_0055C4C8, &tmp);
    out->a = tmp.a;
    out->b = tmp.b;
    return 1;
}
static inline void merge_flush_func_003F56D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F56D0 */

/* merge_units: begin func_003F5720 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

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
static inline void merge_flush_func_003F5720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5720 */
