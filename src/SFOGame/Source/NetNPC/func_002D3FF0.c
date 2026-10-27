/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern int cAIPathData_GetNode(int id);

/* True when both the target and the link exist and the link is ready. */
int cNetNPC_IsTargetVisible(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Same test as cNetNPC_IsTargetVisible (separate vtable slot). */
int cNetNPC_TargetPositionValid(Controller2D* self) {
    return self->target != 0 && self->link != 0 && self->link->ready != 0;
}

/* Stores the id and caches its lookup. */
void cNetNPC_NodeReachedByLocalNpc(Controller2D* self, int id) {
    self->unk208 = id;
    self->unk1E8 = cAIPathData_GetNode(id);
}
