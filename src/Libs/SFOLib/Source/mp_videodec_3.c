/*
 * Libs/SFOLib/Source/mp_videodec: 2 files, 003F5D40-003F5D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F5D40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int sceMpegAddStrCallback(int, int, int, int, int);
extern int viBufEndPut(void*, int);
extern int viBufBeginPut(void*, int, int, int, int);

int videoDecEndPut(Unk3F5D40* self, int a1) {
    return viBufEndPut(self->unk48, a1);
}

int videoDecBeginPut(Unk3F5D40* self, int a1, int a2, int a3, int a4) {
    return viBufBeginPut(self->unk48, a1, a2, a3, a4);
}

int videoDecSetStream(int a0, int a1, int a2, int a3, int a4) {
    sceMpegAddStrCallback(a0, a1 & 255, a2, a3, a4);
    return 1;
}
static inline void merge_flush_func_003F5D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5D40 */

/* merge_units: begin func_003F5D80 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; char sub[0x60]; int mA8; } T5D80;
extern void sceMpegCreate(T5D80* t, int a, int b);
extern void sceMpegAddCallback(T5D80* t, int id, void* cb, int z);
extern void viBufCreate(void* sub, int a, int b, int c, int d, int e);
extern void mpegError(void);
extern void mpegNodata(void);
extern void mpegStopDMA(void);
extern void mpegRestartDMA(void);
extern void mpegTS(void);
int videoDecCreate(T5D80* t, int a, int b, int c, int d, int e, int f, int g)
{
    sceMpegCreate(t, a, b);
    sceMpegAddCallback(t, 0, (void*)mpegError, 0);
    sceMpegAddCallback(t, 1, (void*)mpegNodata, 0);
    sceMpegAddCallback(t, 2, (void*)mpegStopDMA, 0);
    sceMpegAddCallback(t, 3, (void*)mpegRestartDMA, 0);
    sceMpegAddCallback(t, 5, (void*)mpegTS, 0);
    t->mA8 = 0;
    viBufCreate(t->sub, c, d, e, f, g);
    return 1;
}
static inline void merge_flush_func_003F5D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F5D80 */
