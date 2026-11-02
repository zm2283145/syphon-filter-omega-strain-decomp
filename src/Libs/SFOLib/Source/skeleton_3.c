/*
 * Libs/SFOLib/Source/skeleton: 8 files, 003AA230-003AA4E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AA230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cConstLListIterator_cSkeletonDataBankEntryPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_003AA230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA230 */

/* merge_units: begin func_003AA240 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cSkeletonDataBankEntryPtr_end_void)
static inline void merge_flush_func_003AA240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA240 */

/* merge_units: begin func_003AA270 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Stores value into *dst; volatile mirrors the original stack temporary. */
int* std_list_cSkeletonDataBankEntryPtr_generic_iterator_1_ctor(int* dst, int value) {
    volatile int tmp = value;

    *dst = tmp;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AA270(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AA270 */

/* merge_units: begin func_003AA290 */
#pragma push /* merge_units */
/* Temporary file/stream object used while loading. */
typedef struct LoadStream {
    char data[0xA0];
} LoadStream;

extern void cFileMan_ctor_void(LoadStream* s);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(LoadStream* s, int name, int flags, int mode);
extern void cSkeletonDataBank_AddSkeletonData_charP_cFileManR(int skel, int arg, int name, LoadStream* s);
extern void cFileMan_dtor(LoadStream* s, int flags);

/* Loads a skeleton through a temporary stream opened on `name`; returns 0. */
int cSkeletonDataBank_AddSkeletonData_charP_cHogFileR(int skel, int arg, int name, int flags) {
    LoadStream stream;
    cFileMan_ctor_void(&stream);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&stream, name, flags, 0);
    cSkeletonDataBank_AddSkeletonData_charP_cFileManR(skel, arg, name, &stream);
    cFileMan_dtor(&stream, -1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AA290(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AA290 */

/* merge_units: begin func_003AA320 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BCCF8[];
extern char D_004BCD50[];
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
struct SkEnt {
    char* name; int count; int a, b;
    void Destroy() {
        char* p = name;
        if (p) {
            AllocGuard g2;
            cMemMan_Deallocate(0, p, D_004BCD50, 0x66);
        }
    }
};
typedef struct SkNode { struct SkNode* prev; struct SkNode* next; SkEnt* e; } SkNode;
typedef struct { SkNode* n; } SkIt;
typedef struct { int pad; SkNode header; } SkList;
extern "C" {
#if 0 /* merge_units */
extern void std_list_cSkeletonDataBankEntryPtr_begin(SkIt* out, SkList* l);
#endif /* merge_units */
void std_list_cSkeletonDataBankEntryPtr_begin(Iter* out, PtrVec* v); /* merge_units */
#define std_list_cSkeletonDataBankEntryPtr_begin(a0, a1) (std_list_cSkeletonDataBankEntryPtr_begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern SkIt* cLListIterator_cSkeletonDataBankEntryPtr_ctor(SkIt* dst, SkIt* src);
#endif /* merge_units */
Word* cLListIterator_cSkeletonDataBankEntryPtr_ctor(Word* dst, Word* src); /* merge_units */
#define cLListIterator_cSkeletonDataBankEntryPtr_ctor(a0, a1) ((SkIt *)cLListIterator_cSkeletonDataBankEntryPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void std_list_cSkeletonDataBankEntryPtr_end_void_2(SkIt* out, SkList* l);
#endif /* merge_units */
void std_list_cSkeletonDataBankEntryPtr_end_void_2(Iter* out, Tree* t); /* merge_units */
#define std_list_cSkeletonDataBankEntryPtr_end_void_2(a0, a1) (std_list_cSkeletonDataBankEntryPtr_end_void_2((Iter *)(a0), (Tree *)(a1))) /* merge_units */

extern void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(SkIt* out, SkList* l, SkIt* first, SkIt* last);
void cSkeletonDataBank_Clear(SkList* l);
}

static inline void SkBegin(SkIt* out, SkList* l) { SkIt b; std_list_cSkeletonDataBankEntryPtr_begin(&b, l); cLListIterator_cSkeletonDataBankEntryPtr_ctor(out, &b); }
static inline void SkEnd(SkIt* out, SkList* l) { SkIt t; std_list_cSkeletonDataBankEntryPtr_end_void_2(&t, l); cLListIterator_cSkeletonDataBankEntryPtr_ctor(out, &t); }

static inline void SkBegin2(SkIt* out, SkList* l) { SkBegin(out, l); }
static inline void SkEnd2(SkIt* out, SkList* l) { SkEnd(out, l); }

void cSkeletonDataBank_Clear(SkList* l)
{
    SkIt it;
    SkIt end;
    SkEnt* e;
    SkNode* n;

    SkBegin2(&it, l);
    for (n = it.n; SkEnd2(&end, l), n != end.n; n = n->next) {
        e = n->e;
        AllocGuard g;
        if (e) {
            e->Destroy();
        }
        cMemMan_Deallocate(0, e, D_004BCCF8, 0x20);
    }
    SkIt r;
    SkIt first;
    SkIt last;
    last.n = &l->header;
    first.n = l->header.next;
    std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, l, &first, &last);
}
#undef std_list_cSkeletonDataBankEntryPtr_begin /* merge_units */
#undef cLListIterator_cSkeletonDataBankEntryPtr_ctor /* merge_units */
#undef std_list_cSkeletonDataBankEntryPtr_end_void_2 /* merge_units */
static inline void merge_flush_func_003AA320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA320 */

/* merge_units: begin func_003AA4E0 */
#pragma push /* merge_units */
void std_list_cSkeletonDataBankEntryPtr_end_void_2(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cSkeletonDataBankEntryPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cSkeletonDataBankEntryPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003AA4E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA4E0 */

/* merge_units: begin func_003AA510 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize an array of 0x1D0-byte elements: grow with fill, or erase the tail. */
struct Elem_3AA510 { unsigned char b[0x1D0]; };
struct Arr_3AA510;
extern "C" {
void std_vector_imp_cBone_insert(Arr_3AA510* a, Elem_3AA510* pos, unsigned int n, const Elem_3AA510& fill);
void std_vector_imp_cBone_erase(Arr_3AA510* a, Elem_3AA510* first, Elem_3AA510* last);
}
struct Arr_3AA510 {
    int pad0;
    unsigned int count;
    Elem_3AA510* data;
    unsigned int size() const { return count; }
    Elem_3AA510* begin() { return data; }
    Elem_3AA510* end() { return data + count; }
};

extern "C" void std_vector_imp_cBone_resize(Arr_3AA510* a, unsigned int n, const Elem_3AA510& fill)
{
    if (a->size() < n)
        std_vector_imp_cBone_insert(a, a->end(), n - a->size(), fill);
    else if (n < a->size())
        std_vector_imp_cBone_erase(a, a->begin() + n, a->end());
}
static inline void merge_flush_func_003AA510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA510 */

/* merge_units: begin func_003AA5B0 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } D6Scale;
typedef struct { int unk0; unsigned int count; D6Scale* data; } D6Scales;
extern void std_vector_imp_cBoneScale_insert(D6Scales* s, D6Scale* at, unsigned int n, int v);
extern void std_vector_imp_cBoneScale_erase(D6Scales* s, D6Scale* from, D6Scale* to, int v);
#pragma opt_common_subs off
void std_vector_imp_cBoneScale_resize(D6Scales* s, unsigned int n, int v)
{
    unsigned int c = s->count;
    D6Scale* d;
    if (c < n) {
        std_vector_imp_cBoneScale_insert(s, &s->data[s->count], n - c, v);
    } else if (n < c) {
        d = s->data;
        std_vector_imp_cBoneScale_erase(s, &d[n], &d[s->count], v);
    }
}
#pragma opt_common_subs reset
static inline void merge_flush_func_003AA5B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AA5B0 */
