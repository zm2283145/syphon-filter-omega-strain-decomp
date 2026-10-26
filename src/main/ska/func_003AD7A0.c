#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h" /* ALLOC_GUARD_DTOR: discard the out-of-line copy of the empty dtor */

/* AnimCtl_Update: updates every motion group of the controller's deque, evaluates the transition
 * chain between begin and end, runs the transitions, then advances every group. Iterator idiom of
 * src/main/ska/ska_3ABB10.c (MotionGraph_ClearActive). */
struct Ring { int** cur; int** begin; int** x8; int** end; };
struct DqIt {
    Ring ring; char* elem; char* bend;
    DqIt() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~DqIt() {}
    DqIt& operator=(const DqIt& o) {
        ring.cur = o.ring.cur; ring.begin = o.ring.begin; ring.x8 = o.ring.x8; ring.end = o.ring.end;
        elem = o.elem; bend = o.bend;
        return *this;
    }
    bool Ne(char* p) const { return !(elem == p); }
    DqIt& operator++() {
        if ((elem += 0xF8) == bend) {
            if (++ring.cur == ring.end) ring.cur = ring.begin;
            elem = (char*)*ring.cur;
            bend = elem + 0x7C0;
        }
        return *this;
    }
};
struct BlockArray { int cap; int size; int start; int** data; int first; int count; };
struct SkaWords6 { int w[6]; };
struct AnimGroup;
struct AnimCtx;
extern "C" void AnimGroup_Update(AnimGroup* g, AnimCtx* ctx);
struct AnimCtl { char pad0[4]; unsigned char busy; char pad5[0x13]; BlockArray arr; };
extern "C" {
void std_deque_deleter_common_cSkaSystem_Request_make_iterator(DqIt* out, BlockArray* a, int n);
void cSkaPlaybackList_StartOfFrameUpdate(void* g);
void std_deque_cSkaSystem_Request_rend(SkaWords6* self, BlockArray* a);
SkaWords6* cDequeue_cSkaSystem_Request_ReverseIterator_ctor(SkaWords6* dst, SkaWords6* src);
void std_deque_cSkaSystem_Request_rbegin(SkaWords6* self, BlockArray* a);
void AnimCtl_Evaluate(void* a0, void* a1, SkaWords6* q, SkaWords6* req, unsigned char flag, float w, float t);
void AnimCtl_UpdateTransitions(AnimCtl* c, float t);
void AnimCtl_Update(AnimCtl* c, void* m, float dt);
}

extern "C" void AnimCtl_Update(AnimCtl* c, void* m, float dt)
{
    DqIt it;
    SkaWords6 fin;
    SkaWords6 beg;
    DqIt it2;
    DqIt b;
    DqIt r;
    DqIt b2;
    DqIt r2;
    SkaWords6 t1;
    SkaWords6 t2;
    char* e;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&b, &c->arr, 0);
    it = b;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&r, &c->arr, c->arr.count);
    e = r.elem;
    while (it.Ne(e)) {
        cSkaPlaybackList_StartOfFrameUpdate(it.elem + 0xE8);
        ++it;
    }
    c->busy = 1;
    std_deque_cSkaSystem_Request_rbegin(&t1, &c->arr);
    cDequeue_cSkaSystem_Request_ReverseIterator_ctor(&fin, &t1);
    std_deque_cSkaSystem_Request_rend(&t2, &c->arr);
    cDequeue_cSkaSystem_Request_ReverseIterator_ctor(&beg, &t2);
    AnimCtl_Evaluate(c, m, &fin, &beg, 0, 1.0f, dt);
    AnimCtl_UpdateTransitions(c, dt);
    c->busy = 0;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&b2, &c->arr, 0);
    it2 = b2;
    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&r2, &c->arr, c->arr.count);
    e = r2.elem;
    while (it2.Ne(e)) {
        AnimGroup_Update((AnimGroup*)(it2.elem + 0xE8), (AnimCtx*)m);
        ++it2;
    }
}

/* AnimGroup_Update: pushes the group's time scale, then advances the phase of every active
 * contribution (wrapping or clamping at 1) and samples each of its clips. */
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
    float f2C;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
    unsigned char f33;
} Contrib;
typedef struct LNode { struct LNode* prev; struct LNode* next; Contrib* c; } LNode;
typedef struct { LNode* p; } LIt;
struct AnimGroup { int pad[3]; float unkC; };
struct AnimCtx { int count; float vals[4]; int pad14[2]; float scale; };
/* quadword copy: lq/sq has no C spelling */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
} __attribute__((aligned(16)));
extern "C" {
Raw List_Begin(AnimGroup* g);
void std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(LIt* out, const Raw& r);
Raw std_list_cSkaPlaybackGroupPtr_end(AnimGroup* g);
void cLListIterator_cSkaPlaybackGroupPtr_ctor(LIt* out, const Raw& r);
float cSkaPlaybackItem_GetSummedWeight(int c);
void cArray_cSkaPlaybackItem_Begin(VIt* out, IntVec* v);
void cArray_cSkaPlaybackItem_End(VIt* out, IntVec* v);
int cArray_cSkaPlaybackItem_Iterator_opNe(VIt* a, VIt* b);
int cArray_cSkaPlaybackItem_Iterator_opArrow(VIt* a);
void cArray_cSkaPlaybackItem_Iterator_opInc(VIt* a);
int cSkaPlaybackItem_GetAnimation(int c);
V cSkaPlaybackItem_GetSummedAndNormalizedOffsetRootRotation(int o);
void AnimContext_PushTime(AnimCtx* s, float t);
void AnimGroup_ResetInactive(Contrib* c);
float AnimPhase_GetCurrent(int* p);
void AnimPhase_SetPrevious(int* p, float v);
void AnimPhase_SetCurrent(int* p, float t);
float FloatStack_Top(AnimCtx* s);
void AnimTime_Pop(AnimCtx* s);
void SkaClip_SampleFrames(int clip, Contrib* c, float w, const V& q, AnimCtx* ctx);
void AnimGroup_Update(AnimGroup* g, AnimCtx* ctx);
}

static inline void LBegin(LIt* o, AnimGroup* g) { std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(o, List_Begin(g)); }
static inline void LEnd0(LIt* o, AnimGroup* g) { cLListIterator_cSkaPlaybackGroupPtr_ctor(o, std_list_cSkaPlaybackGroupPtr_end(g)); }
static inline void LEnd(LIt* o, AnimGroup* g) { LEnd0(o, g); }
/* FloatStack_Top; the volatile read keeps this count load separate from Push's (retail loads
 * the count twice: once for the top value, once for the push test and index). */
static inline float Top(AnimCtx* s) { float* p = &s->vals[*(volatile int*)&s->count - 1]; return *p; }
/* AnimContext_PushTime, inlined. */
static inline void Push(AnimCtx* s, float t)
{
    if ((unsigned int)s->count < 4) {
        s->vals[s->count] = t;
        s->count = s->count + 1;
    }
}

static inline void SampleClips(Contrib* c, AnimCtx* ctx)
{
    VIt vi;
    VIt ve;
    cArray_cSkaPlaybackItem_Begin(&vi, &c->vec);
    cArray_cSkaPlaybackItem_End(&ve, &c->vec);
    while (cArray_cSkaPlaybackItem_Iterator_opNe(&vi, &ve)) {
        int clip = cSkaPlaybackItem_GetAnimation(cArray_cSkaPlaybackItem_Iterator_opArrow(&vi));
        float w = cSkaPlaybackItem_GetSummedWeight(cArray_cSkaPlaybackItem_Iterator_opArrow(&vi));
        SkaClip_SampleFrames(clip, c, w, cSkaPlaybackItem_GetSummedAndNormalizedOffsetRootRotation(cArray_cSkaPlaybackItem_Iterator_opArrow(&vi)), ctx);
        cArray_cSkaPlaybackItem_Iterator_opInc(&vi);
    }
}

/* the inline returns leave retail's padding nops and jump to the join (see Wrap) */
static inline float Rate(Contrib* c) { if (c->sum != 0.0f) return c->wsum / c->sum; return 0.0f; }
static inline float Wrap(Contrib* c, float next, float cur, float* d)
{
    if (!(next < 1.0f)) {
        if (c->f32) {
            do {
                next -= 1.0f;
            } while (next >= 1.0f);
        } else {
            *d = 1.0f - cur;
            c->f30 = 1;
            next = 1.0f;
        }
        c->f31 = 1;
        return next;
    }
    return next;
}
extern "C" void AnimGroup_Update(AnimGroup* g, AnimCtx* ctx)
{
    Contrib* c;
    LNode* n;
    LIt end;
    LIt it;
    { float v = Top(ctx); Push(ctx, v * ctx->scale); }
    LBegin(&it, g);
    for (n = it.p; LEnd(&end, g), n != end.p; n = n->next) {
        c = n->c;
        if (c->f33) AnimContext_PushTime(ctx, 0.0f);
        if (!c->active) {
            AnimGroup_ResetInactive(c);
        } else {
            float cur = AnimPhase_GetCurrent(c->f20);
            float r;
            float d;
            float next;
            AnimPhase_SetPrevious(c->f20, cur);
            r = Rate(c);
            if (r != 0.0f) d = FloatStack_Top(ctx) / r;
            else d = c->f32 ? 0.0f : 1.0f;
            next = Wrap(c, cur + d, cur, &d);
            c->f2C = d;
            AnimPhase_SetCurrent(c->f20, next);
            SampleClips(c, ctx);
        }
        if (c->f33) AnimTime_Pop(ctx);
    }
    g->unkC = 0;
    if (ctx->count) ctx->count--;
}
