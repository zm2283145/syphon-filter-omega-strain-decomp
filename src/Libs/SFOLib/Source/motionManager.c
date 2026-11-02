/*
 * Libs/SFOLib/Source/motionManager: 2 files, 0040F3E0-0040F520
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F3E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct WObj {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C();
    virtual void v50(float dt);
    virtual void v54(float dt);
    char pad[0x8];
    int serial;
    char pad10[0x1C];
    bool f2C;
    bool f2D;
    bool f2E;
};
struct WHandle { WObj* obj; int serial; };
struct WNode { char pad[0x10]; WHandle h; };
struct WIt { WNode* n; WIt() {} };
extern "C" {
extern void* g_MotionManager;
#if 0 /* merge_units */
void Tree_Begin(WIt* out, void* tree);
#endif /* merge_units */
void Tree_Begin(Iter* out, Tree* t); /* merge_units */
#define Tree_Begin(a0, a1) (Tree_Begin((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
void Tree_End(WIt* out, void* tree);
#endif /* merge_units */
void Tree_End(Iter* out, Tree* t); /* merge_units */
#define Tree_End(a0, a1) (Tree_End((Iter *)(a0), (Tree *)(a1))) /* merge_units */

void std_red_black_tree_1_increment(WIt* it);
void World_ClearPending(void* tree);
}
static inline WObj* WHandle_Get(WHandle* h)
{
    bool isnull = !(bool)h->obj;
    return (isnull || h->obj->serial == h->serial) ? h->obj : 0;
}
static inline void WStep(WHandle* h, float dt)
{
    WObj* o = WHandle_Get(h);
    if (o) {
        o->v54(dt);
        bool act = o->f2D && o->f2C && !o->f2E;
        if (act)
            o->v50(dt);
    }
}
extern "C" void cMotionManager_NextFrame(float dt)
{
    WIt it;
    WIt end;
    {
        WIt tb;
        Tree_Begin(&tb, g_MotionManager);
        it = tb;
    }
    {
        WIt te;
        Tree_End(&te, g_MotionManager);
        end = te;
    }
    for (; (it.n == end.n) ^ 1; std_red_black_tree_1_increment(&it))
        WStep(&it.n->h, dt);
    World_ClearPending(g_MotionManager);
}
#undef Tree_Begin /* merge_units */
#undef Tree_End /* merge_units */
static inline void merge_flush_func_0040F3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040F3E0 */

/* merge_units: begin func_0040F520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

#if 0 /* merge_units */
extern Tree* g_MotionManager;
#endif /* merge_units */
#define g_MotionManager (*(Tree **)&g_MotionManager) /* merge_units */

#if 0 /* merge_units */
extern void World_ClearPending(Tree*);
#endif /* merge_units */
#define World_ClearPending(a0) (World_ClearPending((void *)(a0))) /* merge_units */


void Tree_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

void Tree_Begin(Iter* out, Tree* t) {
    out->p = t->leftmost;
}

/* Clears the global tree g_MotionManager if it exists. */
void cMotionManager_FlushUpdateList(void) {
    Tree* t = g_MotionManager;

    if (t != 0) {
        World_ClearPending(t);
    }
}
#undef g_MotionManager /* merge_units */
#undef World_ClearPending /* merge_units */
static inline void merge_flush_func_0040F520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040F520 */
