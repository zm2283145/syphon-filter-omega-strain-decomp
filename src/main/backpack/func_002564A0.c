/*
 * Matched functions (byte-identical with the retail executable).
 * Pair vector helpers (8-byte entries).
 */

#include "types.h"
#include "backpack_types.h"

extern int HandleVec_Insert(PairVec* v, Pair* pos, int n, int value);

/* push_back(value) */
int HandleVec_PushBack(PairVec* v, int value) {
    return HandleVec_Insert(v, v->data + v->count, 1, value);
}

int func_002564C0(Word* a, Word* b) {
    return a->value == b->value;
}

/* out = end() */
void func_002564E0(Pair** out, PairVec* v) {
    *out = v->data + v->count;
}
