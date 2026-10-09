/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* List_InsertBefore(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* func_0015B1F0(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return List_InsertBefore(&it[1], t, &it[0], value);
}
