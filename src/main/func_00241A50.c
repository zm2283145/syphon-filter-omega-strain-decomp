/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00241A50(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}

void func_00241A90(char* self) {
    *(int*)(self + 4) = 0;
}

void func_00241AA0(char* self) {
    *(int*)(self + 4) = 0;
}

void func_00241AB0(char* self) {
    *(int*)(self + 4) = 0;
}
