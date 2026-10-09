/*
 * Matched functions (byte-identical with the retail executable).
 * LargeInt.c
 */

#include "types.h"

/* Returns 1 when the low word of the large integer is even (bit 0 clear). */
int func_002EFCC0(int* value) {
    return (*value ^ 1) & 1;
}
