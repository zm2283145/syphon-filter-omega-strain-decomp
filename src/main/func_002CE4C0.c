/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int func_002CE4C0(void) {
    return 1;
}

int func_002CE4D0(WordFields* self) {
    return self->unk00;
}

int func_002CE4E0(WordFields* self) {
    return self->unk04;
}

List* func_002CE4F0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
