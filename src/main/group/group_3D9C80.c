/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int Script_ObjectToId(int obj);
extern int Group_FindById(void* self, int* id);

/* Converts obj to its script id and passes it by address to Group_FindById. */
void Group_FindByObject(void* self, int obj) {
    int loc[1];

    loc[0] = Script_ObjectToId(obj);
    Group_FindById(self, loc);
}
