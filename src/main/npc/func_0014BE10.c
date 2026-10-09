/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int func_0016E170(void* obj, int a1, int a2);

typedef struct NpcMoveGobj {
    char pad00[0xC];
    int id;                         /* 0x0C */
} NpcMoveGobj;

typedef struct NpcMoveNode {
    char pad00[0x78];
    int id;                         /* 0x78 */
} NpcMoveNode;

/* vtable slot 0x3F: MoveToGobj. */
int cNPC_MoveToGobj(cNPC* self, NpcMoveGobj* gobj) {
    self->moveTargetGobj = gobj->id;
    self->moveTargetNode = -1;
    func_0016E170(self->unk044, 7, 100);
    return 1;
}

/* vtable slot 0x3E: MoveToNode. */
int cNPC_MoveToNode(cNPC* self, NpcMoveNode* node) {
    func_0016E170(self->unk044, 7, 100);
    self->moveTargetNode = node->id;
    self->moveTargetGobj = -1;
    return 1;
}
