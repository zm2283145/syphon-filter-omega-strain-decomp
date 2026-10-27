#include "types.h"
#include "loose02_types.h"

/* peephole off keeps the unfolded addiu+lq/sq 0(reg) quad copies */
#pragma peephole off

typedef struct {
    Q q0, q1, q2, q3;
    float f40, f44;
    int i48, i4C, i50, i54, i58, i5C;
    unsigned char b60;
} Rec64;

/* Rec64 copy (assignment). */
Rec64* cPathNavigatorTransfer_opAssign(Rec64* dst, Rec64* src) {
    Q q0; Q q1; Q q2; Q q3;
    float f40, f44;
    int i48, i4C, i50, i54, i58, i5C;
    unsigned char b60;

    q0 = src->q0; dst->q0 = q0;
    q1 = src->q1; dst->q1 = q1;
    q2 = src->q2; dst->q2 = q2;
    q3 = src->q3; dst->q3 = q3;
    f40 = src->f40; dst->f40 = f40;
    f44 = src->f44; dst->f44 = f44;
    i48 = src->i48; dst->i48 = i48;
    i4C = src->i4C; dst->i4C = i4C;
    i50 = src->i50; dst->i50 = i50;
    i54 = src->i54; dst->i54 = i54;
    i58 = src->i58; dst->i58 = i58;
    i5C = src->i5C; dst->i5C = i5C;
    b60 = src->b60; dst->b60 = b60;
    return dst;
}


