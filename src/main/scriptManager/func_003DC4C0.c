/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

int* func_003DC4C0(PtrVec* v, int i) {
    return v->data + i;
}

/* Maps a script-local enum id (>= 10) to the global enum id. */
int Script_RemapEnumId(Script* script, int localId) {
    int i = localId - 10;

    return script->enumMap[i];
}
