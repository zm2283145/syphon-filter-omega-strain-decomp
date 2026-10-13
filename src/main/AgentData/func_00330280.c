/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer vector helper.
 */

#include "types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value) */
int PtrVec_PushBack_330280(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
