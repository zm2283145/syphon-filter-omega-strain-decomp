/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud_netlobby.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hud_netlobby_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

void func_0027B4A0(int* dst, int* src) {
    *dst = *src;
}

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_0027B4B0(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}
