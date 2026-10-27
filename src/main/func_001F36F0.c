/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void std_vector_cSkaTransBLEND_reserve(void);
extern void std_vector_deleter_cSkaTransBLEND_clear(int);

void std_vector_imp_cSkaTransBLEND_clear(int a0) {
    std_vector_deleter_cSkaTransBLEND_clear(a0);
}

void cArray_cSkaTransBLEND_ReserveActual(void) {
    std_vector_cSkaTransBLEND_reserve();
}
