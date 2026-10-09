/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "gameFrontEnd_types.h"

extern FeListPos* List_InsertBefore(FeListPos* result, void* list, FeListPos* pos, int value);

Word* func_002CCDE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator increment: advance to the next node. */
FeListPos* func_002CCDF0(FeListPos* it) {
    it->node = it->node->next;
    return it;
}

/* Iterator dereference: address of the node value. */
int* func_002CCE10(FeListPos* it) {
    return &it->node->value;
}

float* func_002CCE20(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_002CCE30(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_002CCE40(void* self) {
    return self;
}

/* push_back on a list whose sentinel node is at +4. */
FeListPos* func_002CCE50(void* list, int value) {
    FeListPos end;
    FeListPos result;

    end.node = (FeListNode*)((char*)list + 4);
    return List_InsertBefore(&result, list, &end, value);
}
