/*
 * Libs/SFOLib/Source/particle: 3 files, 00397840-00397980
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00397840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
struct RingE960 {
    int** cur; int** begin; int** x8; int** end;
};
struct DqItE960 { RingE960 ring; char* elem; char* bend; };
struct DqE960 { int capacity; int count; int size; int** data; unsigned int start; };
#if 0 /* merge_units */
extern "C" void _cdeque_deleter_common_int_begin(RingE960* out, DqE960* arr);
#endif /* merge_units */
struct WordCursor; /* merge_units */
struct WordBuf; /* merge_units */
extern "C" void _cdeque_deleter_common_int_begin(WordCursor* out, WordBuf* buf); /* merge_units */
#define _cdeque_deleter_common_int_begin(a0, a1) (_cdeque_deleter_common_int_begin((WordCursor *)(a0), (WordBuf *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern "C" RingE960* _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(RingE960* d, RingE960* s);
#endif /* merge_units */
extern "C" Quad* _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(Quad* d, Quad* s); /* merge_units */
#define _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(a0, a1) ((RingE960 *)_cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor((Quad *)(a0), (Quad *)(a1))) /* merge_units */

extern "C" void std_deque_deleter_common_cSkaSystem_Request_make_iterator(DqItE960* out, DqE960* dq, int n) {
    unsigned int idx = n + dq->start;
    RingE960 q;
    RingE960 it;
    RingE960 s;
    char* blk;
    _cdeque_deleter_common_int_begin(&s, dq);
    _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(&q, &s);
    it = q;
    RingE960* rp = &it;
    {
        int nn = idx >> 3;
        int size = it.end - it.begin;
        nn += it.cur - it.begin;
        if (nn < 0) nn += size;
        else if (nn >= size) nn -= size;
        rp->cur = rp->begin + nn;
    }
    int** c0 = rp->cur; int** c1 = rp->begin; int** c2 = rp->x8; int** c3 = rp->end;
    blk = dq->count == 0 ? 0 : (char*)*c0;
    out->ring.cur = c0; out->ring.begin = c1; out->ring.x8 = c2; out->ring.end = c3;
    out->elem = blk + (idx & 7) * 248;
    out->bend = blk + 0x7C0;
}
#undef _cdeque_deleter_common_int_begin /* merge_units */
#undef _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor /* merge_units */
static inline void merge_flush_func_00397840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00397840 */

/* merge_units: begin func_00397980 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

Quad* _cdeque_imp_cSkaSystem_RequestPtr_1_generic_iterator_ctor(Quad* d, Quad* s) {
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->d = s->d;
    return d;
}

/* Point a cursor at a word buffer. */
void _cdeque_deleter_common_int_begin(WordCursor* out, WordBuf* buf) {
    out->end = buf->data + buf->count;
    out->begin = buf->data;
    out->cur = out->begin + buf->count;
    out->limit = out->begin + buf->capacity;
}

void std_vector_deleter_cSkaPlaybackItem_clear(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_00397980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00397980 */

/* merge_units: begin func_00397A10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_chain_dtor.h"

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" void cParticleSpray_Definition();
extern "C" void cParticleSpray_GetRenderMatrix();
extern "C" void cParticleBase_Done();
extern "C" void cParticleSpray_Render();
extern "C" void cParticleSpray_NextFrame();
extern void * const D_004DFA80[];
extern "C" char D_004DFB50[];
extern "C" char D_004DFAD8[];
extern "C" VtableChainObject* cParticleSpray_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFA80);
        if (self) {
            self->vtable = D_004DFB50;
            if (self)
                self->vtable = D_004DFAD8;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFA80[8] = { (void*)0x0, (void*)0x0, (void*)cParticleSpray_dtor, (void*)cParticleSpray_Render, (void*)cParticleSpray_NextFrame, (void*)cParticleSpray_Definition, (void*)cParticleBase_Done, (void*)cParticleSpray_GetRenderMatrix };
static inline void merge_flush_func_00397A10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00397A10 */
