/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructor.
 */

#include "types.h"
#include "WaterFx_types.h"

WaterListIter* std_list_deleter_tNode_generic_iterator_ctor_nodebaseP(WaterListIter* it, WaterListLink* node) {
    it->node = node;
    return it;
}
