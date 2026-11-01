/*
 * Libs/SFOLib/Source/man: 4 files, 0038FE90-00390570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0038FE90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cBone_GetScaleMatrix(char* self) {
    return self + 272;
}
static inline void merge_flush_func_0038FE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038FE90 */

/* merge_units: begin func_0038FEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
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
#if 0 /* merge_units */
M* cBone_GetScaleMatrix(void* b);
#endif /* merge_units */
#define cBone_GetScaleMatrix(a0) ((M *)cBone_GetScaleMatrix((char *)(a0))) /* merge_units */

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
#undef cBone_GetScaleMatrix /* merge_units */
static inline void merge_flush_func_0038FEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0038FEA0 */

/* merge_units: begin func_00390570 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int strcmp(const void *, const void *);

#pragma cplusplus on

struct Pair390570 {
    __int128 a;
    __int128 b;
};

struct Self390570 {
    char pad[0x80];
    Pair390570 pairs[0x20];
    char padX[0x22C0 - 0x80 - 0x20 * 0x20];
    short x22C0[0x20];
    short x2300[0x60];
    short x23C0;
    char pad23C2[0x2DB0 - 0x23C2];
    unsigned char x2DB0[0x20];
    unsigned char x2DD0[0x20];
};

struct Entry390570 {
    __int128 key;
    int val;
    char pad[0x1C];
};

struct Cache390570 {
    char pad[0x11C10];
    Entry390570 e[1];
};

extern "C" {
extern Cache390570 g_AgentPartCache;
extern __int128 D_0055DDD0;
extern __int128 D_0055DDE0;
extern __int128 D_0055DE00;
extern __int128 D_0055DE10;
extern int D_0055DE8C;
void cMan_SortParts(Self390570* self);
}

static inline bool Eq390570(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 And390570(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 From390570(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}

extern "C" void cMan_SortParts(Self390570* self)
{
    int which[0x20];
    int score[0x20];
    int i = 0;
    int k;
    __int128 mask = From390570(0xFFFFFFFF00LL);
    int n;
    int j;
    __int128 ta, tb;
    short s0, s1;
    int found;
    int best;
    int bi;

    for (k = 0; self->pairs[k].a; k++) {
        which[k] = 0xFA00;
        score[k] = 0;
    }
    n = k;
    self->x23C0 = n;
    for (j = 0; j < D_0055DE8C; j++) {
        for (k = 0; k < n; k++) {
            if (Eq390570(And390570(mask, self->pairs[k].b), And390570(mask, g_AgentPartCache.e[j].key))) {
                __int128 ek;
                __int128 pa;
                pa = self->pairs[k].a;
                ek = g_AgentPartCache.e[j].key;
                int s = 1;
                if (Eq390570(And390570(D_0055DE00, pa), And390570(D_0055DE00, ek))) s += 2;
                if (Eq390570(And390570(D_0055DE10, pa), And390570(D_0055DE10, ek))) s += 1;
                if (Eq390570(And390570(D_0055DDD0, pa), And390570(D_0055DDD0, ek))) s += 8;
                if (Eq390570(And390570(D_0055DDE0, pa), And390570(D_0055DDE0, ek))) s += 4;
                if (score[k] < s) {
                    which[k] = j;
                    score[k] = s;
                }
            }
        }
    }
    do {
        found = 0;
        best = 0xFA00;
        for (k = i; k < n; k++) {
            if (which[k] < best && which[k] != 0xFA00) {
                best = which[k];
                bi = k;
                found = 1;
            }
        }
        if (found) {
            which[bi] = which[i];
            ta = self->pairs[i].a;
            tb = self->pairs[i].b;
            s0 = self->x22C0[i];
            s1 = self->x2300[i];
            self->pairs[i].a = self->pairs[bi].a;
            self->pairs[i].b = self->pairs[bi].b;
            self->x22C0[i] = self->x22C0[bi];
            self->x2300[i] = self->x2300[bi];
            self->pairs[bi].a = ta;
            self->pairs[bi].b = tb;
            self->x22C0[bi] = s0;
            self->x2300[bi] = s1;
            self->x2DB0[i] = best;
            self->x2DD0[i] = g_AgentPartCache.e[best].val;
            i++;
        }
    } while (found);
    for (; i < 0x20; i++) {
        if (self->pairs[i].a) {
            self->x2DB0[i] = 0;
            self->x2DD0[i] = 1;
        } else {
            self->x2DB0[i] = D_0055DE8C - 1;
            self->x2DD0[i] = g_AgentPartCache.e[D_0055DE8C - 1].val;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00390570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00390570 */

/* merge_units: begin func_00390940 */
#pragma push /* merge_units */
/* cMan_MergeSKLs (main/man): merge a new appearance into the man's current one
 * (release attached meshes, back up the old appearance, swap body-kind tags,
 * fix up the head/hair pairs, reload changed meshes, append new pairs).
 * Compiler: mwcc 3.0b38 (also matches b50). The odd lvalue forms
 * (casts, `(unsigned)i`, `s5 << 1`, the reused `t`) control CSE, evaluation
 * order and register numbering; see build/agents/c56lg/NOTES.md. */
#pragma cplusplus on
#pragma optimization_level 3
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_dead_code off

struct Pair390940 {
    __int128 a;
    __int128 b;
};

struct App390940 {
    __int128 q0;
    __int128 q10;
    __int128 q20;
    __int128 q30;
    Pair390940 pairs[0x20];
};

struct Self390940 {
    char pad[0x20];
    char x20[0x20];
    App390940 app;
    char pad480[0x1EC0 - 0x480];
    char x1EC0[0x2340 - 0x1EC0];
    void* x2340[0x20];
    unsigned short x23C0;
    char pad23C2[0x2BDB - 0x23C2];
    unsigned char x2BDB;
    char pad2BDC[0x2C0C - 0x2BDC];
    unsigned char x2C0C;
    signed char x2C0D;
    char pad2C0E[0x2C14 - 0x2C0E];
    App390940* x2C14;
};

extern "C" {
#if 0 /* merge_units */
extern char g_AgentPartCache[];
#endif /* merge_units */
#define g_AgentPartCache ((char*)&g_AgentPartCache) /* merge_units */


extern __int128 D_0055DE40;
extern char D_0057124C[];
extern char D_004BC310[];
extern char D_004BC3C8[];
extern char D_004BC3D0[];
extern char D_004BC3D8[];
extern char D_004BC3E0[];
extern char D_004BC3E8[];

void DELAY_DELETE_ARRAY(void* p);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
int SKL_FindSex(App390940* app);
int SKL_FindRace(App390940* app);
int SKL_CountAttribs(App390940* app);
int SKL_FindPartIndex(App390940* app, char* type);
int Libc_Strncmp(char* a, char* b, int n);
int FindPart__7MonsterF1(char* cache, __int128 name);
void Monster_LoadAPart(char* cache, __int128 name, char* ctx, char* arg);
void SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(char* cache, App390940* app, char* x, __int128 a, __int128 b, int kind, int tone);
void cMan_MergeSKLs(Self390940* self, App390940* src);
}

static inline void QMove_390940(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline void QMove2_390940(void* d0, void* s0, int n0) {
    int n = n0; void* s = s0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline bool Eq390940(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 And390940(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 Or390940(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 Not390940(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 From390940(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}

static inline void Swap390940(__int128* p, __int128 from, __int128 to) {
    __int128 v;
    __int128 m;
    m = D_0055DDD0;
    v = *p;
    if (Eq390940(And390940(m, v), And390940(m, from))) {
        __int128 b = And390940(to, m);
        __int128 nm = Not390940(m);
        *p = Or390940(And390940(v, nm), b);
    }
}
static inline void MeshP390940(Self390940* self, __int128* name) {
    if (FindPart__7MonsterF1(g_AgentPartCache, *name) == -1) {
        self->x2BDB = 1;
        Monster_LoadAPart(g_AgentPartCache, *name, D_0057124C, self->x20);
    }
}

extern "C" void cMan_MergeSKLs(Self390940* self, App390940* src)
{
    int i = 0;
    int s5;
    int j;
    int s4;
    int s3;
    __int128 tmp;
    char* t;
    Pair390940* p;

    for (; i < self->x23C0; i++) {
        void* e = ((void**)self->x2340)[(unsigned)i];
        if (e) {
            DELAY_DELETE_ARRAY(e);
            ((int*)self->x2340)[i] = 0;
        }
    }
    if (self->x2C14) {
        QMove_390940(&self->app, self->x2C14, 0x44);
    } else {
        App390940* a;
        {
            AllocGuard g;
            a = (App390940*)cMemMan_Allocate(0, 0x440, D_004BC310, 0x313);
        }
        self->x2C14 = a;
        QMove2_390940(self->x2C14, &self->app, 0x44);
    }
    self->x2C0C = SKL_FindSex(&self->app);
    self->x2C0D = SKL_FindRace(&self->app);
    self->x23C0 = SKL_CountAttribs(&self->app);
    s3 = SKL_FindSex(src);
    if (self->x2C0C != s3) {
        __int128 from;
        __int128 to;
        if (self->x2C0C == 1) {
            from = From390940('2');
            to = From390940('1');
        } else {
            from = From390940('1');
            to = From390940('2');
        }
        for (p = src->pairs; p->a; p++) {
            Swap390940((__int128*)p, from, to);
            Swap390940(&p->b, from, to);
        }
        Swap390940(&src->q20, from, to);
    }
    s5 = SKL_FindPartIndex(&self->app, D_004BC3C8);
    if (s5 != -1) {
        j = SKL_FindPartIndex(src, D_004BC3C8);
        if (j != -1) {
            ((__int128*)self->app.pairs)[s5 * 2] = src->pairs[j].a;
            SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(g_AgentPartCache, &self->app, self->x1EC0, self->app.pairs[s5].a, src->pairs[j].a,
                          self->x2C0C, self->x2C0D);
        } else {
            j = SKL_FindPartIndex(src, D_004BC3D0);
            if (j != -1) {
                s4 = SKL_FindPartIndex(&self->app, D_004BC3D0);
                t = (char*)&src->pairs[j];
                s3 = Libc_Strncmp(t + 6, D_004BC3D8, 3);
                tmp = ((__int128*)self->app.pairs)[s5 << 1];
                t = (char*)&tmp;
                if (s4 != -1) {
                    p = &self->app.pairs[s4];
                    if (!Libc_Strncmp((char*)p + 0xA, D_004BC3E0, 4)) {
                        s4 = -1;
                    }
                }
                if (s4 == -1 && s3) {
                    Libc_Strcpy(t + 0xA, D_004BC3E8);
                    MeshP390940(self, &tmp);
                    ((__int128*)self->app.pairs)[s5 * 2] = tmp;
                    SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(g_AgentPartCache, &self->app, self->x1EC0, self->app.pairs[s5].a, tmp,
                                  self->x2C0C, self->x2C0D);
                } else if (s4 != -1 && !s3) {
                    Libc_Strcpy(t + 0xA, D_004BC3E0);
                    MeshP390940(self, &tmp);
                    ((__int128*)self->app.pairs)[s5 * 2] = tmp;
                    SwapPartDependencies__7MonsterFR3SKLR8ManParts11UiUi(g_AgentPartCache, &self->app, self->x1EC0, self->app.pairs[s5].a, tmp,
                                  self->x2C0C, self->x2C0D);
                }
            }
        }
    }
    if (strcmp((char*)&self->app.q20, (char*)&src->q20)) {
        MeshP390940(self, &src->q20);
        self->app.q20 = src->q20;
    }
    for (p = src->pairs; p->a; p++) {
        int found = 0;
        __int128 x;
        __int128 m = D_0055DE40;
        for (i = 0; i < self->x23C0; i++) {
            x = self->app.pairs[i].a;
            if (Eq390940(And390940(m, p->a), And390940(m, x))) {
                found = 1;
                break;
            }
        }
        if (!found) {
            self->app.pairs[self->x23C0 + 2].a = self->app.pairs[self->x23C0 + 1].a;
            self->app.pairs[self->x23C0 + 2].b = self->app.pairs[self->x23C0 + 1].b;
            self->app.pairs[self->x23C0 + 1].a = self->app.pairs[self->x23C0].a;
            self->app.pairs[self->x23C0 + 1].b = self->app.pairs[self->x23C0].b;
            self->x23C0++;
        }
        self->app.pairs[i].b = p->b;
        self->app.pairs[i].a = p->a;
    }
    if (p->b) {
        self->app.pairs[self->x23C0].b = p->b;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00390940(void) {}
#undef g_AgentPartCache /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00390940 */
