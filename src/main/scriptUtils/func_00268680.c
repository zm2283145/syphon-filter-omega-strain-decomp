/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Global_RemoveArray(int);
extern int func_002689F0(int);
extern int func_00269090(int);
extern int func_002690C0(int);

Word* func_00268680(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00268690(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002686A0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* func_002686B0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_002686C0(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* func_002686D0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

int Script_RemoveArray(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)(char*)a0;
    tmp1 = func_002690C0(tmp0);
    Global_RemoveArray(tmp1);
    return 0;
}

int Script_CreateArray(int a0) {
    int loc[1];
    int v0;

    v0 = *(int*)(char*)a0;
    *(int*)(char*)loc = v0;
    a0 = *(int*)(char*)loc;
    v0 = func_002689F0(a0);
    a0 = v0;
    v0 = func_00269090(a0);
    goto ret;
ret:
    return v0;
}
