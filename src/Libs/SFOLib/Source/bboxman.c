/*
 * Libs/SFOLib/Source/bboxman: 3 files, 003C8690-003C8990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C8690 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x3E8]; int ival[125]; float fval[125]; int on; int pad7D4; int count; } VU_3C8690;
#pragma opt_rotateloops off
void cBBoxMan_EndVisibilityTest(VU_3C8690* p)
{
    int i;
    if (p->on) {
        unsigned char busy;
        do {
            unsigned char t;
            busy = 1;
            t = busy;
            if (!(*(volatile int*)0x10008000 & 0x100) && !(*(volatile int*)0x10003800 & 3)) t = 0;
            if (!t && !(*(volatile int*)0x10003800 & 0x0F000000)) busy = 0;
        } while (busy);
        asm __volatile__("vnop");
        asm __volatile__("sync");
        for (i = 0; i < p->count; i++) {
            volatile int* r = (volatile int*)(((i + 5) << 4) | 0x11004000);
            p->ival[i] = r[0];
            p->fval[i] = *(volatile float*)&r[2];
        }
    }
}
#pragma opt_rotateloops reset
static inline void merge_flush_func_003C8690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8690 */

/* merge_units: begin func_003C8750 */
#pragma push /* merge_units */
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) tIVector;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) cVector;
typedef struct { cVector min; cVector max; } cBox;
typedef struct { cVector r[4]; } cMatrix;
typedef struct {
    cBox* boxes[125];
    cMatrix* mats[125];
    unsigned int dcodes[125];
    float zvals[125];
    int numActive;
    unsigned int halMemAddr;
    int batchSize;
} cBBoxMan;
typedef __int128 u_long128;

extern char D_00537F80[];
extern char g_Video[];
extern float D_005383A8;
extern u_long128 D_005390F0[4];
extern char D_00542D10[];
extern int D_00542D2C;
extern int D_00542D48;
extern int D_00542D9C;
extern unsigned int D_004937C0[];
extern unsigned int D_004937D0[];
extern unsigned long long* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int c, int d, int e);
extern void cDmaMan_InsertChain(void* q, int ch, unsigned int s, unsigned int e);
extern void XLib_UpdateCompMat(void* x);
extern void cVU0Man_RunProg(void* m, int i);

static inline void VCopy(cVector* d, const cVector* s) { *(u_long128*)d = *(u_long128*)s; }
static inline void VCopy2(cVector* d, const cVector* s) { *d = *s; }
static inline int FloatBits(float f) { return *(int*)&f; }
static inline float IntBits(int i) { return *(float*)&i; }

static inline int FloatBits2(float f) { return FloatBits(f); }
static inline int FloatBits3(float f) { return FloatBits2(f); }
static inline float IntBits2(int i) { return IntBits(i); }
static inline float Zero() { return 0.0f; }
static inline float IntBits3(int i) { return IntBits2(i); }
static inline float MatW(void* m) { return m ? IntBits(1) : 0.0f; }
static inline cMatrix* GetMat(cBBoxMan* b, int i) { return b->mats[i]; }
static inline int HasMat(cBBoxMan* b, int k) { return b->mats[k] != 0; }
static inline cMatrix* GetMat2(cBBoxMan* b, int k) { cMatrix** m = b->mats; return m[k]; }
static inline float MatW4(cBBoxMan* b, int k, int one) { if (b->mats[k]) return IntBits3(one); return 0.0f; }
static inline void SetIV(tIVector* v, int x, int y, int z, int w) { v->x = x; v->y = y; v->z = z; v->w = w; }
static inline void SetIV2(tIVector* v, int x, int y, int z, int w) { v->x = x; v->z = z; v->y = y; v->w = w; }
/* 4-quad copy loop (hand-written in the original: `addi` is never emitted by the compiler) */
static inline void Copy4(void* d0, const void* s0, int n)
{
    const void* s = s0; u_long128 t; void* d = d0;
    asm {
    loop:
        .set noreorder
        lq t, 0(s)
        addiu d, d, 16
        addi n, n, -1
        addiu s, s, 16
        bgtz n, loop
        sq t, -16(d)
        .set reorder
    }
}

static inline void LoadProg(int p)
{
    if (p != D_00542D48) {
        cDmaMan_InsertChain(D_00537F80, 0, D_004937C0[p], D_004937D0[p]);
        D_00542D48 = p;
    }
}

#pragma optimization_level 3
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_loop_invariants off

void cBBoxMan_StartVisibilityTest(cBBoxMan* self)
{
    tIVector header;
    unsigned long long* vif;
    u_long128* vif2;
    int i;
    cVector bmin;
    cMatrix* l2wMat;
    int n;

    if (self->numActive) {
        SetIV(&header, self->numActive, 0, FloatBits3(D_005383A8), 0);
        vif = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 0, 1, self->halMemAddr, 0, 1);
        *vif++ = (unsigned long long)((self->halMemAddr << 16) | 0x6C000000) << 32;
        n = 4;
        vif2 = (u_long128*)vif;
        *vif2++ = *(u_long128*)&header;
        XLib_UpdateCompMat(g_Video);
        Copy4(vif2, D_005390F0, n);
        vif2 += 4;
        i = 0; { cVector* pb = &bmin; int one = 1;
                for (; i < self->numActive; i++) {
            { cBox* bx = self->boxes[i]; u_long128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(bx)); *(u_long128*)pb = t; }

            bmin.w = self->mats[i] ? IntBits3(one) : 0.0f;

            *vif2++ = *(u_long128*)&bmin;
            *vif2++ = *(u_long128*)&self->boxes[i]->max;
            l2wMat = *(cMatrix**)((char*)&self->boxes[i] + 0x1F4);
            if (l2wMat) {
                *vif2++ = *(u_long128*)&l2wMat->r[0];
                *vif2++ = *(u_long128*)&l2wMat->r[1];
                *vif2++ = *(u_long128*)&l2wMat->r[2];
                *vif2++ = *(u_long128*)&l2wMat->r[3];
            }
        }
        }
        self->batchSize = self->numActive;
        D_00542D9C = 0;
        LoadProg(D_00542D2C);
        D_00542D9C++;
        cVU0Man_RunProg(D_00542D10, 0);
    }
}
static inline void merge_flush_func_003C8750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8750 */

/* merge_units: begin func_003C8990 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;

static inline void Q8990(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma peephole off
#pragma opt_propagation off
void cBBoxMan_SingleVisibilityTest(void* self, V4* box, V4* m, int* outi, float* outf)
{
    V4* d = (V4*)0x11004050;
    V4 v;
    int one;
    int r;
    V4* q;
    float w;
    __int128 t0;
    /* v = box[0]; dest/temp listed as inputs in this order to get retail colouring (&v=s2, temp=s1) */
    __asm__ volatile("lq %1, 0x0(%2); sq %1, 0x0(%0)" : : "r"(&v), "r"(t0), "r"(box) : "memory");
    if (m) {
        one = 1;
        w = *(float*)&one;
    } else {
        w = 0.0f;
    }
    q = &d[1]; /* dead on purpose: retail keeps this addiu */ v.w = w;
    Q8990(d, &v); Q8990(&d[1], &box[1]);
    if (m) {
        Q8990(&d[2], &m[0]); q = &d[2]; Q8990(&d[3], &m[1]); q = &d[3]; Q8990(&d[4], &m[2]); q = &d[4]; Q8990(&d[5], &m[3]); q = &d[5];
    }
    asm {
        .set noreorder
        sync
        vnop
        vcallmsr vi27
        cfc2.i r, vi0
        .set reorder
    }
    d = (V4*)0x11004050;
    *outi = *(int*)&d->x;
    *outf = d->z;
}
static inline void merge_flush_func_003C8990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C8990 */
