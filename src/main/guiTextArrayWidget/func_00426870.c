/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextArrayWidget_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00426870(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

Vec4* func_00426890(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

void* func_004268B0(void* self) {
    return self;
}

Rel* func_004268C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
