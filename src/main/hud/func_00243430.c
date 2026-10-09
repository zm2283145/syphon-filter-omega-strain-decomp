/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_00243430(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
