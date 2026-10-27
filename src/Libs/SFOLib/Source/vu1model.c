/*
 * Libs/SFOLib/Source/vu1model: 7 files, 00376250-00377120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00376250 */
#pragma push /* merge_units */
/* every loop here jumps to its test first */
#pragma opt_rotateloops off
typedef unsigned long long u64_t;

typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx6250;
typedef struct { __int128 q; } Q6250;

typedef struct MData6250 {
    char pad0[0x14];
    int nTex;           /* 0x14 */
    char pad18[0x8];
    Q6250 color;        /* 0x20 */
    char pad30[0x5C - 0x30];
    void* packet;       /* 0x5C */
    char pad60[0x4];
    unsigned char visible; /* 0x64 */
} MData6250;

typedef struct MReg6250 {
    int tex;
    int pad4;
    u64_t* dst0;
    u64_t* dst1;
} MReg6250;

typedef struct Model6250 {
    int pad0;
    MData6250* data;    /* 0x04 */
    short* texIds;      /* 0x08 */
    MReg6250* regs;     /* 0x0C */
    int nRegs;          /* 0x10 */
    int qwc;            /* 0x14 */
    char pad18[0xC];
    unsigned int extra; /* 0x24 */
    char pad28[0x4];
    unsigned char enabled; /* 0x2C */
} Model6250;

typedef struct TexMgr6250 {
    char pad0[0x8];
    char** tex;         /* 0x08 */
    char padC[0xA];
    unsigned char b16;  /* 0x16 */
    char pad17;
    int n;              /* 0x18 */
    short ids[0x200];   /* 0x1C */
} TexMgr6250;

typedef struct Render6250 {
    char pad0[0xA80];
    Mtx6250 mtx[1];
} Render6250;

extern char g_Video[];
extern char D_00537F80[];
extern char D_00543790[];
extern Q6250 D_005381D0;
extern int D_00538C64;
extern char D_00538C68;
extern TexMgr6250* g_TextureMgr;
extern int D_005381C4;
extern int D_005380F8;
extern int D_00538170;
extern int D_004932C0[];
extern int D_004932E0[];
extern u64_t D_004BC1B0;
extern u64_t D_005392D8;
extern int D_00554EFC;
extern void cTexMan_EndBatch(TexMgr6250*);
extern void cDmaMan_InsertChain(void*, int, int, int);
extern unsigned int XLib_SetModelContext(void*, Mtx6250*, unsigned int, unsigned int);
extern Q6250* cDmaMan_BeginChain_eDmaChannel_int(void*, int, int);
extern void cDmaMan_EndChain_int_ulongP(void*, int, Q6250*);
extern void cShadowMan_BeginShadowBatch(void*);
extern void cShadowMan_NextShadowBatch(void*);

/* quadword copy through a register (lq/sq) */
static inline void QC(const void* s0, void* d0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline Mtx6250* MtxAt(int i) { return &((Render6250*)g_Video)->mtx[i]; }
/* 4-quadword copy alternating two registers */
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
/* VU0 4x4 matrix multiply */
static inline void MM(void* d, void* a, void* b)
{
    __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
/* the original copies the packet with this inline-asm quadword loop */
static inline void QCopy6250(void* s, int n, void* d)
{
    asm {
        .set noreorder
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
static inline void FASTDMA_ToSPR(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void FASTDMA_Wait_ToSPR(void)
{
    while (*(volatile int*)0x1000D400 & 0x100)
        ;
}
static inline void Dma_StartFromSpr(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D020 = qwc;
    *(volatile int*)0x1000D080 = sadr;
    *(volatile int*)0x1000D010 = madr;
    *(volatile int*)0x1000D000 = 0x100;
    __asm__ volatile ("sync");
}
static inline void SetTexEnv(void)
{
    int e = D_005380F8;
    if (e != D_00538170) {
        cDmaMan_InsertChain(D_00537F80, 1, D_004932C0[e], D_004932E0[e]);
        D_00538170 = e;
    }
}

void cVU1Model_Render(Model6250* m, unsigned int flags, Mtx6250* xf)
{
    TexMgr6250* tm;
    int spr;
    if (!m->enabled || (flags & 0x80) || !m->data->visible) {
        return;
    }
    QC(&m->data->color, &D_005381D0);
    if (xf) {
        GQR(MtxAt(D_00538C64 + 1), MtxAt(D_00538C64));
        D_00538C64++;
        {
            Mtx6250* c = MtxAt(D_00538C64);
            MM(c, c, xf);
        }
        D_00538C68 = 1;
    }
    tm = g_TextureMgr;
    {
        short* id = m->texIds;
        int i;
        tm->n = 0;
        tm->b16 = 0;
        for (i = m->data->nTex; i > 0; id++, i--) {
            int v = *id;
            if ((unsigned int)tm->n < 0x200) {
                if (tm->n == 0 || tm->ids[tm->n - 1] != v) {
                    tm->ids[tm->n++] = v;
                }
            }
        }
    }
    cTexMan_EndBatch(tm);
    spr = 0x70000000;
    {
        MReg6250* r = m->regs;
        u64_t* d = (u64_t*)(spr + 0x3000);
        int i = m->nRegs;
        for (; i > 0; i--) {
            *d = *(u64_t*)(tm->tex[r->tex] + 0x50);
            r++;
            d++;
        }
    }
    D_005381C4 = 0;
    SetTexEnv();
    { void* xx = &D_005381D0; } /* dead on purpose: retail computes the color address here */
    D_005381C4++;
    QC(&m->data->color, &D_005381D0);
    D_005392D8 = D_004BC1B0;
    XLib_SetModelContext(g_Video, xf, flags, m->extra);
    if (m->qwc <= 0x300) {
        FASTDMA_ToSPR(spr, (int)m->data->packet, m->qwc);
        FASTDMA_Wait_ToSPR();
    }
    {
        u64_t* s = (u64_t*)(spr + 0x3000);
        MReg6250* r = m->regs;
        int i = m->nRegs;
        for (; i > 0; i--) {
            u64_t v = *s;
            s++;
            *r->dst0 = v;
            *r->dst1 = v;
            r++;
        }
    }
    {
        Q6250* p = cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, m->qwc);
        if (m->qwc <= 0x300) {
            Dma_StartFromSpr(spr, (unsigned int)p & 0x0FFFFFFF, m->qwc);
        } else {
            QCopy6250(m->data->packet, m->qwc, p);
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p + m->qwc);
    }
    while (D_00554EFC) {
        Q6250* p;
        cShadowMan_BeginShadowBatch(D_00543790);
        D_005381C4 = 0;
        SetTexEnv();
        D_005381C4++;
        XLib_SetModelContext(g_Video, xf, flags, m->extra);
        p = cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 1, m->qwc);
        QCopy6250(m->data->packet, m->qwc, p);
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p + m->qwc);
        cShadowMan_NextShadowBatch(D_00543790);
    }
    if (xf) {
        D_00538C64--;
        D_00538C68 = 1;
    }
}
static inline void merge_flush_func_00376250(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00376250 */

/* merge_units: begin func_003767E0 */
#pragma push /* merge_units */
typedef struct E { unsigned char* ptr; unsigned int n; unsigned char data[1]; } E;
typedef struct X { char pad[0x58]; char* tab; char pad2[0x68-0x5C]; unsigned int flags; } X;
typedef struct A { int a0; X* x; } A;

void cVU1Model_UpdateLighting(A* a, int idx, unsigned char on) {
    unsigned char cur;
    E* e;
    cur = (a->x->flags >> idx) & 1;
    if (cur != on) {
        a->x->flags ^= 1 << idx;
        e = *(E**)(a->x->tab + idx * 8 + 4);
        while (*(int*)e != 0) {
            unsigned char* s = e->data;
            unsigned char* d = e->ptr;
            unsigned int i;
            if (on) {
                for (i = 0; i < e->n; i++) {
                    *d++ += s[0];
                    *d++ += s[1];
                    *d++ += s[2];
                    s += 4;
                }
            } else {
                for (i = 0; i < e->n; i++) {
                    *d++ -= s[0];
                    *d++ -= s[1];
                    *d++ -= s[2];
                    s += 4;
                }
            }
            e = (E*)((char*)e + (e->n * 4 + 8));
        }
    }
}
static inline void merge_flush_func_003767E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003767E0 */

/* merge_units: begin func_00376930 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
struct E376930 { int x0; void* p; int x8; int xC; };
struct S376930 { char pad[0xC]; E376930* arr; int count; };
extern "C" {
extern void* D_0053924C;
void cAnimTexMan_Remove(void* mgr, void* p);
void cAnimTexture_dtor(void* p, int f);
}
static inline void Del376930(void* o)
{
    AllocGuard g;
    cAnimTexture_dtor(o, -1);
    cMemMan_Deallocate(0, o, "vu1model.cc", 0x2AA);
}
static inline void Rel376930(void* p, int line)
{
    AllocGuard g;
    cMemMan_Deallocate(0, p, "vu1model.cc", line);
}
extern "C" void func_00376930(S376930* s)
{
    if (s->arr) {
        int i;
        for (i = 0; i < s->count; i++) {
            if (s->arr[i].p) {
                cAnimTexMan_Remove(D_0053924C, s->arr[i].p);
                Del376930(s->arr[i].p);
                s->arr[i].p = 0;
            }
        }
        Rel376930(s->arr, 0x2AE);
        s->arr = 0;
        s->count = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00376930 */

/* merge_units: begin func_00376AD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void *cMemMan_Allocate(int, int, char *, int);
void *cScrollAnimTexture_ctor(void *, void *, void *, void *, int);
void *cCellAnimTexture_ctor(void *, void *, void *, void *, int);
void cAnimTexMan_Add(int, void *);
extern char D_004BC170;


#if 0 /* merge_units */
extern int D_0053924C;
#endif /* merge_units */
#define D_0053924C (*(int*)&D_0053924C) /* merge_units */


}

typedef struct FxEnt {
    int f0;
    void *f4;
    char *f8;
    char *fC;
} FxEnt;

typedef struct FxItem {
    int f0;
    char *f4;
    char pad8[0x18];
} FxItem;

typedef struct FxGroup {
    int f0;
    int f4;
    FxItem *f8;
    int fC;
} FxGroup;

typedef struct FxMat {
    int f0;
    int f4;
    char f8[0x30];
    int f38[8];
    int f58;
} FxMat;

typedef struct FxData {
    char pad0[0x10];
    int f10;
    char pad14[0x50 - 0x14];
    FxMat *f50;
    FxGroup *f54;
    char pad58[4];
    int f5C;
} FxData;

typedef struct FxSub {
    char pad0[0x48];
    char f48[0x68];
    char fB0[0x28];
} FxSub;

typedef struct FxSubs {
    int a;
    int b;
    FxSub e[1];
} FxSubs;

typedef struct FxModel {
    int f0;
    FxData *f4;
    short *f8;
    FxEnt *fC;
    int f10;
    int f14;
} FxModel;

static inline void *FxAlloc(int size, int line)
{
    void *p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, size, &D_004BC170, line);
    }
    return p;
}

extern "C" void cVU1Model_BuildTex01Patchup(FxModel *m)
{
    int n;
    int i;
    int k;

    m->fC = (FxEnt *)FxAlloc(m->f10 * 16, 0x242);
    for (k = 0; k < m->f10; k++) {
        m->fC[k].f4 = 0;
    }
    n = 0;
    for (i = 0; i < m->f4->f10; i++) {
        FxGroup *g = &m->f4->f54[i];
        FxMat *mat = &m->f4->f50[g->fC];
        char *s = g->f8->f4;
        if (mat->f4 & 2) {
            void *p = FxAlloc(0x1C, 0x256);
            if (p) {
                p = cScrollAnimTexture_ctor(p, mat->f8, s + 0x10, s + 0x90, m->f8[mat->f38[0]]);
            }
            m->fC[n].f4 = p;
            cAnimTexMan_Add(D_0053924C, m->fC[n].f4);
        } else if (mat->f4 & 4) {
            void *p = FxAlloc(0x34, 0x25C);
            if (p) {
                p = cCellAnimTexture_ctor(p, mat->f8, s + 0x10, s + 0x90, m->f8[mat->f38[0]]);
            }
            m->fC[n].f4 = p;
            cAnimTexMan_Add(D_0053924C, m->fC[n].f4);
        }
        if (mat->f58 == 1) {
            char *t = g->f8->f4;
            *(int *)(t + 0x10) = mat->f4;
            *(int *)(t + 0x90) = mat->f4;
            m->fC[n].f0 = m->f8[mat->f38[0]];
            m->fC[n].f8 = t + 0x50;
            m->fC[n].fC = t + 0xD0;
            n++;
        } else {
            int kk;
            for (kk = 0; kk < g->f4; kk++) {
                char *t = g->f8[kk].f4;
                char *se = t + 0x100;
                int idx = n++;
                int j;
                *(int *)(t + 0x10) = mat->f4;
                *(int *)(t + 0x90) = mat->f4;
                m->fC[idx].f0 = m->f8[mat->f38[0]];
                m->fC[idx].f8 = t + 0x50;
                m->fC[idx].fC = t + 0xD0;
                for (se += 8, j = 1; j < mat->f58; j++, se += sizeof(FxSub)) {
                    m->fC[n].f0 = m->f8[mat->f38[j]];
                    m->fC[n].f8 = ((FxSub *)se)->f48;
                    m->fC[n].fC = ((FxSub *)se)->fB0;
                    n++;
                }
            }
        }
    }
    if (m->f14 <= 0x300) {
        int off = 0x70000000 - m->f4->f5C;
        FxEnt *e = m->fC;
        for (k = m->f10; k > 0; k--) {
            e->f8 += off;
            e->fC += off;
            e++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376AD0(void) {}
#undef D_0053924C /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00376AD0 */

/* merge_units: begin func_00376FF0 */
#pragma push /* merge_units */
typedef struct { int pad0; int value; int pad8; int padC; } E376FF0;
typedef struct { char pad[0xC]; E376FF0* ents; int count; } S376FF0;
int cVU1Model_GetAnimTextures(S376FF0* o, int* out, int max)
{
    int n = 0;
    int i;
    for (i = 0; i < o->count; i++) {
        int v = o->ents[i].value;
        if (v) {
            if (n >= max) break;
            *out = v; n++; out++;
        }
    }
    return n;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00376FF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00376FF0 */

/* merge_units: begin func_00377050 */
#pragma push /* merge_units */
/* cVU1Model_PatchLights: relocate the extra-table entry list and each entry's
 * {ptr, n, data[n]} record chain from file offsets to pointers. */
typedef struct Ent { int id; int *data; } Ent;
typedef struct Hdr {
    char pad0[0x10];
    int x10;
    char pad14[4];
    int x18;
    int count;
    char pad20[0x38];
    Ent *ents;
    char pad5C[0xC];
    int x68;
} Hdr;
typedef struct Model {
    char *base;
    Hdr *hdr;
} Model;
void cVU1Model_PatchLights(Model *m)
{
    int i;
    int *q;
    if (!m->hdr->x18 || !m->hdr->x10) return;
    m->hdr->ents = (Ent *)((int)m->base + (int)m->hdr->ents);
    for (i = 0; i < m->hdr->count; i++) {
        Ent *e = &m->hdr->ents[i];
        e->data = (int *)((int)m->base + (int)e->data);
        q = e->data;
        while (q[0]) {
            *(int **)q = (int *)((int)m->base + (int)*(int **)q);
            {
                int n = q[1];
                q += 2;
                asm { .set reorder } /* scheduling barrier: keeps q += 2 ahead of the n*4 shift */
                q += n;
            }
        }
    }
    m->hdr->x68 = -1;
}
static inline void merge_flush_func_00377050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00377050 */

/* merge_units: begin func_00377120 */
#pragma push /* merge_units */
/* cVU1Model_PatchMaterials */
typedef struct { char pad0[4]; int flags; char pad8[0x40]; int tex[4]; int nTex; char pad5C[0]; } Pt2_Mat;
typedef struct { char pad0[4]; int flags; char pad8[0x10]; int nMat; char pad1C[0x34]; char* mats; } Pt2_Geo;
typedef struct { char pad0[4]; Pt2_Geo* geo; char pad8[0x1C]; int flags; } Pt2_Model;

void cVU1Model_PatchMaterials(Pt2_Model* m) {
    int i;
    for (i = 0; i < m->geo->nMat; i++) {
        Pt2_Mat* mt = (Pt2_Mat*)(m->geo->mats + i * 0x5C);
        int j;
        if (mt->flags & 0x10) m->flags |= 0x20;
        if (mt->flags & 0x20) m->flags |= 0x40;
        for (j = 0; j < mt->nTex; j++) {
            switch (mt->tex[j]) {
            case 2:
                break;
            case 0xB:
                m->flags |= 0x400;
                break;
            case 0xA:
                m->flags |= 0x800;
                break;
            case 0xE:
                m->flags |= 0x1000;
                break;
            }
        }
    }
    if (m->geo->flags & 0x10) {
        m->flags &= ~0x60;
        m->flags |= 0x20000;
    }
}
static inline void merge_flush_func_00377120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00377120 */
