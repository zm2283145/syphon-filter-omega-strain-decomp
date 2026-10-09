/*
 * Matched functions (byte-identical with the retail executable).
 * Obj370000 virtual (vtable D_004DF6A0 slot 12).
 */

#include "loose03_types.h"

/* Copy a 3x4 matrix into self->mtx (xyz of each row first, then the w column). */
void func_00370000(Obj370000* self, Mtx34* src) {
    self->mtx.m[0][0] = src->m[0][0];
    self->mtx.m[0][1] = src->m[0][1];
    self->mtx.m[0][2] = src->m[0][2];
    self->mtx.m[1][0] = src->m[1][0];
    self->mtx.m[1][1] = src->m[1][1];
    self->mtx.m[1][2] = src->m[1][2];
    self->mtx.m[2][0] = src->m[2][0];
    self->mtx.m[2][1] = src->m[2][1];
    self->mtx.m[2][2] = src->m[2][2];
    self->mtx.m[0][3] = src->m[0][3];
    self->mtx.m[1][3] = src->m[1][3];
    self->mtx.m[2][3] = src->m[2][3];
}
