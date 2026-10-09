/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hudTargets.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "hudTargets_types.h"

extern int ObjMarkerMgr_Remove(ObjMarkerMgr* mgr, int* id, int send);

Word* func_00273100(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* List iterator inequality. */
int func_00273110(ListPos* a, ListPos* b) {
    return a->node != b->node;
}

void func_00273130(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* List iterator ++. */
ListPos* func_00273140(ListPos* it) {
    it->node = it->node->next;
    return it;
}

/* List iterator dereference. */
int* func_00273160(ListPos* it) {
    return &it->node->value;
}

float* func_00273170(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void func_00273180(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00273190(void* self) {
    return self;
}

Word* func_002731A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731B0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002731C0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731D0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002731E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002731F0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* Removes the marker for object id (map marker kinds). */
int ObjMarkerMgr_RemoveDefault(ObjMarkerMgr* mgr, int* id) {
    return ObjMarkerMgr_Remove(mgr, id, 1);
}
