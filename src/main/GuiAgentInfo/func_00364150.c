/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentInfo_types.h"

/* Copies a 3x4 block into the matrix at +0x10 (xyz of each row, then w). */
void func_00364150(MtxHolder* self, Mtx34* src) {
    self->m[0][0] = src->m[0][0];
    self->m[0][1] = src->m[0][1];
    self->m[0][2] = src->m[0][2];
    self->m[1][0] = src->m[1][0];
    self->m[1][1] = src->m[1][1];
    self->m[1][2] = src->m[1][2];
    self->m[2][0] = src->m[2][0];
    self->m[2][1] = src->m[2][1];
    self->m[2][2] = src->m[2][2];
    self->m[0][3] = src->m[0][3];
    self->m[1][3] = src->m[1][3];
    self->m[2][3] = src->m[2][3];
}
