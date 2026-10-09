/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_00173970(List*);

/* Constructs an empty list (sentinel at +4). */
List* func_003ECAF0(List* l) {
    l->count = 0;
    func_00173970(l);
    l->last = &l->first;
    l->first = &l->first;
    return l;
}

/* Initializes an empty vector header. */
L4OwnedVec* func_003ECB30(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.count = 0;
    self->vec.data = 0;
    self->owned = 0;
    return self;
}
