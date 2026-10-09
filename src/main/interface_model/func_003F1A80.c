/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "interface_model_types.h"

extern int func_001396D0(int a0, int a1);
extern OwnedVec* func_003F1BF0(OwnedVec* v);

/* Clears the three vector words. */
OwnedVec* func_003F1A80(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int func_003F1AA0(int a0, int a1) {
    return func_001396D0(a0, a1);
}

/* Reads one word from a stream cursor. */
int** func_003F1AB0(int** cursor, int* out) {
    *out = **cursor;
    *cursor = *cursor + 1;
    return cursor;
}

OwnedVec* func_003F1AD0(OwnedVec* v) {
    func_003F1BF0(v);
    v->unk0C = 1;
    return v;
}
