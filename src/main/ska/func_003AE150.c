#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
/* cSkaPlaybackList_StartOfFrameUpdate: drop the motion-group contributions that received no weight this frame, reset the rest */
typedef struct { char unused; } Alloc;
struct TaggedInt { Alloc alloc; int value; TaggedInt(const Alloc& a, int v) : alloc(a), value(v) {} };
typedef struct { int cap; int count; int* data; } IntVec;
typedef struct { int x0; int f4; unsigned char b8; char pad9[7]; __int128 v10; } Elem;
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
/* one-member union: memory-resident iterator like retail; the user operator= keeps the separate reload of it for cur */
union LIt { LNode* p; LIt& operator=(const LIt& o) { p = o.p; return *this; } };
typedef struct { int w; } Raw;
typedef struct { int pad[3]; float unkC; } AnimGroup;
extern "C" {
Raw List_Begin(AnimGroup* g);
void std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(LIt* out, const Raw& r);
Raw std_list_cSkaPlaybackGroupPtr_end(AnimGroup* g);
void cLListIterator_cSkaPlaybackGroupPtr_ctor(LIt* out, const Raw& r);
Elem* std_vector_cSkaPlaybackItem_opIndex(IntVec* v, int i);
void MotionGroup_ClearContributions(IntVec* v);
void func_00396C10(IntVec* v, int f);
void Mem_Free(int pool, void* p, char* file, int line);
void ActiveList_EraseMatching(void* self, TaggedInt arg);
extern char D_004BCFF8[];
void cSkaPlaybackList_StartOfFrameUpdate(AnimGroup* g);
}
static inline void EraseValue(void* self, int value)
{
    Alloc alloc;
    TaggedInt t(alloc, value);
    /* the int round trip keeps the argument's address in a register: retail passes it with ldl/ldr */
    ActiveList_EraseMatching(self, *(TaggedInt*)(int)&t);
}
static inline void LBegin0(LIt* o, AnimGroup* g) { std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(o, List_Begin(g)); }
/* the extra inline level orders the begin/end Raw temporaries below the erase tag like retail */
static inline void LBegin(LIt* o, AnimGroup* g) { LBegin0(o, g); }
static inline void LEnd0(LIt* o, AnimGroup* g) { cLListIterator_cSkaPlaybackGroupPtr_ctor(o, std_list_cSkaPlaybackGroupPtr_end(g)); }
static inline void LEnd(LIt* o, AnimGroup* g) { LEnd0(o, g); }
static inline void VZero(void* d) { asm { .set reorder; sq zero, 0(d) } }
static inline unsigned char Expire(Contrib* c)
{
    if (c->id == -1) {
        Elem* e;
        if (!c->active) return true;
        e = std_vector_cSkaPlaybackItem_opIndex(&c->vec, 0);
        e->f4 = 0;
        e->b8 = 0;
        VZero(&e->v10);
    } else {
        if (!c->active && !c->f32) return true;
        MotionGroup_ClearContributions(&c->vec);
    }
    c->active = 0;
    c->sum = 0.0f;
    c->wsum = 0.0f;
    return false;
}
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_loop_invariants off
void cSkaPlaybackList_StartOfFrameUpdate(AnimGroup* g)
{
    LIt it;
    LIt cur;
    LIt end;
    { LIt t; LBegin(&t, g); it.p = t.p; }
    while (LEnd(&end, g), it.p != end.p) {
        cur = it;
        it.p = it.p->next;
        if (Expire(cur.p->c) != 0) {
            Contrib* d = cur.p->c;
            {
                AllocGuard ag;
                if (d) {
                    IntVec* v = &d->vec;
                    if (v && v && v) func_00396C10(v, 0); /* triple null test of the nested inline member dtors, as in func_00396910.c */
                }
                Mem_Free(0, d, D_004BCFF8, 0xE1);
            }
            EraseValue(g, (int)&cur.p->c);
        }
    }
}
