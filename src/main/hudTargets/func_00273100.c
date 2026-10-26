/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern int ObjMarkerMgr_Remove(ObjMarkerMgr* mgr, int* id, int send);

Word* cLListIterator_cHudTargetInfoPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* List iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_5(ListPos* a, ListPos* b) {
    return a->node != b->node;
}

void cLList_cHudTargetInfoPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* List iterator ++. */
ListPos* cLListIterator_cHudTargetInfoPtr_opInc(ListPos* it) {
    it->node = it->node->next;
    return it;
}

/* List iterator dereference. */
int* cLListIterator_cHudTargetInfoPtr_opMul(ListPos* it) {
    return &it->node->value;
}

float* cLListIterator_cHudTargetInfoPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_cHudTargetInfoPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cHudTargetInfoPtr_ctor_void(void* self) {
    return self;
}

Word* cLListIterator_cHudTargetsObserverPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cHudTargetsObserverPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_cHudTargetsObserverPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cHudTargetInfoPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cHudTargetInfoPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cHudTargetInfoPtr_begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* Removes the marker for object id (map marker kinds). */
int ObjMarkerMgr_RemoveDefault(ObjMarkerMgr* mgr, int* id) {
    return ObjMarkerMgr_Remove(mgr, id, 1);
}
