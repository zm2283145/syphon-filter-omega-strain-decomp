/*
 * main/ska: range (2 files, 003AECE0-003AED40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AECE0 */
#pragma push /* merge_units */
typedef struct { char d[0x180]; } RootElem_3AECE0;
typedef struct { int pad0; int count; RootElem_3AECE0* data; unsigned char flag; } RootColl_3AECE0;
typedef struct { signed char c; } Tag_3AECE0;
extern void std_vector_imp_cSkaAnimAnchorListEntry_do_assign(RootColl_3AECE0* self, RootElem_3AECE0* first, RootElem_3AECE0* last, Tag_3AECE0 tag);
RootColl_3AECE0* cArray_cSkaAnimAnchorListEntry_opAssign(RootColl_3AECE0* self, RootColl_3AECE0* o) {
    if (self != o) {
        Tag_3AECE0 tag;
        std_vector_imp_cSkaAnimAnchorListEntry_do_assign(self, o->data, o->data + o->count, tag);
    }
    self->flag = o->flag;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AECE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AECE0 */

/* merge_units: begin func_003AED40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; unused xx locals reproduce retail's dead addius (they survive only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void cQuatVec_ctor_cQuatVecR(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { cQuatVec_ctor_cQuatVecR(this, &o); void* xx = this; } };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
void cQuaternion_GetIdentity(V* q);
void cVector_Get0001(V* v);
void cQuatVec_ctor_cQuaternionR_cVectorR(Plc* p, V* q, V* v);
void std_vector_cSkaAnimAnchorListEntry_ctor(void* self);
}
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        cQuaternion_GetIdentity(&q);
        cVector_Get0001(&v);
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
struct Wd { int value; };
extern "C" {
Wd* cString4_ctor(Wd* dst, Wd* src);
void* std_vector_deleter_cString4_data(void* self);
int std_vector_cSkaAnimAnchorListEntry_reserve(void* a0, int a1);
int cArrayCapacity_Int(int* n);
void cSkaAnimAnchor_ctor(void* p);
struct Elem;
void std_vector_imp_cSkaAnimAnchorListEntry_insert(void* self, void* pos, int n, const Elem& v);
void* cSkaAnimAnchor_dtor(void* self, short flags);
}
/* cSkaAnimAnchorList_ctor_cArrayR: Elem dtor uses the weak .dtors_drop idiom (include/alloc_guard.h); "Elem* t = this" keeps the element address in s0; iterators default-constructed then assigned give retail's temp+copy stack slots */
struct It {
    Wd* p;
    It() {}
    It(Wd* q) : p(q) {}
    bool operator==(const It& o) const { Wd* b = o.p; Wd* a = p; return a == b; }
    bool operator!=(const It& o) const { return !(*this == o); }
    void operator++() { p++; }
};
struct WVec {
    int x0; int size; Wd* data;
    It begin() { return It(*(Wd**)std_vector_deleter_cString4_data(this)); }
    It end() { return It(*(Wd**)std_vector_deleter_cString4_data(this) + size); }
};
#pragma define_section ELEM_DTOR ".dtors_drop" far_absolute RX
struct Elem { Wd w; char pad[0xC]; char root[0x170]; Elem(Wd& x) { Elem* t = this; cString4_ctor(&t->w, &x); cSkaAnimAnchor_ctor(t->root); } __declspec(weak) __declspec(ELEM_DTOR) ~Elem() { cSkaAnimAnchor_dtor(root, -1); } } __attribute__((aligned(16)));
struct S { int x0; int size; char* data; unsigned char bC; Plc p10; Plc p30; };
extern "C" S* cSkaAnimAnchorList_ctor_cArrayR(S* s, WVec* src);
S* cSkaAnimAnchorList_ctor_cArrayR(S* s, WVec* src)
{
    It it; It e;
    int n = src->size;
    std_vector_cSkaAnimAnchorListEntry_ctor(s);
    std_vector_cSkaAnimAnchorListEntry_reserve(s, cArrayCapacity_Int(&n));
    s->bC = 1;
    s->p10 = Ident();
    s->p30 = Ident();
    it = src->begin();
    e = src->end();
    while (it != e) {
        std_vector_imp_cSkaAnimAnchorListEntry_insert(s, s->data + s->size * 0x180, 1, Elem(*it.p));
        ++it;
    }
    return s;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AED40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AED40 */
