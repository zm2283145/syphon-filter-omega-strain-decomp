/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* List_InsertBefore(L4Iter* out, void* list, L4Iter* pos, int* value);
L4Iter* func_003CAC70(void* list, int* value);

/* Appends value to the list at +0x20; always returns 1. */
int func_003CAC40(Unk3CAC40* self, int value) {
    int loc[1];

    loc[0] = value;
    func_003CAC70(self->unk20, loc);
    return 1;
}

/* push_back on a list whose sentinel node is at +4. */
L4Iter* func_003CAC70(void* list, int* value) {
    L4Iter it[2];

    it[0].node = (L4Node*)((char*)list + 4);
    return List_InsertBefore(&it[1], list, &it[0], value);
}
