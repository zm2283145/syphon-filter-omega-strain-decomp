/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "map_types.h"

extern int func_0026C3B0(MapEntry* entry);
extern int func_00272AC0(MapItem* item);

void func_0026C7E0(MapEntry* entry) {
    MapItem* item = entry->item;

    if (item->unk24 != 0 && func_00272AC0(item) == 0) {
        func_0026C3B0(entry);
    }
}
