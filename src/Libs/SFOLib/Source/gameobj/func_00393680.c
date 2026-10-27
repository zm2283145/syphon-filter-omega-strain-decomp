/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Address of the member at +8. */
void* std_vector_deleter_cSkaAnimAnchorListEntry_data(char* self) {
    return self + 8;
}
