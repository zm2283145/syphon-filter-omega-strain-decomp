#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"

typedef unsigned long U64;
typedef long S64;
typedef unsigned int u_int;
typedef __int128 u_long128;

struct cMatrix {
    float m[4][4];
    cMatrix();
    cMatrix(const cMatrix& o);
    cMatrix& operator=(const cMatrix& o);
    cMatrix operator*(const cMatrix& b) const;
} __attribute__((aligned(16)));
struct cVector {
    float x, y, z, w;
    cVector() {}
    /* quadword copies (lq/sq) */
    cVector(const cVector& o) { void* xx = this; u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    cVector& operator=(const cVector& o) { u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector operator*(float s) const;
} __attribute__((aligned(16)));
struct tRGBA { float r, g, b, a; };
struct tIRGBA { int r, g, b, a; };
struct cXViewport {
    char pad0[0x90];
    cVector scale;
    cVector offset;
    char padB0[0x100 - 0xB0];
    float fov;
    char pad104[0x110 - 0x104];
};
struct cTexMan {
    char pad0[0x14];
    unsigned char batching;
    char pad15;
    unsigned char b16;
    char pad17;
    unsigned int count;
    short queue[512];
};
struct cTexture;
struct XLib {
    char pad0[0x1C];
    int scrW;
    int scrH;
    char pad24[0x2C - 0x24];
    int scrPsm;
    char pad30[0xD0 - 0x30];
    unsigned char restore;
    char padD1[0xF8 - 0xD1];
    unsigned int fbMask;
    char padFC[0x120 - 0xFC];
    unsigned int prim;
    unsigned int alphaFix;
    unsigned int fog;
    unsigned int vram[2];
    unsigned int zbuf;
    char pad138[0x140 - 0x138];
    int curBuf;
    char pad144[0x160 - 0x144];
    int fogR, fogG, fogB;
    char pad16C[0x180 - 0x16C];
    float fogNear;
    char pad184[0x190 - 0x184];
    float fogFar;
    char pad194[0x1F0 - 0x194];
    cXViewport viewportStack[8];
    int viewportNum;
    int viewNum;
    char padA78[0xA80 - 0xA78];
    cMatrix viewStack[16];
    cMatrix flipMat;
    cMatrix compMat;
    char padF00[0x1058 - 0xF00];
    cTexMan* texMan;
    char pad105C[0x1060 - 0x105C];
    int activeTID;
    char pad1064[0x10E8 - 0x1064];
    U64 alphaReg;
};

extern "C" {
extern int g_DrawMode;
extern char D_00537F80[];
extern U64 D_004BC1B0;
void cMatrix_ctor_void(cMatrix* m);
cXViewport* XLib_GetViewport(XLib* x);
const cMatrix* cXViewport_GetProjMat(cXViewport* v);
void cMatrix_ctor_cMatrixR(cMatrix* m, const cMatrix* o);
int cXViewport_IsOrtho(cXViewport* v);
cMatrix cMatrix_opMul_cMatrixR(const cMatrix* a, const cMatrix* b);
void cMatrix_opAssign(cMatrix* d, const cMatrix* s);
u_int XLib_GetOutCode(XLib* x, const cMatrix* m, const cVector* v);
void XLib_UpdateCompMat(XLib* x);
void cXViewport_Validate(cXViewport* v);
float Libc_Tanf(float f);
void TexMan_UploadSlots(cTexMan* t);
void XLib_UpdateRenderFrameEnv(XLib* x);
U64* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
U64 XLib_GetPrimEnv(XLib* x);
U64 XLib_GetPixelEnv(XLib* x);
cTexMan* XLib_GetTexMan(XLib* x);
U64* cTexMan_GetTEX0_1(cTexMan* t, int i);
U64* cTexMan_GetTEX1_1(cTexMan* t, int i);
void cDmaMan_EndChain_int(void* q, int n);
U64* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void* q, int a, int b, int c, int d);
cVector* cVector_ctor_float_float_float_float(cVector* v, float x, float y, float z, float w);
int nSFO_Macros_FTOI(float f);
float XLib_GetGuardBandScaleX(XLib* x);
float XLib_GetGuardBandScaleY(XLib* x);
tIRGBA* tIRGBA_ctor(tIRGBA* c, int r, int g, int b, int a);
cTexture* cTexMan_GetTexture(cTexMan* t, int id);
int cTexture_GetWidth(cTexture* t);
int cTexture_GetHeight(cTexture* t);
int cTexture_GetPSM(cTexture* t);
U64* cTexture_GetTEX0_1(cTexture* t);
u_int cTexMan_GetTxtrAddr(cTexMan* t, int id);
float cVector_GetLength(cVector* v);
void XLib_FrameEnvChanged(XLib* x);
void cDmaMan_EndChain_int_ulongP(void* q, int n, U64* p);
void XLib_DrawLensFlares(XLib* self, const cVector& src, float size, const tRGBA* cols, const int* tids, const float* poss, const float* scls, int num, unsigned char dazzle, unsigned char cover);
}

inline cMatrix::cMatrix() { cMatrix_ctor_void(this); }
inline cMatrix::cMatrix(const cMatrix& o) { cMatrix_ctor_cMatrixR(this, &o); }
inline cMatrix& cMatrix::operator=(const cMatrix& o) { cMatrix_opAssign(this, &o); return *this; }
inline cMatrix cMatrix::operator*(const cMatrix& b) const { return cMatrix_opMul_cMatrixR(this, &b); }

/* integer conversion as cvt.w.s + mfc1 (a C cast compiles to trunc.w.s) */
static inline int F2I(float f) { int r = 0; float t; asm { cvt.w.s t, f; mfc1 r, t } return r; }

/* VU0 4x4 matrix * vector */
static inline cVector operator*(const cMatrix& m, const cVector& v)
{
    const cMatrix* a = &m;
    cVector t(v);
    cVector* o = &t;
    asm { lqc2 vf8, 0x0(o); lqc2 vf4, 0x0(a); lqc2 vf5, 0x10(a); lqc2 vf6, 0x20(a); lqc2 vf7, 0x30(a); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(o) }
    return *o;
}
inline cVector cVector::operator*(float s) const
{
    cVector r;
    const cVector* a = this;
    int q;
    cVector* o = &r;
    /* VU0 vector * scalar; noreorder: retail has no hazard nop between the mfc1 and the qmtc2 */
    asm { .set noreorder; lqc2 vf1, 0x0(a); mfc1 q, s; qmtc2.ni q, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(o); .set reorder }
    return *o;
}
static inline cXViewport* CurVP(XLib* x) { cXViewport* v = &x->viewportStack[x->viewportNum]; return v; }
static inline cMatrix LensImpl(XLib* self)
{
    cMatrix m;
    cMatrix proj(*cXViewport_GetProjMat(XLib_GetViewport(self)));
    proj.m[0][0] /= 1.5f;
    proj.m[1][1] /= 1.5f;
    if (!cXViewport_IsOrtho(XLib_GetViewport(self))) {
        m = cMatrix_opMul_cMatrixR(&cMatrix_opMul_cMatrixR(&proj, &self->flipMat), &self->viewStack[self->viewNum]);
    } else {
        m = proj * self->viewStack[self->viewNum];
    }
    return m;
}
static inline cMatrix LensMatrix(XLib* self) { return LensImpl(self); }
static inline u_int OutCode0(XLib* self, const cMatrix& m, const cVector& v) { return XLib_GetOutCode(self, &m, &v); }
static inline u_int OutCode(XLib* self, const cVector& v) { return OutCode0(self, LensMatrix(self), v); }
static inline const cVector& VpScale(XLib* self) { cXViewport* v = &self->viewportStack[self->viewportNum]; cXViewport_Validate(v); return v->scale; }
static inline const cVector& VpOffset(XLib* self) { cXViewport* v = &self->viewportStack[self->viewportNum]; cXViewport_Validate(v); return v->offset; }
static inline void AddTID(cTexMan* m, int id)
{
    unsigned n = m->count;
    if (n < 512) {
        if (n == 0 || m->queue[n - 1] != id) m->queue[m->count++] = id;
    }
}
static inline U64 Dup2(U64 v) { return v | (v << 2); }
static inline void FlushFrameEnv(XLib* self)
{
    int n;
    U64* q;
    if (self->restore) {
        XLib_UpdateRenderFrameEnv(self);
        self->restore = 0;
    }
    n = 9;
    if (self->activeTID != -1) n += 2;
    {
        int one = 1;
        q = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, one, one, n + 2, 0, one);
    }
    *q++ = 0x11000000;
    *q++ = 0x300002E | ((U64)0x20001E9 << 32);
    *q++ = 0x1000404 | ((U64)(u_int)((n + 1) | 0x50000000) << 32);
    *q++ = (S64)n | (0x8000 | ((U64)0x10000000 << 32));
    *q++ = 0xE;
    *q++ = self->prim;
    *q++ = 0x1A;
    *q++ = XLib_GetPrimEnv(self);
    *q++ = 0x1B;
    *q++ = XLib_GetPixelEnv(self);
    *q++ = 0x47;
    *q++ = self->alphaFix;
    *q++ = 0x46;
    if (self->alphaReg == D_004BC1B0) {
        *q++ = (S64)self->fogR | ((S64)self->fogG << 8) | ((S64)self->fogB << 16);
    } else {
        *q++ = 0;
    }
    *q++ = 0x3D;
    *q++ = Dup2(self->fog);
    *q++ = 8;
    *q++ = Dup2(self->fog);
    *q++ = 9;
    *q++ = 0;
    *q++ = 0x3F;
    *q++ = self->alphaReg;
    *q++ = 0x42;
    if (self->activeTID != -1) {
        *q++ = *cTexMan_GetTEX0_1(XLib_GetTexMan(self), self->activeTID);
        *q++ = 6;
        *q++ = *cTexMan_GetTEX1_1(XLib_GetTexMan(self), self->activeTID);
        *q++ = 0x14;
        self->activeTID = -1;
    }
    cDmaMan_EndChain_int(D_00537F80, 1);
}
static inline U64* DrawFlares(XLib* self, U64* vif, const tRGBA* cols, const int* tids, const float* poss, const float* scls, int num,
                              unsigned char dazzle, unsigned char cover, float alphaScl, float flareW, float flareH, int x, int y)
{
    int hw = self->scrW >> 1;
    int hh = self->scrH >> 1;
    cVector dir;
    int i;
    cVector_ctor_float_float_float_float(&dir, (2048.0f - (float)x) / (float)hw, (2048.0f - (float)y) / (float)hh, 0.0f, 0.0f);
    for (i = 0; i < num; i++) {
        int px = nSFO_Macros_FTOI((float)x - dir.x * poss[i]);
        int py = nSFO_Macros_FTOI((float)y - dir.y * poss[i]);
        int w = nSFO_Macros_FTOI(flareW * scls[i]);
        int h = nSFO_Macros_FTOI(flareH * scls[i]);
        int gx = nSFO_Macros_FTOI((float)hw * XLib_GetGuardBandScaleX(self));
        int gy = nSFO_Macros_FTOI((float)hh * XLib_GetGuardBandScaleY(self));
        if (px < 2048 - gx + w) continue;
        if (px > gx + 2048 - w) continue;
        if (py < 2048 - gy + h) continue;
        if (py > gy + 2048 - h) continue;
        {
            tIRGBA col;
            cTexture* tex;
            int tw;
            int th;
            int psm;
            U64 tex0;
            u_int addr;
            int ga;
            tIRGBA_ctor(&col, nSFO_Macros_FTOI(128.0f * cols[i].r), nSFO_Macros_FTOI(128.0f * cols[i].g), nSFO_Macros_FTOI(128.0f * cols[i].b), nSFO_Macros_FTOI(128.0f * (alphaScl * cols[i].a)));
            if (col.a <= 0) continue;
            tex = cTexMan_GetTexture(XLib_GetTexMan(self), tids[i]);
            tw = cTexture_GetWidth(tex);
            th = cTexture_GetHeight(tex);
            psm = cTexture_GetPSM(tex);
            tex0 = *cTexture_GetTEX0_1(tex);
            addr = cTexMan_GetTxtrAddr(XLib_GetTexMan(self), tids[i]) >> 5;
            *vif++ = 0;
            *vif++ = 0x3F;
            *vif++ = (U64)addr | ((U64)((u_int)tw >> 6) << 16) | ((U64)(u_int)psm << 24) | ((U64)0xFFFFFF << 32);
            *vif++ = 0x4D;
            *vif++ = 0x316;
            *vif++ = 0;
            *vif++ = 0xFFFFFFFF;
            *vif++ = 1;
            *vif++ = 0xC100010;
            *vif++ = 3;
            *vif++ = 0;
            *vif++ = 5;
            *vif++ = 0xC100010;
            *vif++ = 3;
            *vif++ = (U64)(u_int)(tw << 4) | ((U64)(u_int)(th << 4) << 16);
            *vif++ = 5;
            *vif++ = 0;
            *vif++ = 0x3F;
            *vif++ = tex0;
            *vif++ = 6;
            ga = 0;
            if (dazzle && i == 0) {
                float l = 1.0f - cVector_GetLength(&dir);
                ga = nSFO_Macros_FTOI(120.0f * (l * (l * (l * l))));
            }
            *vif++ = 0x156;
            *vif++ = 0;
            *vif++ = (S64)col.r | ((S64)col.g << 8) | ((S64)col.b << 16) | ((S64)col.a << 24);
            *vif++ = 1;
            *vif++ = 0;
            *vif++ = 3;
            *vif++ = ((U64)((px - w) << 4) | ((U64)((py - h) << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
            *vif++ = 5;
            *vif++ = (U64)(u_int)(tw << 4) | ((U64)(u_int)(th << 4) << 16);
            *vif++ = 3;
            *vif++ = ((U64)((px + w) << 4) | ((U64)((py + h) << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
            *vif++ = 5;
            if (cover && dazzle && i == 0) {
                U64 uv = (S64)(int)(((u_int)tw >> 1) << 4) | ((S64)(int)(((u_int)th >> 1) << 4) << 16);
                S64 g = ga;
                int x0 = 2048 - (self->scrW >> 1);
                int x1 = (self->scrW >> 1) + 2048;
                int y0 = 2048 - (self->scrH >> 1);
                int y1 = (self->scrH >> 1) + 2048;
                *vif++ = 0x156;
                *vif++ = 0;
                *vif++ = (S64)col.r | ((S64)col.g << 8) | ((S64)col.b << 16) | (g << 24);
                *vif++ = 1;
                *vif++ = uv;
                *vif++ = 3;
                *vif++ = ((U64)(x0 << 4) | ((U64)(y0 << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
                *vif++ = 5;
                *vif++ = uv;
                *vif++ = 3;
                *vif++ = ((U64)(x1 << 4) | ((U64)(y1 << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
                *vif++ = 5;
            }
            XLib_FrameEnvChanged(self);
        }
    }
    return vif;
}

static inline cVector Xf(const cMatrix& m, const cVector& v) { return m * v; }
static inline U64* DrawFlares2(XLib* self, U64* vif, const tRGBA* cols, const int* tids, const float* poss, const float* scls, int num,
                              unsigned char dazzle, unsigned char cover, float alphaScl, float flareW, float flareH, int x, int y)
{ return DrawFlares(self, vif, cols, tids, poss, scls, num, dazzle, cover, alphaScl, flareW, flareH, x, y); }
static inline U64* DrawFlares3(XLib* self, U64* vif, const tRGBA* cols, const int* tids, const float* poss, const float* scls, int num,
                              unsigned char dazzle, unsigned char cover, float alphaScl, float flareW, float flareH, int x, int y)
{ return DrawFlares2(self, vif, cols, tids, poss, scls, num, dazzle, cover, alphaScl, flareW, flareH, x, y); }
extern "C" void XLib_DrawLensFlares(XLib* self, const cVector& src, float size, const tRGBA* cols, const int* tids, const float* poss, const float* scls, int num, unsigned char dazzle, unsigned char cover)
{
    if (num == 0) return;
    u_int ocode = OutCode(self, src);
    if (ocode & ~0x40) return;
    float alphaScl = 1.0f;
    XLib_UpdateCompMat(self);
    cVector sunScr = Xf(self->compMat, src);
    float invw = 1.0f / sunScr.w;
    if (ocode & 0x40) {
        if (g_DrawMode & 0x180) {
            float fval = 0.5019608f * (self->fogNear + self->fogFar * invw);
            if (fval <= 0.0f) return;
            fval = (fval < 128.0f) ? fval : 128.0f;
            alphaScl = fval / 128.0f;
        }
    }
    const cVector& scl = VpScale(self);
    const cVector& off = VpOffset(self);
    cVector pscl = scl * invw;
    sunScr.x = off.x + sunScr.x * pscl.x;
    sunScr.y = off.y + sunScr.y * pscl.y;
    sunScr.z = off.z + sunScr.z * pscl.z;
    float fovScl = 1.0f / Libc_Tanf(CurVP(self)->fov);
    const float k = 0.015625f;
    cVector sizeScl;
    sizeScl.x = k * (fovScl * pscl.x);
    sizeScl.y = k * (fovScl * pscl.y);
    float sampSz = 0.5f * sizeScl.x;
    float flareW = size * sizeScl.x;
    float flareH = size * -sizeScl.y;
    int x = F2I(sunScr.x) >> 4;
    int y = F2I(sunScr.y) >> 4;
    int z = F2I(sunScr.z) >> 4;
    int scrLimitX = self->scrW >> 1;
    int scrLimitY = self->scrH >> 1;
    int cx = x;
    int cy = y;
    int cs = F2I(sampSz);
    if (cs > 40) cs = 40;
    if (cx < 2048 - scrLimitX + cs) cx = 2048 - scrLimitX + cs;
    if (cx > 2048 + scrLimitX - cs) cx = 2048 + scrLimitX - cs;
    if (cy < 2048 - scrLimitY + cs) cy = 2048 - scrLimitY + cs;
    if (cy > 2048 + scrLimitY - cs) cy = 2048 + scrLimitY - cs;
    u_int scrw = *(u_int*)((char*)self + 0x10);
    u_int scrh = self->scrH;
    u_int scrp = self->scrPsm;
    {
        cTexMan* tm = self->texMan;
        tm->batching = 1;
        tm->count = 0;
        tm->b16 = 0;
    }
    for (int t = 0; t < num; t++) {
        AddTID(self->texMan, tids[t]);
    }
    TexMan_UploadSlots(self->texMan);
    FlushFrameEnv(self);
    U64* start = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 1);
    U64* vif = start;
    *vif++ = 0;
    *vif++ = 0;
    *vif++ = 0xE;
    *vif++ = 1;
    *vif++ = 0x1A;
    u_int fbMsk = self->fbMask & 0xFFFFFF;
    *vif++ = (((U64)(scrw >> 6) << 16) | (U64)self->vram[self->curBuf]) | ((U64)scrp << 24) | ((U64)fbMsk << 32);
    *vif++ = 0x4C;
    *vif++ = 0x6A;
    *vif++ = 0x42;
    *vif++ = 0x51001;
    *vif++ = 0x47;
    *vif++ = 0x46;
    *vif++ = 0;
    *vif++ = 0;
    *vif++ = 1;
    *vif++ = ((U64)((cx - cs) << 4) | ((U64)((cy - cs) << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
    *vif++ = 5;
    *vif++ = ((U64)((cx + cs) << 4) | ((U64)((cy + cs) << 4) << 16)) | ((U64)0xFFFFFFFF << 32);
    *vif++ = 5;
    *vif++ = 0xFFFFFFFF;
    *vif++ = 1;
    *vif++ = ((U64)((x - cs) << 4) | ((U64)((y - cs) << 4) << 16)) | ((U64)z << 32);
    *vif++ = 5;
    *vif++ = ((U64)((x + cs) << 4) | ((U64)((y + cs) << 4) << 16)) | ((U64)z << 32);
    *vif++ = 5;
    *vif++ = (((U64)(scrw >> 6) << 16) | (U64)self->vram[self->curBuf]) | ((U64)scrp << 24) | ((U64)0xFFFFFF << 32);
    *vif++ = 0x4D;
    *vif++ = self->zbuf;
    *vif++ = 0x4F;
    *vif++ = 0x60;
    *vif++ = 0x15;
    *vif++ = (((U64)(scrw >> 6) << 14) | (U64)(u_int)(self->vram[self->curBuf] << 5)) | ((U64)scrp << 20) | 0xEA8000000;
    *vif++ = 7;
    *vif++ = 5;
    *vif++ = 9;
    *vif++ = 0x31001;
    *vif++ = 0x48;
    *vif++ = 0;
    *vif++ = 0x19;
    *vif++ = 0x316;
    *vif++ = 0;
    int soffx0 = 0x7FF - scrLimitX;
    int soffy0 = 0x7FF - scrLimitY;
    int soffx1 = 0x801 - scrLimitX;
    int soffy1 = 0x801 - scrLimitY;
    *vif++ = 0;
    *vif++ = 0x3F;
    *vif++ = (U64)((cx - cs - soffx0) << 4) | ((U64)((cy - cs - soffy0) << 4) << 16);
    *vif++ = 3;
    *vif++ = 0x4000000;
    *vif++ = 5;
    *vif++ = (U64)((cx + cs - soffx1) << 4) | ((U64)((cy + cs - soffy1) << 4) << 16);
    *vif++ = 3;
    *vif++ = 0x6000200;
    *vif++ = 5;
    *vif++ = 0;
    *vif++ = 0x3F;
    *vif++ = 0x4100010;
    *vif++ = 3;
    *vif++ = 0x7000000;
    *vif++ = 5;
    *vif++ = 0x6100210;
    *vif++ = 3;
    *vif++ = 0x8000100;
    *vif++ = 5;
    *vif++ = 0;
    *vif++ = 0x3F;
    *vif++ = 0x7100010;
    *vif++ = 3;
    *vif++ = 0x9000000;
    *vif++ = 5;
    *vif++ = 0x8100110;
    *vif++ = 3;
    *vif++ = 0x9800080;
    *vif++ = 5;
    *vif++ = 0;
    *vif++ = 0x3F;
    *vif++ = 0x9100010;
    *vif++ = 3;
    *vif++ = 0xA000000;
    *vif++ = 5;
    *vif++ = 0x9900090;
    *vif++ = 3;
    *vif++ = 0xA400040;
    *vif++ = 5;
    *vif++ = 0;
    *vif++ = 0x3F;
    *vif++ = 0xA100010;
    *vif++ = 3;
    *vif++ = 0xC000000;
    *vif++ = 5;
    *vif++ = 0xA500050;
    *vif++ = 3;
    *vif++ = 0xC200020;
    *vif++ = 5;
    *vif++ = 1;
    *vif++ = 0x46;
    *vif++ = 0x8000000048;
    *vif++ = 0x42;
    *vif++ = 0x4010;
    *vif++ = 8;
    vif = DrawFlares3(self, vif, cols, tids, poss, scls, num, dazzle, cover, alphaScl, flareW, flareH, x, y);
    *vif++ = 0x11000000;
    *vif++ = 0;
    int qwc = (vif - start) >> 1;
    *start++ = 0x13000000 | ((U64)(u_int)(qwc | 0x50000000) << 32);
    *start = (S64)(qwc - 1) | (0x8000 | ((U64)0x10000000 << 32));
    cDmaMan_EndChain_int_ulongP(D_00537F80, 1, vif);
    self->restore = 1;
}
