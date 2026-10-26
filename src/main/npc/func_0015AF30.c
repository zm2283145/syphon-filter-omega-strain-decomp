/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void std_list_cActiveListItemPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}

Word* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
