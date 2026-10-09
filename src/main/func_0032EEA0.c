/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int func_00337B10(PairVec* v, Pair* pos, int count, Pair* value);

/* push_back on a vector of Pair. */
int func_0032EEA0(PairVec* v, Pair* value) {
    return func_00337B10(v, v->data + v->count, 1, value);
}

/* Pair constructor. */
Pair* func_0032EEC0(Pair* self, int first, int second) {
    self->first = first;
    self->second = second;
    return self;
}
