/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* True when the stored word equals value. */
int func_003B0120(Word* w, int value) {
    return w->value == value;
}

int func_003B0130(char* self) {
    return *(int*)(self + 4);
}

int func_003B0140(char* self) {
    return *(int*)(self + 0);
}

/* Table entry of owner selected by the index stored at idx +0x20. */
SkaPair* func_003B0150(SkaPairIndex* idx, SkaPairTableOwner* owner) {
    return &owner->table[idx->index];
}

int func_003B0170(char* self) {
    return *(int*)(self + 0);
}

/* Address of element i in an array of 20-byte elements. */
char* func_003B0180(SkaVec* v, int i) {
    char* data = v->data;
    return data + i * 20;
}

/* Second word of table entry i. */
int func_003B01A0(SkaPairTableOwner* owner, int i) {
    return ((SkaPair*)((char*)owner->table + (i << 3)))->unk4;
}
