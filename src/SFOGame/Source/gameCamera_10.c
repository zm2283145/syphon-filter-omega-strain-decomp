/*
 * SFOGame/Source/gameCamera: 3 files, 0017E1B0-0017EB50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0017E1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "v4_asm_copy.h"
#pragma always_inline on
#pragma inline_depth(8)

/* cGameCamera_NextFrame: per-frame camera update: refresh its node, face along the node's forward row,
 * run the base logic and, while armed, ping every visible player that is not in state 4
 * (event D_004EE930 to the listener at +0xCE8, then a 15-frame cooldown). */

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r0, r1, r2, r3; };

class XNode {
public:
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0x10 - 4];
    M4 m;
    unsigned char dirty;
};

class Ctl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsActive();
    VPAD8(d) VPAD4(e)
    virtual unsigned char State();
    char pad4[0x30 - 4];
    void* target;
};

struct Player { char pad0[0x58]; Ctl* ctl; };

struct Cam {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    bool b2E;
    char pad2F[0x50 - 0x2F];
    XNode* node;
    char pad54[0x64 - 0x54];
    float heading;
    char pad68[0xCE0 - 0x68];
    int cooldown;
    unsigned char armed;
    char padCE5[3];
    void* listener;
};

struct Msg { char* vt; char pad4[0x20]; void* target; unsigned char kind; char pad25[0x24 - 0x21 + 3]; };

extern "C" {
extern char D_004EE930[];
extern char D_004DCF10[];
extern char D_004DA310[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(Cam* c, float dt);
Player* cNetObj_GetPlayer(int i);
int cGameCamera_CanSee(Cam* c, void* target);
void cMessage_ctor_cMessageNameR(void* e, char* type);
void QueueMessage_cMessageR_cSystemP_int(void* e, void* to, int f);
void cMessage_dtor(void* e, int f);
void cGameCamera_NextFrame(Cam* c, float dt);
}

static inline void Face(Cam* c)
{

    XNode* n = c->node;
    V4 f;
    if (n->dirty) n->Update();
    {
        M4* m = (M4*)((char*)n + 0x10);
        /* 128-bit lq/sq quadword copy; the volatile asm also keeps MW's materialised bools below */
        { V4* d = &f; const V4* s = &m->r1; __int128 t; asm volatile { lq t, 0(s); sq t, 0(d) } }
    }
    /* volatile read: retail loads f.y in the call delay slot */
    c->heading = Libc_Atan2f(f.x, *(volatile float*)&f.y);
}
static inline M4* Xf(XNode* n) { if (n->dirty) n->Update(); return &n->m; }

static inline bool Standing(Cam* o) { bool r = false; if (o->b2D && o->b2C) r = true; return r; }
static inline bool Alive(Cam* o) { bool r = false; if (Standing(o) && ((o->b2E != 0) ^ 1)) r = true; return r; }
/* the bool temporary keeps retail's daddiu for the single-player 1 */
static inline int DeadOk(void) { int r; if (g_IsMultiplayer) r = D_005721C0; else { bool on = true; r = on; } return r; }

struct EvMsg {
    char* vt; char pad4[0x1C]; unsigned char kind; char pad21[3]; void* target; char pad28[8];
    EvMsg(void* t) { EvMsg* self = (EvMsg*)(int)this; cMessage_ctor_cMessageNameR(self, D_004EE930); self->vt = D_004DCF10; self->vt = D_004DA310; self->target = t; }
    /* explicit teardown at the end of the send block (retail inlines it; a C++ dtor also emits a weak out-of-line copy) */
    void Done() { vt = D_004DCF10; cMessage_dtor(this, 0); }
};

void cGameCamera_NextFrame(Cam* c, float dt)
{
    Face(c);
    cGOBJ_NextFrame(c, dt);
    if (!Alive(c)) return;
    if (!c->armed) return;
    if (c->cooldown) {
        c->cooldown--;
        return;
    }
    {
        int i;
        for (i = 0; i < 4; i++) {
            Player* p = cNetObj_GetPlayer(i);
            if (p && p->ctl && p->ctl->IsActive() && p->ctl->State() != 4) {
                void* t = p->ctl->target;
                if (cGameCamera_CanSee(c, t)) {
                    EvMsg m(t);
                    m.kind = DeadOk() ? 1 : 2;
                    if (c->listener) QueueMessage_cMessageR_cSystemP_int(&m, c->listener, 0);
                    c->cooldown = 15;
                    m.Done();
                }
            }
        }
    }
}
static inline void merge_flush_func_0017E1B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017E1B0 */

/* merge_units: begin func_0017E3F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off

struct V4_17E3F0 {
    float x, y, z, w;
    V4_17E3F0& operator=(const V4_17E3F0& o) { const V4_17E3F0* s = &o; V4_17E3F0* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
typedef V4_17E3F0 V4c;
struct Mtx_17E3F0 { V4c r[4]; };
struct Pair_17E3F0 { V4c a; V4c b; Pair_17E3F0() {} Pair_17E3F0(const Pair_17E3F0& o); };
struct Id_17E3F0 { int v; Id_17E3F0() {} };
struct Reader_17E3F0 { int version; int a, b; char* cur; };

struct Base70 { void* vtbl; char p4[0xC]; V4c v10; V4c v20; V4c v30; V4c v40; V4c v50; unsigned char b60; char p61[0xF]; V4c v70; unsigned char b80; char p81[0xF]; char o90[0x30]; };
struct Base170 { void* vtbl; unsigned char b4; char p5[3]; float f8; char pC[4]; V4c v10; int f20; int f24; char p28[8]; V4c v30; V4c v40; };
struct CurveA { void* vtbl; char p4[0xBC]; unsigned char bC0; char pC1[0xF]; };
struct CurveB { void* vtbl; char p4[0xBC]; };
struct CC70 { void* vtbl; char p4[0x1C]; int f20; char p24[0xC]; V4c v30; V4c v40; V4c v50; int f60; char p64[0xC]; };

struct Cam_17E3F0 {
    void* vtbl;
    char p4[8];
    Id_17E3F0 id;
    char p10[0x20];
    int f30;
    char p34[0x2C];
    float f60;
    int f64;
    char p68[8];
    Base70 m70;
    int f130;
    char p134[0xC];
    V4c lo140;
    V4c hi150;
    int f160;
    int f164;
    char p168[8];
    Base170 m170;
    int f1C0;
    char p1C4[0xC];
    V4c lo1D0;
    V4c hi1E0;
    int f1F0;
    int f1F4;
    char p1F8[8];
    unsigned char b200;
    unsigned char b201;
    char p202[0xE];
    CurveA c210;
    CurveB c2E0;
    CurveB c3A0;
    CurveA c460;
    CurveA c530;
    CurveB c600;
    CurveB c6C0;
    CurveA c780;
    CurveB c850;
    CurveB c910;
    CurveB c9D0;
    char mA90[0x40];
    Pair_17E3F0 place;
    V4c vAF0;
    V4c qB00;
    V4c qB10;
    char mB20[0x140];
    unsigned char bC60;
    char pC61;
    unsigned char bC62;
    char pC63;
    float fC64;
    float fC68;
    char pC6C[4];
    CC70 mC70;
    int fCE0;
    unsigned char bCE4;
};

extern "C" {
extern char D_004DA470[], D_004DA580[], D_004DAD90[], D_004DAD70[], D_004DA440[], D_004DA410[], D_004DA3E0[], D_004DA2F0[];
extern char g_IdentityMatrix[];
extern float D_004A3FC8;
extern char D_0048A158[], D_0048A160[];
extern signed char D_004E1D80;
void cGOBJ_ctor(Cam_17E3F0*, int*, int, int*);
void cGOBJ_CreateXform(Cam_17E3F0*, void*, int);
void cCollisionRoutine_cBox_ctor(void*);
V4c* cVector_GetZero(void);
void cVector_ctor_cVectorR(V4c* d, const V4c* s);
void cQuaternion_ctor_void(V4c*);
void cArray_cVector_ctor(V4c*);
V4c cVector_Get0001(void);
V4c cQuaternion_GetIdentity(void);
V4c cQuaternion_GetZero(void);
void func_0017F8B0(void*);
float func_0017F860(float);
void cQuaternion_ctor_cQuaternionR(V4c* d, const V4c* s);
void cSplinedMotion_cQuaternion_ctor(CurveA* c, const V4c* q, const V4c* z);
void cSplinedMotion_cVector_ctor(CurveB* c, const V4c* o, const V4c* z);
void cSplinedMotion_float_ctor_floatR_floatR(void*, char*, char*);
void cSplinedMotion_Scalar_ctor(void*);
void cCameraShake_cPulsedShakeMagnitude_ctor(void*);
void cSplinedMotion_Vector_ctor(void*);
void cCollisionModelList_ctor(CC70*, int*, int*);
void cActivationTracker_ctor(V4c*);
void cMatrix_SetAxes(Mtx_17E3F0* m, V4c* a, V4c* b, V4c* c);
void cMatrix_SetTranslation(Mtx_17E3F0* m, V4c* t);
void cGOBJ_DestroyXform(Cam_17E3F0*);
void cGOBJ_UpdateMotion(Cam_17E3F0*, float);
}

extern "C" {
extern Pair_17E3F0 D_00497F00;
Pair_17E3F0* cQuatVec_ctor_cQuaternionR_cVectorR(Pair_17E3F0* p, const V4c* a, const V4c* b);
Pair_17E3F0* cQuatVec_ctor_cQuatVecR(Pair_17E3F0* d, const Pair_17E3F0* s);
}
static inline const Pair_17E3F0& IdentPl_17E3F0(void)
{
    if (!D_004E1D80) {
        cQuatVec_ctor_cQuaternionR_cVectorR(&D_00497F00, &cQuaternion_GetIdentity(), &cVector_Get0001());
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
static inline int Read_17E3F0(Reader_17E3F0* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline float ReadF_17E3F0(Reader_17E3F0* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void ReadV_17E3F0(Reader_17E3F0* r, V4c* v, float w)
{
    float x = ReadF_17E3F0(r);
    float y = ReadF_17E3F0(r);
    float z = ReadF_17E3F0(r);
    v->w = w; v->x = x; v->y = y; v->z = z;
}
static inline void CurveA_Init(CurveA* c, unsigned char f)
{
    cSplinedMotion_cQuaternion_ctor(c, &cQuaternion_GetIdentity(), &cQuaternion_GetZero());
    c->vtbl = D_004DA440;
    c->bC0 = f;
}
static inline void CurveB_Init(CurveB* c)
{
    cSplinedMotion_cVector_ctor(c, &cVector_Get0001(), cVector_GetZero());
    c->vtbl = D_004DA410;
}
static inline void Bounds_Init(V4c* lo, V4c* hi)
{
    lo->x = 3.4028235e38f; lo->y = 3.4028235e38f; lo->z = 3.4028235e38f; lo->w = 1.0f;
    hi->x = -3.4028235e38f; hi->y = -3.4028235e38f; hi->z = -3.4028235e38f; hi->w = 1.0f;
}
#pragma push
#pragma opt_propagation off
static inline void QId_17E3F0(V4c* q) { float x = 0.0f; float y = 0.0f; float z = 0.0f; float w = 1.0f; q->x = x; q->y = y; q->z = z; q->w = w; }
static inline void SetF60_17E3F0(Cam_17E3F0* c) { float a = 1.134464f; float h = 0.5f; c->f60 = h * a; }
#pragma pop
static inline void SetO_17E3F0(V4c* p) { asm { sqc2 vf0, 0x0(p) } }

extern "C" Cam_17E3F0* Camera_ConstructStream(Cam_17E3F0* self, Reader_17E3F0* r)
{
    int idv;
    int b0, b1;
    int g0, g1;
    V4c r0, r1, r2, pos;
    Mtx_17E3F0 m;
    g1 = 0;
    g0 = 0;
    cGOBJ_ctor(self, &g0, 9, &g1);
    self->vtbl = D_004DA470;
    self->f60 = 0;
    self->f64 = 0;
    cGOBJ_CreateXform(self, g_IdentityMatrix, 0);
    self->f30 = 0;
    self->vtbl = D_004DA580;
    {
        Base70* p = &self->m70;
        cCollisionRoutine_cBox_ctor(p);
        p->vtbl = D_004DAD90;
        cVector_ctor_cVectorR(&p->v10, cVector_GetZero());
        cQuaternion_ctor_void(&p->v20);
        cArray_cVector_ctor(&p->v30);
        cVector_ctor_cVectorR(&p->v40, &cVector_Get0001());
        cVector_ctor_cVectorR(&p->v50, &cVector_Get0001());
        p->b60 = 0;
        cVector_ctor_cVectorR(&p->v70, &cVector_Get0001());
        p->b80 = 0;
        func_0017F8B0(p->o90);
    }
    self->f130 = 0;
    Bounds_Init(&self->lo140, &self->hi150);
    self->f160 = 0;
    self->f164 = 0;
    {
        Base170* p = &self->m170;
        cCollisionRoutine_cBox_ctor(p);
        p->vtbl = D_004DAD70;
        p->b4 = 0;
        p->f8 = func_0017F860(D_004A3FC8);
        cQuaternion_ctor_cQuaternionR(&p->v10, &cQuaternion_GetIdentity());
        p->f20 = 0;
        p->f24 = 0;
        cVector_ctor_cVectorR(&p->v30, &cVector_Get0001());
        cVector_ctor_cVectorR(&p->v40, cVector_GetZero());
    }
    self->f1C0 = 0;
    Bounds_Init(&self->lo1D0, &self->hi1E0);
    self->f1F0 = 0;
    self->f1F4 = 0;
    self->b200 = 0;
    self->b201 = 1;
    { CurveA* c = &self->c210; CurveA_Init(c, 1); }
    { CurveB* c = &self->c2E0; CurveB_Init(c); }
    { CurveB* c = &self->c3A0; CurveB_Init(c); }
    { CurveA* c = &self->c460; CurveA_Init(c, 0); }
    { CurveA* c = &self->c530; CurveA_Init(c, 0); }
    { CurveB* c = &self->c600; CurveB_Init(c); }
    { CurveB* c = &self->c6C0; CurveB_Init(c); }
    { CurveA* c = &self->c780; CurveA_Init(c, 1); }
    { CurveB* c = &self->c850; CurveB_Init(c); }
    { CurveB* c = &self->c910; CurveB_Init(c); }
    { CurveB* c = &self->c9D0; CurveB_Init(c); }
    {
        char* p = self->mA90;
        cSplinedMotion_float_ctor_floatR_floatR(p, D_0048A158, D_0048A160);
        *(char**)p = D_004DA3E0;
    }
    Pair_17E3F0 pl;
    IdentPl_17E3F0();
    cQuatVec_ctor_cQuatVecR(&pl, &D_00497F00);
    V4c oa, ob;
    self->place.a = pl.a;
    self->place.b = pl.b;
    SetO_17E3F0(&ob);
    { V4c* d = &self->vAF0; *d = (oa = ob); }
    QId_17E3F0(&self->qB00);
    QId_17E3F0(&self->qB10);
    {
        char* p = self->mB20;
        cSplinedMotion_Scalar_ctor(p);
        cCameraShake_cPulsedShakeMagnitude_ctor(p + 0x38);
        cSplinedMotion_Vector_ctor(p + 0x80);
    }
    self->bC60 = 0;
    self->bC62 = 0;
    self->fC64 = 1.134464f;
    self->fC68 = 1.134464f;
    {
        CC70* p = &self->mC70;
        b1 = 0;
        b0 = 0;
        cCollisionModelList_ctor(p, &b0, &b1);
        p->vtbl = D_004DA2F0;
        p->f20 = 0;
        cVector_ctor_cVectorR(&p->v30, cVector_GetZero());
        cActivationTracker_ctor(&p->v40);
        p->f60 = 0;
    }
    {
        int hi = Read_17E3F0(r);
        int lo = Read_17E3F0(r);
        idv = lo | (hi << 16);
        self->id = *(Id_17E3F0*)&idv;
    }
    ReadV_17E3F0(r, &pos, 1.0f);
    ReadV_17E3F0(r, &r0, 0.0f);
    ReadV_17E3F0(r, &r1, 0.0f);
    ReadV_17E3F0(r, &r2, 0.0f);
    cMatrix_SetAxes(&m, &r0, &r1, &r2);
    cMatrix_SetTranslation(&m, &pos);
    cGOBJ_DestroyXform(self);
    cGOBJ_CreateXform(self, &m, 0);
    SetF60_17E3F0(self);
    cGOBJ_UpdateMotion(self, 0.0f);
    self->fCE0 = 0;
    self->bCE4 = 0;
    return self;
}
static inline void merge_flush_func_0017E3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017E3F0 */

/* merge_units: begin func_0017EB50 */
#pragma push /* merge_units */
extern char D_004DA410[];
extern void cSplinedMotion_cVector_TeleportByDelta();
extern void cSplinedMotion_cVector_UpdateVelocity();
extern void cSplinedMotion_cVector_UpdateSplinePoints();
extern void cSplinedMotion_float_UpdateSplinePoints();
extern void cSplinedMotion_float_UpdateVelocity();
extern void cSplinedMotion_float_FixUpResultOfSplineEvaluation();
extern void cSplinedMotion_cVector_FixUpResultOfSplineEvaluation();
extern void func_0017ECD0();
extern void cCollisionSystem_cBox_dtor_void();
extern void cSplinedMotion_float_TeleportByDelta();
void * const D_004DA380[12] = { (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)cSplinedMotion_float_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_float_UpdateSplinePoints, (void*)cSplinedMotion_float_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_float_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004DA3B0[12] = { (void*)0x0, (void*)0x0, (void*)cCollisionSystem_cBox_dtor_void, (void*)cSplinedMotion_cVector_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_cVector_UpdateSplinePoints, (void*)cSplinedMotion_cVector_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_cVector_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_004DA3E0[];
extern void cSplinedMotion_Scalar_dtor_void(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EB50;
V_EB50* cCameraShake_dtor(V_EB50* self, short flag)
{
    if (self) {
        V_EB50* m = (V_EB50*)((char*)self + 0x80);
        void* m2;
        if (m) {
            self[0x20].vt = D_004DA410;
            if (m)
                self[0x20].vt = ((char*)D_004DA3B0);
        }
        m2 = (char*)self + 0x38;
        if (m2)
            cSplinedMotion_Scalar_dtor_void(m2, -1);
        if (self) {
            self->vt = D_004DA3E0;
            if (self)
                self->vt = ((char*)D_004DA380);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0017EB50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0017EB50 */
