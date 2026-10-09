/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int D_005061D8;
extern int PtrVec_Insert(PtrVec*, int*, int, int*);
extern int PtrVec_PushBack_282530(PtrVec*, int*);
extern PtrVec* func_00282550(void);

/* Appends a value to the list from func_00282550 and hands out the next id from D_005061D8. */
int func_002824D0(int value, int* outId) {
    int tmp;

    tmp = value;
    PtrVec_PushBack_282530(func_00282550(), &tmp);
    *outId = D_005061D8;
    D_005061D8 = D_005061D8 + 1;
    return *outId;
}

/* push_back */
int PtrVec_PushBack_282530(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
