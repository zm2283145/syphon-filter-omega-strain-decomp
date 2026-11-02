/*
 * SFOGame/Source/ai: 2 files, 0016F710-0016F7E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016F710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004D9850[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
#if 0 /* merge_units */
void cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(void* self, void* other);
#endif /* merge_units */
struct cActionMsg; /* merge_units */
cActionMsg* cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(cActionMsg* self, cActionMsg* src); /* merge_units */
#define cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(a0, a1) ((void)cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR((cActionMsg *)(a0), (cActionMsg *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cObjectId_ctor_cObjectIdR(void* dst, void* src);
#endif /* merge_units */
Word* cObjectId_ctor_cObjectIdR(Word* dst, Word* src); /* merge_units */
#define cObjectId_ctor_cObjectIdR(a0, a1) ((void)cObjectId_ctor_cObjectIdR((Word *)(a0), (Word *)(a1))) /* merge_units */

void cVector_ctor_cVectorR(void* dst, void* src);
}
struct Msg_0016F710 {
    void* vtable;
    char base[0x30];
    char a[0xC];
    char v[0x10];
};
extern "C" Msg_0016F710* cAISoundSystemGOBJPositionMessage_Clone(Msg_0016F710* self)
{
    Msg_0016F710* p;
    {
        AllocGuard guard;
        p = (Msg_0016F710*)cMemMan_Allocate(0, 0x50, "ai.hh", 0x164);
    }
    if (p) {
        cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(p, self);
        p->vtable = D_004D9850;
        cObjectId_ctor_cObjectIdR(p->a, self->a);
        cVector_ctor_cVectorR(p->v, self->v);
    }
    return p;
}
#undef cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR /* merge_units */
#undef cObjectId_ctor_cObjectIdR /* merge_units */
static inline void merge_flush_func_0016F710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F710 */

/* merge_units: begin func_0016F7E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy and the action-message copy constructor.
 */

#include "ai_types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004DFD80[]; /* cMessage vtable */

Word* cObjectId_ctor_cObjectIdR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

cActionMsg* cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(cActionMsg* self, cActionMsg* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004D92A0;
    self->event = src->event;
    self->action = src->action;
    self->amplitude = src->amplitude;
    self->unk2C = src->unk2C;
    self->base.vtable = D_004D92C0;
    self->sender = src->sender;
    return self;
}
static inline void merge_flush_func_0016F7E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F7E0 */
