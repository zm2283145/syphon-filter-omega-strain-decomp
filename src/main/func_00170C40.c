/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_00170C40(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int func_00170C50(int a0, int a1) {
    return ((unsigned int)(0) < (unsigned int)((*(int*)(char*)a0 ^ *(int*)(char*)a1)));
}

void func_00170C70(Iter* out, Tree* t) {
    out->p = &t->header;
}

int func_00170C80(int a0) {
    *(int*)((char*)a0) = *(int*)((char*)*(int*)(char*)a0 + 4);
    return a0;
}

int func_00170CA0(int a0) {
    return (*(int*)(char*)a0 + 8);
}

int func_00170CB0(int a0, int a1) {
    *(float*)((char*)a0) = *(float*)(char*)a1;
    return a0;
}

void func_00170CC0(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00170CD0(void* self) {
    return self;
}

Word* func_00170CE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00170CF0(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

void func_00170D00(Iter* out, PtrVec* v) {
    out->p = v->data;
}

Word* func_00170D10(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00170D20(Iter* out, Tree* t) {
    out->p = &t->header;
}
