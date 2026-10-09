/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern int func_0015DDB0(int id);

/* True when both the target and the link exist and the link is ready. */
int func_002D3FF0(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Same test as func_002D3FF0 (separate vtable slot). */
int func_002D4030(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Stores the id and caches its lookup. */
void func_002D4070(Controller2D* self, int id) {
    self->unk208 = id;
    self->unk1E8 = func_0015DDB0(id);
}
