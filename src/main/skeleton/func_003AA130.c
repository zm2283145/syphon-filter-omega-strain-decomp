/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "skeleton_types.h"

extern SkelListPos* List_InsertBefore(SkelListPos* result, void* list, SkelListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
SkelListPos* func_003AA130(void* list, int value) {
    SkelListPos end;
    SkelListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
