/*
 * Libs/SFOLib/Source/lights: 10 files, 00373590-00373940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00373590 */
#pragma push /* merge_units */
#include "types.h"
/* cLightMan_AddLightScoreBox: bounding-sphere test of a light entry, appends (light, key) to the gather list */
typedef struct Pt1TbVec { float x, y, z, w; } __attribute__((aligned(16))) Pt1TbVec;
typedef struct Pt1TbEntry {
    unsigned char flags;
    char pad1[3];
    void* light;
    float range;
    float weight;
    Pt1TbVec pos;
} Pt1TbEntry;
typedef struct Pt1TbCand { void* light; float key; } Pt1TbCand;
typedef struct Pt1TbList { char pad[0x2000]; Pt1TbCand cand[1]; } Pt1TbList;
typedef struct Pt1TbGather {
    char pad0[0x50];
    int count;
    Pt1TbList* list;
} Pt1TbGather;

void cLightMan_AddLightScoreBox(Pt1TbGather* g, Pt1TbVec* pos, Pt1TbEntry* e, float radius)
{
    float key;
    unsigned char ok;
    if (e->flags == 2) {
        key = 0.0f;
        ok = 1;
    } else {
        int r;
        int st;
        int k;
        asm {
            lqc2 vf1, 0x0(pos)
            lqc2 vf2, 0x10(e)
            vsub.xyzw vf3, vf2, vf1
            mfc1 r, radius
            qmtc2 r, vf5
            lqc2 vf6, 0x0(e)
            vaddz.x vf7, vf5, vf6z
            vmul.xyz vf4, vf3, vf3
            vaddw.x vf9, vf0, vf0w
            vmul.x vf8, vf7, vf7
            vmulax.x ACC, vf9, vf4x
            vmadday.x ACC, vf9, vf4y
            vmaddz.x vf10, vf9, vf4z
            vsub.x vf11, vf10, vf8
            vnop
            vnop
            vnop
            vmulw.x vf8, vf10, vf6w
            cfc2 st, vi16
            qmfc2 k, vf8
        }
        {
            /* S flag (bit 1) of dist^2 - (radius + range)^2: inside the light's reach */
            unsigned s = (st >> 1) << 31;
            unsigned zero = 0;
            ok = !(s <= zero);
        }
        asm { mtc1 k, key } /* key bits from VU0 into an FPR */
    }
    if (ok) {
        g->list->cand[g->count].key = key;
        g->list->cand[g->count].light = e->light;
        g->count++;
    }
}
static inline void merge_flush_func_00373590(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373590 */

/* merge_units: begin func_00373670 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* cLightMan_BuildVisibleLightSubset: rebuilds the per-frame light table: takes the
 * current view matrix and a camera vector scaled by the field of view,
 * pushes an identity matrix, runs cLightMan_TestVisibleLight over the three light
 * lists, flushes the table from the data cache and pops the matrix. Types
 * as in cLightMan_TestVisibleLight (cLightMan_TestVisibleLight.c); camera as in
 * cVU1Man_SetView (cVU1Man_SetView.c). */
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Mtx { __int128 r[4]; Mtx() {} Mtx(const Mtx& o) { const Mtx* s = &o; Mtx* d = this; GQR(d, (void*)s); } };
typedef struct Render { char pad0[0xA80]; Mtx mtx[0x14]; } Render;
struct V { float x, y, z, w; };
struct Cam { char pad0[0xF8]; float fovA; float fovB; float half; unsigned char useA; };
struct L40 { char d[0x40]; };
struct LE0 { char d[0xE0]; };
struct L50 { char d[0x50]; };
struct LEnt { char d[0x20]; };
struct LMgr { int pad0; L50* l50; L40* l40; LE0* lE0; int pad10; int n50; int n40; int nE0; char pad20[0x4C - 0x20]; int count; char pad50[0x10]; LEnt ents[1]; };
extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern int D_00538C64;
extern char D_00538C68;
float Libc_Cosf(float a);
void SyncDCache(void* a, void* b);
#if 0 /* merge_units */
void cLightMan_TestVisibleLight(LMgr* self, void* l, Mtx* m, V* cam, float f);
#endif /* merge_units */
struct LMgr_00373940; /* merge_units */
struct Light; /* merge_units */
struct M; /* merge_units */
struct V_00373940; /* merge_units */
void cLightMan_TestVisibleLight(LMgr_00373940* self, Light* l, M* m, V_00373940* cam, float f); /* merge_units */
#define cLightMan_TestVisibleLight(a0, a1, a2, a3, a4) (cLightMan_TestVisibleLight((LMgr_00373940 *)(a0), (Light *)(a1), (M *)(a2), (V_00373940 *)(a3), (a4))) /* merge_units */

void cLightMan_BuildVisibleLightSubset(LMgr* self);
}
static inline Mtx* MtxAt(int i) { return &((Render*)g_Video)->mtx[i]; }
static inline Cam* CurCam() { return (Cam*)(g_Video + D_00538C60 * 0x110 + 0x1F0); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

extern "C" void cLightMan_BuildVisibleLightSubset(LMgr* self)
{
    float f;
    int i;
    self->count = 0;
    Mtx m(*MtxAt(D_00538C64));
    V c;
    {
        Cam* cam = CurCam();
        f = 0.5f * (cam->useA ? cam->fovA : cam->fovB);
    }
    c.x = 0.0f;
    c.y = f;
    c.z = 0.0f;
    c.w = 1.0f;
    f = f / Libc_Cosf(CurCam()->half);
    GQR(MtxAt(D_00538C64 + 1), MtxAt(D_00538C64));
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    for (i = 0; i < self->n40; i++)
        cLightMan_TestVisibleLight(self, &self->l40[i], &m, &c, f);
    for (i = 0; i < self->nE0; i++)
        cLightMan_TestVisibleLight(self, &self->lE0[i], &m, &c, f);
    for (i = 0; i < self->n50; i++)
        cLightMan_TestVisibleLight(self, &self->l50[i], &m, &c, f);
    SyncDCache(&self->ents[0], &self->ents[self->count]);
    D_00538C64--;
    D_00538C68 = 1;
}
#undef cLightMan_TestVisibleLight /* merge_units */
static inline void merge_flush_func_00373670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373670 */

/* merge_units: begin func_00373940 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_00373940 {
    float x, y, z, w;
    V_00373940() {}
    V_00373940(const V_00373940& o, int) { __int128 t; V_00373940* d = this; const V_00373940* s = &o; d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V_00373940(const V_00373940& o) { const V_00373940* s = &o; void* xx = this; V_00373940* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V_00373940& operator=(const V_00373940& o) { void* xx = this; const V_00373940* s = &o; V_00373940* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
};
struct M { float m[4][4]; } __attribute__((aligned(16)));
static inline V_00373940& XformInPlace(V_00373940* v, const M* m)
{
    __asm__ volatile(
        "lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2 $vf12, 0x0(%0)" : "+r"(v) : "r"(m) : "memory");
    return *v;
}
static inline V_00373940 Xform3(V_00373940 v, const M* m) { V_00373940& r = XformInPlace(&v, m); return V_00373940(r, 0); }
static inline void Sub(V_00373940* c, const V_00373940* a, const V_00373940* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
struct LV { char vpad[4]; virtual float v0(); virtual float v1(); virtual float v2(); virtual float v3(); virtual float v4(); virtual float v5(); virtual float v6(); virtual float v7(); virtual float v8(); virtual float v9(); virtual float v10(); virtual float v11(); };
struct Light {
    char pad0[4];
    void* vt;
    char pad8[0x14 - 0x8];
    float x14;
    float x18;
    unsigned char x1C;
    unsigned char x1D;
    signed char type;
    char pad1F[0x30 - 0x1F];
    V_00373940 pos;
};
struct LEnt_00373940 { signed char type; unsigned char x61; unsigned char code; char pad; Light* light; float x68; float x6C; V_00373940 pos; };
struct LMgr_00373940 { char pad0[0x4C]; int count; char pad50[0x10]; LEnt_00373940 ents[1]; };
extern "C" {
void XLib_UpdateCompMat(void*);
unsigned int XLib_GetOutCode(void*, M*, V_00373940*);
extern M D_005390F0;
}
/* Adds a light to the manager's per-frame table if it is directional (type 2), its transformed
   position passes the camera clip test, or it lies within its radius (+f) of the camera. */
extern "C" void cLightMan_TestVisibleLight(LMgr_00373940* self, Light* l, M* m, V_00373940* cam, float f)
{
    int code;
    bool ok;
    if (!l->x1C) return;
    if ((unsigned char)l->type == 2) {
        code = 1;
        ok = true;
    } else {
        V_00373940 q = Xform3(l->pos, m); V_00373940 e; V_00373940 d;
        XLib_UpdateCompMat(g_Video);
        M* view = &D_005390F0;
        ok = (XLib_GetOutCode(g_Video, view, &q) & ~0x40) == 0;
        if (ok) {
            code = 3;
        } else {
            float lim = f + 0.5f * ((LV*)l)->v11();
            Sub(&d, cam, &q);
            e = d;
            ok = e.Length() < lim;
            if (ok) {
                code = 2;
            }
        }
    }
    if (ok) {
        self->ents[self->count].type = l->type;
        self->ents[self->count].x61 = (unsigned char)(int)l->x1D;
        self->ents[self->count].code = (unsigned char)code;
        self->ents[self->count].light = l;
        self->ents[self->count].x68 = l->x14;
        self->ents[self->count].x6C = l->x18;
        self->ents[self->count].pos = l->pos;
        self->count++;
    }
}
static inline void merge_flush_func_00373940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373940 */

/* merge_units: begin func_00373BA0 */
#pragma push /* merge_units */
typedef struct { float a; float b; } A5_00373BA0;
int CompareSources(A5_00373BA0* x, A5_00373BA0* y) {
    float b = y->b, a = x->b;
    if (a < b) return -1;
    else if (a > b) return (unsigned char)(a > b);
    return (unsigned char)(a > b);
}
static inline void merge_flush_func_00373BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373BA0 */

/* merge_units: begin func_00373BE0 */
#pragma push /* merge_units */
int cLightMan_GetAmbientLight(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 16);
    cond = v1 == 0;
    v0 = 0;
    if (cond) goto L00373BF0;
    v0 = *(int*)(char*)a0;
L00373BF0:;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00373BE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373BE0 */

/* merge_units: begin func_00373C00 */
#pragma push /* merge_units */
typedef struct { char pad0[8]; int id; char padC[0x34]; } LtA;
typedef struct { char pad0[8]; int id; char padC[0x44]; } LtB;
typedef struct { char pad0[8]; int id; char padC[0xD4]; } LtD;
typedef struct { LtA* amb; LtB* pt; LtA* dir; LtD* spot; int nAmb; int nPt; int nDir; int nSpot; } LtMgr;

void* cLightMan_GetLightSource(LtMgr* m, int type, int id) {
    switch (type) {
    case 1: {
        int i;
        for (i = 0; i < m->nAmb; i++) {
            if (m->amb[i].id == id) return &m->amb[i];
        }
        } break;
    case 2: {
        int i;
        for (i = 0; i < m->nPt; i++) {
            if (m->pt[i].id == id) return &m->pt[i];
        }
        } break;
    case 4: {
        int i;
        for (i = 0; i < m->nDir; i++) {
            if (m->dir[i].id == id) return &m->dir[i];
        }
        } break;
    case 0x10: {
        int i;
        for (i = 0; i < m->nSpot; i++) {
            if (m->spot[i].id == id) return &m->spot[i];
        }
        } break;
    }
    return 0;
}
static inline void merge_flush_func_00373C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373C00 */

/* merge_units: begin func_00373D70 */
#pragma push /* merge_units */
typedef struct { int pad0; void* light; char pad8[24]; } Pt2_LEnt;
typedef struct { char pad0[0x4C]; int count; char pad50[0x10]; Pt2_LEnt ents[1]; } Pt2_LMgr;
typedef struct { char pad0[8]; int x8; char padC[0x12]; unsigned char type; } Pt2_Light;
typedef struct { char pad[0x60]; Pt2_LEnt e; } Pt2_Row;
#if 0 /* merge_units */
extern void SyncDCache(Pt2_LEnt*, Pt2_LEnt*);
#endif /* merge_units */
#define SyncDCache(a0, a1) (SyncDCache((void *)(a0), (void *)(a1))) /* merge_units */

static inline void Pt2_QMove(void* d, void* s, int n) {
    __int128 t;
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
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void cLightMan_RemoveLight(Pt2_LMgr* m, Pt2_Light* l) {
    int i;
    switch (l->type) {
    case 1:
        break;
    case 2:
        break;
    case 4:
        l->x8 = -1;
        break;
    case 0x10:
        break;
    }
    for (i = 0; i < m->count; i++) {
        Pt2_Row* r = (Pt2_Row*)((i << 5) + (int)m);
        if (r->e.light == l) {
            m->count = m->count - 1;
            Pt2_QMove(&r->e, &m->ents[i + 1], (m->count - i) * 2);
            SyncDCache(m->ents, &m->ents[m->count]);
            return;
        }
    }
}
#pragma pop
#undef SyncDCache /* merge_units */
static inline void merge_flush_func_00373D70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373D70 */

/* merge_units: begin func_00373E70 */
#pragma push /* merge_units */
typedef struct { char pad[8]; int id; char padC[0x34]; } LmA;
typedef struct { char pad[8]; int id; char padC[0x44]; } LmB;
typedef struct { char pad[8]; int id; char padC[0x34]; } LmC;
typedef struct { char pad[8]; int id; char padC[0xD4]; } LmD;
typedef struct { char pad[8]; int id; } LmAny;
typedef struct {
    LmA* a;
    LmB* b;
    LmC* c;
    LmD* d;
    int na;
    int nb;
    int nc;
    int nd;
} LightMgr;
LmAny* cLightMan_AddLight(LightMgr* m, unsigned char kind)
{
    LmAny* l = 0;
    int i;
    switch (kind) {
    case 1:
        for (i = 0; i < m->na && !l; i++) {
            if (m->a[i].id == -1)
                l = (LmAny*)&m->a[i];
        }
        break;
    case 2:
        for (i = 0; i < m->nb && !l; i++) {
            if (m->b[i].id == -1)
                l = (LmAny*)&m->b[i];
        }
        break;
    case 4:
        for (i = 0; i < m->nc && !l; i++) {
            if (m->c[i].id == -1)
                l = (LmAny*)&m->c[i];
        }
        break;
    case 0x10:
        for (i = 0; i < m->nd && !l; i++) {
            if (m->d[i].id == -1)
                l = (LmAny*)&m->d[i];
        }
        break;
    }
    if (l)
        l->id = i;
    return l;
}
static inline void merge_flush_func_00373E70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00373E70 */

/* merge_units: begin func_00374020 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct S374020 { void* p[4]; int n[4]; };
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
static inline void Rel374020(void* p, int line)
{
    AllocGuard g;
    cMemMan_Deallocate(0, p, "lights.cc", line);
}
extern "C" void cLightMan_DeallocateLightSources(S374020* s)
{
    if (s->p[0]) {
        Rel374020(s->p[0], 0x94);
        s->p[0] = 0;
        s->n[0] = 0;
    }
    if (s->p[1]) {
        Rel374020(s->p[1], 0x9B);
        s->p[1] = 0;
        s->n[1] = 0;
    }
    if (s->p[2]) {
        Rel374020(s->p[2], 0xA1);
        s->p[2] = 0;
        s->n[2] = 0;
    }
    if (s->p[3]) {
        Rel374020(s->p[3], 0xA7);
        s->p[3] = 0;
        s->n[3] = 0;
    }
}
static inline void merge_flush_func_00374020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00374020 */

/* merge_units: begin func_00374270 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
extern char D_004BC150[];
}

/* the original zeroes each pool with this inline-asm clear (quadword or byte loop) */
static inline void MemClear_4270(void* dst, int n) {
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
        .set reorder
    done:
    }
}

struct LightA_4270 { int f0; int f4; int f8; char pad[0x40 - 0xC]; };
struct LightB_4270 { int f0; int f4; int f8; char pad[0x50 - 0xC]; };
struct LightC_4270 { int f0; int f4; int f8; char pad[0x40 - 0xC]; };
struct LightD_4270 { int f0; int f4; int f8; char pad[0xE0 - 0xC]; };

struct LightPools_4270 {
    LightA_4270* a;
    LightB_4270* b;
    LightC_4270* c;
    LightD_4270* d;
    unsigned int na;
    unsigned int nb;
    unsigned int nc;
    unsigned int nd;
};

/* pool init loops: no unrolling or strength reduction, test at the bottom; the
   explicit off/mid/neg temporaries in this declaration order give retail's registers */
#pragma opt_unroll_loops off
#pragma opt_propagation off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
extern "C" void cLightMan_AllocateLightSources(LightPools_4270* m, unsigned char type, unsigned int n)
{
    switch (type) {
    case 1: {
        int size = n * sizeof(LightA_4270);
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, size, D_004BC150, 0x5E);
        }
        m->a = (LightA_4270*)p;
        MemClear_4270(m->a, size);
        m->na = n;
        {
            unsigned int i;
            int off;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                off = i * sizeof(*m->a);
                *(int*)((char*)m->a + off + 8) = neg;
            }
        }
        break;
    }
    case 2: {
        int size = n * sizeof(LightB_4270);
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, size, D_004BC150, 0x6A);
        }
        m->b = (LightB_4270*)p;
        MemClear_4270(m->b, size);
        m->nb = n;
        {
            unsigned int i;
            int off;
            int mid;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                mid = i * 5;
                off = mid << 4;
                *(int*)((char*)m->b + off + 8) = neg;
            }
        }
        break;
    }
    case 4: {
        int size = n * sizeof(LightC_4270);
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, size, D_004BC150, 0x76);
        }
        m->c = (LightC_4270*)p;
        MemClear_4270(m->c, size);
        m->nc = n;
        {
            unsigned int i;
            int off;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                off = i * sizeof(*m->c);
                *(int*)((char*)m->c + off + 8) = neg;
            }
        }
        break;
    }
    case 0x10: {
        int size = n * sizeof(LightD_4270);
        void* p;
        {
            AllocGuard g;
            p = cMemMan_Allocate(0, size, D_004BC150, 0x82);
        }
        m->d = (LightD_4270*)p;
        MemClear_4270(m->d, size);
        m->nd = n;
        {
            unsigned int i;
            int off;
            int mid;
            int neg;
            i = 0;
            neg = -1;
            for (; i < n; i++) {
                mid = i * 7;
                off = mid << 5;
                *(int*)((char*)m->d + off + 8) = neg;
            }
        }
        break;
    }
    }
}
static inline void merge_flush_func_00374270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00374270 */
