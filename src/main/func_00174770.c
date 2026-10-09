/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001748F0(PtrVec*, int, int);
extern int func_00174A20(PtrVec*, int, int);

/* Empty vector, then fill through func_00174A20. */
PtrVec* func_00174770(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    func_00174A20(v, a1, a2);
    return v;
}

/* Empty vector, then fill through func_001748F0. */
PtrVec* func_001747B0(PtrVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    func_001748F0(v, a1, a2);
    return v;
}
