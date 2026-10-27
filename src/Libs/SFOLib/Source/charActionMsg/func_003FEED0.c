/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc
 */

#include "types.h"
#include "globalization_types.h"

/* Clear unk04. */
void std_vector_deleter_1_clear(LocTable* self) {
    self->unk04 = 0;
}
