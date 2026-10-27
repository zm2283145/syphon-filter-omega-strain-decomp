/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "skeleton_types.h"

extern SkelListPos* std_list_deleter_voidPtr_insert(SkelListPos* result, void* list, SkelListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
SkelListPos* std_list_cSkeletonDataBankEntryPtr_push_back(void* list, int value) {
    SkelListPos end;
    SkelListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
