/*
 * Libs/SFOLib/Source/particle: 2 files, 00397980-00397A10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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

#include "types.h"
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
