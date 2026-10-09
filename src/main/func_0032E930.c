/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int func_003385A0(Vec24* v, Elem24* pos, int count, Elem24* value);

/* push_back: insert one element at the end. */
int func_0032E930(Vec24* v, Elem24* value) {
    return func_003385A0(v, &v->data[v->count], 1, value);
}
