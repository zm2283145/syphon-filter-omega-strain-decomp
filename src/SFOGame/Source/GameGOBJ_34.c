/*
 * SFOGame/Source/GameGOBJ: 2 files, 002186A0-002186F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002186A0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

void func_002186A0(IntFloatVec* v) {
    v->count = v->count - 1;
}

IntFloat* cSafePtr_cGOBJ_opAssign_cSafePtrR(IntFloat* dst, IntFloat* src) {
    dst->i = src->i;
    dst->f = src->f;
    return dst;
}

IntFloat* func_002186D0(IntFloatVec* v, int i) {
    return &v->data[i];
}

int func_002186E0(IntFloatVec* v) {
    return v->count;
}
static inline void merge_flush_func_002186A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002186A0 */

/* merge_units: begin func_002186F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "sound_event.h"
#pragma inline_depth(8)
#pragma opt_propagation off

struct Qt { float x, y, z, w; } __attribute__((aligned(16)));

struct V {
    float x, y, z, w;
    V() {}
    /* empty asm barrier: keeps a dead zero register (retail daddu v0,zero,zero after the copy) */
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; int z = 0; __asm__ volatile("" : "+r"(z)); }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V& operator-=(const V& o) { V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(tp), "r"(op) : "memory"); return *this; }
    V& operator+=(const V& o) { V* d = this; V* a = this; const V* b = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void CopyM(void* dd, const void* ss) { void* d = dd; __int128 qa, qb; const void* s = ss; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct M {
    V r0, r1, r2, r3;
    M() {}
    M(const M& o) { CopyM(this, &o); }
    M(const Qt& q)
    {
        M* m = this;
        const Qt* qp = &q;
        __asm__ volatile(
            "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
            "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
            "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
            "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
            "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
            "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
            : : "r"(m), "r"(qp) : "memory");
    }
    float* f() { return (float*)this; }
    const float* f() const { return (const float*)this; }
};

struct Plc : M {
    Plc(const M& m, const V& pos)
    {
        r0.x = m.r0.x; r0.y = m.r0.y; r0.z = m.r0.z;
        r1.x = m.r1.x; r1.y = m.r1.y; r1.z = m.r1.z;
        r2.x = m.r2.x; r2.y = m.r2.y; r2.z = m.r2.z;
        r0.w = m.r0.w; r1.w = m.r1.w; r2.w = m.r2.w;
        r3 = pos;
    }
};

static inline M MMul(M& a, M& b) { M r; M* rp = &r; M* bp = &b; M* ap = &a; __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }

struct Src {
    VPAD16(a) VPAD4(b)
    virtual void Refresh();
    char pad4[0xC];
    M xform;
    unsigned char dirty;
    M* Xform() { if (dirty) Refresh(); return &xform; }
};

struct Kid { char pad0[0x49]; unsigned char type; };
struct Cursor { int cur; int dir; };
struct Arr { int a; int n; int c; int d; int Size() { return n; } };

struct PathObj {
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetPlacementI(M* p);
    VPAD4(d) VPAD1(e)
    virtual void SetPlacement(M* p);
    char pad4[0x4C];
    Src* src;
    char pad54[0x1C];
    int nKids;
    char pad74[8];
    Kid** kids;
    char pad80[0x18];
    int nPts;
    char pad9C[8];
    Arr rots;
    Arr segs;
    float delay;
    float wait;
    int stopAt;
    Cursor* cur;
    float speed;
    int mode;
    unsigned char done;
    char padDD[3];
    float t;
    void* snd;
};

extern "C" {
extern char g_Game[];
extern char D_004DAE30[];
extern char g_TriggerMsgKey[];
extern char D_004DAF10[];
extern char D_004F5450[];
extern char D_004DAE90[];
void cGOBJ_NextFrame(PathObj* o, float dt);
void PathObj_GetPoint(PathObj* o, V* out, int i);
void cMatrix_Copy_InvertRotTrans(M* out, M* in);
Qt* func_002181C0(Arr* v, int i);
int func_002181D0(Arr* v);
float* func_002181E0(Arr* v, int i);
int func_002181F0(Arr* v);
void cPathedGOBJ_TransformAttached(PathObj* o, M m, int f);
void cPathedGOBJ_ResetAndTrigger(PathObj* o);
M cPathedGOBJ_GetAdjustedRot(PathObj* o, int a, int b, float t);
}

static inline int ObjId(Kid* o) { return o ? *(int*)((char*)o + 0xC) : 0; }

struct LiftMsg {
    CMSG_HEADER;
    int mkind;
    int floor;
    int from;
    int to;
    char pad34[4];
    LiftMsg(int k, int f)
    {
        LiftMsg* p = this;
        cMessage_ctor_cMessageNameR(p, g_TriggerMsgKey);
        p->vtable = D_004DAF10;
        p->mkind = k;
        p->floor = f;
        p->to = ObjId(0);
        p->from = ObjId(0);
    }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~LiftMsg() { vtable = D_004DAF10; cMessage_dtor(this, 0); }
};

struct Notice {
    CMSG_HEADER;
    int nkind;
    int arg;
    char pad2C[4];
    Notice(int k, int a) { Notice* p = this; cMessage_ctor_cMessageNameR(p, D_004F5450); p->vtable = D_004DAE90; p->nkind = k; p->arg = a; }
    Notice(Cursor* c) { Notice* p = this; int a = c->cur; cMessage_ctor_cMessageNameR(p, D_004F5450); p->vtable = D_004DAE90; p->nkind = 0; p->arg = a; }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Notice() { vtable = D_004DAE90; cMessage_dtor(this, 0); }
};

static inline void Notify(PathObj* o, int kind, int arg) { Notice n(o->cur); n.Send(o); }

static inline int Clamp0(int i) { if (i < 0) i = 0; return i; }
static inline Qt* RotAt(PathObj* o, int idx)
{
    int i = Clamp0(idx);
    Qt* q;
    if (i < func_002181D0(&o->rots)) q = func_002181C0(&o->rots, i);
    else q = func_002181C0(&o->rots, func_002181D0(&o->rots) - 1);
    return q;
}
static inline float* SegAt(PathObj* o, int idx)
{
    int i = Clamp0(idx);
    float* q;
    if (i < func_002181F0(&o->segs)) q = func_002181E0(&o->segs, i);
    else q = func_002181E0(&o->segs, func_002181F0(&o->segs) - 1);
    return q;
}

/* cPathedGOBJ_ResetAndTrigger: put the path object back on its first point
 * (placement from point 0 and the first rotation key), pass the movement on,
 * rewind the cursor and send the trigger message to itself. */
/* the trigger message is a temporary of a helper: it gets the lowest frame slot, below the MMul temp */
/* the trigger message is a helper temporary: it gets the lowest frame slot, below the MMul temp */
static inline void Trigger(PathObj* o) { LiftMsg(0, 0).Send(o); }
extern "C" void cPathedGOBJ_ResetAndTrigger(PathObj* self)
{
    M inv;
    cMatrix_Copy_InvertRotTrans(&inv, self->src->Xform());
    int i = 0;
    V pt;
    PathObj_GetPoint(self, &pt, i);
    Qt* q;
    if (i < func_002181D0(&self->rots)) q = func_002181C0(&self->rots, i);
    else q = func_002181C0(&self->rots, func_002181D0(&self->rots) - 1);
    Plc p(M(*q), pt);
    self->SetPlacement(&p);
    cPathedGOBJ_TransformAttached(self, MMul(p, inv), 1);
    self->cur->dir = 1;
    self->cur->cur = i;
    self->t = 0.0f;
    Trigger(self);
}
static inline void merge_flush_func_002186F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002186F0 */
