/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_00224D80(void);

/* Transpose the upper 3x3 of a 4x4 matrix in place. */
Mtx44* Mtx_Transpose3x3(Mtx44* m) {
    float m01;
    float m10;
    float m02;
    float m20;
    float m12;
    float m21;

    m01 = m->m[0][1];
    m10 = m->m[1][0];
    m->m[0][1] = m10;
    m->m[1][0] = m01;
    m02 = m->m[0][2];
    m20 = m->m[2][0];
    m->m[0][2] = m20;
    m->m[2][0] = m02;
    m12 = m->m[1][2];
    m21 = m->m[2][1];
    m->m[1][2] = m21;
    m->m[2][1] = m12;
    return m;
}

int func_0013EE60(void) {
    return 0;
}

/* Init: owner, a value from func_00224D80 and a set flag. */
Unk0013EE70* func_0013EE70(Unk0013EE70* self, int owner) {
    int value;

    self->owner = owner;
    value = func_00224D80();
    self->value = value;
    self->valid = 1;
    return self;
}
