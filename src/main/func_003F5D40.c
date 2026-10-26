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
