/*
 * Matched functions (byte-identical with the retail executable).
 * Writes one scalar into two fields.
 */

#include "types.h"
#include "path_types.h"

void func_0015FDC0(PathScalarPair* self, float value) {
    self->unk08 = value;
    self->unk28 = value;
}
