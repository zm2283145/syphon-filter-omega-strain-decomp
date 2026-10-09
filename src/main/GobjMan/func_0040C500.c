/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: script object ID word helpers.
 */

#include "types.h"
#include "GobjMan_types.h"

/* Pack (category, index, kind) into an ID word. */
GobjId* Id_Build(GobjId* id, int category, int index, int kind) {
    id->word = index | (((kind + 1) << 24) | (category << 16));
    return id;
}

/* Index fits in the 16-bit index field. */
int Id_IsValidIndex(unsigned int index) {
    return index < 0x10000;
}

/* Category fits in the 8-bit category field. */
int Id_IsValidCategory(unsigned int category) {
    return category < 256;
}
