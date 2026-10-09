/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);
extern OwnedVec* func_003E1960(OwnedVec* v);

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_003E1900(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

OwnedVec* func_003E1930(OwnedVec* v) {
    func_003E1960(v);
    v->unk0C = 1;
    return v;
}
