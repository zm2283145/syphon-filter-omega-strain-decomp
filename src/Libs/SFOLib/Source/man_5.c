/*
 * Libs/SFOLib/Source/man: 3 files, 00385370-003855D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00385370 */
#pragma push /* merge_units */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vu0_ops.h"

typedef struct { float x, y, z, w; } V4_385420;
typedef struct { V4_385420 r[4]; } Mtx_385420;
typedef struct { V4_385420 trans; float m[3][4]; char pad[0x10]; } Attach_385420;
typedef struct {
    char pad0[0x14];
    unsigned char flag14;
    char pad15[3];
    char nodes[0x10];
    void* xform;
} Skel_385420;
typedef struct {
    char pad0[0x2450];
    unsigned char node[0x10];
    Attach_385420 attach[0x10];
    char pad[0x2C04 - 0x2460 - 0x10 * 0x50];
    Skel_385420* skel;
} Actor_385420;
void cMan_GetGunMatrix_WithoutFlippingAxes(Actor_385420* a, Mtx_385420* out, int i); /* gsynth: defined below */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void Q5370(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q5370(this, &o); }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    void Rotate(V* v) const { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(v), "r"(this) : "memory"); }
    V Rotated(V v) const { V* p = &v; Rotate(p); return *p; }
    void Translate(V v) { __asm__ volatile("lqc2 vf1, 0x30(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x30(%0)" : : "r"(this), "r"(&v) : "memory"); }
};
struct Muzzle { char pad[0x130]; V off; };
struct Weapon { char pad[0x2410]; Muzzle* muzzle[4]; };
#if 0 /* merge_units */
extern "C" void cMan_GetGunMatrix_WithoutFlippingAxes(Weapon* a, M* out, int i);
#endif /* merge_units */
#define cMan_GetGunMatrix_WithoutFlippingAxes(a0, a1, a2) (cMan_GetGunMatrix_WithoutFlippingAxes((Actor_385420 *)(a0), (Mtx_385420 *)(a1), (a2))) /* merge_units */


extern "C" void cMan_GetGunBarrelMatrix_WithoutFlippingAxes(Weapon* w, M* m, int i)
{
    cMan_GetGunMatrix_WithoutFlippingAxes(w, m, i);
    if (w->muzzle[i]) {
        m->Translate(m->Rotated(w->muzzle[i]->off));
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00385370(void) {}
#undef cMan_GetGunMatrix_WithoutFlippingAxes /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00385370 */

/* merge_units: begin func_00385420 */
#pragma push /* merge_units */
extern void* cArray_cBone_opIndex_int(void*, int);
extern void* cBone_Xform(void*);
extern Mtx_385420* cXform_GetMatrix(void*);
extern void cMatrix_GetTransformed(Mtx_385420*, Mtx_385420*, Mtx_385420*);
extern void cMatrix_ctor_cMatrixR(Mtx_385420*, Mtx_385420*);

/* Indexing through an unsized-array view emits idx*0x50 + base (retail addu order). */
#define ATT(a, i) (*(Attach_385420(*)[])(a)->attach)[i]

void cMan_GetGunMatrix_WithoutFlippingAxes(Actor_385420* a, Mtx_385420* out, int i)
{
    Mtx_385420 node;
    Mtx_385420 m;
    Skel_385420* s = a->skel;
    int n = a->node[i];
    Attach_385420* at;
    Mtx_385420* pm;
    V4_385420* d;
    V4_385420* src;
    Mtx_385420* pn;

    if (s->flag14) {
        Mtx_385420* t = cXform_GetMatrix(cBone_Xform(cArray_cBone_opIndex_int(s->nodes, n)));
        cMatrix_GetTransformed(&node, t, cXform_GetMatrix(s->xform));
    } else {
        cMatrix_ctor_cMatrixR(&node, cXform_GetMatrix(s->xform));
    }
    d = &m.r[3];
    pm = &m;
    src = &ATT(a, i).trans;
    m.r[0].x = ATT(a, i).m[0][0];
    m.r[0].y = ATT(a, i).m[0][1];
    m.r[0].z = ATT(a, i).m[0][2];
    m.r[1].x = ATT(a, i).m[1][0];
    m.r[1].y = ATT(a, i).m[1][1];
    m.r[1].z = ATT(a, i).m[1][2];
    m.r[2].x = ATT(a, i).m[2][0];
    m.r[2].y = ATT(a, i).m[2][1];
    m.r[2].z = ATT(a, i).m[2][2];
    m.r[0].w = ATT(a, i).m[0][3];
    m.r[1].w = ATT(a, i).m[1][3];
    m.r[2].w = ATT(a, i).m[2][3];
    { __int128 q = V4Load(src); pn = &node; V4Store(d, q); }
    VU0_MulMtx44(out, pn, pm);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00385420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00385420 */

/* merge_units: begin func_003855D0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef unsigned long long U64;
struct cMatrix { float m[4][4]; } __attribute__((aligned(16)));
struct cMatrixNxM { float m[4][3]; } __attribute__((aligned(16)));
struct Parts { __int128* part; unsigned short qwc; char pad[10]; };
struct gunList {
    char pad0[0x2C0];
    Parts gunParts[2][8];
    char pad3C0[0x40C - 0x3C0];
    unsigned char gunPartCount;
    unsigned char gunHoldType;
    unsigned char gunHoldTypeHand2;
    unsigned char gunAnimType;
    signed char gunHolsterPart;
    signed char gunFlarePart;
    signed char gunLightPart;
    signed char gunStockPartOn;
    signed char gunStockPartOff;
    unsigned char gunGlow;
    signed char gunTransparency;
    signed char gunLoading;
    unsigned char gunMalloc;
    unsigned char gunIsBullet;
    int gunRefCount;
};
struct manRenderSPAD {
    char header[0xA50];
    U64 manTex0[32];
    U64 gunTex0[8][8];
    cMatrix gunBoneData[8][11];
    cMatrixNxM gunLightData[8];
    U64 shellTex0;
};
struct cMan {
    char pad0[0x2410];
    gunList* manGuns[10];
    char gunInvis[10];
    char gunOnOffFlag[10];
    char pad244C[0x2D90 - 0x244C];
    unsigned char triggerPulled;
    unsigned char triggerPulled2;
};

static inline void QMove(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

extern "C" U64* cMan_ManDMAGuns(cMan* self, U64* dmaVif, int lod, int shadow, int transparency)
{
    manRenderSPAD* SPAD = (manRenderSPAD*)0x70000000;
    U64 backclip = 0;
    int j;
    gunList* aGun;
    U64 vifCode3;
    int k;
    int gunGlow;
    int lightPart;
    int holsterPart;
    int stockPart;
    int flarePart;
    unsigned int i;

    if (transparency != 128) backclip = 32;
    for (j = 0; j < 8; j++) {
        aGun = self->manGuns[j];
        if (aGun == 0) continue;
        if (self->gunInvis[j]) continue;
        if (aGun->gunLoading) continue;
        vifCode3 = 0x6C4D008500000000ULL | 0x15000000;
        *dmaVif++ = 0x1000004D;
        *dmaVif++ = vifCode3;
        for (k = 0; k < 11; k++) {
            QMove(dmaVif, &SPAD->gunBoneData[j][k], 4);
            QMove(dmaVif + 8, &SPAD->gunLightData[j], 3);
            dmaVif += 14;
        }
        gunGlow = aGun->gunGlow;
        lightPart = aGun->gunLightPart;
        if (self->gunOnOffFlag[j]) lightPart = -1;
        holsterPart = aGun->gunHolsterPart;
        if (j == 3 || j == 4) holsterPart = -1;
        stockPart = aGun->gunStockPartOn;
        if (j == 0) stockPart = aGun->gunStockPartOff;
        if (j == 6 && self->gunOnOffFlag[j]) stockPart = aGun->gunStockPartOff;
        flarePart = aGun->gunFlarePart;
        for (i = 0; i < aGun->gunPartCount; i++) {
            if (aGun->gunParts[lod][i].part == 0) continue;
            if (i == holsterPart) continue;
            if (i == lightPart) continue;
            if (i == stockPart) continue;
            if (i != flarePart) {
                dmaVif[0] = 0x10000001;
                dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                dmaVif[2] = SPAD->gunTex0[j][i];
                dmaVif[3] = backclip;
                dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                dmaVif[5] = 0;
                dmaVif += 6;
            } else if (!shadow) {
                if (gunGlow || (j == 0 && self->triggerPulled && self->triggerPulled < 3)) {
                    dmaVif[0] = 0x10000001;
                    dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                    dmaVif[2] = SPAD->gunTex0[j][i];
                    dmaVif[3] = 0xBFC00000ULL;
                    dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                    dmaVif[5] = 0;
                    dmaVif += 6;
                }
                if (gunGlow || (j == 1 && self->triggerPulled2 && self->triggerPulled2 < 3)) {
                    dmaVif[0] = 0x10000001;
                    dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
                    dmaVif[2] = SPAD->gunTex0[j][i];
                    dmaVif[3] = 0xBFC00000ULL;
                    dmaVif[4] = (long long)(int)(aGun->gunParts[lod][i].qwc + 0x30000000) + ((U64)(unsigned int)aGun->gunParts[lod][i].part << 32);
                    dmaVif[5] = 0;
                    dmaVif += 6;
                }
            }
        }
    }
    if (self->manGuns[0] && self->manGuns[0]->gunHolsterPart != -1) {
        U64 vifCode3 = 0x6C07008500000000ULL | 0x15000000;
        int holsterPart;
        *dmaVif++ = 0x10000007;
        *dmaVif++ = vifCode3;
        QMove(dmaVif, &SPAD->gunBoneData[3][0], 4);
        QMove(dmaVif + 8, &SPAD->gunLightData[3], 3);
        dmaVif += 14;
        holsterPart = self->manGuns[0]->gunHolsterPart;
        dmaVif[0] = 0x10000001;
        dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
        dmaVif[2] = SPAD->gunTex0[0][holsterPart];
        dmaVif[3] = backclip;
        dmaVif[4] = (long long)(int)(self->manGuns[0]->gunParts[lod][holsterPart].qwc + 0x30000000) + ((U64)(unsigned int)self->manGuns[0]->gunParts[lod][holsterPart].part << 32);
        dmaVif[5] = 0;
        dmaVif += 6;
    }
    if (self->manGuns[1] && self->manGuns[1]->gunHolsterPart != -1) {
        U64 vifCode3 = 0x6C07008500000000ULL | 0x15000000;
        int holsterPart;
        *dmaVif++ = 0x10000007;
        *dmaVif++ = vifCode3;
        QMove(dmaVif, &SPAD->gunBoneData[4][0], 4);
        QMove(dmaVif + 8, &SPAD->gunLightData[4], 3);
        dmaVif += 14;
        holsterPart = self->manGuns[1]->gunHolsterPart;
        dmaVif[0] = 0x10000001;
        dmaVif[1] = 0x6C01806800000000ULL | 0x01000404;
        dmaVif[2] = SPAD->gunTex0[1][holsterPart];
        dmaVif[3] = backclip;
        dmaVif[4] = (long long)(int)(self->manGuns[1]->gunParts[lod][holsterPart].qwc + 0x30000000) + ((U64)(unsigned int)self->manGuns[1]->gunParts[lod][holsterPart].part << 32);
        dmaVif[5] = 0;
        dmaVif += 6;
    }
    return dmaVif;
}
static inline void merge_flush_func_003855D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003855D0 */
