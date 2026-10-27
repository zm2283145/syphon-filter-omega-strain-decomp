/*
 * SFOGame/Source/taser: 2 files, 00264BB0-00264E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00264BB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; V* d = this; register __int128 q; asm volatile { lq q, 0x0(s)
 sq q, 0x0(d) } return *this; }
} __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, t;
    M() {}
};
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
struct Ctl;
struct Tgt;
struct HeldItem {
    void* owner;
    Ctl* ctl;
    char p8[0x34 - 0x8];
    unsigned char b34; char p35[3];
    char p38[0x60 - 0x38];
    M m60;
};
extern "C" {
extern void cMessage_ctor_cMessageNameR(void* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void* cSKM_GOBJ_GetSkeleton_void(Tgt* t);
extern void cSkeleton_GetBoneToWorldMatrix(M* out, void* skel, signed char code);
extern void cMatrix_InvertRot(M* m);
extern int cMatrix_IsZeroTranslation(M* m);
extern V* func_00133EC0(M* m);
extern V* cVector_ctor_cVectorR(V* d, V* s);
extern void cVector_NegateXYZ(V* v);
extern void cVector_Rotate_cMatrixR(V* v, M* m);
extern void cMatrix_SetTranslation(M* m, V* v);
extern void cGameSystem_PushWeaponCam(void* w, Tgt* t, Ctl* c);
extern void cAirTaser_BeginShocking_cHumanP_int_cVector(HeldItem* h, Tgt* t, int part, V pos);
extern unsigned char g_IsMultiplayer;
extern signed char ActorNodeCodeTable[];
extern char g_Game[];
extern char g_ActorActionMsgClass[];
extern char D_00504050[];
extern char D_004DCDA0[];
extern char D_004DCF10[];
extern char D_004E01E0[];
extern char D_004E0840[];
extern int D_0048B1D0;
void cAirTaser_BeginShocking_cHumanP_int(HeldItem* h, Tgt* t, int part);
}
static inline void InvertRigid(M* m)
{
    cMatrix_InvertRot(m);
    if (!cMatrix_IsZeroTranslation(m)) {
        V t;
        cVector_ctor_cVectorR(&t, func_00133EC0(m));
        cVector_NegateXYZ(&t);
        cVector_Rotate_cMatrixR(&t, m);
        cMatrix_SetTranslation(m, &t);
    }
}

struct StateMsg {
    void* vt;
    char pad4[0x24 - 0x4];
    int state;
    char sub;
    char pad29[3];
    int stamp;
};
struct TaserMsg {
    void* vt;
    char pad4[0x1C - 0x4];
    int i1C;
    char b20;
    char pad21[3];
    char b24;
    char pad25[3];
    Tgt* tgt;
    int part;
    char pad30[0x10];
    V pos;
};
static inline void StateMsg_Init(StateMsg* p, int st, char sb)
{
    cMessage_ctor_cMessageNameR(p, g_ActorActionMsgClass);
    p->vt = D_004E0840;
    p->state = st;
    p->sub = sb;
    p->vt = D_004E01E0;
    p->stamp = D_0048B1D0;
}
static inline void TaserMsg_Init(TaserMsg* p, Tgt* t, int part, V v)
{
    cMessage_ctor_cMessageNameR(p, D_00504050);
    p->vt = D_004DCF10;
    p->vt = D_004DCDA0;
    p->b24 = 1;
    p->tgt = t;
    p->part = part;
    p->pos = v;
}
void cAirTaser_BeginShocking_cHumanP_int(HeldItem* h, Tgt* t, int part)
{
    V pos;
    M m;
    TaserMsg tm;
    StateMsg sm;
    if (part > -1) {
        cSkeleton_GetBoneToWorldMatrix(&m, cSKM_GOBJ_GetSkeleton_void(t), ActorNodeCodeTable[(unsigned char)part]);
        InvertRigid(&m);
        pos = h->m60.t;
        Apply(&pos, &m, &pos);
    }
    if (!h->b34) cGameSystem_PushWeaponCam(g_Game, t, h->ctl);
    {
        StateMsg* p = &sm;
        cMessage_ctor_cMessageNameR(p, g_ActorActionMsgClass);
        p->vt = D_004E0840;
        p->state = 7;
        p->sub = 2;
        p->vt = D_004E01E0;
        p->stamp = D_0048B1D0;
        QueueMessage_cMessageR_cSystemP_int(p, t, 0);
        sm.vt = D_004E0840;
        cMessage_dtor(p, 0);
    }
    if (g_IsMultiplayer) {
        V v = pos;
        TaserMsg* p = &tm;
        cMessage_ctor_cMessageNameR(p, D_00504050);
        p->vt = D_004DCF10;
        p->vt = D_004DCDA0;
        p->b24 = 1;
        p->tgt = t;
        p->part = part;
        p->pos = v;
        tm.b20 = 4;
        tm.i1C = 0x40;
        QueueMessage_cMessageR_cSystemP_int(&tm, h->ctl, 0);
        tm.vt = D_004DCF10;
        cMessage_dtor(p, 0);
    }
    cAirTaser_BeginShocking_cHumanP_int_cVector(h, t, part, pos);
}
static inline void merge_flush_func_00264BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264BB0 */

/* merge_units: begin func_00264E10 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef int Q128 __attribute__((mode(TI)));
static inline void QCopy(void* d, const void* s) { Q128 q; __asm__ volatile("lq %0, 0x0(%2)\n sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void QCopyB(void* d, const void* s) { register Q128 q; asm volatile { lq q, 0x0(s)
 sq q, 0x0(d) } }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4& operator=(const V4& o) { QCopyB(this, &o); return *this; }
    void Set(const V4& o) { QCopy(this, &o); }
} __attribute__((aligned(16)));
struct Vd {
    float x, y, z, w;
    Vd() {}
    Vd& operator=(const Vd& o) { Q128 tt = 0; QCopy(this, &o); return *this; }
} __attribute__((aligned(16)));
struct V3 { float x, y, z; } __attribute__((aligned(16)));
struct Mtx { float m[4][4]; } __attribute__((aligned(16)));
struct Owner { char p[0x3C]; int x3C; };
struct VObj58 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int Check(bool a, bool b); /* 0x54 */
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual void GetMtx(Mtx* m, int a, int b); /* 0x60 */
};
struct Ctl { char p[0x14]; unsigned char b14; char p15[0x58 - 0x15]; VObj58* x58; };
struct Tgt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual V4 GetPos(int a); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual int Kind(); /* 0x108 */
    int pad4[2];
    int id;
    char p10[0x4C - 0x10];
    int x4C;
    char p50[0x58 - 0x50];
    VObj58* x58;
    char p5C[0x320C - 0x5C];
    int x320C;
    char p3210[0x33A0 - 0x3210];
    int x33A0;
    char p33A4[0x346A - 0x33A4];
    unsigned char b346A;
};
typedef Tgt HObj;
struct Trail {
    int pad;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07();
    virtual void Update(V4* p); /* 0x28 */
};
struct Seg { V4 pos; V4 x10; V4 a; V4 b; };
struct Query {
    Ctl* ctl; Mtx* frame; int x08; unsigned char b0C; char p0D[3];
    int sub; float range; Owner* owner; float x1C;
    unsigned char b20; char p21[3]; int x24; float x28; unsigned char b2C; unsigned char b2D; char p2E[2];
    int hit; float dist; Tgt* tgt; int part; int pad40[4];
};
struct HeldItem_00264E10 {
    Owner* owner;
    Ctl* ctl;
    unsigned char b8; char p9[3];
    Trail* trail;
    char x10[4];
    int idx;
    Mtx* segs;
    char p1C[0x2C - 0x1C];
    HObj* hp;
    int hid;
    unsigned char b34; char p35[3];
    int x38;
    char p3C[0x50 - 0x3C];
    Vd x50;
    Mtx m60;
    V4 xA0;
    float xB0;
    char pB4[0xC0 - 0xB4];
    int xC0;
    static bool Same(int a, int b) { return a == b; }
    bool Valid() { return !hp || Same(hp->id, hid); }
    HObj* Get() { return Valid() ? hp : 0; }
    void Set(HObj* o) { hp = o; int d; hid = *(o ? &o->id : (d = -1, &d)); }
    void Clear() { Set(0); }
    bool Tracking() { return !b34; }
    Mtx*& Segs() { return segs; }
};
extern "C" {
extern float D_0048B0F0;
extern float D_0048B100;
extern float D_0048B108;
extern int g_HumanActorClassKey;
extern char D_004A8210[];
extern int g_Hud;
void GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(Mtx* m, V4* v, Vd* out);
void cAirTaser_Release(HeldItem_00264E10* h);
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(Mtx* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
void CheckBulletCollisions(Query* q);
int cHuman_IsInvulnerable(Tgt* t);
void cHud_SetCallout(float a, float b, int c, void* pos, void* name, int d, int e, int f);
void std_vector_imp_TaserPoint_insert(void* a, Mtx* m, int n, Seg* s);
void cParticle_NextFrame(float dt, int a, Mtx* m, int b);
#if 0 /* merge_units */
void cAirTaser_BeginShocking_cHumanP_int(HeldItem_00264E10* h, Tgt* t, int part);
#endif /* merge_units */
#define cAirTaser_BeginShocking_cHumanP_int(a0, a1, a2) (cAirTaser_BeginShocking_cHumanP_int((HeldItem *)(a0), (a1), (a2))) /* merge_units */

void cAirTaser_SmoothLine(float a, HeldItem_00264E10* h, int b);
int cAirTaser_LosBlocked(HeldItem_00264E10* h);
}
static inline float Abs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Clamp(float v, float lo, float hi) { float r = 0.0f; asm { max.s r, v, lo } asm { min.s r, r, hi } return r; }
static inline void M3Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(o)
        sqc2 vf9, 0x10(o)
        sqc2 vf10, 0x20(o)
        sqc2 vf11, 0x30(o)
    }
}
static inline void Apply_00264E10(V4* o, Mtx* m, V4* v) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void RotEuler(Mtx* m, const V3& a) {
    float az = a.z; float ay = a.y; float ax = a.x;
    float cz = COS(az); float sz = SIN(az);
    float cx = COS(ax); float sx = SIN(ax);
    float cy = COS(ay); float sy = SIN(ay);
    float cycz = cy * cz; float cysz = cy * sz; float sycz = sy * cz; float sysz = sy * sz;
    cMatrix_Set_ColumnMajorForm(m, cycz + sysz * sx, -cysz + sycz * sx, sy * cx,
                      cx * sz, cx * cz, -sx,
                      -sycz + cysz * sx, sysz + cycz * sx, cy * cx);
}
static inline void Emit(HeldItem_00264E10* self, const V4& p) {
    Seg s;
    s.a.x = 0.0f; s.a.y = 0.0f; s.a.z = 0.0f; s.a.w = 0.0f;
    s.b.x = 0.65f; s.b.y = 0.65f; s.b.z = 1.0f; s.b.w = 1.0f;
    s.pos = p;
    std_vector_imp_TaserPoint_insert(self->x10, self->Segs() + self->idx, 1, &s);
}
extern "C" void cAirTaser_UpdateShot(HeldItem_00264E10* self, float dt) {
    unsigned char live = self->ctl->b14;
    if (live && cAirTaser_LosBlocked(self)) {
        cAirTaser_Release(self);
        return;
    }
    if (!self->Get()) self->b34 = 1;
    if (!self->b34) self->xA0.Set(self->Get()->GetPos(self->x38));
    Vd dir;
    GetTargetAngle_cMatrixR_cVectorR_cEulerAngleTP(&self->m60, &self->xA0, &dir);
    if (!(Abs(dir.x) <= 0.5f) || !(Abs(dir.z) <= 0.5f)) {
        dir = self->x50;
    } else {
        dir.x = Clamp(dir.x, -D_0048B100, D_0048B100);
        dir.z = Clamp(dir.z, -D_0048B108, D_0048B108);
    }
    self->x50 = dir;
    {
        V3 ang;
        Mtx rot;
        ang.y = 0.0f;
        ang.x = dir.x;
        ang.z = dir.z;
        RotEuler(&rot, ang);
        M3Mul(&rot, &self->m60, &rot);
        self->m60.m[0][0] = rot.m[0][0];
        self->m60.m[0][1] = rot.m[0][1];
        self->m60.m[0][2] = rot.m[0][2];
        self->m60.m[1][0] = rot.m[1][0];
        self->m60.m[1][1] = rot.m[1][1];
        self->m60.m[1][2] = rot.m[1][2];
        self->m60.m[2][0] = rot.m[2][0];
        self->m60.m[2][1] = rot.m[2][1];
        self->m60.m[2][2] = rot.m[2][2];
        self->m60.m[0][3] = rot.m[0][3];
        self->m60.m[1][3] = rot.m[1][3];
        self->m60.m[2][3] = rot.m[2][3];
    }
    Query q;
    q.x1C = 0.0f;
    q.sub = -1;
    q.b2C = 1;
    q.b20 = 0;
    q.b0C = 0;
    q.x08 = 0;
    q.x24 = 0;
    q.b2D = 1;
    float step = dt * D_0048B0F0;
    if (live) {
        q.ctl = self->ctl;
        q.range = step;
        q.frame = &self->m60;
        q.owner = self->owner;
        q.b20 = 1;
        q.x28 = 0.2f;
        CheckBulletCollisions(&q);
        if (q.hit) step = q.dist;
    }
    self->xB0 += step;
    V4 a;
    a.x = 0.0f; a.y = step / 2.0f; a.z = 0.0f; a.w = 1.0f;
    V4 b;
    b.x = 0.0f; b.y = step; b.z = 0.0f; b.w = 1.0f;
    Apply_00264E10(&a, &self->m60, &a);
    Apply_00264E10(&b, &self->m60, &b);
    Emit(self, a);
    Emit(self, b);
    *(V4*)self->m60.m[3] = b;
    cParticle_NextFrame(dt, self->xC0, &self->m60, 0);
    if (live && q.hit && q.tgt) {
        self->Clear();
        unsigned char k = q.tgt->Kind();
        bool dead = true;
        if (k != 3 && k != 2) dead = false;
        int* pd;
        int id;
        if (!dead && (pd = &g_HumanActorClassKey, id = *pd, q.tgt->x4C == id)) {
            Tgt* t = q.tgt;
            bool mine = false;
            bool held = false;
            if (self->Tracking()) {
                if (t == self->Get()) held = true;
            }
            if (held && self->x38 == -1) mine = true;
            bool m2 = mine;
            VObj58* o = t->x58;
            bool blocked = false;
            if (o && o->Check(held, mine)) blocked = true;
            if (blocked || t->x320C == 2 || t->x320C == 0x1A || cHuman_IsInvulnerable(t) || t->b346A || cAirTaser_LosBlocked(self)) {
                cAirTaser_Release(self);
            } else if ((m2 || q.hit == 3) && t->x33A0) {
                cHud_SetCallout(5.0f, 0.0f, g_Hud, (char*)t + 0xC, D_004A8210, -1, 0, 0);
                cAirTaser_Release(self);
            } else {
                cAirTaser_BeginShocking_cHumanP_int(self, t, q.part);
            }
        } else {
            cAirTaser_Release(self);
        }
    }
    {
        Mtx m;
        self->ctl->x58->GetMtx(&m, 0, 0);
        *(V4*)self->Segs() = *(V4*)m.m[3];
    }
    if (self->trail) self->trail->Update(&b);
    cAirTaser_SmoothLine(1.0f, self, 1);
    if (live && self->b8 == 1 && !(self->xB0 <= (float)self->owner->x3C)) {
        self->Clear();
        cAirTaser_Release(self);
    }
}
#undef cAirTaser_BeginShocking_cHumanP_int /* merge_units */
static inline void merge_flush_func_00264E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00264E10 */
