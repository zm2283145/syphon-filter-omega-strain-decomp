/*
 * Libs/SFOLib/Source/ska: 11 files, 003ADD80-003AE150
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
Elem* std_vector_cSkaPlaybackItem_opIndex(IntVec* v, int i);
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
static inline void merge_flush_func_003AE150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AE150 */
