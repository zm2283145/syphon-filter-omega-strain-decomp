/*
 * main/ska: range (4 files, 003AD2C0-003AD3A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003AD2C0 */
#pragma push /* merge_units */
typedef struct HandlePair {
    int first;
    int second;
} HandlePair;

/* True when first is non-zero or second is not -1. */
int cSkaPlaybackGroupId_IsValid(HandlePair* p) {
    return p->first != 0 || ~p->second != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD2C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD2C0 */

/* merge_units: begin func_003AD2F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int v; } Obj40;
/* Returns whether the field at +0x40 is set. */
int cSkaAnimCheckpoints_HasScheduledEvents(Obj40* o) { return !(o->v == 0); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD2F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD2F0 */

/* merge_units: begin func_003AD310 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern SkaTransitionReq* std_list_deleter_voidPtr_ctor_void(SkaTransitionReq* self);

/* True when both requests carry the same key. */
int cDequeue_cSkaSystem_Request_ReverseIterator_opEq(SkaTransitionReq* a, SkaTransitionReq* b) {
    return a->key == b->key;
}

SkaTransitionReq* TransitionReq_Construct(SkaTransitionReq* self, float time) {
    std_list_deleter_voidPtr_ctor_void(self);
    self->unk0C = time;
    return self;
}

/* Reset: zero words, both limits to FLT_MAX. */
SkaTransitionReq* cSkaSystem_Transition_ctor_void(SkaTransitionReq* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 3.4028235e38f;
    self->unk0C = 3.4028235e38f;
    self->key = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD310 */

/* merge_units: begin func_003AD3A0 */
#pragma push /* merge_units */
typedef struct { char data[0xF8]; } DequeItem;
typedef struct { unsigned int mapSize; int unk4; unsigned int start; DequeItem** map; unsigned int first; unsigned int count; } Deque;

/* Returns a pointer to the last element of a block-based deque (8 items per block). */
DequeItem* std_deque_deleter_common_cSkaSystem_Request_back_void_2(Deque* self)
{
    unsigned int index = self->first + self->count - 1;
    return &self->map[(self->start + (index >> 3)) % self->mapSize][index & 7];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AD3A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AD3A0 */
