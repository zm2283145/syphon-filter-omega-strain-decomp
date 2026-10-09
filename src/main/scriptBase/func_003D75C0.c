/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern PtrVec* D_00554F30;  /* global enum table, ids start at 10 */

/* Returns the global enum descriptor for enum id 'id'. */
int ScriptEnum_GetById(int id) {
    int i = id - 10;

    return D_00554F30->data[i];
}
