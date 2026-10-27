/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int cScriptInterpreter_PackPtr(int obj);
extern int cGroup_Find_cObjectIdR(void* self, int* id);

/* Converts obj to its script id and passes it by address to cGroup_Find_cObjectIdR. */
void cGroup_Find_cSystemP(void* self, int obj) {
    int loc[1];

    loc[0] = cScriptInterpreter_PackPtr(obj);
    cGroup_Find_cObjectIdR(self, loc);
}
