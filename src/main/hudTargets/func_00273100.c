/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int ObjMarkerMgr_Remove(int, int, int);

Word* func_00273100(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_00273110(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_00273130(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_00273140(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_00273160(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_00273170(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
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

int func_00273200(int a0, int a1) {
    return ObjMarkerMgr_Remove(a0, a1, 1);
}
