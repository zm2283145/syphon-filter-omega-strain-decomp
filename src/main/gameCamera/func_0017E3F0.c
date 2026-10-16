#pragma cplusplus on
#pragma exceptions off
#include "types.h"

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
extern char D_0055C9F0[];
extern float D_004A3FC8;
extern char D_0048A158[], D_0048A160[];
extern signed char D_004E1D80;
void cGOBJ_ctor(Cam_17E3F0*, int*, int, int*);
void Object_AttachTransform(Cam_17E3F0*, void*, int);
void func_0017F9D0(void*);
V4c* Vec4_GetZero(void);
void Vec4_Assign(V4c* d, const V4c* s);
void func_00132840(V4c*);
void func_0017F980(V4c*);
V4c Vec4_SetOrigin(void);
V4c Quat_SetIdentity(void);
V4c func_0017F820(void);
void func_0017F8B0(void*);
float func_0017F860(float);
void func_00132800(V4c* d, const V4c* s);
void CameraCurve_MakeQuaternion(CurveA* c, const V4c* q, const V4c* z);
void func_0017F520(CurveB* c, const V4c* o, const V4c* z);
void PhysicalBase_Construct(void*, char*, char*);
void func_0017F330(void*);
void func_0017F2E0(void*);
void Curve_Construct(void*);
void func_00136540(CC70*, int*, int*);
void func_001364B0(V4c*);
void Mtx_SetBasis(Mtx_17E3F0* m, V4c* a, V4c* b, V4c* c);
void Mtx_SetTranslation(Mtx_17E3F0* m, V4c* t);
void func_003CDF20(Cam_17E3F0*);
void Actor_BaseWorldUpdate(Cam_17E3F0*, float);
}

extern "C" {
extern Pair_17E3F0 D_00497F00;
Pair_17E3F0* Placement_GetIdentity(Pair_17E3F0* p, const V4c* a, const V4c* b);
Pair_17E3F0* VecPair_Copy(Pair_17E3F0* d, const Pair_17E3F0* s);
}
static inline const Pair_17E3F0& IdentPl_17E3F0(void)
{
    if (!D_004E1D80) {
        Placement_GetIdentity(&D_00497F00, &Quat_SetIdentity(), &Vec4_SetOrigin());
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
    CameraCurve_MakeQuaternion(c, &Quat_SetIdentity(), &func_0017F820());
    c->vtbl = D_004DA440;
    c->bC0 = f;
}
static inline void CurveB_Init(CurveB* c)
{
    func_0017F520(c, &Vec4_SetOrigin(), Vec4_GetZero());
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
    Object_AttachTransform(self, D_0055C9F0, 0);
    self->f30 = 0;
    self->vtbl = D_004DA580;
    {
        Base70* p = &self->m70;
        func_0017F9D0(p);
        p->vtbl = D_004DAD90;
        Vec4_Assign(&p->v10, Vec4_GetZero());
        func_00132840(&p->v20);
        func_0017F980(&p->v30);
        Vec4_Assign(&p->v40, &Vec4_SetOrigin());
        Vec4_Assign(&p->v50, &Vec4_SetOrigin());
        p->b60 = 0;
        Vec4_Assign(&p->v70, &Vec4_SetOrigin());
        p->b80 = 0;
        func_0017F8B0(p->o90);
    }
    self->f130 = 0;
    Bounds_Init(&self->lo140, &self->hi150);
    self->f160 = 0;
    self->f164 = 0;
    {
        Base170* p = &self->m170;
        func_0017F9D0(p);
        p->vtbl = D_004DAD70;
        p->b4 = 0;
        p->f8 = func_0017F860(D_004A3FC8);
        func_00132800(&p->v10, &Quat_SetIdentity());
        p->f20 = 0;
        p->f24 = 0;
        Vec4_Assign(&p->v30, &Vec4_SetOrigin());
        Vec4_Assign(&p->v40, Vec4_GetZero());
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
        PhysicalBase_Construct(p, D_0048A158, D_0048A160);
        *(char**)p = D_004DA3E0;
    }
    Pair_17E3F0 pl;
    IdentPl_17E3F0();
    VecPair_Copy(&pl, &D_00497F00);
    V4c oa, ob;
    self->place.a = pl.a;
    self->place.b = pl.b;
    SetO_17E3F0(&ob);
    { V4c* d = &self->vAF0; *d = (oa = ob); }
    QId_17E3F0(&self->qB00);
    QId_17E3F0(&self->qB10);
    {
        char* p = self->mB20;
        func_0017F330(p);
        func_0017F2E0(p + 0x38);
        Curve_Construct(p + 0x80);
    }
    self->bC60 = 0;
    self->bC62 = 0;
    self->fC64 = 1.134464f;
    self->fC68 = 1.134464f;
    {
        CC70* p = &self->mC70;
        b1 = 0;
        b0 = 0;
        func_00136540(p, &b0, &b1);
        p->vtbl = D_004DA2F0;
        p->f20 = 0;
        Vec4_Assign(&p->v30, Vec4_GetZero());
        func_001364B0(&p->v40);
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
    Mtx_SetBasis(&m, &r0, &r1, &r2);
    Mtx_SetTranslation(&m, &pos);
    func_003CDF20(self);
    Object_AttachTransform(self, &m, 0);
    SetF60_17E3F0(self);
    Actor_BaseWorldUpdate(self, 0.0f);
    self->fCE0 = 0;
    self->bCE4 = 0;
    return self;
}
