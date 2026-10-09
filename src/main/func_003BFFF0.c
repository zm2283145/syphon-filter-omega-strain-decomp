/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int func_00183D90(Vec112* v, Elem112* pos, int count, Elem112* value);

/* push_back: insert one element at the end. */
int func_003BFFF0(Vec112* v, Elem112* value) {
    return func_00183D90(v, &v->data[v->count], 1, value);
}
