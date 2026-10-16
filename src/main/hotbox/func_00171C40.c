/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);
extern int PtrVec_PushBack_171C70(PtrVec* v, int* value);

/* Appends value to the vector at +0x60. */
void func_00171C40(cHotbox* self, int value) {
    PtrVec_PushBack_171C70(&self->unk60, &value);
}

/* push_back on a pointer vector. */
int PtrVec_PushBack_171C70(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
