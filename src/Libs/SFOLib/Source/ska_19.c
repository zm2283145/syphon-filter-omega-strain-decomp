/*
 * Libs/SFOLib/Source/ska: 3 files, 003B0120-003B0280
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

/* merge_units: begin func_003B0280 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct Item { void* what; float start; float end; };
struct Wrap { Item* p; };
struct It {
    Wrap m;
    It(Item* e) { m.p = e; }
    It(const It& o) { m.p = o.m.p; } It(const Wrap& w) : m(w) {} 
    Item* operator->() const { return &*m.p; }
    bool operator==(const It& o) const { return m.p == o.m.p; }
    bool operator!=(const It& o) const { return !(m.p == o.m.p); }
    void Inc() { m.p++; }
};
struct SwItem { void* what; char pad[16]; };
struct Switch { char pad[0x2C]; SwItem* items; };
struct Blend { char vec[4]; int n; Item* first; char padC[4]; float d0, d1; int pid; unsigned char rev; unsigned char sinus; };
struct TP { Switch* sw; Blend* trans; unsigned char active, isRev; int cur; int nxt; float timer; unsigned char needInterp; float interp; void* w0; void* w1; };
extern "C" Item** std_vector_deleter_cSkaBlendSequenceItem_data_void_2(const void* v);
static inline float MinF(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float Clamp01(float x) { float r; float hi; int t; asm { lui t, 0x3F80; mtc1 zero, r; mtc1 t, hi; max.s r, x, r; min.s r, r, hi } return r; }
// hi is read from v1, loaded by a separate asm at the start of the block
static inline float Clamp01W(float x) { float r; asm { mtc1 zero, r; mtc1 v1, f4; max.s r, x, r; min.s r, r, f4 } return r; }
static inline It End(const Blend* b) { return It(*std_vector_deleter_cSkaBlendSequenceItem_data_void_2(b) + b->n); }

static inline void* What(TP* s, int st) { return s->sw->items[st].what; }
extern "C" void cSkaTransPlayback_UpdateWhatToPlay(TP* self, const Blend* trans, float duration)
{
    void* play0; void* play1;
    float tn = MinF(1.0f, self->timer / duration);
    int listSize = trans->n;
    play0 = What(self, self->cur);
    play1 = What(self, self->nxt);
    It end = End(trans);
    It prev = end;
    It next = listSize > 0 ? It(trans->first) : end;
    float prevEnd = 0.0f;
    for (int i = 0; i < listSize + 1; i++) {
        if (i == listSize) next = It(end.m);
        bool notEnd = next != end;
        float nextStart = notEnd ? next->start : 1.0f;
        if (tn <= nextStart) {
            if (tn <= prevEnd) {
                self->w0 = (prev == end) ? play0 : (play0 = prev->what);
                self->w1 = self->w0;
                self->interp = 1.0f;
                self->needInterp = 0;
                return;
            } else {
                self->w0 = (prev == end) ? play0 : (play0 = prev->what);
                self->w1 = (next == end) ? play1 : (play1 = next->what);
                if (!trans->sinus) {
                    self->interp = Clamp01((tn - prevEnd) / (nextStart - prevEnd));
                } else {
                    asm { lui v1, 0x3F80 }
                    float x2;
                    float x = (tn - prevEnd) / (nextStart - prevEnd);
                    x2 = x * x;
                    x *= x2;
                    float c2 = 2.0f;
                    float c3 = 3.0f;
                    c3 *= x2;
                    c2 *= x;
                    float v = c3 - c2;
                    self->interp = Clamp01W(v);
                }
                self->needInterp = 1;
            }
            return;
        }
        prev = next;
        prevEnd = notEnd ? next->end : 1.0f;
        next.Inc();
    }
}
static inline void merge_flush_func_003B0280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0280 */
