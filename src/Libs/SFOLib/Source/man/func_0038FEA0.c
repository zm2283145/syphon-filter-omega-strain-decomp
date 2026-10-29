#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct M;
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; __int128 q; V* pd = this; const V* ps = &o; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V& operator=(const V& o) { void* xx = this; V* pd = this; const V* ps = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(pd), "r"(ps) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float r[4][4];
    M() {}
    const V& operator[](int i) const { const V* p = (const V*)r[i]; return *p; }
    const M& Gun(const V& up, const V& fwd);
    M(const M& o) { void* xx = this; __int128 qa, qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M& operator=(const M& o) { void* xx = this; __int128 qa, qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Place {
    V loc;
    M mat;
};
struct Skel {
    char pad0[0x14];
    unsigned char hasBones;
    char pad15[3];
    char bones[0x10];
};
struct Man {
    char pad0[0x2450];
    unsigned char gunBone[16];  /* 0x2450 */
    Place place[10];            /* 0x2460 */
    char pad2780[0x2C04 - 0x2780];
    Skel* skeleton;             /* 0x2C04 */
};
extern "C" {
void* cArray_cBone_opIndex_int(void* a, int i);
M* cBone_GetScaleMatrix(void* b);
M* cMatrix_GetUnit(void);
void cVector_Cross(V* ret, const V* a, const V* b);
int cVector_IsZeroXYZ(const V* v);
void cVector_GetNormalized_void(V* ret, const V* v);
V* cVector_Normalize_void(V* v);
V* cVector_ctor_cVectorR(V* d, const V* s);
V* cVector_ctor_float_float_float_float(V* d, float x, float y, float z, float w);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, const V* a, const V* b, const V* c, const V* d);
M* cMatrix_MakeLookAtMatrix_cVectorR(M* m, const V* v);
void cMatrix_SetUnit(M* m);
}
static inline void MulV(V* d, const M* m, const V* v) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory"); }
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void NegV(V* d, const V* a) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a) : "memory"); }
static inline V operator-(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }
struct NV : V { NV() {} NV(const NV& o) { void* xx = this; NV* pd = this; const NV* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } } };
static inline NV operator-(const V& a) { const V* p = &a; NV r; NegV(&r, p); return r; }
static inline V operator*(const M& m, const V& v) { V r(v); V* p = &r; MulV(p, &m, p); return *p; }
static inline float Len(const V* pv)
{
    float ret = 0.0f;
    int t;
    asm {
        lqc2 vf1, 0(pv)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, ret
    }
    return ret;
}

inline const M& M::Gun(const V& up, const V& fwd)
{
    const M* src;
    V cross;
    cVector_Cross(&cross, &up, &fwd);
    if (!cVector_IsZeroXYZ(&cross)) {
        V y;
        V x;
        V z;
        V w;
        cVector_GetNormalized_void(&y, &up);
        cVector_ctor_cVectorR(&x, cVector_Normalize_void(&cross));
        cVector_Cross(&z, &x, &y);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, &x, &y, &z, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
        src = this;
    } else if (!cVector_IsZeroXYZ(&up)) {
        src = cMatrix_MakeLookAtMatrix_cVectorR(this, &up);
    } else {
        cMatrix_SetUnit(this);
        src = this;
    }
    return *src;
}

extern "C" void cMan_SetGunLoc(Man* man, int index, int bone)
{
    V diffs[3];
    float lengths[3];
    V* verts;
    V* tVerts;
    float tVertsX;
    float tVertsY;
    int place;
    float longest;
    float shortest;
    int longEdge;
    int shortEdge;
    int origin;
    int second;
    int third;

    verts = (V*)0x70000540;
    tVerts = (V*)0x11004050;
    tVerts += index;
    tVerts += index;
    tVertsX = tVerts->x - 32896.0f;
    if (tVertsX < 0.0f) tVertsX = 0.0f;
    if (tVertsX > 1.0f) tVertsX = 1.0f;
    tVertsY = tVerts->y - 32896.0f;
    if (tVertsY < 0.0f) tVertsY = 0.0f;
    if (tVertsY > 1.0f) tVertsY = 1.0f;
    place = (int)(4.0f * tVertsX) + ((int)(4.0f * tVertsY) << 2);
    if (place < 10 && place >= 0) {
        verts += index;
        diffs[0] = verts[0] - verts[1];
        diffs[1] = verts[1] - verts[2];
        diffs[2] = verts[2] - verts[0];
        lengths[0] = Len(&diffs[0]);
        lengths[1] = Len(&diffs[1]);
        lengths[2] = Len(&diffs[2]);
        longest = lengths[0];
        shortest = lengths[0];
        longEdge = 0;
        shortEdge = 0;
        if (lengths[1] > longest) { longest = lengths[1]; longEdge = 1; }
        if (lengths[2] > longest) { longest = lengths[2]; longEdge = 2; }
        if (lengths[1] < shortest) { shortest = lengths[1]; shortEdge = 1; }
        if (lengths[2] < shortest) { shortest = lengths[2]; shortEdge = 2; }
        if (longEdge == 0) {
            if (shortEdge == 1) { origin = 2; second = 0; third = 1; }
            else { origin = 2; second = 1; third = 0; }
        }
        if (longEdge == 1) {
            if (shortEdge == 2) { origin = 0; second = 1; third = 2; }
            else { origin = 0; second = 2; third = 1; }
        }
        if (longEdge == 2) {
            if (shortEdge == 0) { origin = 1; second = 2; third = 0; }
            else { origin = 1; second = 0; third = 2; }
        }
        man->place[place].loc = verts[origin];
        man->place[place].loc = (man->skeleton->hasBones ? *cBone_GetScaleMatrix(cArray_cBone_opIndex_int(man->skeleton->bones, bone)) : *cMatrix_GetUnit()) * man->place[place].loc;
        V gunUp = verts[origin] - verts[third];
        V gunForward = verts[origin] - verts[second];
        M gunMat = M().Gun(gunUp, gunForward);
        M gunMatRotated;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(&gunMatRotated, &(const V&)(-gunMat[2]), &gunMat[1], &gunMat[0], &(const V&)V(0.0f, 0.0f, 0.0f, 1.0f));
        man->place[place].mat = gunMatRotated;
        man->gunBone[place] = (unsigned char)bone;
    }
}