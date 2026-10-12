#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x30]; V4 v30; } C44_O;
extern unsigned char D_00535D62;
static inline unsigned char eq4_(V4* a, V4* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
#pragma push
#pragma bool off



void Light_SetPosition(C44_O* o, V4* v) {
    if ((eq4_(&o->v30, v) != 0) ^ 1) {
        { V4* d = &o->v30; VCopyF(d, v); }
        D_00535D62 = 1;
    }
}
#pragma pop