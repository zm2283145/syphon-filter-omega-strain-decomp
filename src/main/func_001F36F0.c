/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void Vector_Reserve_20B3F0_Thunk_1F3710(void);
extern void std_vector_deleter_cSkaTransBLEND_clear(int);

void std_vector_imp_cSkaTransBLEND_clear(int a0) {
    std_vector_deleter_cSkaTransBLEND_clear(a0);
}

void Vector_Reserve_20B3F0_Thunk(void) {
    Vector_Reserve_20B3F0_Thunk_1F3710();
}
