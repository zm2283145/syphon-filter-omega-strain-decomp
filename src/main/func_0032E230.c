/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int func_00337F90(Vec28* v, Elem28* pos, int count, Elem28* value);

/* push_back: insert one element at the end. */
int func_0032E230(Vec28* v, Elem28* value) {
    return func_00337F90(v, &v->data[v->count], 1, value);
}
