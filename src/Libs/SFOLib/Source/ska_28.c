/*
 * Libs/SFOLib/Source/ska: 2 files, 003B0120-003B01C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B0120 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_003B0120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0120 */

/* merge_units: begin func_003B01C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Find the list entry whose data starts with key. */
typedef struct { int key; } Data_3B01C0;
typedef struct Node_3B01C0 { int pad0; struct Node_3B01C0* next; Data_3B01C0* data; } Node_3B01C0;
typedef struct { Node_3B01C0* p; } It_3B01C0;
typedef struct { int w[1]; } Raw_3B01C0;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B01C0;

extern "C" {
void std_list_deleter_voidPtr_begin_void(Raw_3B01C0* out, void* list);
void std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(It_3B01C0* out, Raw_3B01C0* raw);
void std_list_cSkaTransPlaybackPtr_end(Raw_3B01C0* out, void* list);
void cLListIterator_cSkaTransPlaybackPtr_ctor(It_3B01C0* out, Raw_3B01C0* raw);
}

extern "C" Data_3B01C0* cSkaParams_GetTransPlayback(Obj_3B01C0* o, int key)
{
    It_3B01C0 last;
    It_3B01C0 first;
    Raw_3B01C0 rawFirst;
    Raw_3B01C0 rawEnd;
    Node_3B01C0* n;
    std_list_deleter_voidPtr_begin_void(&rawFirst, &o->list);
    std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(&first, &rawFirst);
    for (n = first.p; (std_list_cSkaTransPlaybackPtr_end(&rawEnd, &o->list), cLListIterator_cSkaTransPlaybackPtr_ctor(&last, &rawEnd), n != last.p); n = n->next) {
        if (n->data->key == key)
            return n->data;
    }
    return 0;
}
static inline void merge_flush_func_003B01C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B01C0 */
