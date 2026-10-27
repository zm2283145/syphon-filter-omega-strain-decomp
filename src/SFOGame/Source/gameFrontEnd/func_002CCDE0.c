/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "gameFrontEnd_types.h"

extern FeListPos* std_list_deleter_voidPtr_insert(FeListPos* result, void* list, FeListPos* pos, int value);

Word* cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator increment: advance to the next node. */
FeListPos* cLListIterator_GuiWidgetPtr_opInc(FeListPos* it) {
    it->node = it->node->next;
    return it;
}

/* Iterator dereference: address of the node value. */
int* cLListIterator_GuiWidgetPtr_opMul(FeListPos* it) {
    return &it->node->value;
}

float* cLListIterator_GuiWidgetPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_GuiWidgetPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_GuiWidgetPtr_ctor_void(void* self) {
    return self;
}

/* push_back on a list whose sentinel node is at +4. */
FeListPos* std_list_GuiWidgetPtr_push_back_GuiWidgetPR(void* list, int value) {
    FeListPos end;
    FeListPos result;

    end.node = (FeListNode*)((char*)list + 4);
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
