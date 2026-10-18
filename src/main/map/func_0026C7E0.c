/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "map_types.h"

extern int HudMap_NextMarker(MapEntry* entry);
extern int HudMarkers_GetHighlight(MapItem* item);

void func_0026C7E0(MapEntry* entry) {
    MapItem* item = entry->item;

    if (item->unk24 != 0 && HudMarkers_GetHighlight(item) == 0) {
        HudMap_NextMarker(entry);
    }
}
