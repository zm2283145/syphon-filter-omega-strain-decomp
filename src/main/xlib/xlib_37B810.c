/*
 * main/xlib: range (2 files, 0037B810-0037BD40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037B810 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } GsQ;
typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0xD0 - 0x24];
    unsigned char ready;
    char padD1[0x120 - 0xD1];
    unsigned int f120;
    unsigned int f124;
    unsigned int f128;
    char pad12C[0x160 - 0x12C];
    int f160;
    int f164;
    int f168;
    char pad16C[0x1060 - 0x16C];
    int f1060;
    char pad1064[0x10E8 - 0x1064];
    u64_t f10E8;
} RB810;
extern char D_00537F80[];
extern u64_t D_004BC1B0[];
extern GsQ *DmaPacket_Reserve(void *q, int a, int b, int c, int d, int e);
extern void cDmaMan_EndChain_int(void *q, int a);
extern u64_t *cTexMan_GetTEX1_1(void *p, int i);
extern u64_t *cTexMan_GetTEX0_1(void *p, int i);
extern void *XLib_GetTexMan(RB810 *o);
extern u64_t Renderer_SetTestReg(RB810 *o);
extern u64_t Renderer_SetPrmodeReg(RB810 *o);
extern void Renderer_RestoreRenderState(RB810 *o);

void Video_DrawScreenFxBuf(RB810 *o, int *rgba, int fbp, unsigned int fbw, int tv, int psm, int ai)
{
    unsigned int x1;
    int y1;
    unsigned int tu;
    int tv16;
    int x0;
    int y0;
    int n;
    GsQ *q;

    tv16 = tv * 16;
    tu = fbw * 16;
    x0 = (0x800 - (o->w >> 1)) * 16;
    y0 = (0x800 - (o->h >> 1)) * 16;
    x1 = x0 + o->w * 16;
    y1 = y0 + o->h * 16;
    if (o->ready) {
        Renderer_RestoreRenderState(o);
        o->ready = 0;
    }
    n = 9;
    if (o->f1060 != -1) {
        n += 2;
    }
    q = DmaPacket_Reserve(D_00537F80, 1, 1, n + 2, 0, 1);
    q->lo = 0x11000000;
    q->hi = 0x300002EULL | ((u64_t)0x20001E9 << 32);
    q++;
    q->lo = ((u64_t)(unsigned int)((n + 1) | 0x50000000) << 32) | 0x1000404;
    q->hi = (long long)n | 0x8000ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = o->f120; q++; q->lo = 0x1A;
    q->hi = Renderer_SetPrmodeReg(o); q++; q->lo = 0x1B;
    q->hi = Renderer_SetTestReg(o); q++; q->lo = 0x47;
    q->hi = o->f124; q++; q->lo = 0x46;
    if (o->f10E8 == D_004BC1B0[0]) {
        q->hi = (long long)o->f160 | ((long long)o->f164 << 8) | ((long long)o->f168 << 16); q++;
    } else {
        q->hi = 0; q++;
    }
    q->lo = 0x3D;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 8;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 9;
    q->hi = 0; q++; q->lo = 0x3F;
    q->hi = o->f10E8; q++; q->lo = 0x42;
    if (o->f1060 != -1) {
        q->hi = *cTexMan_GetTEX0_1(XLib_GetTexMan(o), o->f1060); q++; q->lo = 6;
        q->hi = *cTexMan_GetTEX1_1(XLib_GetTexMan(o), o->f1060); q++; q->lo = 0x14;
        o->f1060 = -1;
    }
    cDmaMan_EndChain_int(D_00537F80, 1);
    q = DmaPacket_Reserve(D_00537F80, 1, 1, 0xE, 0, 1);
    q->lo = 0x11000000ULL | ((u64_t)0x5000000E << 32);
    q->hi = 0x800DULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = 1; q++; q->lo = 0x1A;
    q->hi = 0x31001; q++; q->lo = 0x47;
    q->hi = D_004BC1B0[ai]; q++; q->lo = 0x42;
    q->hi = 0; q++; q->lo = 0x3F;
    q->hi = 0x60; q++; q->lo = 0x14;
    q->hi = (u64_t)(unsigned int)(fbp << 5) | ((u64_t)(fbw >> 6) << 14) | ((u64_t)(unsigned int)psm << 20) | 0xAA8000000ULL; q++; q->lo = 6;
    q->hi = 5; q++; q->lo = 8;
    q->hi = 0x156; q++; q->lo = 0;
    q->hi = (long long)rgba[0] | ((long long)rgba[1] << 8) | ((long long)rgba[2] << 16) | ((long long)rgba[3] << 24) | ((u64_t)0x3F800000 << 32); q++; q->lo = 1;
    q->hi = 0; q++; q->lo = 3;
    q->hi = (u64_t)(unsigned int)x0 | ((u64_t)(unsigned int)y0 << 16); q++; q->lo = 5;
    { u64_t t = tu; q->hi = t | ((u64_t)(unsigned int)tv16 << 16); } q++; q->lo = 3;
    { u64_t t = x1; q->hi = t | ((u64_t)(unsigned int)y1 << 16); } q++; q->lo = 5;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037B810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037B810 */

/* merge_units: begin func_0037BD40 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef struct { int unk0; int unk4; int unk8; } Sub10CC;
typedef struct {
    char pad0[0x1C];
    int w;
    int h;
    char pad24[0x2C - 0x24];
    int psm;
    char pad30[0xD0 - 0x30];
    unsigned char ready;
    char padD1[0x120 - 0xD1];
    unsigned int f120;
    unsigned int f124;
    unsigned int f128;
    int tbp[5];
    int cur;
    char pad144[0x160 - 0x144];
    int f160;
    int f164;
    int f168;
    char pad16C[0x1060 - 0x16C];
    int f1060;
    char pad1064[0x10CC - 0x1064];
    Sub10CC sub;
    char pad10D8[0x10E8 - 0x10D8];
    u64_t f10E8;
} RB810_0037BD40;
#if 0 /* merge_units */
extern void *XLib_GetTexMan(RB810_0037BD40 *o);
#endif /* merge_units */
#define XLib_GetTexMan(a0) (XLib_GetTexMan((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern u64_t Renderer_SetTestReg(RB810_0037BD40 *o);
#endif /* merge_units */
#define Renderer_SetTestReg(a0) (Renderer_SetTestReg((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern u64_t Renderer_SetPrmodeReg(RB810_0037BD40 *o);
#endif /* merge_units */
#define Renderer_SetPrmodeReg(a0) (Renderer_SetPrmodeReg((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Renderer_RestoreRenderState(RB810_0037BD40 *o);
#endif /* merge_units */
#define Renderer_RestoreRenderState(a0) (Renderer_RestoreRenderState((void *)(a0))) /* merge_units */

extern unsigned int cUserFrameEnv_GetVramAddr(Sub10CC *s);
extern int cUserFrameEnv_GetHeight(Sub10CC *s);
extern int cUserFrameEnv_GetWidth(Sub10CC *s);
extern void cUserFrameEnv_Deactivate(Sub10CC *s, int a);
extern void cUserFrameEnv_Activate(Sub10CC *s);

static inline u64_t Tex(unsigned int a, int b, int c) { u64_t t = (u64_t)a | ((long long)b << 16); return t | ((u64_t)(unsigned int)c << 24); }

void Video_CopyToScreenFxBuf(RB810_0037BD40 *o, int ai)
{
    GsQ *r;
    Sub10CC *sub;
    int x1;
    int y1;
    unsigned int tu;
    int tv;
    int tbp;
    int x0;
    int y0;
    unsigned int t20;
    int n;
    GsQ *q;

    sub = &o->sub;
    cUserFrameEnv_Activate(sub);
    x0 = (0x800 - (cUserFrameEnv_GetWidth(sub) >> 1)) * 16;
    y0 = (0x800 - (cUserFrameEnv_GetHeight(sub) >> 1)) * 16;
    x1 = x0 + cUserFrameEnv_GetWidth(sub) * 16;
    y1 = y0 + cUserFrameEnv_GetHeight(sub) * 16;
    tu = o->w * 16;
    tv = o->h * 16;
    tbp = o->tbp[o->cur];
    t20 = cUserFrameEnv_GetVramAddr(sub);
    if (o->ready) {
        Renderer_RestoreRenderState(o);
        o->ready = 0;
    }
    n = 9;
    if (o->f1060 != -1) {
        n += 2;
    }
    q = DmaPacket_Reserve(D_00537F80, 1, 1, n + 2, 0, 1);
    q->lo = 0x11000000;
    q->hi = 0x300002EULL | ((u64_t)0x20001E9 << 32);
    q++;
    q->lo = ((u64_t)(unsigned int)((n + 1) | 0x50000000) << 32) | 0x1000404;
    q->hi = (long long)n | 0x8000ULL | ((u64_t)0x10000000 << 32);
    q++;
    q->lo = 0xE;
    q->hi = o->f120; q++; q->lo = 0x1A;
    q->hi = Renderer_SetPrmodeReg(o); q++; q->lo = 0x1B;
    q->hi = Renderer_SetTestReg(o); q++; q->lo = 0x47;
    q->hi = o->f124; q++; q->lo = 0x46;
    if (o->f10E8 == D_004BC1B0[0]) {
        q->hi = (long long)o->f160 | ((long long)o->f164 << 8) | ((long long)o->f168 << 16); q++;
    } else {
        q->hi = 0; q++;
    }
    q->lo = 0x3D;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 8;
    q->hi = o->f128 | ((u64_t)o->f128 << 2); q++; q->lo = 9;
    q->hi = 0; q++; q->lo = 0x3F;
    q->hi = o->f10E8; q++; q->lo = 0x42;
    if (o->f1060 != -1) {
        q->hi = *cTexMan_GetTEX0_1(XLib_GetTexMan(o), o->f1060); q++; q->lo = 6;
        q->hi = *cTexMan_GetTEX1_1(XLib_GetTexMan(o), o->f1060); q++; q->lo = 0x14;
        o->f1060 = -1;
    }
    cDmaMan_EndChain_int(D_00537F80, 1);
    r = DmaPacket_Reserve(D_00537F80, 1, 1, 0x11, 0, 1);
    r->lo = 0x11000000ULL | ((u64_t)0x50000011 << 32);
    r->hi = 0x8010ULL | ((u64_t)0x10000000 << 32);
    r++;
    r->lo = 0xE;
    r->hi = 1; r++; r->lo = 0x1A;
    r->hi = Tex(t20, cUserFrameEnv_GetWidth(sub) >> 6, sub->unk8); r++; r->lo = 0x4D;
    r->hi = (u64_t)(unsigned int)x0 | ((u64_t)(unsigned int)y0 << 32); r++; r->lo = 0x19;
    r->hi = ((long long)(cUserFrameEnv_GetWidth(sub) - 1) << 16) | ((long long)(cUserFrameEnv_GetHeight(sub) - 1) << 48); r++; r->lo = 0x41;
    r->hi = 0x31001; r++; r->lo = 0x48;
    r->hi = D_004BC1B0[(long long)ai]; r++; r->lo = 0x43;
    r->hi = 0; r++; r->lo = 0x3F;
    r->hi = 0x60; r++; r->lo = 0x15;
    r->hi = (u64_t)(unsigned int)(tbp << 5) | ((long long)(o->w >> 6) << 14) | ((long long)o->psm << 20) | 0xAA8000000ULL; r++; r->lo = 7;
    r->hi = 5; r++; r->lo = 9;
    r->hi = 0x356; r++; r->lo = 0;
    r->hi = 0x80808080ULL | ((u64_t)0x3F800000 << 32); r++; r->lo = 1;
    r->hi = 0; r++; r->lo = 3;
    r->hi = (u64_t)(unsigned int)x0 | ((u64_t)(unsigned int)y0 << 16); r++; r->lo = 5;
    r->hi = (u64_t)(unsigned int)tu | ((u64_t)(unsigned int)tv << 16); r++; r->lo = 3;
    r->hi = (u64_t)(unsigned int)x1 | ((u64_t)(unsigned int)y1 << 16); r++; r->lo = 5;
    o->ready = 1;
    cUserFrameEnv_Deactivate(sub, 1);
}
#undef XLib_GetTexMan /* merge_units */
#undef Renderer_SetTestReg /* merge_units */
#undef Renderer_SetPrmodeReg /* merge_units */
#undef Renderer_RestoreRenderState /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0037BD40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0037BD40 */
