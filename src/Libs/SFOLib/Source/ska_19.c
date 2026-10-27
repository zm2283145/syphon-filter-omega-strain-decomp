/*
 * Libs/SFOLib/Source/ska: 2 files, 003AEBA0-003AEC80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AEBA0 */
#pragma push /* merge_units */
/* cSkaAnimAnchorList_ClearAccumulation (ska.cc): reset every root entry's accumulation state.
 * The asm zero stores (VZeroF) keep the iterators in stack slots like retail. */
#include "types.h"
#include "vc_copy.h"
#pragma cplusplus on
#pragma bool on
typedef int Q128 __attribute__((mode(TI)));
struct RSub_3AEBA0 { char pad[0xE0]; Q128 a; Q128 b; float w; int pad2[3]; Q128 q[4]; char pad3[0x20]; };
struct REnt_3AEBA0 { int pad0[4]; RSub_3AEBA0 sub; };
struct RColl_3AEBA0 { int pad0; int count; };
struct RIt_3AEBA0;
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b);
struct RIt_3AEBA0 {
    REnt_3AEBA0* p;
    RIt_3AEBA0(REnt_3AEBA0* x) : p(x) {}
    RIt_3AEBA0(const RIt_3AEBA0& o) : p(o.p) {}
    bool operator==(const RIt_3AEBA0& o) const { return REq(this, &o); }
    bool operator!=(const RIt_3AEBA0& o) const { return !(*this == o); }
    REnt_3AEBA0* operator->() const { return p; }
    RIt_3AEBA0& operator++() { p++; return *this; }
};
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b) { REnt_3AEBA0* bp = b->p; return a->p == bp; }
extern "C" REnt_3AEBA0** std_vector_deleter_cSkaAnimAnchorListEntry_data(RColl_3AEBA0*);
static inline RIt_3AEBA0 RBegin(RColl_3AEBA0* c) { RIt_3AEBA0 r(*std_vector_deleter_cSkaAnimAnchorListEntry_data(c)); return r; }
static inline RIt_3AEBA0 REnd(RColl_3AEBA0* c) { RIt_3AEBA0 r(*std_vector_deleter_cSkaAnimAnchorListEntry_data(c) + c->count); return r; }
static inline void RSubReset(RSub_3AEBA0* s, float z) {
    *(int*)((char*)s + 0xD0) = 0;
    VZeroF(&s->a);
    VZeroF(&s->b);
    s->w = z;
    for (Q128* q = s->q; q != s->q + 4; q++) VZeroF(q);
}
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void cSkaAnimAnchorList_ClearAccumulation(RColl_3AEBA0* self) {
    RIt_3AEBA0 it = RBegin(self);
    RIt_3AEBA0 end = REnd(self);
    for (; it != end; ++it) {
        RSubReset(&it->sub, 0.0f);
    }
}
static inline void merge_flush_func_003AEBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AEBA0 */

/* merge_units: begin func_003AEC80 */
#pragma push /* merge_units */
/* Temporary model description built by cSkaAnimAnchorList_ctor_cArrayR. */
typedef struct ModelDesc {
    char header[0x10];
    char first[0x20];
    char second[0x20];
} ModelDesc;

extern void cSkaAnimAnchorList_ctor_cArrayR(ModelDesc* desc);
extern void cArray_cSkaAnimAnchorListEntry_opAssign(void* self, ModelDesc* desc);
extern void cQuatVec_opAssign(void* dst, void* src);
extern void std_vector_deleter_cSkaAnimAnchorListEntry_dtor(ModelDesc* desc, int flags);

/* Initializes a root collection from a temporary model description. */
void cSkaAnimAnchorList_Reset(char* self) {
    ModelDesc desc;
    cSkaAnimAnchorList_ctor_cArrayR(&desc);
    cArray_cSkaAnimAnchorListEntry_opAssign(self, &desc);
    cQuatVec_opAssign(self + 0x10, desc.first);
    cQuatVec_opAssign(self + 0x30, desc.second);
    std_vector_deleter_cSkaAnimAnchorListEntry_dtor(&desc, 0);
}
static inline void merge_flush_func_003AEC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AEC80 */
