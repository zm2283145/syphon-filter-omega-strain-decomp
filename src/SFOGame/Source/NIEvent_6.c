/*
 * SFOGame/Source/NIEvent: 11 files, 00239DF0-0023B0B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00239DF0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#pragma optimize_for_size on
struct Key_239DF0 { float a; float t; float c; float d; };
struct Vec_239DF0 {
    int capacity; int count; Key_239DF0* data;
};
struct Track_239DF0 {
    float cur;
    Vec_239DF0 keys;
    int pad10;
    int w14;
    int w18;
    unsigned char b1C;
};
struct Reader_239DF0 { int version; int size; unsigned int base; char* cur; };
static inline float RdF_239DF0(Reader_239DF0* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline int RdI_239DF0(Reader_239DF0* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline Key_239DF0* Zero_239DF0(void* d0, int n0) { void* dst = d0; int n = n0; Key_239DF0* r;
    asm {
        beqz dst, done
        move r, dst
    loop:
        sb $zero, 0(dst)
        addiu n, n, -1
        addiu dst, dst, 1
        bnez n, loop
    done:
    }
    return r;
}
extern "C" void std_vector_imp_FloatKey_resize(Vec_239DF0* v, unsigned int n, const Key_239DF0* value);
extern "C" void cNIEventFloatTrack_Init_cPopulationR(Track_239DF0* self, Reader_239DF0* r)
{
    Key_239DF0 k1;
    Key_239DF0 k0;
    int n = RdI_239DF0(r);
    int i;
    if (n)
        self->w14 = (int)(RdF_239DF0(r) - 1.0f);
    {
        Key_239DF0* p1 = Zero_239DF0(&k1, 16);
        Key_239DF0* p0 = Zero_239DF0(&k0, 16);
        std_vector_imp_FloatKey_resize(&self->keys, 0, p0);
        std_vector_imp_FloatKey_resize(&self->keys, n, p1);
    }
    i = 0;
    if (0 < n) do {
        self->keys.data[i].a = RdF_239DF0(r);
        self->keys.data[i].t = RdF_239DF0(r);
        self->keys.data[i].c = *(float*)r->cur;
        r->cur += 4;
        self->keys.data[i].d = *(float*)r->cur;
        r->cur += 4;
    } while (++i < n);
    self->b1C = 0;
    self->w18 = 0;
    if (self->keys.count > 0)
        self->cur = self->keys.data[0].t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239DF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239DF0 */

/* merge_units: begin func_00239FA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Tgt00239FA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void apply();
    char pad[0x34];
    int value;
};
struct Ev00239FA0 {
    char pad00[0x38];
    int value;
    char pad3C[0xDC - 0x3C];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt00239FA0* target;
};
extern "C" void cNIEventOBJ_Render(Ev00239FA0* self)
{
    if (self->enabled) {
        self->target->value = self->value;
        self->target->apply();
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239FA0 */

/* merge_units: begin func_00239FF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { Mtx* d = this; const Mtx* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
struct Sub {
    VPAD1(a)
    virtual void SetMtx(Mtx* m);
    VPAD16(b) VPAD2(c)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
struct Box { V mn, mx; };
struct Obj {
    VPAD32(a)
    virtual Box* GetBox();
    char pad4[0x4C];
    Sub* sub;
};
static inline const Mtx& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
// abs.s: no C equivalent
static inline float Fabs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void MulM(V* v, Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }

extern "C" int cNIEventOBJ_GetBeamExtents(Obj* o, V* mn, V* mx)
{
    V c;
    V e;
    Box* b = o->GetBox();
    if (!b) return 0;
    *mn = b->mn;
    *mx = b->mx;
    Mtx m = SubMtx(o->sub);
    float ax = Fabs(mx->x - mn->x);
    float ay = Fabs(mx->y - mn->y);
    float az = Fabs(mx->z - mn->z);
    c.w = 1.0f;
    c.x = mn->x + (mx->x - mn->x) / 2.0f;
    c.y = mn->y + (mx->y - mn->y) / 2.0f;
    c.z = mn->z + (mx->z - mn->z) / 2.0f;
    e = c;
    if (!(ax < ay) && !(ax < az)) {
        c.x = mn->x;
        e.x = mx->x;
    } else if (!(ay < ax) && !(ay < az)) {
        c.y = mn->y;
        e.y = mx->y;
    } else {
        c.z = mn->z;
        e.z = mx->z;
    }
    *mn = c;
    *mx = e;
    MulM(mn, &m);
    MulM(mx, &m);
    return 1;
}
static inline void merge_flush_func_00239FF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00239FF0 */

/* merge_units: begin func_0023A250 */
#pragma push /* merge_units */
#pragma cplusplus on

class Tgt0023A250 {
public:
    VPAD32(a)
    virtual int run();
};
struct Ev0023A250 {
    char pad00[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0xDC - 0x2F];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt0023A250* target;
};
extern "C" int cNIEventOBJ_GetBBox(Ev0023A250* self)
{
    Tgt0023A250* t;
    return (self->enabled && (t = self->target) != 0 && !(self->b2D == 0) && self->b2C && !self->b2E)
        ? t->run() : 0;
}
static inline void merge_flush_func_0023A250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A250 */

/* merge_units: begin func_0023A2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
/* cNIEventOBJ_ForceMatUpdate (update): updates the event node, then drives the attached
 * object from the owner's matrix: for mode 5 with rows 1 and 2 swapped and
 * the new row 1 negated (Y/Z swap), otherwise through the play or idle
 * matrix slot depending on whether the event is playing; finally pokes every
 * child element of the two attach types. Types as in cNIEventOBJ_SetEndState
 * (NIEvent_23B450.c) and cNIEventLight_ProcessNextFrame. */
#pragma always_inline on
#pragma inline_depth(8)
struct V4_A2D0 { float x, y, z, w; } __attribute__((aligned(16)));
struct M4_A2D0 { V4_A2D0 r[4]; };
class Owner_A2D0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void Sync();
    char p4[0x10 - 4];
    M4_A2D0 mtx;
    unsigned char dirty;
};
class Obj_A2D0 {
public:
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void SetMatrix(M4_A2D0* m);
    VPAD4(d) VPAD1(e)
    virtual void SetIdleMatrix(M4_A2D0* m);
    char p4[0x50 - 4];
    void* model;
};
class Elem_A2D0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Attach();
    char p4[0x4C - 4];
    int type;
};
struct PtrVec_A2D0 { int cap; int n; Elem_A2D0** data; };
class Ev_A2D0 {
public:
    VPAD1(a)
    char p4[0x50 - 4];
    Owner_A2D0* owner;
    char p54[0x60 - 0x54];
    int mode;
    char p64[0x9C - 0x64];
    PtrVec_A2D0 elems;
    char pA8[0x130 - 0xA8];
    unsigned char playing;
    char p131[0x140 - 0x131];
    Obj_A2D0* obj;
};
extern "C" {
extern int D_004F7C60;
extern int D_004F7C98;
void cNIEventBase_ForceMatUpdate(Ev_A2D0* self);
#if 0 /* merge_units */
Elem_A2D0** std_vector_cNIEventBasePtr_opIndex(PtrVec_A2D0* v, int i);
#endif /* merge_units */
int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i); /* merge_units */
#define std_vector_cNIEventBasePtr_opIndex(a0, a1) ((Elem_A2D0 * *)std_vector_cNIEventBasePtr_opIndex((PtrVec *)(a0), (a1))) /* merge_units */

void cMatrix_SetXAxis(M4_A2D0* m, V4_A2D0* v);
void cMatrix_SetYAxis(M4_A2D0* m, V4_A2D0* v);
void cMatrix_SetZAxis(M4_A2D0* m, V4_A2D0* v);
void cNIEventOBJ_ForceMatUpdate(Ev_A2D0* self);
}
static inline void GQR(void* dd, void* ss) { void* s = ss; void* d = dd; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void VCopy(V4_A2D0* d, const V4_A2D0* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline Elem_A2D0* At(PtrVec_A2D0* v, int i) { return *std_vector_cNIEventBasePtr_opIndex(v, i); }
static inline bool Is(int k, Elem_A2D0* e) { return e->type == k; }
static inline Owner_A2D0* SyncedOwner(Ev_A2D0* self) { Owner_A2D0* o = self->owner; if (o->dirty) o->Sync(); return o; }

extern "C" void cNIEventOBJ_ForceMatUpdate(Ev_A2D0* self)
{
    int i;
    cNIEventBase_ForceMatUpdate(self);
    if (self->obj && self->obj->model) {
        if (self->mode != 5) {
            if (self->playing) {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetMatrix(&o->mtx);
            } else {
                Owner_A2D0* o = SyncedOwner(self);
                self->obj->SetIdleMatrix(&o->mtx);
            }
        } else {
            Owner_A2D0* o = SyncedOwner(self);
            M4_A2D0 m;
            V4_A2D0 r0;
            V4_A2D0 r1;
            V4_A2D0 r2;
            GQR(&m, &o->mtx);
            VCopy(&r0, &m.r[0]);
            VCopy(&r1, &m.r[1]);
            VCopy(&r2, &m.r[2]);
            r2.x = -r2.x;
            r2.y = -r2.y;
            r2.z = -r2.z;
            cMatrix_SetXAxis(&m, &r0);
            cMatrix_SetYAxis(&m, &r2);
            cMatrix_SetZAxis(&m, &r1);
            self->obj->SetMatrix(&m);
        }
    }
    for (i = 0; i < self->elems.n; i++) {
        if (Is(D_004F7C60, At(&self->elems, i)))
            self->elems.data[i]->Attach();
        else if (Is(D_004F7C98, At(&self->elems, i)))
            self->elems.data[i]->Attach();
    }
}
#undef std_vector_cNIEventBasePtr_opIndex /* merge_units */
static inline void merge_flush_func_0023A2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A2D0 */

/* merge_units: begin func_0023A550 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i) {
    return v->data + i;
}
static inline void merge_flush_func_0023A550(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A550 */

/* merge_units: begin func_0023A560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "nievent_v10.h"

/* Event virtual 10: call slot 66 while inactive. */
DEFINE_NIEVENT_V10(cNIEventOBJ_NextFrame)
static inline void merge_flush_func_0023A560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A560 */

/* merge_units: begin func_0023A5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

/*
 * cNIEventOBJ::ProcessNextFrame (NIEvent.cc), transcribed from the prototype
 * (ProcessNextFrame__11cNIEventOBJFf) + retail-only cHuman::BulletBlood call.
 * DRAFT: the prototype's line-segment/box test is a hand-written VU0 asm
 * routine with internal branches (prototype 0x2469dc..0x246f88); here it is a
 * plain C stand-in, so the middle of the function does not match.
 */

struct V_0023A5A0 {
    float x, y, z, w;
    V_0023A5A0() {}
    V_0023A5A0& operator=(const V_0023A5A0& o) { const V_0023A5A0* s = &o; V_0023A5A0* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    V_0023A5A0(const V_0023A5A0& o) { const V_0023A5A0* s = &o; V_0023A5A0* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

struct M { float m[4][4]; } __attribute__((aligned(16)));

struct cLineSegment {
    V_0023A5A0 endPoints[2];
    cLineSegment() {}
};

struct cBox { V_0023A5A0 min; V_0023A5A0 max; };

struct XNode {
    VPAD16(a) VPAD4(b) virtual void Update();
    char pad04[0xC];
    M mat;                  /* +0x10 */
    unsigned char dirty;    /* +0x50 */
};

struct cHuman {
    VPAD16(a) VPAD16(b) virtual cBox* GetBox();   /* +0x88 */
    char pad04[0x4C];
    XNode* xform;           /* +0x50 */
};

struct cCtrl {
    VPAD16(a) VPAD2(b) VPAD1(e) virtual int IsActive();      /* +0x54 */
    VPAD8(c) VPAD4(d) virtual unsigned char State(); /* +0x88 */
    char pad04[0x2C];
    cHuman* human;          /* +0x30 */
};

struct cPlayerObj {
    char pad00[0x58];
    cCtrl* ctrl;            /* +0x58 */
};

struct cEvBase {
    VPAD32(a) VPAD32(b) VPAD2(c) virtual void Step(float t);  /* +0x110 */
    char pad04[0x48];
    void* kind;             /* +0x4C */
};

struct cEvVec { int pad; int count; cEvBase** data; };

struct cObjX {
    VPAD16(a) virtual void Activate();  /* +0x48 */
};

struct cNIEventOBJ {
    VPAD32(a) VPAD32(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual void Advance(float t);  /* +0x134 */
    char pad04[0x28];
    unsigned char mEnabled;       /* +0x2C */
    unsigned char mActiveFlag;    /* +0x2D */
    unsigned char mStreamingFlag; /* +0x2E */
    char pad2F[0x31];
    int type;                     /* +0x60 */
    char pad64[0x38];
    cEvVec events;                /* +0x9C */
    char padA8[0x34];
    unsigned char bDC;            /* +0xDC */
    char padDD[0x53];
    unsigned char playing;        /* +0x130 */
    char pad131[3];
    float speed;                  /* +0x134 */
    char pad138[8];
    cObjX* mObject;               /* +0x140 */
};

struct Msg {
    void* vtable;
    void* type;
    char pad08[0x18];
    unsigned char kind;           /* +0x20 */
    char pad21[3];
    void* who;                    /* +0x24 */
};

struct HitInfo { char pad[0x4C]; float range; };

extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
extern char D_00506210[];
extern char D_004DCF10[];
extern char D_004DCF30[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
#if 0 /* merge_units */
extern void* D_004F7C60;
#endif /* merge_units */
#define D_004F7C60 (*(void **)&D_004F7C60) /* merge_units */

#if 0 /* merge_units */
extern void* D_004F7C98;
#endif /* merge_units */
#define D_004F7C98 (*(void **)&D_004F7C98) /* merge_units */

extern float D_0048AE20;
void cMessage_ctor_cMessageNameR(void* m, void* name);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* to, int f);
#if 0 /* merge_units */
void cMessage_dtor(void* m, int f);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

void cGOBJ_NextFrame(void* g, float t);
#if 0 /* merge_units */
int cNIEventOBJ_GetBeamExtents(cNIEventOBJ* self, V_0023A5A0* a, V_0023A5A0* b);
#endif /* merge_units */
#define cNIEventOBJ_GetBeamExtents(a0, a1, a2) (cNIEventOBJ_GetBeamExtents((Obj *)(a0), (V *)(a1), (V *)(a2))) /* merge_units */

cPlayerObj* cNetObj_GetPlayer(int i);
void cMatrix_Copy_InvertRotTrans(M* out, M* in);
int cHuman_BulletBlood(cHuman* h, V_0023A5A0* pos, V_0023A5A0* dir, int a, HitInfo* hit);
#if 0 /* merge_units */
cEvBase** std_vector_cNIEventBasePtr_opIndex(cEvVec* v, int i);
#endif /* merge_units */
#define std_vector_cNIEventBasePtr_opIndex(a0, a1) ((cEvBase * *)std_vector_cNIEventBasePtr_opIndex((PtrVec *)(a0), (a1))) /* merge_units */


}

static inline bool Enabled(cNIEventOBJ* o) { bool a = false; if (o->mActiveFlag && o->mEnabled) a = true; return a; }
static inline bool Streaming(cNIEventOBJ* o) { bool b = o->mStreamingFlag; return b; }
static inline bool NotStreaming(cNIEventOBJ* o) { return Streaming(o) ^ 1; }
static inline bool IsActive(cNIEventOBJ* o) { bool r = false; if (Enabled(o) && NotStreaming(o)) r = true; return r; }

struct cDoneMsg : Msg {
    cDoneMsg(void* w) { Msg* m = this; cMessage_ctor_cMessageNameR(m, D_004F7C30); m->vtable = D_004DBEB0; m->who = w; }
    void Done() { vtable = D_004DBEB0; cMessage_dtor(this, 0); }
};
struct cHitMsg : Msg {
    cHitMsg(void* w) { Msg* m = this; cMessage_ctor_cMessageNameR(m, D_00506210); m->vtable = D_004DCF10; m->vtable = D_004DCF30; m->who = w; }
    void Done() { vtable = D_004DCF10; cMessage_dtor(this, 0); }
};
static inline void Queue(const Msg& m, void* to) { QueueMessage_cMessageR_cSystemP_int((void*)&m, to, 0); }
static inline unsigned char HitKind() { unsigned char x; if (g_IsMultiplayer) x = D_005721C0; else x = 1; return x ? 1 : 2; }

static inline void Apply(V_0023A5A0* o, M* m, V_0023A5A0* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void SubV(V_0023A5A0* d, const V_0023A5A0* a, const V_0023A5A0* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline V_0023A5A0 Sub(const V_0023A5A0& a, const V_0023A5A0& b) { V_0023A5A0 r; SubV(&r, &a, &b); return r; }

static inline bool Intersects(const cLineSegment& l, const cBox& box)
{
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    int hit;
    bool res;
    unsigned int c0;
    unsigned int c1;
    unsigned int t;
    int done;
    unsigned int diff;
    unsigned int sign;
    __asm__ volatile(".set noreorder; daddu %1, $0, $0; daddu %2, $0, $0; lqc2 $vf3, 0x0(%3); lqc2 $vf4, 0x0(%4); lqc2 $vf1, 0x0(%5); addi %0, $0, 0x1; .set reorder" : "=r"(done), "=r"(c0), "=r"(c1) : "r"(&l.endPoints[0]), "r"(&l.endPoints[1]), "r"(&box.min));
    __asm__ volatile(".set noreorder; vsub.xyz $vf6, $vf3, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; andi %0, %0, 0xE0; vsub.xyz $vf8, $vf4, $vf1; vnop; vnop; vnop; vnop; vnop; cfc2.ni %1, $vi17; andi %1, %1, 0xE0; and %2, %0, %1; bnel %2, $0, 1f; addi %3, $0, 0x0; lqc2 $vf2, 0x0(%5); vsub.xyz $vf7, $vf2, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %2, $vi17; srl %0, %0, 4; andi %2, %2, 0xE0; or %0, %0, %2; vsub.xyz $vf9, $vf2, $vf4; vnop; vnop; vnop; vnop; vnop; cfc2.ni %2, $vi17; srl %1, %1, 4; andi %2, %2, 0xE0; addi %3, $0, 0x0; or %1, %1, %2; and %2, %0, %1; bnel %2, $0, 1f; nop; or %2, %0, %1; beql %2, $0, 1f; addi %3, $0, 0x1; addi %4, $0, 0x0; 1: andi %4, %4, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(res), "=r"(done) : "r"(&box.max), "4"(done), "0"(c0), "1"(c1));
    if (done) return res;
    diff = c0 ^ c1;
    __asm__ volatile(".set noreorder; vsub.xyzw $vf5, $vf4, $vf3; vnop; vnop; vnop; vnop; vnop; cfc2.ni %0, $vi17; vsub.xyz $vf6, $vf0, $vf6; .set reorder" : "=r"(sign));
    if (!(done = sign & 8) && (done = diff & 0x88)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5x; vmulx.xyzw $vf8, $vf5, $vf6x; vmulx.xyzw $vf9, $vf5, $vf7x");
        if (done = diff & 8) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
        if (done = diff & 0x80) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
    }
    if (!(done = sign & 4) && (done = diff & 0x44)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5y; vmuly.xyzw $vf8, $vf5, $vf6y; vmuly.xyzw $vf9, $vf5, $vf7y");
        if (done = diff & 4) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
        if (done = diff & 0x40) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; prot3w %0, %0; prot3w %2, %2; prot3w %1, %1; mtc1 %2, $f0; mtc1 %0, $f1; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1;  1: andi %3, %3, 0xFF; .set reorder" : "=r"(c0), "=r"(c1), "=r"(t), "=r"(done));
        if (done) return true;
        }
    }
    if (!(sign & 2) && (diff & 0x22)) {
        __asm__ volatile("vdiv $Q, $vf0w, $vf5z; vmulz.xyzw $vf8, $vf5, $vf6z; vmulz.xyzw $vf9, $vf5, $vf7z");
        if (diff & 2) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf8, $vf8, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf8; mtc1 %0, $f1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1; nop; 1: andi %3, %3, 0xFF; .set reorder" : "=r"(a), "=r"(b), "=r"(c), "=r"(hit));
        if (hit) return true;
        }
        if (diff & 0x20) {
        __asm__ volatile(".set noreorder; vmulaw.xyzw $ACC, $vf3, $vf0w; vwaitq; vmaddq.xyzw $vf9, $vf9, $Q; qmfc2.ni %0, $vf1; qmfc2.ni %1, $vf2; addi %3, $0, 0x0; qmfc2.ni %2, $vf9; mtc1 %0, $f1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; prot3w %0, %0; prot3w %2, %2; mtc1 %0, $f1; prot3w %1, %1; mtc1 %2, $f0; c.le.s $f1, $f0; mtc1 %1, $f1; bc1fl 1f; nop; c.le.s $f0, $f1; nop; bc1fl 1f; nop; addi %3, $0, 0x1;  1: andi %3, %3, 0xFF; .set reorder" : "=r"(d), "=r"(e), "=r"(f), "=r"(hit));
        if (hit) return true;
        }
    }
    return false;
}
static inline void Play(cNIEventOBJ* self, float timeStep)
{
    unsigned char was = self->playing;
    float a = timeStep * self->speed;
    self->Advance(was ? a : 0.0f);
    if (was && !self->playing) {
        cDoneMsg msg(0);
        Queue(msg, self);
        msg.Done();
    }
}

extern "C" void cNIEventOBJ_ProcessNextFrame(cNIEventOBJ* self, float timeStep)
{
    if (self->bDC && self->mObject)
        self->mObject->Activate();

    if (self->playing || (self->type == 3 && self->bDC && IsActive(self))) {
        Play(self, timeStep);
    }

    cGOBJ_NextFrame(self, timeStep);

    if (IsActive(self) && self->type == 6) {
        V_0023A5A0 point1;
        V_0023A5A0 point2;
        if (cNIEventOBJ_GetBeamExtents(self, &point1, &point2)) {
            cLineSegment line;
            line.endPoints[0] = point1;
            line.endPoints[1] = point2;
            for (int i = 0; i < 4; i++) {
                cPlayerObj* player = cNetObj_GetPlayer(i);
                if (!player || !player->ctrl || !player->ctrl->IsActive() || player->ctrl->State() == 4)
                    continue;
                cHuman* human = player->ctrl->human;
                XNode* n = human->xform;
                if (n->dirty) n->Update();
                M invmat;
                cMatrix_Copy_InvertRotTrans(&invmat, &n->mat);
                cBox* box = human->GetBox();
                cLineSegment invLine;
                invLine.endPoints[0] = line.endPoints[0];
                invLine.endPoints[1] = line.endPoints[1];
                Apply(&invLine.endPoints[0], &invmat, &invLine.endPoints[0]);
                Apply(&invLine.endPoints[1], &invmat, &invLine.endPoints[1]);
                if (Intersects(invLine, *box)) {
                    V_0023A5A0 dir = Sub(point2, point1);
                    HitInfo hit;
                    hit.range = D_0048AE20;
                    if (cHuman_BulletBlood(human, &point1, &dir, 0, &hit)) {
                        cHitMsg msg(human); msg.kind = HitKind(); Queue(msg, self); msg.Done();

                    }
                }
            }
        }
    }

    for (int i = 0; i < self->events.count; i++) {
        void* g; void* h;
        if ((*std_vector_cNIEventBasePtr_opIndex(&self->events, i))->kind == (h = D_004F7C60))
            self->events.data[i]->Step(timeStep);
        else if ((*std_vector_cNIEventBasePtr_opIndex(&self->events, i))->kind == (g = D_004F7C98))
            self->events.data[i]->Step(timeStep);
    }
}
#undef D_004F7C60 /* merge_units */
#undef D_004F7C98 /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cNIEventOBJ_GetBeamExtents /* merge_units */
#undef std_vector_cNIEventBasePtr_opIndex /* merge_units */
static inline void merge_flush_func_0023A5A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023A5A0 */

/* merge_units: begin func_0023B0B0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cBeamMsg_dtor, D_004DCF30, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_0023B0B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B0B0 */

/* merge_units: begin func_0023B120 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Child_23B120 { char pad[0x4C]; int kind; };
class Node_23B120 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void slot70();
    char pad04[0x98];
    PtrVec children;
};
extern "C" {
int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i);
void cNIEventOBJ_UpdateChildren(Node_23B120* self);
}
/* Calls virtual slot 70, then recurses into every child whose kind (+0x4C) is NIEventOBJ (D_004F7C60). */
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_UpdateChildren(Node_23B120* self)
{
    int i;
    self->slot70();
    for (i = 0; i < self->children.count; i++) {
        Child_23B120* c = (Child_23B120*)*std_vector_cNIEventBasePtr_opIndex(&self->children, i);
        if (c->kind == D_004F7C60)
            cNIEventOBJ_UpdateChildren((Node_23B120*)self->children.data[i]);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023B120 */

/* merge_units: begin func_0023B1C0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNIEventOBJ_UpdateAll: advance the event object's tracks; when anything moved, rebuild its rotation matrix and apply */
struct V4_23B4C0 { float x, y, z, w;
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_23B4C0 { V4_23B4C0 r[4];
    M4_23B4C0() {}
};
static inline float Rad_23B4C0(float d) { return d * 0.017453292f; }
static inline __int128 LoadQ_23B4C0(const V4_23B4C0* s) { __int128 t; asm { .set noreorder; lq t, 0x0(s); .set reorder } return t; }
/* quad copies (lq/sq); volatile like retail: it also keeps MW's branchy bool materialisation of rot */
static inline void StoreAll_23B4C0(M4_23B4C0* d, const M4_23B4C0* s, __int128 t, V4_23B4C0* pd) { __int128 qa; __int128 qb; asm volatile { .set noreorder; sq t, 0x0(pd); lq qa, 0x0(s); .set reorder; lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
struct K64_23B4C0 { float t; char pad[0x3C]; };
struct K8_23B4C0 { float t; int v; };
struct K16_23B4C0 { float t; char pad[0xC]; };
struct Rot_23B4C0 { float val; int cap; int n; K16_23B4C0* data; int pad10; int state; float t; unsigned char flag; char pad1D[3]; };
extern "C" {
float cVector_X_void(V4_23B4C0* v);
float cVector_Y_void(V4_23B4C0* v);
float cVector_Z_void(V4_23B4C0* v);
void cMatrix_SetWithAxisAngle(M4_23B4C0* m, float x, float y, float z, float a);
void cMatrix_ctor_void(M4_23B4C0* m);
void cMatrix_Rotate(M4_23B4C0* a, M4_23B4C0* b);
void cNIEventFXTrack_Update(void* l, float dt);

bool cNIEventFloatTrack_Update(Rot_23B4C0* p, float dt);
}
static inline void MakeRot_23B4C0(M4_23B4C0* m, const V4_23B4C0& a, float ang) { cMatrix_SetWithAxisAngle(m, a.x, a.y, a.z, ang); }
class Elem_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD4(d)
    virtual void Reset();
};
class Self_23B4C0 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void Apply();
    VPAD2(e)
    virtual bool Step(float dt);
    virtual bool Step2(float dt);
    char pad4[0x60 - 0x4];
    int mode;
    char pad64[0x9C - 0x64];
    int acap; int an; Elem_23B4C0** adata;
    char padA8[0xB0 - 0xA8];
    int n1; K64_23B4C0* d1;
    char padB8[0xC0 - 0xB8];
    float t1;
    char padC4[0xC8 - 0xC4];
    int n2; K8_23B4C0* d2;
    char padD0[0xD8 - 0xD0];
    float t2;
    char padDC[0xE0 - 0xDC];
    V4_23B4C0 pos;
    M4_23B4C0 mtx;
    unsigned char b130;
    char pad131[0x144 - 0x131];
    Rot_23B4C0 rx;
    Rot_23B4C0 ry;
    Rot_23B4C0 rz;
    char list[4];
};

static inline unsigned char Rot3(Self_23B4C0* self, float dt) { unsigned char r1 = cNIEventFloatTrack_Update(&self->rx, dt); unsigned char r2 = cNIEventFloatTrack_Update(&self->ry, dt); unsigned char r3 = cNIEventFloatTrack_Update(&self->rz, dt); return r1 || r2 || r3; }
static inline unsigned char Moved(Self_23B4C0* self, float dt) { if (self->mode == 3) return 1; return Rot3(self, dt); }

extern "C" void cNIEventOBJ_UpdateAll(Self_23B4C0* self, float dt)
{
    unsigned char a = self->Step(dt);
    unsigned char rot = Moved(self, dt);
    unsigned char b = self->Step2(dt);
    cNIEventFXTrack_Update(self->list, dt);
    if (a || rot || b) {
        if (self->mode != 3) {
            M4_23B4C0 m0;
            V4_23B4C0 ax1;
            V4_23B4C0 ax2;
            V4_23B4C0 ax3;
            M4_23B4C0 m1;
            M4_23B4C0 m2;
            float ang;
            ang = Rad_23B4C0(self->rx.val);
            ax1.Set(1.0f, 0.0f, 0.0f, 0.0f);
            cMatrix_SetWithAxisAngle(&m0, cVector_X_void(&ax1), cVector_Y_void(&ax1), cVector_Z_void(&ax1), ang);
            float ang2 = Rad_23B4C0(self->ry.val);
            ax2.Set(0.0f, 1.0f, 0.0f, 0.0f);
            cMatrix_ctor_void(&m1);
            MakeRot_23B4C0(&m1, ax2, ang2);
            cMatrix_Rotate(&m0, &m1);
            float ang3 = Rad_23B4C0(self->rz.val);
            ax3.Set(0.0f, 0.0f, 1.0f, 0.0f);
            cMatrix_ctor_void(&m2);
            MakeRot_23B4C0(&m2, ax3, ang3);
            cMatrix_Rotate(&m0, &m2);
            StoreAll_23B4C0(&self->mtx, &m0, LoadQ_23B4C0(&self->pos), &m0.r[3]);
        }
        self->Apply();
    }
}
static inline void merge_flush_func_0023B1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023B1C0 */
