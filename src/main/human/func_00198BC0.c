/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

/* 24-byte iterator returned by the lookup at 0x001BE960. */
typedef struct Iter24 {
    int w[6];
} Iter24;

extern int func_001BE960(Iter24*, char*, int);

void* func_00198BC0(char* self) {
    return self + 232;
}

int func_00198BD0(char* self) {
    return *(int*)(self + 16);
}

/* Lookup using the key at src+0x14; copy the resulting iterator to out. */
void func_00198BE0(Iter24* out, char* src) {
    Iter24 it;

    func_001BE960(&it, src, *(int*)(src + 20));
    out->w[0] = it.w[0];
    out->w[1] = it.w[1];
    out->w[2] = it.w[2];
    out->w[3] = it.w[3];
    out->w[4] = it.w[4];
    out->w[5] = it.w[5];
}

/* Same lookup with key 0. */
void func_00198C40(Iter24* out) {
    Iter24 it;
    char* src;

    func_001BE960(&it, src, 0);
    out->w[0] = it.w[0];
    out->w[1] = it.w[1];
    out->w[2] = it.w[2];
    out->w[3] = it.w[3];
    out->w[4] = it.w[4];
    out->w[5] = it.w[5];
}
