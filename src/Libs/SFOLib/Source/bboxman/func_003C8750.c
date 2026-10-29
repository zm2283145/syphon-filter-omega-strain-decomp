#include "types.h"
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
