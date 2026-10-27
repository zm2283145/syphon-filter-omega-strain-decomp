#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_1AF720;
typedef struct { unsigned char enable; unsigned char mode; char p2[2]; float radius; char p8[8]; V4_1AF720 centre; } S_1AF720;
extern signed char D_004E1D88;
extern float D_004E1D90;
extern float D_004E1D94;
extern float D_004E1D98;
extern float D_004E1D9C;
void cBone_SkeletonBBoxContribution_Clear(S_1AF720* s) {
    if (s != 0) {
        float z;
        V4_1AF720* d; V4_1AF720* p;
        s->enable = 0;
        s->mode = 1;
        *(int*)&s->radius = 0;
        z = 0.0f;
        if (!D_004E1D88) {
            D_004E1D88 = 1;
            D_004E1D90 = z;
            D_004E1D94 = z;
            D_004E1D98 = z;
            D_004E1D9C = z;
        }
        p = (V4_1AF720*)&D_004E1D90; d = &s->centre;
        VCopyF(d, p);
    }
}