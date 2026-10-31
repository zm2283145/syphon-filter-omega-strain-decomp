#pragma cplusplus on
#include "types.h"
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

struct cSKYBOX_GOBJ {
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

extern "C" void cSKYBOX_GOBJ_Load(cSKYBOX_GOBJ* self)
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
