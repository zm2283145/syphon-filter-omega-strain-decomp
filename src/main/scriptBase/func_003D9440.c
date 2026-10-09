/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern PtrVec* D_00554F28;  /* global script type table (ScriptType* entries, ids start at 100) */

/* Sets field +0x40 of script type 'typeId'. */
void ScriptType_SetParent(int typeId, int value) {
    int i = typeId - 100;
    ScriptType* type = (ScriptType*)D_00554F28->data[i];

    type->unk40 = value;
}
