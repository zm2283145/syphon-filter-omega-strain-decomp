/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Vector_Reserve_20A790_Thunk_1F4350(void);
extern void std_vector_deleter_cSkaBlendSequenceItem_clear(int);

void std_vector_imp_cSkaBlendSequenceItem_clear(int a0) {
    std_vector_deleter_cSkaBlendSequenceItem_clear(a0);
}

void Vector_Reserve_20A790_Thunk(void) {
    Vector_Reserve_20A790_Thunk_1F4350();
}
