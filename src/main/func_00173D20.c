/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001748F0(PtrVec*, int, ValFlag*);

/* Empty vector, then fill through func_001748F0 with a {value, 0} argument. */
PtrVec* func_00173D20(PtrVec* v, int a1, int value) {
    ValFlag arg;

    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    arg.value = value;
    arg.flag = 0;
    func_001748F0(v, a1, &arg);
    return v;
}
