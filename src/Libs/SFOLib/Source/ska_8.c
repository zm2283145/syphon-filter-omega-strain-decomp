/*
 * Libs/SFOLib/Source/ska: 19 files, 003ADD80-003AE740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ADD80 */
#pragma push /* merge_units */
#include "types.h"

void cSkaParams_PopTimeStep(int a0) {
    int v1;
    int cond;

    v1 = *(int*)(char*)a0;
    cond = v1 == 0;
    if (cond) goto L003ADD98;
    v1 = v1 + -1;
    *(int*)(char*)a0 = v1;
L003ADD98:;
    goto ret;
ret:;
}
static inline void merge_flush_func_003ADD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADD80 */

/* merge_units: begin func_003ADDA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

/* Iterator inequality. */
int cArray_cSkaPlaybackItem_Iterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Advance an iterator over 32-byte elements. */
Iter16* cArray_cSkaPlaybackItem_Iterator_opInc(Iter16* it) {
    it->p = it->p + 32;
    return it;
}
static inline void merge_flush_func_003ADDA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADDA0 */

/* merge_units: begin func_003ADDE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Obj3ADDE0 { char p0[8]; unsigned char b8; char p9[7]; V v10; };
static inline int IsZero(const V* v)
{
    int k, fl;
    unsigned char r = 0;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void NormQ(V* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyzw vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddaz.w ACC, vf0, vf2z
        vmaddw.w vf3, vf0, vf2w
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyzw vf4, vf1, Q
        sqc2 vf4, 0x0(a)
    }
}
static inline void Unit(V* a) {
    asm { sqc2 vf0, 0x0(a) }
}
extern "C" V cSkaPlaybackItem_GetSummedAndNormalizedOffsetRootRotation(Obj3ADDE0* o)
{
    if (o->b8) return o->v10;
    if (!IsZero(&o->v10)) {
        V t = o->v10;
        V* p = &t;
        NormQ(p);
        return *p;
    }
    V r;
    Unit(&r);
    return r;
}
static inline void merge_flush_func_003ADDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADDE0 */

/* merge_units: begin func_003ADEB0 */
#pragma push /* merge_units */
float cSkaPlaybackItem_GetSummedWeight(char* self) {
    return *(float*)(self + 4);
}

int cArray_cSkaPlaybackItem_Iterator_opArrow(char* self) {
    return *(int*)(self + 0);
}

/* End iterator of an array of 32-byte elements. */
void cArray_cSkaPlaybackItem_End(Iter16* out, SkaVec* v) {
    out->p = v->data + (v->count << 5);
}

void cArray_cSkaPlaybackItem_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003ADEB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADEB0 */

/* merge_units: begin func_003ADF00 */
#pragma push /* merge_units */
typedef struct {
    float start;
    float cur;
    unsigned char clamp01;
} AnimPhase_3ADF00;
static inline float clamp_3ADF00(float x, float lo, float hi) {
    asm {
        max.s lo, x, lo
        min.s lo, lo, hi
    }
    return lo;
}
void cSkaPlaybackGroup_cPlaybackPosWithHistory_SetCurr(AnimPhase_3ADF00* p, float t) {
    p->cur = t;
    if (p->clamp01)
        p->cur = clamp_3ADF00(p->cur, 0.0f, 1.0f);
    else
        p->cur = clamp_3ADF00(p->cur, p->start, 1.0f);
}
static inline void merge_flush_func_003ADF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADF00 */

/* merge_units: begin func_003ADF60 */
#pragma push /* merge_units */
float cSkaParams_TimeStep(FStack* s) {
    float* p = &s->vals[s->count - 1];
    return *p;
}
static inline void merge_flush_func_003ADF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADF60 */

/* merge_units: begin func_003ADF80 */
#pragma push /* merge_units */
typedef struct { float prev; float max; unsigned char unitBounds; } D6Phase;
static inline float d6_clamp(float x, float lo, float hi) { asm { max.s lo, x, lo; min.s lo, lo, hi } return lo; }
static inline float d6_clampr(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
void cSkaPlaybackGroup_cPlaybackPosWithHistory_SetPrev(D6Phase* p, float v)
{
    p->prev = v;
    if (p->unitBounds) {
        p->prev = d6_clamp(p->prev, 0.0f, 1.0f);
    } else {
        p->prev = d6_clampr(p->prev, 0.0f, p->max);
    }
}
static inline void merge_flush_func_003ADF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADF80 */

/* merge_units: begin func_003ADFE0 */
#pragma push /* merge_units */
float cSkaPlaybackGroup_cPlaybackPosWithHistory_Curr(char* self) {
    return *(float*)(self + 4);
}
static inline void merge_flush_func_003ADFE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADFE0 */

/* merge_units: begin func_003ADFF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; float a; float b; int pad28; int c; unsigned char d; unsigned char e; } XDFF0;
static inline float clamp_DFF0(float x, float lo, float hi) { asm { max.s lo, x, lo
 min.s lo, lo, hi } return lo; }
#pragma opt_propagation off
void cSkaPlaybackGroup_Rewind(XDFF0* t) {
    float v = clamp_DFF0(0.0f, 0.0f, 1.0f);
    t->b = v;
    t->a = v;
    t->c = 0;
    t->d = 0;
    t->e = 0;
}
static inline void merge_flush_func_003ADFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ADFF0 */

/* merge_units: begin func_003AE020 */
#pragma push /* merge_units */
extern void std_deque_deleter_common_cSkaSystem_Request_make_iterator(SkaWords6* out, int a1, int a2);

/* Push a time value if the four-slot stack is not full. */
void cSkaParams_PushTimeStep(SkaTimeStack* s, float t) {
    if ((unsigned int)s->count < 4) {
        s->times[s->count] = t;
        s->count = s->count + 1;
    }
}

/* Fill a six-word value from std_deque_deleter_common_cSkaSystem_Request_make_iterator with a zero third argument. */
void std_deque_cSkaSystem_Request_rend(SkaWords6* self, int a1) {
    SkaWords6 tmp;
    int w;

    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&tmp, a1, 0);
    w = tmp.w[0];
    self->w[0] = w;
    w = tmp.w[1];
    self->w[1] = w;
    w = tmp.w[2];
    self->w[2] = w;
    w = tmp.w[3];
    self->w[3] = w;
    w = tmp.w[4];
    self->w[4] = w;
    w = tmp.w[5];
    self->w[5] = w;
}

/* Six-word copy assignment. */
SkaWords6* cDequeue_cSkaSystem_Request_ReverseIterator_ctor(SkaWords6* dst, SkaWords6* src) {
    dst->w[0] = src->w[0];
    dst->w[1] = src->w[1];
    dst->w[2] = src->w[2];
    dst->w[3] = src->w[3];
    dst->w[4] = src->w[4];
    dst->w[5] = src->w[5];
    return dst;
}

/* Fill a six-word value from std_deque_deleter_common_cSkaSystem_Request_make_iterator, passing src and its word +0x14. */
void std_deque_cSkaSystem_Request_rbegin(SkaWords6* self, SkaWords6* src) {
    SkaWords6 tmp;
    int w;

    std_deque_deleter_common_cSkaSystem_Request_make_iterator(&tmp, (int)src, src->w[5]);
    w = tmp.w[0];
    self->w[0] = w;
    w = tmp.w[1];
    self->w[1] = w;
    w = tmp.w[2];
    self->w[2] = w;
    w = tmp.w[3];
    self->w[3] = w;
    w = tmp.w[4];
    self->w[4] = w;
    w = tmp.w[5];
    self->w[5] = w;
}
static inline void merge_flush_func_003AE020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE020 */

/* merge_units: begin func_003AE150 */
#pragma push /* merge_units */
#pragma cplusplus on
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
Raw std_list_deleter_voidPtr_begin_void(AnimGroup* g);
void std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(LIt* out, const Raw& r);
Raw std_list_cSkaPlaybackGroupPtr_end(AnimGroup* g);
void cLListIterator_cSkaPlaybackGroupPtr_ctor(LIt* out, const Raw& r);
#if 0 /* merge_units */
Elem* std_vector_cSkaPlaybackItem_opIndex(IntVec* v, int i);
#endif /* merge_units */
char* std_vector_cSkaPlaybackItem_opIndex(SkaVec* v, int i); /* merge_units */
#define std_vector_cSkaPlaybackItem_opIndex(a0, a1) ((Elem *)std_vector_cSkaPlaybackItem_opIndex((SkaVec *)(a0), (a1))) /* merge_units */

void std_vector_deleter_cSkaPlaybackItem_clear(IntVec* v);
void func_00396C10(IntVec* v, int f);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_list_imp_voidPtr_remove_if(void* self, TaggedInt arg);
extern char D_004BCFF8[];
void cSkaPlaybackList_StartOfFrameUpdate(AnimGroup* g);
}
static inline void EraseValue(void* self, int value)
{
    Alloc alloc;
    TaggedInt t(alloc, value);
    /* the int round trip keeps the argument's address in a register: retail passes it with ldl/ldr */
    std_list_imp_voidPtr_remove_if(self, *(TaggedInt*)(int)&t);
}
static inline void LBegin0(LIt* o, AnimGroup* g) { std_list_cSkaPlaybackGroupPtr_generic_iterator_ctor(o, std_list_deleter_voidPtr_begin_void(g)); }
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
        std_vector_deleter_cSkaPlaybackItem_clear(&c->vec);
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
                cMemMan_Deallocate(0, d, D_004BCFF8, 0xE1);
            }
            EraseValue(g, (int)&cur.p->c);
        }
    }
}
#undef std_vector_cSkaPlaybackItem_opIndex /* merge_units */
static inline void merge_flush_func_003AE150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE150 */

/* merge_units: begin func_003AE340 */
#pragma push /* merge_units */
/* Address of element i in an array of 32-byte elements. */
char* std_vector_cSkaPlaybackItem_opIndex(SkaVec* v, int i) {
    return v->data + (i << 5);
}
static inline void merge_flush_func_003AE340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE340 */

/* merge_units: begin func_003AE350 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V_003AE350 {
    float x, y, z, w;
    V_003AE350() {}
    V_003AE350(const V_003AE350& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); void* xx = this; }
    V_003AE350& operator=(const V_003AE350& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    static V_003AE350 Unit() { V_003AE350 r; V_003AE350* d = &r; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(d) : "memory"); return r; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V_003AE350 operator*(const V_003AE350& b) const {
        V_003AE350 c; const V_003AE350* r = &b; const V_003AE350* l = this; V_003AE350* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx { char pad0[0x14]; int n; void* items[1]; };
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V_003AE350& q, Ctx* c);
    void Run(float t, const V_003AE350& q, Ctx* c) { const void* xx = &q; Eval(t, q, c); }
};
static inline float MinA(float a, float b) { asm { min.s b, a, b } return b; }
static inline float MinT(const float& a, const float& b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float MinF(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float ClampR(float x, float& lo, float hi) { __asm__ volatile("max.s %0, %1, %0; min.s %0, %0, %2" : "+f"(lo) : "f"(x), "f"(hi)); return lo; }
static inline float Clamp(float x, float lo, float hi) { __asm__ volatile("max.s %0, %1, %0; min.s %0, %0, %2" : "+f"(lo) : "f"(x), "f"(hi)); return lo; }

struct Phase {
    float dur, fade, rate, padC, cur;
    float Left() const { return MaxF(0.0f, 1.0f - cur); }
};
struct Blend { int pad0; EvNode* node; Phase ph; char pad1C[0xC4]; float limit; float time; };

extern "C" void cSkaSystem_Request_Process(Blend* self, bool* outA, float* outRem, bool* done, Ctx* ctx, bool* hold, float t, float dt);

void cSkaSystem_Request_Process(Blend* self, bool* outA, float* outRem, bool* done, Ctx* ctx, bool* hold, float t, float dt)
{
    *done = false;
    if (!*hold) {
        float one = 1.0f; float old = self->ph.cur;
        float v = MinA(one, old + dt * self->ph.rate);
        *done = old < 1.0f && v >= 1.0f;
        self->ph.cur = v;
    }
    float p = self->ph.cur;
    float z; float p2 = p * p;
    float x = 3.0f * p2 - 2.0f * (p * p2); z = 0.0f; float zc = z; float w = t * ClampR(x, z, 1.0f);
    if (zc != w) {
        if (ctx->n == 0) { ctx->items[ctx->n] = self; ctx->n++; }
        self->node->Run(w, V_003AE350::Unit(), ctx);
        if (ctx->n) ctx->n--;
    }
    *outRem = MaxF(0.0f, t - w);
    *outA = false;
    if (!*hold) {
        Phase* ph = &self->ph;
        float a; float l = ph->Left(); a = l * ph->dur; if (a < 0.5f * (ph->dur - ph->fade)) *outA = true;
        ph = &self->ph;
        float b; float l2 = ph->Left(); b = l2 * ph->dur; if (!(b <= 0.5f * (ph->dur + ph->fade))) *hold = true;
    }
    self->time += dt;
    if (self->limit != -1.0f) self->time = MinT(self->limit, self->time);
}
static inline void merge_flush_func_003AE350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE350 */

/* merge_units: begin func_003AE5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct C6Ent_3AE5E0 { int key; int pad[3]; char value[0x170]; };
struct C6Coll_3AE5E0 { int pad0; int count; };
#if 0 /* merge_units */
extern "C" C6Ent_3AE5E0** std_vector_deleter_cSkaAnimAnchorListEntry_data(C6Coll_3AE5E0*);
#endif /* merge_units */
extern "C" void* std_vector_deleter_cSkaAnimAnchorListEntry_data(void*); /* merge_units */
#define std_vector_deleter_cSkaAnimAnchorListEntry_data(a0) ((C6Ent_3AE5E0 * *)std_vector_deleter_cSkaAnimAnchorListEntry_data((void *)(a0))) /* merge_units */

extern "C" char D_005429F0[];
static inline int C6Eq(C6Ent_3AE5E0* a, C6Ent_3AE5E0* b) { return a == b; }
extern "C" void* RootCollection_FindByKey(C6Coll_3AE5E0* self, int* key) {
    C6Ent_3AE5E0* it = *std_vector_deleter_cSkaAnimAnchorListEntry_data(self);
    C6Ent_3AE5E0* end = *std_vector_deleter_cSkaAnimAnchorListEntry_data(self) + self->count;
    for (; C6Eq(it, end) ^ 1; it++) {
        if (it->key == *key) return it->value;
    }
    return D_005429F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AE5E0(void) {}
#undef std_vector_deleter_cSkaAnimAnchorListEntry_data /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE5E0 */

/* merge_units: begin func_003AE690 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off

#if 0 /* merge_units */
extern "C" C6Ent_3AE5E0** func_003AE740(C6Coll_3AE5E0*);
#endif /* merge_units */
extern "C" void* func_003AE740(char* self); /* merge_units */
#define func_003AE740(a0) ((C6Ent_3AE5E0 * *)func_003AE740((char *)(a0))) /* merge_units */

extern "C" void* cSkaAnimAnchorList_Find(C6Coll_3AE5E0* self, int* key) {
    C6Ent_3AE5E0* it = *func_003AE740(self);
    C6Ent_3AE5E0* end = *func_003AE740(self) + self->count;
    for (; C6Eq(it, end) ^ 1; it++) {
        if (it->key == *key) return it->value;
    }
    return D_005429F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AE690(void) {}
#undef func_003AE740 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE690 */

/* merge_units: begin func_003AE740 */
#pragma push /* merge_units */
void* func_003AE740(char* self) {
    return self + 8;
}
static inline void merge_flush_func_003AE740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE740 */

/* merge_units: begin func_003AE750 */
#pragma push /* merge_units */
/* cSkaAnimAnchorList_Update (proto cSkaAnimAnchorList::Update): rebuilds the skeleton target as the
 * hemisphere-aligned sum of every anchor's weighted target transform, then the blend of the anchors'
 * world transforms weighted by each anchor's weight; both rotations are normalised (identity when zero)
 * and the positions get w = 1. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct cVector {
    float x, y, z, w;
    cVector() {}
    /* quad copy (lq/sq; C has no 128-bit move) */
    cVector(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
    /* VU0 add in place */
    cVector& operator+=(const cVector& o) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
    /* 4D dot product through VU0 (sum in vf4w, moved to an FPR) */
    float Dot(const cVector& o) const
    {
        float ret = 0.0f;
        int t;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddaz.w $ACC, $vf0, $vf3z; vmaddw.w $vf4, $vf0, $vf3w; qmfc2 %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "=f"(ret), "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return ret;
    }
    /* q = -q (ACC = 0, vf1 = ACC - vf1 * 1) */
    void Negate() { cVector* d = this; cVector* s = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(s), "r"(d) : "memory"); }
    void Normalize() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyzw $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddaz.w $ACC, $vf0, $vf2z; vmaddw.w $vf3, $vf0, $vf2w; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyzw $vf4, $vf1, $Q; sqc2 $vf4, 0x0(%0)" : : "r"(this) : "memory"); }
    void SetIdentity() { __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(this) : "memory"); }
    void SetW(float f) { cVector* p = this; p->w = f; }
    void Zero() { __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct cQuaternion : cVector {
    /* quad copy; xx is dead on purpose (retail keeps the extra addiu, and reuses it for a following Dot) */
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { const cVector* s = &o; cVector* xx = this; __int128 q; cVector* d = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
};
/* VU0 scale (vmulx) into a temporary, returned by value (as the ska.cc siblings) */
static inline cQuaternion ScaleGQ(const cVector* v, float s)
{
    cQuaternion r; int t; cQuaternion* q = &r;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "=r"(t) : "r"(v), "r"(q), "f"(s) : "memory");
    return *q;
}
/* VU0 scale into a temporary, then copied out (the ska.cc ScaleTo form) */
static inline void ScaleTo(cVector* out, const cVector* v, float s)
{
    cVector r; int t; cVector* q = &r;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2 %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "=r"(t) : "r"(v), "r"(q), "f"(s) : "memory");
    { cVector* pd; __int128 t2; pd = out; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t2) : "r"(q)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t2), "r"(pd) : "memory"); }
}
/* VU0 all-components-zero test (status flags) */
static inline int IsZero_003AE750(const cVector* v)
{
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}

struct cQuatVec {
    cQuaternion rot;
    cVector pos;
    void Zero() { rot.Zero(); pos.Zero(); }
};
struct cSkaAnimAnchor_TreeNode;
struct cSkaAnimAnchor {
    char pad0[0xD0];
    float weight;
};
struct cSkaAnimAnchorListEntry {
    char name[0x10];
    cSkaAnimAnchor anchor;
    char pad[0x180 - 0x10 - sizeof(cSkaAnimAnchor)];
};
struct cSkaAnimAnchorList;
extern "C" {
#if 0 /* merge_units */
cSkaAnimAnchorListEntry** std_vector_deleter_cSkaAnimAnchorListEntry_data(cSkaAnimAnchorList* l);
#endif /* merge_units */
#define std_vector_deleter_cSkaAnimAnchorListEntry_data(a0) ((cSkaAnimAnchorListEntry * *)std_vector_deleter_cSkaAnimAnchorListEntry_data((void *)(a0))) /* merge_units */

unsigned char cSkaAnimAnchor_Update(cSkaAnimAnchor* a, cVector* rot, cVector* pos);
cQuatVec* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(cSkaAnimAnchor* a);
cVector* cQuatVec_Rotation(cQuatVec* q);
cVector* cQuatVec_Translation(cQuatVec* q);
void cSkaAnimAnchorList_Update(cSkaAnimAnchorList* self);
}
struct Iterator {
    cSkaAnimAnchorListEntry* p;
    explicit Iterator(cSkaAnimAnchorListEntry* e) { p = e; }
    Iterator(const Iterator& o) { p = o.p; }
    void operator++() { p++; }
    cSkaAnimAnchorListEntry* operator->() const { return p; }
};
inline bool operator==(const Iterator& a, const Iterator& b) { cSkaAnimAnchorListEntry* q = b.p; return a.p == q; }
inline bool operator!=(const Iterator& a, const Iterator& b) { return !(a == b); }
struct cSkaAnimAnchorList {
    int unk0;
    int count;
    char pad8[8];
    cQuatVec skeletonTarget;
    cQuatVec blendOfAnchorTransforms;
    Iterator begin() { Iterator it(*std_vector_deleter_cSkaAnimAnchorListEntry_data(this)); return it; }
    Iterator end() { Iterator it(*std_vector_deleter_cSkaAnimAnchorListEntry_data(this) + count); return it; }
};

void cSkaAnimAnchorList_Update(cSkaAnimAnchorList* self)
{
    cQuaternion prevTargetRot = self->skeletonTarget.rot;
    self->skeletonTarget.Zero();
    for (Iterator curr = self->begin(), end = self->end(); curr != end; ++curr) {
        cSkaAnimAnchor& anchor = curr->anchor;
        cQuaternion weightedSkeletonTargetRot;
        cVector weightedSkeletonTargetPos;
        if (cSkaAnimAnchor_Update(&anchor, &weightedSkeletonTargetRot, &weightedSkeletonTargetPos)) {
            if (weightedSkeletonTargetRot.Dot(prevTargetRot) < 0.0f)
                weightedSkeletonTargetRot.Negate();
            self->skeletonTarget.rot += weightedSkeletonTargetRot;
            self->skeletonTarget.pos += weightedSkeletonTargetPos;
        }
    }
    if (IsZero_003AE750(&self->skeletonTarget.rot))
        self->skeletonTarget.rot.SetIdentity();
    else
        self->skeletonTarget.rot.Normalize();
    self->skeletonTarget.pos.SetW(1.0f);

    cQuaternion prevBlendOfAnchorTransforms_Rotation = self->blendOfAnchorTransforms.rot;
    self->blendOfAnchorTransforms.Zero();
    for (Iterator curr = self->begin(), end = self->end(); curr != end; ++curr) {
        cSkaAnimAnchor& anchor = curr->anchor;
        if (anchor.weight > 0.0f) {
            cQuaternion weightedAnchorRot = ScaleGQ(cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&anchor)), anchor.weight);
            if (weightedAnchorRot.Dot(prevBlendOfAnchorTransforms_Rotation) < 0.0f)
                weightedAnchorRot.Negate();
            self->blendOfAnchorTransforms.rot += weightedAnchorRot;
            cVector weightedAnchorTrans;
            ScaleTo(&weightedAnchorTrans, cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(&anchor)), anchor.weight);
            { cVector* pos = &self->blendOfAnchorTransforms.pos; *pos += weightedAnchorTrans; }
        }
    }
    if (IsZero_003AE750(&self->blendOfAnchorTransforms.rot))
        self->blendOfAnchorTransforms.rot.SetIdentity();
    else
        self->blendOfAnchorTransforms.rot.Normalize();
    self->blendOfAnchorTransforms.pos.w = 1.0f;
}
#undef std_vector_deleter_cSkaAnimAnchorListEntry_data /* merge_units */
static inline void merge_flush_func_003AE750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE750 */

/* merge_units: begin func_003AEBA0 */
#pragma push /* merge_units */
/* cSkaAnimAnchorList_ClearAccumulation (ska.cc): reset every root entry's accumulation state.
 * The asm zero stores (VZeroF) keep the iterators in stack slots like retail. */
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
#if 0 /* merge_units */
extern "C" REnt_3AEBA0** std_vector_deleter_cSkaAnimAnchorListEntry_data(RColl_3AEBA0*);
#endif /* merge_units */
#define std_vector_deleter_cSkaAnimAnchorListEntry_data(a0) ((REnt_3AEBA0 * *)std_vector_deleter_cSkaAnimAnchorListEntry_data((void *)(a0))) /* merge_units */


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
#undef std_vector_deleter_cSkaAnimAnchorListEntry_data /* merge_units */
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
