/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in it[1]. */
Iter* std_list_tNPCInfoPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
