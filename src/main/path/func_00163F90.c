/*
 * Matched functions (byte-identical with the retail executable).
 * Word copy.
 */

#include "types.h"
#include "path_types.h"

Word* func_00163F90(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
