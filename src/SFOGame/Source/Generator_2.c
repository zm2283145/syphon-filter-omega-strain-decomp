/*
 * SFOGame/Source/Generator: 2 files, 0021C7E0-0021C830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021C7E0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Swaps the contents of two vectors. */
void std_swap_vectordeleterR_vectordeleterR_17(PtrVec* a, PtrVec* b) {
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

void std_vector_deleter_cQuaternion_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_func_0021C7E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021C7E0 */

/* merge_units: begin func_0021C830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" void cMessage_getSOBJClassId();
extern "C" void cGeneratorDataMessage_dtor();
extern "C" void cGeneratorDataMessage_Pack();
extern void * const D_004DB5E0[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004DB5E0); p->a24 = s->a24; p->b28 = s->b28;

DEFINE_MESSAGE_CLONE(cGeneratorDataMessage_Clone, Msg_0021C830, 44, D_004A4C78, 253, CLONE_BODY)
void * const D_004DB5E0[8] = { (void*)0x0, (void*)0x0, (void*)cGeneratorDataMessage_dtor, (void*)cGeneratorDataMessage_Clone, (void*)cGeneratorDataMessage_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_0021C830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021C830 */
