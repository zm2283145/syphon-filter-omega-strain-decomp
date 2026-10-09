/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "materialProperties_types.h"

extern int func_00409940(MaterialVec* v, MaterialProps* pos, int n, int value);   /* insert */

/* back() */
MaterialProps* MaterialVec_Back(MaterialVec* v) {
    return &v->data[v->count] - 1;
}

/* push_back(v, value) */
int MaterialVec_PushBack(MaterialVec* v, int value) {
    return func_00409940(v, v->data + v->count, 1, value);
}

/* size() */
int func_004093D0(MaterialVec* v) {
    return v->count;
}
