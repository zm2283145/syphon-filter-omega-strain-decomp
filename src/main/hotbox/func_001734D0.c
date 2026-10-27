/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);

/* push_back on a pointer vector. */
int cArray_cHotboxPtr_PushBackActual(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
