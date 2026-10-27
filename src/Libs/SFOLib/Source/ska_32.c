/*
 * main/ska: range (2 files, 003B0CB0-003B0D00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_003B0CB0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaPlaybackItem_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_003B0CB0 */

/* merge_units: begin func_003B0D00 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { int w; } Clip;
typedef struct { int cap; int count; int* data; } IntVec;
typedef struct { int* p; } VIt;
typedef struct { int w; } Raw;
typedef struct Contrib {
    int id;
    IntVec vec;
    int pad10;
    unsigned char active;
    char pad15[3];
    float sum;
    float wsum;
    int f20[3];
    int f2C;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
    unsigned char f33;
} Contrib;
typedef struct LNode { struct LNode* prev; struct LNode* next; Contrib* c; } LNode;
typedef struct { LNode* p; } LIt;
typedef struct { int pad[3]; float unkC; } AnimGroup;

extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
extern char D_004BCFE8[];
extern char D_004BCFF0[];
Raw std_list_deleter_voidPtr_begin_void(AnimGroup* g);
void std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(LIt* out, const Raw& r);
Raw std_list_cSkaPlaybackGroupPtr_end(AnimGroup* g);
void cLListIterator_cSkaPlaybackGroupPtr_ctor(LIt* out, const Raw& r);
float cSkaPlaybackItem_GetSummedWeight(Clip* c);
void cArray_cSkaPlaybackItem_Begin(VIt* out, IntVec* v);
void cArray_cSkaPlaybackItem_End(VIt* out, IntVec* v);
int cArray_cSkaPlaybackItem_Iterator_opNe(VIt* a, VIt* b);
int cArray_cSkaPlaybackItem_Iterator_opArrow(VIt* a);
void cArray_cSkaPlaybackItem_Iterator_opInc(VIt* a);
int cSkaPlaybackItem_HasSameAnimation(int e, Clip* c);
void cSkaPlaybackItem_Accumulate(int e, Clip* c);
void cArray_cSkaPlaybackItem_PushBackActual(IntVec* v, Clip* c);
int cSkaPlaybackItem_GetAnimation(Clip* c);
int cSkaAnim_IsLooping(int x);
int cArrayCapacity_ctor(Raw* out, int n);
void cArray_cSkaPlaybackItem_ctor(IntVec* v, int a, int n);
void cSkaPlaybackGroup_cPlaybackPosWithHistory_ctor(float t, int* p);
void cSkaPlaybackGroup_Add(Contrib* c, Clip* clip, float w);
void std_list_cSkaPlaybackGroupPtr_push_back(AnimGroup* g, Contrib** c);
}

static inline void Contrib_Add(Contrib* c, float weight, Clip* clip)
{
    float w = cSkaPlaybackItem_GetSummedWeight(clip);
    bool found;
    VIt it;
    VIt end;
    c->active = 1;
    found = false;
    c->sum += w;
    c->wsum += weight * w;
    cArray_cSkaPlaybackItem_Begin(&it, &c->vec);
    cArray_cSkaPlaybackItem_End(&end, &c->vec);
    while (cArray_cSkaPlaybackItem_Iterator_opNe(&it, &end)) {
        if (cSkaPlaybackItem_HasSameAnimation(cArray_cSkaPlaybackItem_Iterator_opArrow(&it), clip)) {
            cSkaPlaybackItem_Accumulate(cArray_cSkaPlaybackItem_Iterator_opArrow(&it), clip);
            found = true;
            break;
        }
        cArray_cSkaPlaybackItem_Iterator_opInc(&it);
    }
    if (!found) {
        cArray_cSkaPlaybackItem_PushBackActual(&c->vec, clip);
        c->f32 = c->f32 && cSkaAnim_IsLooping(cSkaPlaybackItem_GetAnimation(clip));
    }
}

static inline void Contrib_Init(Contrib* c, int id, float t)
{
    Raw r;
    c->id = id;
    cArray_cSkaPlaybackItem_ctor(&c->vec, cArrayCapacity_ctor(&r, 1), 1);
    c->sum = 0;
    c->wsum = 0;
    cSkaPlaybackGroup_cPlaybackPosWithHistory_ctor(t, c->f20);
    c->f2C = 0;
    c->f30 = 0;
    c->f31 = 0;
    c->f32 = 1;
    c->f33 = 0;
}

static inline void LBegin(LIt* o, AnimGroup* g) { std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(g)); }
static inline void LEnd(LIt* o, AnimGroup* g) { cLListIterator_cSkaPlaybackGroupPtr_ctor(o, std_list_cSkaPlaybackGroupPtr_end(g)); }
static inline Contrib* Contrib_New(char* file, int line)
{
    AllocGuard g;
    return (Contrib*)cMemMan_Allocate(0, sizeof(Contrib), file, line);
}

extern "C" void cSkaPlaybackList_Add(float weight, AnimGroup* g, Clip* clip, int id)
{
    Contrib* t1;
    Contrib* t2;
    LIt end1;
    LIt end2;
    if (id == -1) {
        LNode* n;
        LIt it1;
        LBegin(&it1, g);
        for (n = it1.p; LEnd(&end1, g), n != end1.p; n = n->next) {
            Contrib* c = n->c;
            bool m = c->vec.count == 1 && c->vec.data[0] == clip->w;
            if (m) {
                Contrib_Add(c, weight, clip);
                return;
            }
        }
        Contrib* c;
        { AllocGuard ag; c = (Contrib*)cMemMan_Allocate(0, sizeof(Contrib), D_004BCFF0, 0xFD); }
        if (c) {
            Contrib_Init(c, -1, g->unkC);
            cSkaPlaybackGroup_Add(c, clip, weight);
        }
        t1 = c;
        std_list_cSkaPlaybackGroupPtr_push_back(g, &t1);
    } else {
        LNode* n;
        LIt it2;
        LBegin(&it2, g);
        for (n = it2.p; LEnd(&end2, g), n != end2.p; n = n->next) {
            Contrib* c = n->c;
            if (id == c->id) {
                Contrib_Add(c, weight, clip);
                return;
            }
        }
        Contrib* c;
        { AllocGuard ag; c = (Contrib*)cMemMan_Allocate(0, sizeof(Contrib), D_004BCFE8, 0x112); }
        if (c) {
            Contrib_Init(c, id, g->unkC);
            cSkaPlaybackGroup_Add(c, clip, weight);
        }
        t2 = c;
        std_list_cSkaPlaybackGroupPtr_push_back(g, &t2);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B0D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B0D00 */
