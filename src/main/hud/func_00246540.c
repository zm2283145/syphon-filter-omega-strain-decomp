/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_00246540(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

Rel* func_00246570(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* func_00246590(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
