#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_001D5E50(V4* q) {
    if (q->w < 0.0f) {
        asm {
            lqc2 vf1, 0(q)
            vmulax.xyzw ACC, vf0, vf0x
            vmsubw.xyzw vf1, vf1, vf0w
            sqc2 vf1, 0(q)
        }
    }
}