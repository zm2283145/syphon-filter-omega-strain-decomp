/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004FFB50;
extern int func_001302F0(void*);
extern int func_0041F150(Unk288A80*);

int* func_002888B0(PtrVec* v, int i) {
    return v->data + i;
}

Rel* func_002888C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Base update, then record whether an agent is selected. */
int func_002888E0(Unk288A80* self) {
    int selected;

    func_0041F150(self);
    selected = func_001302F0(&D_004FFB50);
    self->unk48 = selected != 0;
    return selected;
}
