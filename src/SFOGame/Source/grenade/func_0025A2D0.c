#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "vslot_pad.h"

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; Q16(d, &o); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; Q16(d, s); return *this; }
} __attribute__((aligned(16)));
struct M4P { V r0, r1, r2, r3; M4P() {} } __attribute__((aligned(16)));
static inline void UM(void* p0) { void* p = p0; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline V operator-(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(p), "r"(a), "r"(b) : "memory");
    return r;
}
static inline V operator+(const V& a0, const V& b0) {
    V r; V* p = &r; const V* a = &a0; const V* b = &b0;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(p), "r"(a), "r"(b) : "memory");
    return r;
}
static inline V operator*(const V& a0, float k) {
    V r; V* p = &r; const V* a = &a0; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(p), "r"(a), "f"(k) : "memory");
    return r;
}
static inline V Mul2(const V& a0, float k) {
    const V* a = &a0; V r; V* p = &r; __int128 t = 0;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(p), "r"(a), "f"(k) : "memory");
    return r;
}

struct Def { char pad[0xBC]; unsigned char kind; char padBD[0xB]; float radius; char padCC[0x10]; int opaque; };
struct Owner { char pad[0xC]; int serial; };
struct XNode { virtual void v0(); virtual void SetMatrix(const M4P& m); };
struct RGB { float r, g, b; RGB(float r0, float g0, float b0) : r(r0), g(g0), b(b0) {} };
struct RGBA { float r, g, b, a; RGBA() {} };
struct Light { int x0; char* vt; };
struct LightV { int x0; VPAD8(a) VPAD1(b) virtual void Enable(); };
struct Face {
    struct VV { float x, y, z, w; } verts[3];
    V normal;
    unsigned char b40, b41, b42;
    char pad43[0x60 - 0x43];
    int l60, l64;
    char pad68[8];
    
} __attribute__((aligned(16)));
static inline void FaceInit(Face* f) { __asm__("" : "+r"(f)); { Face::VV* e = f->verts; Face::VV* end = f->verts + 3; do { e++; } while (e != end); } f->b40 = 0; f->b42 = 0; f->l60 = 0; f->l64 = 0; }
struct Los;
struct AE {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Activate(int on);
    VPAD8(d) VPAD4(e)
    virtual void CreateXform(const void* m, int f);
    char pad4[0x2B];
    unsigned char b2F;
    char pad30[0x50 - 0x30];
    XNode* xform;
    char pad54[0x60 - 0x54];
    float t;
    char pad64[0xC];
    V loc;
    Def* entry;
    Owner* owner;
    int ownerId;
    char pad8C[4];
    V edge[4];
    Light* light;
    unsigned char deletePending;
    unsigned char instant;
    unsigned char opaque;
};

extern "C" {
extern char D_004DC5B0[];
extern char D_004D9200[];
extern char g_IdentityMatrix[];
extern char D_004F8040[];
extern char g_LightMgr[];
extern char g_Game[];
extern char g_LosCheckService[];
extern float D_0048B010;
extern float D_0048B018;
extern signed char D_004F8050;
extern V D_004F8060[4];
void nGobjManager_GetNextId(int* id, int kind);
void cGOBJ_ctor(void* self, int* gid, int n, int* tag);
void nGobjManager_AddGOBJ(void* o);
void func_0025A860(void* list, AE** p);
void* cLightMan_AddLight(void* mgr, int type);
RGBA* tRGBA_ctor_tRGBR_float(RGBA* out, const RGB* c, float a);
Light* cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(Light* l, int type, RGBA* c, V* pos, int f);
void LightEffect_SetInner(Light* l, float r);
void LightEffect_SetOuter(Light* l, float r);
Los* cSystemContainer_GetSystem(void* c, void* name);
bool cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(Los* los, V* hit, Face* face, V* from, V* ray, void* g1, void* g2, int a, int b, int c, void* cb, int d);

AE* cAreaEffect_ctor(AE* self, Owner* thrower, V* loc, Def* entry, unsigned char instant);
}

struct PointLight : Light {
    PointLight(const RGB& c, AE** s, float in, float out); 
    void* operator new(unsigned int, void* p) { return p; }
};

inline PointLight::PointLight(const RGB& c, AE** s, float in, float out) { cLightSrc_ctor_eLightSrcTypes_tRGBAR_cVectorR_uint(this, 4, tRGBA_ctor_tRGBR_float(&RGBA(), &c, 0.0f), &(*s)->loc, 3); vt = D_004D9200; LightEffect_SetInner(this, in); LightEffect_SetOuter(this, out); }
static inline Light* NewLight(AE** ps) { return new (cLightMan_AddLight(g_LightMgr, 4)) PointLight(RGB(1.0f, 1.0f, 1.0f), ps, D_0048B018, D_0048B010); }
static inline Light* NewLight2(AE** ps) { return NewLight(ps); }
static inline Light* NewLight3(AE** ps) { return NewLight2(ps); }
static inline Light* NewLight4(AE** ps) { return NewLight3(ps); }
AE* cAreaEffect_ctor(AE* self, Owner* thrower, V* loc, Def* entry, unsigned char instant)
{
    int id;
    int tag;
    tag = 0;
    nGobjManager_GetNextId(&id, 245);
    cGOBJ_ctor(self, &id, 3, &tag);
    *(char**)self = D_004DC5B0;
    self->ownerId = -2;
    self->owner = 0;
    { V* e = self->edge; V* end = self->edge + 4; do { e++; } while (e != end); }
    self->b2F = 1;
    self->owner = thrower;
    {
        int none;
        self->ownerId = *(thrower ? &thrower->serial : (none = -1, &none));
    }
    self->loc = *loc;
    self->entry = entry;
    self->deletePending = 0;
    self->t = 0.0f;
    self->instant = instant;
    {
        M4P mat;
        UM(&mat);
        mat.r3 = *loc;
        self->CreateXform(g_IdentityMatrix, 0);
        self->xform->SetMatrix(mat);
        self->Activate(1);
        nGobjManager_AddGOBJ(self);
        func_0025A860(D_004F8040, &self);
        self->opaque = self->entry->opaque != 0;
        if (self->entry->kind == 3) {
            self->light = NewLight4(&self);
        } else {
            self->light = 0;
        }
        if (self->light) ((LightV*)self->light)->Enable();
        {
            unsigned char k = self->entry->kind;
            if (k == 5 || k == 6 || k == 7) {
                Los* los = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
                if (!D_004F8050) {
                    D_004F8060[0].x = 0.0f; D_004F8060[0].y = 1.0f; D_004F8060[0].z = 0.0f; D_004F8060[0].w = 0.0f;
                    D_004F8060[1].x = 0.0f; D_004F8060[1].y = -1.0f; D_004F8060[1].z = 0.0f; D_004F8060[1].w = 0.0f;
                    D_004F8060[2].x = 1.0f; D_004F8060[2].y = 0.0f; D_004F8060[2].z = 0.0f; D_004F8060[2].w = 0.0f;
                    D_004F8060[3].x = -1.0f; D_004F8060[3].y = 0.0f; D_004F8060[3].z = 0.0f; D_004F8060[3].w = 0.0f;
                    D_004F8050 = 1;
                }
                for (int i = 0; i < 4; i++) {
                    V hitPoint;
                    Face face;
                    FaceInit(&face);
                    V ray = D_004F8060[i] * self->entry->radius;
                    bool hit = cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(los, &hitPoint, &face, loc, &ray, 0, 0, 0, 88, 0, 0, 0);
                    if (hit) {
                        self->edge[i] = *loc + Mul2(hitPoint - *loc, 0.9f);
                    } else {
                        self->edge[i] = *loc + ray;
                    }
                }
            }
        }
    }
    return self;
}
