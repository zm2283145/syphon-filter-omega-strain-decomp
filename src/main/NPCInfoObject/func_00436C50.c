/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern void func_00436EA0(Tree* t, int root);

/* Tree clear: frees the nodes under the root and resets to empty. */
void func_00436C50(Tree* t) {
    if (t->header != 0) {
        func_00436EA0(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}
