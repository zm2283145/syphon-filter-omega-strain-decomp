/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "callback_types.h"

extern CbListPos* List_InsertBefore(CbListPos* result, void* list, CbListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4 (named List_End in the symbol map). */
CbListPos* List_End(void* list, int value) {
    CbListPos end;
    CbListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
