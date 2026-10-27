/*
 * Matched functions (byte-identical with the retail executable).
 * Small container helpers.
 */

#include "types.h"

Word* cConstLListIterator_cParticleDefinitionPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
