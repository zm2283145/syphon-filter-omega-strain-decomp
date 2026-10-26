/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_deleter_EnumField_clear(Word* self) {
    self[1].value = 0;
}
