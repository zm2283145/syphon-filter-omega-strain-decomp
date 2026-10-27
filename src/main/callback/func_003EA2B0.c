/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "callback_types.h"

extern CbListPos* std_list_deleter_voidPtr_insert(CbListPos* result, void* list, CbListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4 (named std_list_cCBDataPtr_push_back in the symbol map). */
CbListPos* std_list_cCBDataPtr_push_back(void* list, int value) {
    CbListPos end;
    CbListPos result;

    end.node = (char*)list + 4;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
