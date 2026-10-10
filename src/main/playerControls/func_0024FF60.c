#include "types.h"

typedef struct { float m[16]; } Mtx16;

/* Builds a 4x4 matrix from 16 floats; returns it. */
Mtx16* func_0024FF60(Mtx16* out, float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7,
                     float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
{
    out->m[0] = m0;
    out->m[1] = m1;
    out->m[2] = m2;
    out->m[3] = m3;
    out->m[4] = m4;
    out->m[5] = m5;
    out->m[6] = m6;
    out->m[7] = m7;
    out->m[8] = m8;
    out->m[9] = m9;
    out->m[10] = m10;
    out->m[11] = m11;
    out->m[12] = m12;
    out->m[13] = m13;
    out->m[14] = m14;
    out->m[15] = m15;
    return out;
}
