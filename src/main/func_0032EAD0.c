/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int func_00338B60(Vec36* v, Elem36* pos, int count, Elem36* value);

/* push_back: insert one element at the end. */
int func_0032EAD0(Vec36* v, Elem36* value) {
    return func_00338B60(v, &v->data[v->count], 1, value);
}
