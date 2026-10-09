/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a marker list whose sentinel node is at +4. */
ListPos* ObjMarkerList_Append(MarkerList* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (ListNode*)&list->unk04;
    return List_InsertBefore(&result, list, &end, value);
}
