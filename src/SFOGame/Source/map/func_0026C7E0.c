/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "map_types.h"

extern int cMap_NextObjective(MapEntry* entry);
extern int cHudTargetManager_GetObjectiveTarget(MapItem* item);

void cMap_Update(MapEntry* entry) {
    MapItem* item = entry->item;

    if (item->unk24 != 0 && cHudTargetManager_GetObjectiveTarget(item) == 0) {
        cMap_NextObjective(entry);
    }
}
