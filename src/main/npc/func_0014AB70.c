/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int List_InsertBefore(int, int, int, int);

Word* func_0014AB70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014AB80(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_0014AB90(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = List_InsertBefore(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}

Word* func_0014ABC0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_0014ABD0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0014ABE0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_0014ABF0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_0014AC00(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_0014AC20(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_0014AC30(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_0014AC50(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_0014AC60(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void func_0014AC70(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_0014AC80(void* self) {
    return self;
}
