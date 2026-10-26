/*
 * main/skeleton: 5 files, 003AA230-003AA320
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
#pragma pop /* merge_units */
/* merge_units: end func_003AA230 */

/* merge_units: begin func_003AA240 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cSkeletonDataBankEntryPtr_end_void)
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

extern void Resource_Construct(LoadStream* s);
extern void Hog_Register(LoadStream* s, int name, int flags, int mode);
extern void Skel_ReadFile(int skel, int arg, int name, LoadStream* s);
extern void FileMan_Release(LoadStream* s, int flags);

/* Loads a skeleton through a temporary stream opened on `name`; returns 0. */
int Skel_Load(int skel, int arg, int name, int flags) {
    LoadStream stream;
    Resource_Construct(&stream);
    Hog_Register(&stream, name, flags, 0);
    Skel_ReadFile(skel, arg, name, &stream);
    FileMan_Release(&stream, -1);
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
extern void Mem_Free(int pool, void* p, char* file, int line);
}
struct SkEnt {
    char* name; int count; int a, b;
    void Destroy() {
        char* p = name;
        if (p) {
            AllocGuard g2;
            Mem_Free(0, p, D_004BCD50, 0x66);
        }
    }
};
typedef struct SkNode { struct SkNode* prev; struct SkNode* next; SkEnt* e; } SkNode;
typedef struct { SkNode* n; } SkIt;
typedef struct { int pad; SkNode header; } SkList;
extern "C" {
extern void std_list_cSkeletonDataBankEntryPtr_begin(SkIt* out, SkList* l);
extern SkIt* cLListIterator_cSkeletonDataBankEntryPtr_ctor(SkIt* dst, SkIt* src);
extern void std_list_cSkeletonDataBankEntryPtr_end_void_2(SkIt* out, SkList* l);
extern void ObjectList_EraseRange(SkIt* out, SkList* l, SkIt* first, SkIt* last);
void Skel_FreeAll(SkList* l);
}

static inline void SkBegin(SkIt* out, SkList* l) { SkIt b; std_list_cSkeletonDataBankEntryPtr_begin(&b, l); cLListIterator_cSkeletonDataBankEntryPtr_ctor(out, &b); }
static inline void SkEnd(SkIt* out, SkList* l) { SkIt t; std_list_cSkeletonDataBankEntryPtr_end_void_2(&t, l); cLListIterator_cSkeletonDataBankEntryPtr_ctor(out, &t); }

static inline void SkBegin2(SkIt* out, SkList* l) { SkBegin(out, l); }
static inline void SkEnd2(SkIt* out, SkList* l) { SkEnd(out, l); }

void Skel_FreeAll(SkList* l)
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
        Mem_Free(0, e, D_004BCCF8, 0x20);
    }
    SkIt r;
    SkIt first;
    SkIt last;
    last.n = &l->header;
    first.n = l->header.next;
    ObjectList_EraseRange(&r, l, &first, &last);
}
#pragma pop /* merge_units */
/* merge_units: end func_003AA320 */
