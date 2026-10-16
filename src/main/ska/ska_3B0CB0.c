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
DEFINE_TRIVIAL_DTOR(func_003B0CB0)
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
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
extern char D_004BCFE8[];
extern char D_004BCFF0[];
Raw List_Begin(AnimGroup* g);
void func_00396B10(LIt* out, const Raw& r);
Raw func_00396B00(AnimGroup* g);
void func_00396AF0(LIt* out, const Raw& r);
float func_003ADEB0(Clip* c);
void func_003ADEF0(VIt* out, IntVec* v);
void func_003ADED0(VIt* out, IntVec* v);
int func_003ADDA0(VIt* a, VIt* b);
int func_003ADEC0(VIt* a);
void func_003ADDC0(VIt* a);
int func_003B1710(int e, Clip* c);
void func_003B15B0(int e, Clip* c);
void func_003B1590(IntVec* v, Clip* c);
int func_00198B20(Clip* c);
int func_003B1580(int x);
int func_00290BB0(Raw* out, int n);
void func_003B1510(IntVec* v, int a, int n);
void func_003B14E0(float t, int* p);
void func_003B1290(Contrib* c, Clip* clip, float w);
void func_003B1260(AnimGroup* g, Contrib** c);
}

static inline void Contrib_Add(Contrib* c, float weight, Clip* clip)
{
    float w = func_003ADEB0(clip);
    bool found;
    VIt it;
    VIt end;
    c->active = 1;
    found = false;
    c->sum += w;
    c->wsum += weight * w;
    func_003ADEF0(&it, &c->vec);
    func_003ADED0(&end, &c->vec);
    while (func_003ADDA0(&it, &end)) {
        if (func_003B1710(func_003ADEC0(&it), clip)) {
            func_003B15B0(func_003ADEC0(&it), clip);
            found = true;
            break;
        }
        func_003ADDC0(&it);
    }
    if (!found) {
        func_003B1590(&c->vec, clip);
        c->f32 = c->f32 && func_003B1580(func_00198B20(clip));
    }
}

static inline void Contrib_Init(Contrib* c, int id, float t)
{
    Raw r;
    c->id = id;
    func_003B1510(&c->vec, func_00290BB0(&r, 1), 1);
    c->sum = 0;
    c->wsum = 0;
    func_003B14E0(t, c->f20);
    c->f2C = 0;
    c->f30 = 0;
    c->f31 = 0;
    c->f32 = 1;
    c->f33 = 0;
}

static inline void LBegin(LIt* o, AnimGroup* g) { func_00396B10(o, List_Begin(g)); }
static inline void LEnd(LIt* o, AnimGroup* g) { func_00396AF0(o, func_00396B00(g)); }
static inline Contrib* Contrib_New(char* file, int line)
{
    AllocGuard g;
    return (Contrib*)Mem_Alloc(0, sizeof(Contrib), file, line);
}

extern "C" void AnimGroup_AddContribution(float weight, AnimGroup* g, Clip* clip, int id)
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
        { AllocGuard ag; c = (Contrib*)Mem_Alloc(0, sizeof(Contrib), D_004BCFF0, 0xFD); }
        if (c) {
            Contrib_Init(c, -1, g->unkC);
            func_003B1290(c, clip, weight);
        }
        t1 = c;
        func_003B1260(g, &t1);
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
        { AllocGuard ag; c = (Contrib*)Mem_Alloc(0, sizeof(Contrib), D_004BCFE8, 0x112); }
        if (c) {
            Contrib_Init(c, id, g->unkC);
            func_003B1290(c, clip, weight);
        }
        t2 = c;
        func_003B1260(g, &t2);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B0D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B0D00 */
