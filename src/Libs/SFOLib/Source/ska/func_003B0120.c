/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* True when the stored word equals value. */
int cSkaTransPlayback_CheckId(Word* w, int value) {
    return w->value == value;
}

int cSkaSwitchValue_CurrGoalState(char* self) {
    return *(int*)(self + 4);
}

int cSkaSwitchValue_NextGoalState(char* self) {
    return *(int*)(self + 0);
}

/* Table entry of owner selected by the index stored at idx +0x20. */
SkaPair* cSkaSwitch_GetSwitchValue(SkaPairIndex* idx, SkaPairTableOwner* owner) {
    return &owner->table[idx->index];
}

int cSkaSwitchItem_WhatToPlay(char* self) {
    return *(int*)(self + 0);
}

/* Address of element i in an array of 20-byte elements. */
char* cArray_cSkaSwitchItem_opIndex(SkaVec* v, int i) {
    char* data = v->data;
    return data + i * 20;
}

/* Second word of table entry i. */
int cSkaParams_GetSwitchCurrGoalState(SkaPairTableOwner* owner, int i) {
    return ((SkaPair*)((char*)owner->table + (i << 3)))->unk4;
}
