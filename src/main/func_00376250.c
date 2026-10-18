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

extern char D_005381F0[];
extern char D_00537F80[];
extern char D_00543790[];
extern Q6250 D_005381D0;
extern int D_00538C64;
extern char D_00538C68;
extern TexMgr6250* D_00539248;
extern int D_005381C4;
extern int D_005380F8;
extern int D_00538170;
extern int D_004932C0[];
extern int D_004932E0[];
extern u64_t D_004BC1B0;
extern u64_t D_005392D8;
extern int D_00554EFC;
extern void func_00382910(TexMgr6250*);
extern void func_00375A30(void*, int, int, int);
extern unsigned int Renderer_SetDrawState(void*, Mtx6250*, unsigned int, unsigned int);
extern Q6250* func_00375B40(void*, int, int);
extern void func_00375AC0(void*, int, Q6250*);
extern void Shadow_RenderBatch(void*);
extern void Shadow_NextReceiverBatch(void*);

/* quadword copy through a register (lq/sq) */
static inline void QC(const void* s0, void* d0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline Mtx6250* MtxAt(int i) { return &((Render6250*)D_005381F0)->mtx[i]; }
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
static inline void Dma_StartToSpr(int sadr, int madr, int qwc)
{
    *(volatile int*)0x1000D420 = qwc;
    *(volatile int*)0x1000D480 = sadr;
    *(volatile int*)0x1000D410 = madr;
    *(volatile int*)0x1000D400 = 0x100;
    __asm__ volatile ("sync");
}
static inline void Dma_WaitToSpr(void)
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
        func_00375A30(D_00537F80, 1, D_004932C0[e], D_004932E0[e]);
        D_00538170 = e;
    }
}

void Model_Draw(Model6250* m, unsigned int flags, Mtx6250* xf)
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
    tm = D_00539248;
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
    func_00382910(tm);
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
    Renderer_SetDrawState(D_005381F0, xf, flags, m->extra);
    if (m->qwc <= 0x300) {
        Dma_StartToSpr(spr, (int)m->data->packet, m->qwc);
        Dma_WaitToSpr();
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
        Q6250* p = func_00375B40(D_00537F80, 1, m->qwc);
        if (m->qwc <= 0x300) {
            Dma_StartFromSpr(spr, (unsigned int)p & 0x0FFFFFFF, m->qwc);
        } else {
            QCopy6250(m->data->packet, m->qwc, p);
        }
        func_00375AC0(D_00537F80, 1, p + m->qwc);
    }
    while (D_00554EFC) {
        Q6250* p;
        Shadow_RenderBatch(D_00543790);
        D_005381C4 = 0;
        SetTexEnv();
        D_005381C4++;
        Renderer_SetDrawState(D_005381F0, xf, flags, m->extra);
        p = func_00375B40(D_00537F80, 1, m->qwc);
        QCopy6250(m->data->packet, m->qwc, p);
        func_00375AC0(D_00537F80, 1, p + m->qwc);
        Shadow_NextReceiverBatch(D_00543790);
    }
    if (xf) {
        D_00538C64--;
        D_00538C68 = 1;
    }
}
