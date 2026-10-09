/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* List_InsertBefore(L4Iter* out, void* list, L4Iter* pos, int value);

/* Address of the value in the node referenced by the word at +8. */
int* func_00415B20(L4Node** self) {
    return &self[2]->value;
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* func_00415B30(void* list, int value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return List_InsertBefore(&it[1], list, &it[0], value);
}
