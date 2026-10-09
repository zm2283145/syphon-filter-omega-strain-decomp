/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

void* func_0019D190(char* self) {
    return self + 16;
}

void* func_0019D1A0(void* self) {
    return self;
}

/* Copy a 3x4 block: xyz of each row first, then the w column. */
Mtx34* Mtx34_Copy(Mtx34* dst, Mtx34* src) {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[0][1];
    dst->m[0][2] = src->m[0][2];
    dst->m[1][0] = src->m[1][0];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[1][2];
    dst->m[2][0] = src->m[2][0];
    dst->m[2][1] = src->m[2][1];
    dst->m[2][2] = src->m[2][2];
    dst->m[0][3] = src->m[0][3];
    dst->m[1][3] = src->m[1][3];
    dst->m[2][3] = src->m[2][3];
    return dst;
}

void* func_0019D220(char* self) {
    return self + 8;
}

int func_0019D230(char* self) {
    return *(int*)(self + 4);
}

void* Actor_GetEdgeRoot2(Actor* actor) {
    return actor->edgeRoot;
}
