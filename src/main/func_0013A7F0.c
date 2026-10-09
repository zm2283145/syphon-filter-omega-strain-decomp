/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern ListPos* List_InsertBefore(ListPos* result, void* list, ListPos* pos, int value);

/* push_back on a list whose sentinel node is at +4. */
ListPos* func_0013A7F0(void* list, int value) {
    ListPos end;
    ListPos result;

    end.node = (char*)list + 4;
    return List_InsertBefore(&result, list, &end, value);
}

int func_0013A820(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 0xE0-byte records. */
ElemE0Iter* func_0013A840(ElemE0Iter* it) {
    it->p = it->p + 1;
    return it;
}

ElemE0* func_0013A860(ElemE0Iter* it) {
    return it->p;
}
