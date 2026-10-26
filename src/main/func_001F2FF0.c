/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Vector_Reserve_20C2A0_Thunk_1F3010(void);
extern void std_vector_deleter_cSkaSwitchItem_clear(int);

void std_vector_imp_cSkaSwitchItem_clear(int a0) {
    std_vector_deleter_cSkaSwitchItem_clear(a0);
}

void Vector_Reserve_20C2A0_Thunk(void) {
    Vector_Reserve_20C2A0_Thunk_1F3010();
}
