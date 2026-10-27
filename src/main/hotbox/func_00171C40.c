/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);
extern int std_vector_cGOBJPtr_push_back(PtrVec* v, int* value);

/* Appends value to the vector at +0x60. */
void cHotbox_AddTarget(cHotbox* self, int value) {
    std_vector_cGOBJPtr_push_back(&self->unk60, &value);
}

/* push_back on a pointer vector. */
int std_vector_cGOBJPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
