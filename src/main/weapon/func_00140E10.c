/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Libc_Cosf(float);
extern int Libc_Sinf(float);

int cGobjController_IsNPC(void) {
    return 0;
}

Mtx44* cMatrix_Set_ColumnMajorForm(Mtx44* m, float a, float b, float c, float d, float e, float f,
                     float g, float h, float i) {
    m->m[0][0] = a;
    m->m[0][1] = d;
    m->m[0][2] = g;
    m->m[1][0] = b;
    m->m[1][1] = e;
    m->m[1][2] = h;
    m->m[2][0] = c;
    m->m[2][1] = f;
    m->m[2][2] = i;
    m->m[0][3] = 0;
    m->m[1][3] = 0;
    m->m[2][3] = 0;
    m->m[3][0] = 0;
    m->m[3][1] = 0;
    m->m[3][2] = 0;
    m->m[3][3] = 1.0f;
    return m;
}

int SIN(float f12) {
    return Libc_Sinf(f12);
}

int COS(float f12) {
    return Libc_Cosf(f12);
}

int func_00140E90(void) {
    return 0;
}
