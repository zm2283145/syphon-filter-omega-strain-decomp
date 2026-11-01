/*
 * Libs/SFOLib/Source/skybox: 8 files, 003BBD00-003BC270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BBD00 */
#pragma push /* merge_units */
#include "types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cSKYBOX_GOBJ: only the slots used here are named (vtable offset in comments). */
struct cSKYBOX_GOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int who); /* +0x68 */
};

/* Script native: cSKYBOX_GOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cSKYBOX_GOBJ_Disable(ScriptArg* args)
{
    cSKYBOX_GOBJ* obj = (cSKYBOX_GOBJ*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD00 */

/* merge_units: begin func_003BBD30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003BBD30 { int i; float f; void* p; unsigned char b; } ScriptArg_003BBD30;

struct cSKYBOX_GOBJ_003BBD30 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int value); /* +0x64 */
};

/* Script native: cSKYBOX_GOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cSKYBOX_GOBJ_Enable(ScriptArg_003BBD30* args)
{
    cSKYBOX_GOBJ_003BBD30* obj = (cSKYBOX_GOBJ_003BBD30*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD30 */

/* merge_units: begin func_003BBD60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ script type registration and class helpers.
 */


extern int D_00542C98;   /* cSKYBOX_GOBJ class type id */
extern int D_00542CA0;   /* cSKYBOX_GOBJ script type */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern int* cGOBJ_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cSKYBOX_GOBJ script type under its parent type. */
void cSKYBOX_GOBJ_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_00542CA0, *parent);
}

int cSKYBOX_GOBJ_getSOBJClassId(void) {
    return D_00542C98;
}

int cSKYBOX_GOBJ_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD60 */

/* merge_units: begin func_003BBDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o, int) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector(const cVector& o, char) { const cVector* src = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(src) : "memory"); }
    cVector(const cVector& o, signed char) { cVector* tt = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(tt), "r"(&o) : "memory"); }
    cVector(const cVector& o, unsigned char) { const cVector* src = &o; void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(src) : "memory"); }
    cVector(const cVector& o, long) { void* xx = this; const cVector* src = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(src) : "memory"); }
    cVector(const cVector& a, const cVector& b, float) { const cVector* p = &a; const cVector* r = &b; asm { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(r); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(this) } }
    cVector(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    void Cp(const cVector& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector operator-(const cVector& o) const {
        cVector t(*this, o, 0.0f); return cVector(t, 0);
    }
    cVector operator*(float k) const {
        cVector t; __int128 tt = 0; cVector* q = &t; const cVector* p = this;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(q); .set reorder }
        return t;
    }
    cVector operator/(float k) const { return *this * (1.0f / k); }
    cVector& operator/=(float k) { return *this *= 1.0f / k; }
    cVector& DivEq(float k) { float r = 1.0f / k; return *this *= r; }
    cVector& DivEq2(float k) { *this *= 1.0f / k; return *this; }
    cVector& operator*=(float k) {
        cVector* p = this; int tt;
        asm { .set noreorder; lqc2 vf1, 0x0(p); mfc1 tt, k; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(p); .set reorder }
        return *this;
    }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
    void SetMul(const cVector& v, float k) { __int128 z = 0; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(&v), "r"(this), "f"(k) : "memory"); }
} __attribute__((aligned(16)));

struct cFileMan { char data[0x9C]; };
struct cHogFile;

struct cBox { cVector bmin; cVector bmax; cVector Size() const { cVector t; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(&bmax), "r"(&bmin) : "memory"); return t; } };
struct cModelInfo { char p0[0x30]; cBox bbox; };
static inline cVector Scale(cVector v, float k) { void* pv = &v; cVector r; r.SetMul(v, k); return r; }
struct cVU1Model { void* data; cModelInfo* info; char p8[0x28]; };

struct cSLayer {
    char hog[0x174];
    cVU1Model model;
    char p1A4[0xC];
    cVector rot;
    cVector drot;
    cVector lrot;
    cVector trans;
    cVector dir;
    float dist;
    float ddist;
    float brad;
    unsigned int flags;
};

struct tSLayerInit {
    char* name;
    char p4[0xC];
    cVector dir;
    cVector drot;
    unsigned int flags;
    char p34[0xC];
};

struct tSKYBOXInit {
    char* hogName;
    char* texName;
    int numLayers;
    char pC[4];
    tSLayerInit layers[1];
};

struct cSKYBOX_GOBJ_003BBDC0 {
    char p0[0x60];
    cHogFile* hogFile;
    cHogFile* texHogFile;
    int numLayers;
    cSLayer* layers[8];
    tSKYBOXInit* init;
    void Add(cSLayer* p) { layers[numLayers] = p; numLayers++; }
    cSLayer* Get(int i) { return layers[i]; }
    tSLayerInit& LI(int i) { return init->layers[i]; }
    unsigned int LF(int i) { return init->layers[i].flags; }
};

extern "C" {
extern char D_004BD030[];
extern char D_004BD038[];
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void cFileMan_ctor_void(cFileMan* fm);
void cFileMan_dtor(cFileMan* fm, int f);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(cFileMan* fm, const char* name, cHogFile* hog, int b);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(cFileMan* fm, const char* name, void* io, int b);
void Alloc_Lock(int);
void EnableIntc(int);
void* cMemMan_Allocate(int, int, char*, int);
cSLayer* cSLayer_ctor(void* p, cFileMan* fm, cFileMan* tf);
char* strchr(const char*, int);
void Libc_Strcpy(char*, const char*);
}

static inline cVector Sz1(const cBox& b) { return b.Size(); }
static inline cVector Sz2(const cBox& b) { return Sz1(b); }
static inline cVector Sz3(const cBox& b) { return Sz2(b); }
static inline cVector Sz4(const cBox& b) { return Sz3(b); }
static inline cVector Sc2(cVector v, float k) { return Scale(v, k); }
static inline cVector ScR(const cVector& v, float k) { return Scale(v, k); }
static inline cVector ScR2(const cVector& v, float k) { return ScR(v, k); }
static inline cVector Sb1(const cVector& a, const cVector& b) { return a - b; }
static inline cVector Sb2(const cVector& a, const cVector& b) { return Sb1(a, b); }
static inline cVector Sb3(const cVector& a, const cVector& b) { return Sb2(a, b); }
static inline cVector Sb4(const cVector& a, const cVector& b) { return Sb3(a, b); }
static inline cVector Dv1(const cVector& a, float b) { return a / b; }
static inline cVector Dv2(const cVector& a, float b) { return Dv1(a, b); }
static inline cVector Dv3(const cVector& a, float b) { return Dv2(a, b); }
static inline cVector Dv4(const cVector& a, float b) { return Dv3(a, b); }
static inline cVector Ml1(const cVector& a, float b) { return a * b; }
static inline cVector Ml2(const cVector& a, float b) { return Ml1(a, b); }
static inline cVector Ml3(const cVector& a, float b) { return Ml2(a, b); }
static inline cVector Ml4(const cVector& a, float b) { return Ml3(a, b); }
static inline float Ln1(const cVector& a) { return a.Length(); }
static inline float Ln2(const cVector& a) { return Ln1(a); }
static inline float Ln3(const cVector& a) { return Ln2(a); }
static inline float Ln4(const cVector& a) { return Ln3(a); }
static inline void SetDirR(cSLayer& layer, const cVector& v) { layer.ddist = v.Length(); layer.dir = v; }
static inline void SetDirV(cSLayer& layer, cVector v) { layer.ddist = v.Length(); layer.dir = v; }
static inline void SetDirR2(cSLayer& layer, const cVector& v) { SetDirR(layer, v); }
static inline void SetDirP(cSLayer* layer, const cVector& v) { layer->ddist = v.Length(); layer->dir = v; }

static inline cVector Sc3(cVector v, float k) { return Sc2(v, k); }
static inline cVector ScR3(const cVector& v, float k) { return ScR2(v, k); }
static inline cVector Sz5(const cBox& b) { return Sz4(b); }
static inline cVector Sz6(const cBox& b) { return Sz5(b); }
static inline cVector Sb5(const cVector& a, const cVector& b) { return Sb4(a, b); }
static inline cVector Sb6(const cVector& a, const cVector& b) { return Sb5(a, b); }
static inline cVector ScD(cVector v, float k, cVector r = cVector()) { void* pv = &v; r.SetMul(v, k); return cVector(r, 0); }
static inline cVector ScDR(const cVector& v, float k, cVector r = cVector()) { r.SetMul(v, k); return r; }
static inline cVector ScD2(cVector v, float k) { return ScD(v, k); }
static inline cVector ScDR2(const cVector& v, float k) { return ScDR(v, k); }
static inline cVector ScDN(cVector v, float k, cVector r = cVector()) { r.SetMul(v, k); return r; }
static inline void SetDirR3(cSLayer& layer, const cVector& v) { SetDirR2(layer, v); }
static inline cVector SbB(const cVector& a, const cVector& b) { void* xx = (void*)&a; return Sb1(a, b); }
static inline cVector SbBb(const cVector& a, const cVector& b) { void* xx = (void*)&b; return Sb1(a, b); }
static inline cVector SbM(const cVector& a, const cVector& b) { cVector r = Sb1(a, b); void* xx = &r; return r; }
static inline cVector SbN(const cVector& a, const cVector& b) { void* xx = (void*)&a; cVector r = a - b; return r; }
static inline float Lx(const cVector& v) { void* xx = (void*)&v; return v.Length(); }
static inline float Lx2(const cVector& v) { return Lx(v); }
static inline float Ly(const cVector& v) { float r = v.Length(); void* xx = (void*)&v; return r; }
static inline float Lz(cVector v) { return v.Length(); }
static inline void CpG(cVector& d, const cVector& s) { d.Cp(s); }
static inline void CpH(cVector& d, const cVector& s) { CpG(d, s); }
static inline void CpI(cVector& d, const cVector& s) { CpH(d, s); }
static inline void CpP(cVector& d, const cVector& s) { void* pv = &d; d.Cp(s); }
static inline void CpQ(cVector& d, const cVector& s) { void* pv = &d; CpG(d, s); }
static inline void CpE(cVector& d, const cVector& s) { d = s; }
static inline void CpE2(cVector& d, const cVector& s) { CpE(d, s); }
static inline cVector ScB(const cBox& b, float k, cVector v = cVector(), cVector r = cVector()) { cVector s; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&s), "r"(&b.bmax), "r"(&b.bmin) : "memory"); void* pv = &v; CpG(v, s); r.SetMul(v, k); return cVector(r, 0); }
static inline cVector ScB2(const cVector& mn, const cVector& mx, float k, cVector v = cVector(), cVector r = cVector()) { cVector s; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&s), "r"(&mx), "r"(&mn) : "memory"); void* pv = &v; CpG(v, s); r.SetMul(v, k); return cVector(r, 0); }
static inline cVector ScB3(const cVector& mx, const cVector& mn, float k, cVector v = cVector(), cVector r = cVector()) { cVector s; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&s), "r"(&mx), "r"(&mn) : "memory"); void* pv = &v; CpG(v, s); r.SetMul(v, k); return cVector(r, 0); }
static inline const cVector& Mx(const cBox& b) { return b.bmax; }
static inline const cVector& Mn(const cBox& b) { return b.bmin; }
static inline const cBox& Bx(const cBox& b) { return b; }
static inline const cBox* Bp(const cBox* b) { return b; }

extern "C" void cSKYBOX_GOBJ_Load(cSKYBOX_GOBJ_003BBDC0* self)
{
    cFileMan fm;
    cFileMan tf;
    char* pHName;
    char* pTName;
    cSLayer* outter;
    int l;
    cSLayer* pl;

    cFileMan_ctor_void(&fm);
    cFileMan_ctor_void(&tf);
    pHName = self->init->hogName;
    pTName = self->init->texName;
    outter = 0;
    self->numLayers = 0;
    for (l = 0; l < self->init->numLayers; l++) {
        char* pFName = self->init->layers[l].name;
        char* extension = strchr(pFName, '.');
        cSLayer* p;
        Libc_Strcpy(extension, D_004BD030);
        if (pHName) {
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&fm, pFName, self->hogFile, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(&tf, pTName, self->texHogFile, 0);
        } else {
            cFileMan_EncodeFilename_charP_cFileIOP_bool(&fm, pFName, 0, 0);
        }
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = (cSLayer*)cMemMan_Allocate(0, 0x210, D_004BD038, 0x9F);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (p) p = cSLayer_ctor(p, &fm, &tf);
        self->layers[self->numLayers] = p;
        self->numLayers++;
        self->Get(l)->flags = self->LF(l);
        if (self->init->layers[l].flags & 0x10) outter = self->Get(l);
    }
    {
        cVector bsize = ScB3(Mx(outter->model.info->bbox), outter->model.info->bbox.bmin, 0.5f);
        cVector blo(-bsize.x, -bsize.y, -bsize.z, 0.0f);
        cVector bhi(bsize.x, bsize.y, bsize.z, 0.0f);
        int i;
        for (i = 0; i < self->numLayers; i++) {
            pl = self->layers[i];
            pl->brad = 0.5f * (bhi - blo).Length();
            {
                const cVector& drot = self->init->layers[i].drot;
                if (pl->flags & 8) {
                    pl->drot = drot;
                } else {
                    pl->drot = Dv4(drot, 60.0f);
                }
            }
            SetDirR(*pl, Ml3(self->init->layers[i].dir, (1.0f / 60.0f)));
            if (pl->ddist != 0.0f) pl->dir /= pl->ddist;
        }
    }
    cFileMan_dtor(&tf, -1);
    cFileMan_dtor(&fm, -1);
}
static inline void merge_flush_func_003BBDC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BBDC0 */

/* merge_units: begin func_003BC270 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ field setter.
 */

#include "skybox_types.h"

void cSKYBOX_GOBJ_Init(cSkyboxGobj* self, int value) {
    self->unk8C = value;
}
static inline void merge_flush_func_003BC270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC270 */

/* merge_units: begin func_003BC280 */
#pragma push /* merge_units */
/* cSKYBOX_GOBJ_Render (proto cSKYBOX_GOBJ::Render): draws the sky layers back to front with
 * z writes off, z test "always", the sky draw context, and the current view with its
 * translation cleared; then restores the context, z state and view. */
#pragma cplusplus on
#pragma inline_depth(8)
typedef unsigned long u_long;
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); return *this; }
    V& r(int i) { return *(V*)m[i]; }
} __attribute__((aligned(16)));
struct cSLayer;
struct cSKYBOX_GOBJ_003BC280 {
    char pad0[0x68];
    int numLayers;
    cSLayer* layers[8];
};
extern "C" {
extern char g_Video[];
extern int g_DrawMode;
extern u_long D_00538290;          /* XLib screen.zbuf */
extern unsigned char D_005382C0;   /* XLib screen.frameEnvChanged */
extern unsigned int D_005382E4;    /* XLib pixenv.ztst */
extern unsigned int D_005382EC;    /* XLib pixenv.zmsk */
extern int D_00538C64;             /* XLib viewNum */
extern unsigned char D_00538C68;   /* XLib compMatDirty */
void cSLayer_Render(cSLayer* l);
void cSKYBOX_GOBJ_Render(cSKYBOX_GOBJ_003BC280* self);
}
#define STK(i) (*(M*)(g_Video + 0xA80 + (i) * 0x40))

/* 128-bit lq/sq copies: C has no quadword move. The dead `p` copy is deliberate: retail keeps
 * the extra destination address computation. */
static inline void CpV(V* dst, const V* src) { V* p = dst; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(dst), "r"(src) : "memory"); }
/* ZBUF.ZMSK (bit 32) follows pixenv.zmsk */
static inline void UpdateZBuf() { u_long m = (u_long)D_005382EC << 32; D_00538290 = (D_00538290 & ~((u_long)1 << 32)) | m; }
static inline void PushView(M& m)
{
    STK(D_00538C64 + 1) = STK(D_00538C64);
    D_00538C64++;
    STK(D_00538C64) = m;
    D_00538C68 = 1;
}

void cSKYBOX_GOBJ_Render(cSKYBOX_GOBJ_003BC280* self)
{
    unsigned int xlibCtxt = g_DrawMode;
    unsigned int skyCtxt;
    M vmat;
    int i;
    skyCtxt = (xlibCtxt & ~0x1F0) | 0x10000000;
    D_005382EC = 1;
    D_005382C0 = 1;
    D_005382E4 = 1;
    g_DrawMode = skyCtxt;
    UpdateZBuf();
    vmat = STK(D_00538C64);
    { V t(0.0f, 0.0f, 0.0f, 1.0f); CpV((V*)vmat.m[3], &t); }
    PushView(vmat);
    for (i = self->numLayers - 1; i >= 0; i--)
        cSLayer_Render(self->layers[i]);
    D_00538C64--;
    g_DrawMode = xlibCtxt;
    D_00538C68 = 1;
    D_005382C0 = 1;
    D_005382EC = 0;
    UpdateZBuf();
    D_005382E4 = 2;
}
static inline void merge_flush_func_003BC280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BC280 */

/* merge_units: begin func_003BC520 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0x68]; int count; void* items[1]; } G4_Act;
extern void cSLayer_Update(void* a);
extern void cGOBJ_NextFrame(G4_Act* a, float dt);
void cSKYBOX_GOBJ_NextFrame(G4_Act* a, float dt)
{
    int i;
    for (i = 0; i < a->count; i++) {
        cSLayer_Update(a->items[i]);
    }
    cGOBJ_NextFrame(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC520 */

/* merge_units: begin func_003BC5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004DFC70[];
void cGOBJ_dtor(void* self, int flag);
void cHogFile_dtor(void* p, int flag);
void cVU1Model_dtor(void* p, int flag);
void cVU1Model_Unload(void* p);
void operator_delete(void* p);
}
struct SkyM {
    char pad0[0x16C]; void* p16C; unsigned char b170; char pad171[3]; char m174[4];
};
struct SkyG {
    void* vt; char pad4[0x64]; int n68; SkyM* a6C[1];
};
static inline void DelSky(SkyM* p)
{
    AllocGuard g;
    if (p) {
        cVU1Model_Unload(p->m174);
        if (p->b170) {
            void* q = p->p16C;
            AllocGuard g2;
            cMemMan_Deallocate(0, q, D_004BD038, 0x2B);
        }
        cVU1Model_dtor(p->m174, -1);
        cHogFile_dtor(p, -1);
    }
    cMemMan_Deallocate(0, p, D_004BD038, 0x97);
}
extern "C" SkyG* cSKYBOX_GOBJ_dtor(SkyG* self, short flag)
{
    int i;
    if (self) {
        self->vt = D_004DFC70;
        for (i = 0; i < self->n68; i++) {
            if (self->a6C[i])
                DelSky(self->a6C[i]);
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC5A0 */
