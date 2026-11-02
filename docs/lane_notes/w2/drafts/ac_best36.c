/* W2 XLib_ApplyContext draft: 36 lab lines (6 are lab masking artefacts), exact size (1097 instrs), ~35 check_match words.
   NOT acceptable as is: AddV4 is a CW asm volatile lw/sw copy (retail shape is impossible from C, see W2 NOTES) - needs owner approval. */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
typedef unsigned long long U64;
typedef unsigned int u32;
typedef __int128 u_long128;

static inline void RQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void Mul44(void* d, const void* a, const void* b)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%2); lqc2 $vf5, 0x10(%2); lqc2 $vf6, 0x20(%2); lqc2 $vf7, 0x30(%2)\n"
        "lqc2 $vf8, 0x0(%1); lqc2 $vf9, 0x10(%1); lqc2 $vf10, 0x20(%1); lqc2 $vf11, 0x30(%1)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(b), "r"(a) : "memory");
}

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; RQ(this, &o); }
    V& operator=(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    V& R(int i) { return *(V*)m[i]; }
} __attribute__((aligned(16)));
struct IV {
    int x, y, z, w;
    IV() {}
    IV(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; }
    IV& operator=(const IV& o) { RQ(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W4 { u32 x, y, z, w; };
struct tGSReg { U64 val; U64 reg; };

struct cXform {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void Update();
    char pad04[0x10 - 4];
    M transform;
    unsigned char dirty;
    M* GetMatrix() { if (dirty) Update(); return &transform; }
};
struct XFHolder { char pad[0x50]; cXform* xf; };
struct tShadow { char pad0[0x50]; M smat; V sscl; V soff; V sdir; };
struct ShadowMan {
    char pad0[0x104E0];
    V lightDir;                 /* 0x104E0 = D_00553C70 */
    char pad104F0[0x10540 - 0x104F0];
    tShadow shadows[1];         /* 0x10540 */
};
struct cTexture { char pad[0x60]; unsigned char txtrIsVram; unsigned char clutIsVram; };
struct cTexMan {
    int txtrBuffAddr;
    int txtrBuffEndAddr;
    cTexture** textures;
    int maxTextures;
    int numTextures;
    unsigned char txtrsModifiable;
    unsigned char txtrsNoUploads;
    unsigned char batchTerm;
    unsigned int numBatchTIDs;
    short batchTIDs[512];
    void AddTID(int id) {
        unsigned n = numBatchTIDs;
        if (n < 512) {
            if (n == 0 || batchTIDs[n - 1] != id) batchTIDs[numBatchTIDs++] = id;
        }
    }
};
struct XLib {
    char pad0[0x1C];
    int buffWidth;          /* 0x1C */
    int buffHeight;         /* 0x20 */
    char pad24[0x2C - 0x24];
    int psm;                /* 0x2C */
    int zpsm;               /* 0x30 */
    char pad34[0x64 - 0x34];
    unsigned char ishalf;   /* 0x64 */
    float gbScaleX[4];      /* 0x68 */
    float gbScaleY[4];      /* 0x78 */
    int gbScaleNum;         /* 0x88 */
    U64 frame1;             /* 0x90 */
    U64 frame2;             /* 0x98 */
    U64 zbuf;               /* 0xA0 */
    U64 xyoffset;           /* 0xA8 */
    char padB0[0xD0 - 0xB0];
    unsigned char frameEnvChanged; /* 0xD0 */
    char padD1[0xD8 - 0xD1];
    u32 ate;                /* 0xD8 */
    u32 atst;
    u32 aref;
    u32 afail;
    u32 date;
    u32 datm;
    u32 zte;
    u32 ztst;
    u32 fbmsk;              /* 0xF8 */
    u32 zmsk;               /* 0xFC */
    u32 iip;
    u32 tme;                /* 0x104 */
    u32 fge;                /* 0x108 */
    u32 abe;
    u32 aa1;                /* 0x110 */
    u32 fst;                /* 0x114 */
    u32 ctxt;
    u32 fix;
    u32 prmodecont;         /* 0x120 */
    u32 colClamp;           /* 0x124 */
    u32 texClamp;           /* 0x128 */
    int frameBuffAddr[2];   /* 0x12C */
    int zBuffAddr;          /* 0x134 */
    int frameFxBuffAddr;
    int txtrBuffAddr;
    int currFrameBuf;       /* 0x140 */
    char pad144[0x160 - 0x144];
    int fogR, fogG, fogB, fogA; /* 0x160 */
    V fogColorf;            /* 0x170 */
    char pad180[0x1A0 - 0x180];
    V fogCoeff;             /* 0x1A0 */
    char pad1B0[0xA70 - 0x1B0];
    int viewportNum;        /* 0xA70 */
    int viewNum;            /* 0xA74 */
    char padA78[0xA80 - 0xA78];
    M viewStack[16];        /* 0xA80 */
    char padE80[0xFA0 - 0xE80];
    V lookatVec;            /* 0xFA0 */
    char padFB0[0x1058 - 0xFB0];
    cTexMan* texMan;        /* 0x1058 */
    void* animTexMan;
    int activeTID;          /* 0x1060 */
    int userEnv;
    char pad1068[0x10CC - 0x1068];
    int userFbuffTID5;      /* 0x10CC */
    char pad10D0[0x10E0 - 0x10D0];
    u32 context;            /* 0x10E0 */
    u32 lastContext;        /* 0x10E4 */
    U64 alphaReg;           /* 0x10E8 */
    V colOff;               /* 0x10F0 */
};

extern "C" {
extern u32* D_005381C8;
extern char D_00537F80[];
extern char D_00538080[];
extern int D_00537E50;
extern W4 D_00537F30;
extern W4 D_00537E70[];
extern int D_00554F04;
extern int D_00554F00;
extern int* D_00554EFC;
extern ShadowMan D_00543790;
extern V D_00537D90;
extern u_long128 D_00493330;
extern IV D_005381D0;
extern U64 D_004BC1B0;
u32* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void*, int, int, int, int);
U64* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void*, int, int, int, int, int);
void cDmaMan_EndChain_int_ulongP(void*, int, void*);
void cDmaMan_EndChain_int(void*, int);
M cMatrix_Copy_InvertRotTrans(const M*);
void cTexMan_EndBatch(cTexMan*);
void XLib_UpdateRenderFrameEnv(XLib*);
U64 XLib_GetPrimEnv(XLib*);
U64 XLib_GetPixelEnv(XLib*);
cTexMan* XLib_GetTexMan(XLib*);
U64* cTexMan_GetTEX0_1(cTexMan*, int);
U64* cTexMan_GetTEX1_1(cTexMan*, int);
void cVU1Man_SetView(void*);
}

#define UNPACK(addr, n) (0x6C000000 | (addr) | ((n) << 16))
static inline void Add32(u32 v) { u32* p = D_005381C8; D_005381C8 = p + 1; *p = v; }
static inline void Add32V(u32 v);
static inline void Add32V2(u32 v) { Add32V(v); }
static inline void Add32V(u32 v) { u32 x = v; u32* p = D_005381C8; D_005381C8 = p + 1; *p = x; }
/* one-quadword UNPACK: VIF code plus four words; retail's two-register copy is a volatile asm block (see W2 NOTES) */
static inline void AddV4_0(u32 addr, const void* src)
{
    u32 a; u32 c = UNPACK(addr, 1); const void* q = src; u32* p = D_005381C8;
    asm volatile {
        .set noreorder
        lw a, 0(q)
        sw c, 0(p)
        lw c, 4(q)
        sw a, 4(p)
        sw c, 8(p)
        lw a, 8(q)
        lw c, 12(q)
        sw a, 12(p)
        sw c, 16(p)
        .set reorder }
    D_005381C8 += 5;
}
static inline void AddV4_8(u32 addr, const void* src)
{
    u32 a; const void* q = src; u32 c = UNPACK(addr, 1); u32* p = D_005381C8;
    asm volatile {
        .set noreorder
        lw a, 0(q)
        sw c, 0(p)
        lw c, 4(q)
        sw a, 4(p)
        sw c, 8(p)
        lw a, 8(q)
        lw c, 12(q)
        sw a, 12(p)
        sw c, 16(p)
        .set reorder }
    D_005381C8 += 5;
}
static inline void AddV4_9(u32 addr, const void* src)
{
    const void* q = src; u32 a; u32 c = UNPACK(addr, 1); u32* p = D_005381C8;
    asm volatile {
        .set noreorder
        lw a, 0(q)
        sw c, 0(p)
        lw c, 4(q)
        sw a, 4(p)
        sw c, 8(p)
        lw a, 8(q)
        lw c, 12(q)
        sw a, 12(p)
        sw c, 16(p)
        .set reorder }
    D_005381C8 += 5;
}
static inline void AddV4_10(u32 addr, const void* src)
{
    const void* q = src; u32 c = UNPACK(addr, 1); u32 a; u32* p = D_005381C8;
    asm volatile {
        .set noreorder
        lw a, 0(q)
        sw c, 0(p)
        lw c, 4(q)
        sw a, 4(p)
        sw c, 8(p)
        lw a, 8(q)
        lw c, 12(q)
        sw a, 12(p)
        sw c, 16(p)
        .set reorder }
    D_005381C8 += 5;
}
/* packet data copy: quadword lq/sq loop when everything is 16-byte aligned, word loop otherwise (inline asm, no C equivalent for lq/sq) */
static inline void VifCopy(int n, u32* d, const void* s)
{
    u32 u, t;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 3
        or t, t, u
        nop
        bgtz t, wl
    ql:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -4
        addiu s, s, 0x10
        bgtz n, ql
        sq u, -0x10(d)
        b done
        nop
    wl:
        lw u, 0(s)
        lw t, 4(s)
        addi n, n, -4
        sw u, 0(d)
        addiu s, s, 0x10
        sw t, 4(d)
        lw u, -8(s)
        addiu d, d, 0x10
        lw t, -4(s)
        sw u, -8(d)
        bgtz n, wl
        sw t, -4(d)
    done:
        .set reorder
    }
}
static inline void AddUnpack(u32 addr, const void* src, int qwc)
{
    const void* s = src;
    Add32V2(UNPACK(addr, qwc));
    qwc *= 4;
    VifCopy(qwc, D_005381C8, s);
    D_005381C8 += qwc;
}

#define GS_FRAME(fbp, fbw, psm, fbmsk) ((U64)(fbp) | ((U64)(fbw) << 16) | ((U64)(psm) << 24) | ((U64)(fbmsk) << 32))
#define GS_ZBUF(zbp, psm, zmsk) ((U64)(zbp) | ((U64)(psm) << 24) | ((U64)(zmsk) << 32))
#define GS_XYOFFSET(ofx, ofy) ((U64)(ofx) | ((U64)(ofy) << 32))
static inline void SetFrameEnv(XLib* c, unsigned int w, unsigned int h, unsigned int psm, unsigned int fbp, unsigned int fbmsk, unsigned int zpsm, unsigned int zbp, unsigned int zmsk, unsigned char field)
{
    unsigned int ofx;
    unsigned int ofy;
    ofx = (0x800 - (w >> 1)) << 4;
    ofy = (0x800 - (h >> 1)) << 4;
    if (field) {
        ofy += (unsigned char)!(int)((*(volatile U64*)0x12001000 >> 13) & 1) << 3;
    }
    c->frame1 = GS_FRAME(fbp, w >> 6, psm, fbmsk);
    c->frame2 = GS_FRAME(fbp, w >> 6, psm, 0xFFFFFF);
    c->zbuf = GS_ZBUF(zbp, zpsm, zmsk);
    c->xyoffset = GS_XYOFFSET(ofx, ofy);
    c->frameEnvChanged = 1;
}
static inline void RestoreFrameEnv(XLib* c)
{
    SetFrameEnv(c, c->buffWidth, c->buffHeight, c->psm, c->frameBuffAddr[c->currFrameBuf], c->fbmsk, c->zpsm, c->zBuffAddr, c->zmsk, c->ishalf);
    ((unsigned char*)c)[c->viewportNum * 0x110 + 0x2F6] = 1;
}
static inline void SendGSRegs(tGSReg* regs, int n)
{
    U64* p = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 4, 0, 1);
    *p++ = 0x11000000 | ((U64)0x50000003 << 32);
    *p++ = 0x8002 | ((U64)0x10000000 << 32);
    *p++ = 0xE;
    for (unsigned int i = 0; i < 2; i++) {
        *p++ = regs[i].val;
        *p++ = regs[i].reg;
    }
    *p++ = 0x11000000;
    *p++ = 0;
}
static inline U64 Dup2(U64 v) { return v | (v << 2); }
static inline void FlushContext(XLib* self)
{
    int n;
    U64* p;
    if (self->frameEnvChanged) {
        XLib_UpdateRenderFrameEnv(self);
        self->frameEnvChanged = 0;
    }
    n = 9;
    if (self->activeTID != -1) n += 2;
    p = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, n + 2, 0, 1);
    *p++ = 0x11000000;
    *p++ = 0x300002E | ((U64)0x20001E9 << 32);
    *p++ = 0x1000404 | ((U64)(u32)((n + 1) | 0x50000000) << 32);
    *p++ = (long long)n | (0x8000 | ((U64)0x10000000 << 32));
    *p++ = 0xE;
    *p++ = self->prmodecont;
    *p++ = 0x1A;
    *p++ = XLib_GetPrimEnv(self);
    *p++ = 0x1B;
    *p++ = XLib_GetPixelEnv(self);
    *p++ = 0x47;
    *p++ = self->colClamp;
    *p++ = 0x46;
    if (self->alphaReg == D_004BC1B0) {
        *p++ = (long long)self->fogR | ((long long)self->fogG << 8) | ((long long)self->fogB << 16);
    } else {
        *p++ = 0;
    }
    *p++ = 0x3D;
    *p++ = Dup2(self->texClamp);
    *p++ = 8;
    *p++ = Dup2(self->texClamp);
    *p++ = 9;
    *p++ = 0;
    *p++ = 0x3F;
    *p++ = self->alphaReg;
    *p++ = 0x42;
    if (self->activeTID != -1) {
        *p++ = *cTexMan_GetTEX0_1(XLib_GetTexMan(self), self->activeTID);
        *p++ = 6;
        *p++ = *cTexMan_GetTEX1_1(XLib_GetTexMan(self), self->activeTID);
        *p++ = 0x14;
        self->activeTID = -1;
    }
    cDmaMan_EndChain_int(D_00537F80, 1);
}

extern "C" void XLib_ApplyContext(XLib* self, u32 flags)
{
    u32 drawParms;
    int lqwc;
    u32 vu1Addr;
    M xFormMat;
    M* matUsed;
    cXform* xForm;
    tShadow* shadow;
    int count;
    int s;
    V camPos;
    V bumpLightNorm;
    float uScl;
    float vScl;
    V uvScale;
    V uvOffset;
    u_long128 clipPrimTag;
    IV drawParmsVec;
    tGSReg regs[2];

    drawParms = 0;
    matUsed = 0;
    lqwc = 0;
    D_005381C8 = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 0);
    Add32V(0x11000000);
    Add32(0);
    if (flags & 0x40000) {
        drawParms |= 1;
        flags &= 0xFF5FFFDF;
        flags |= 0x400000;
    } else {
        flags &= ~0x200;
    }
    if (flags & 0x4000) {
        AddV4_9(0x1E, &self->colOff);
        drawParms |= 4;
    }
    if (flags & 0x10) {
        if (D_00537E50) {
            lqwc = D_00537E50 * 2;
            AddV4_9(0xF, &D_00537F30);
            AddUnpack(0x10, D_00537E70, lqwc);
            drawParms |= 0x10;
        }
    }
    if (D_00554F04) {
        vu1Addr = 0xF;
        AddV4_9(vu1Addr, &D_00543790.lightDir);
        vu1Addr++;
        xForm = ((XFHolder*)D_00554EFC[0])->xf;
        count = D_00554F04;
        for (s = 0; s < count; s++) {
            shadow = &D_00543790.shadows[D_00554EFC[D_00554F00 + s + 1]];
            if (xForm) {
                Mul44(&xFormMat, &shadow->smat, xForm->GetMatrix());
                matUsed = &xFormMat;
            } else {
                matUsed = &shadow->smat;
            }
            AddUnpack(vu1Addr, matUsed, 4);
            AddV4_8(vu1Addr + 4, &shadow->sscl);
            AddV4_8(vu1Addr + 5, &shadow->soff);
            AddV4_0(vu1Addr + 6, &shadow->sdir);
            vu1Addr += 7;
        }
        drawParms |= 0x20;
    }
    if (flags & 0x21C00) {
        if (flags & 0xC00) {
            camPos = cMatrix_Copy_InvertRotTrans(&self->viewStack[self->viewNum]).R(3);
            AddV4_9(0x1C, &camPos);
        } else if (flags & 0x1000) {
            bumpLightNorm = D_00537D90;
            bumpLightNorm.w = 0.0f;
            AddV4_9(0x1C, &bumpLightNorm);
        } else {
            AddV4_9(0x1C, &self->lookatVec);
            drawParms |= 0x80;
        }
    }
    if (flags & 0x80) {
        AddV4_9(0x2C, &self->fogCoeff);
        drawParms |= 2;
        if (flags & 0x20) flags &= ~0x80;
    } else if (flags & 0x100) {
        AddV4_9(0x2C, &self->fogCoeff);
        AddV4_9(0x2D, &self->fogColorf);
        drawParms |= 0x40;
    }
    if (flags & 0x2000) {
        uScl = 1.0f / (float)(self->buffWidth << 4);
        vScl = 1.0f / (float)(self->buffHeight << 4);
        uvScale.x = 0.5f * self->gbScaleX[self->gbScaleNum];
        uvScale.y = -0.5f * self->gbScaleY[self->gbScaleNum];
        uvScale.z = 1.0f;
        uvScale.w = 1.0f;
        uvOffset.x = 0.5f;
        uvOffset.y = 0.5f;
        uvOffset.z = uScl;
        uvOffset.w = vScl;
        AddV4_8(0x2C, &uvScale);
        AddV4_9(0x2D, &uvOffset);
    }
    if (flags & 0x40000000) {
        { __int128 t; void* d = &clipPrimTag; const void* s = &D_00493330; asm { lq t, 0(s)
 sq t, 0(d) } }
        AddV4_10(0x1F, &clipPrimTag);
    }
    if (flags & 0x10000000) {
        drawParms |= 1;
    }
    if (flags & 0x20000000) {
        drawParms |= 8;
    }
    drawParmsVec.y = 329;
    drawParmsVec.x = drawParms;
    drawParmsVec.z = 0;
    drawParmsVec.w = 0;
    AddV4_9(0, &drawParmsVec);
    while ((u32)D_005381C8 & 0xF) Add32(0);
    cDmaMan_EndChain_int_ulongP(D_00537F80, 1, D_005381C8);
    self->tme = (flags & 1) != 0;
    self->fge = (flags & 0x80) != 0;
    self->aa1 = (flags & 0x200) != 0;
    self->fst = (flags & 0x1000000) != 0;
    self->prmodecont = 0;
    if (flags & 0x40000) {
        D_005381D0 = IV(0, 0, 0, 0);
    }
    if (flags & 0xD22000) {
        if (flags & 0x400000) {
            self->ate = 1; self->atst = 6; self->aref = 64; self->afail = 1;
        } else if (flags & 0x800000) {
            self->ate = 1; self->atst = 6; self->aref = 0; self->afail = 0;
        } else if (flags & 0x2000) {
            RestoreFrameEnv(self);
            regs[0].val = 0x51001;
            regs[0].reg = 0x48;
            regs[1].val = 0x88;
            regs[1].reg = 0x43;
            SendGSRegs(regs, 2);
            self->prmodecont = 1;
            self->ate = 1; self->atst = 0; self->aref = 0; self->afail = 3;
            self->alphaReg = 0x54;
            self->activeTID = self->userFbuffTID5;
        } else {
            self->ate = 1; self->atst = 0; self->aref = 0; self->afail = 1;
        }
    } else {
        self->ate = 1; self->atst = 6; self->aref = 0; self->afail = 0;
    }
    if (self->activeTID >= 0) {
        cTexMan* tm = self->texMan;
        cTexture* t = tm->textures[self->activeTID];
        if (!(t->txtrIsVram & t->clutIsVram)) {
            tm->numBatchTIDs = 0;
            tm->batchTerm = 0;
            self->texMan->AddTID(self->activeTID);
            cTexMan_EndBatch(self->texMan);
        }
    }
    FlushContext(self);
    cVU1Man_SetView(D_00538080);
    self->lastContext = flags;
}
