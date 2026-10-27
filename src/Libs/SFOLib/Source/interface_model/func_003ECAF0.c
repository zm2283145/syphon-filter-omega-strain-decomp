/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int details_compressed_pair_imp_cAllocator_voidPtr_int_1_first(List*);

/* Constructs an empty list (sentinel at +4). */
List* std_list_cSfxSchedulerPtr_ctor(List* l) {
    l->count = 0;
    details_compressed_pair_imp_cAllocator_voidPtr_int_1_first(l);
    l->last = &l->first;
    l->first = &l->first;
    return l;
}

/* Initializes an empty vector header. */
L4OwnedVec* cSfxScheduler_tItem_ctor(L4OwnedVec* self) {
    self->vec.unk0 = 0;
    self->vec.count = 0;
    self->vec.data = 0;
    self->owned = 0;
    return self;
}
