/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructor.
 */

#include "types.h"
#include "WaterFx_types.h"

WaterListIter* func_002B3FB0(WaterListIter* it, WaterListLink* node) {
    it->node = node;
    return it;
}
