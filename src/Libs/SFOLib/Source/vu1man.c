/*
 * Libs/SFOLib/Source/vu1man: 3 files, 00377C70-00378020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00377C70 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
typedef struct { __int128 r[4]; } Mtx4;
struct V4f { float f[4]; V4f() {} V4f(float a, float b, float c, float d) { f[0] = a; f[1] = b; f[2] = c; f[3] = d; } };
typedef struct {
    char pad0[0x10];
    float mA[16];
    float mB[16];
    __int128 q90;
    __int128 qA0;
    __int128 qB0;
    char padC0[0x10];
    __int128 qD0;
    char padE0[0x24];
    unsigned char useA;
} Cam;
extern "C" {
extern char g_Video[];
extern int D_00538C60;
extern V4f D_00493320;
extern float D_00538258[];
extern float D_00538268[];
extern int D_00538278;
extern char D_00537F80[];
extern Mtx4 D_005390F0;
extern Mtx4 D_005390B0;
extern void XLib_UpdateCompMat(void* r);
extern void cXViewport_Validate(Cam* c);
extern void* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(void* q, int a, int b, int n, int c, int d);
}
typedef struct { char pad[0x150]; __int128 q150; } Obj7C70;
static inline Cam* CurCam() { return (Cam*)(g_Video + D_00538C60 * 0x110 + 0x1F0); }
static inline __int128* CamQ(Cam* c) { cXViewport_Validate(c); if (c->useA) return &c->qB0; return &c->qD0; }
static inline float* CamMtx(Cam* c) { cXViewport_Validate(c); if (c->useA) return c->mA; return c->mB; }

/* Refreshes camera matrices and uploads view/projection matrices, camera vectors, the object's
   vector at +0x150 and the viewport scale as a 14-qword VU packet. */
extern "C" void cVU1Man_SetView(Obj7C70* o) {
    XLib_UpdateCompMat(g_Video);
    Mtx4* view = &D_005390F0;
    XLib_UpdateCompMat(g_Video);
    Mtx4* proj = &D_005390B0;
    Cam* c;
    c = CurCam(); cXViewport_Validate(c); __int128* p90 = &c->q90;
    c = CurCam(); cXViewport_Validate(c); __int128* pA0 = &c->qA0;
    __int128* pB0 = CamQ(CurCam());
    V4f k = D_00493320;
    float wa = D_00538258[D_00538278];
    float sx = 1.0f / wa;
    float sy = 1.0f / D_00538268[D_00538278];
    float* m = CamMtx(CurCam());
    V4f v(m[0] * sx, m[5] * sy, m[10], m[15]);
    __int128* pkt = (__int128*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_int_etc(D_00537F80, 1, 1, 14, 0, 1);
    *(unsigned long*)pkt = 0x6C0E000111000000;
    __int128* p = (__int128*)((char*)pkt + 8);
    p[0] = view->r[0]; p[1] = view->r[1]; p += 2;
    p[0] = view->r[2]; p[1] = view->r[3]; p += 2;
    p[0] = proj->r[0]; p[1] = proj->r[1]; p += 2;
    p[0] = proj->r[2]; p[1] = proj->r[3]; p += 2;
    p[0] = *p90; p[1] = *pA0; p += 2;
    p[0] = *pB0; p[1] = o->q150; p += 2;
    p[0] = *(__int128*)&k; p[1] = *(__int128*)&v;
}
static inline void merge_flush_func_00377C70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00377C70 */

/* merge_units: begin func_00377F20 */
#pragma push /* merge_units */
typedef struct { int first; unsigned int last; } R377F20;
typedef struct { int count; R377F20 r[20]; } G377F20;
extern G377F20 D_00492F80[5];
extern unsigned int D_00493300[5];

void cVU1Man_BuildAddressTable(int* out)
{
    int k;
int acc;
int g;
G377F20* gp;
int j;
unsigned int* ep;
    k = 0;
    acc = 0;
    for (g = 0, gp = D_00492F80, ep = D_00493300; g < 5; g++, gp++, ep++) {
        G377F20* gq = gp;
        for (j = 0; j < gp->count; j++) {
            int* fp = &gp->r[j].first;
            if (k != *fp) { do { out[k++] = -1; } while (k != *fp); }
            out[k++] = acc;
            if (j < gp->count - 1)
                acc += (gq->r[j + 1].last - fp[1]) >> 3;
            else
                acc += ((unsigned int)*ep - fp[1]) >> 3;
        }
        acc = 0;
    }
}
static inline void merge_flush_func_00377F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00377F20 */

/* merge_units: begin func_00378020 */
#pragma push /* merge_units */
typedef struct { int first; int last; } R378020;
typedef struct { int count; R378020 r[20]; } G378020;
typedef struct { char p0[0x78]; int map[1]; } O378020;
#if 0 /* merge_units */
extern G378020 D_00492F80[5];
#endif /* merge_units */
#define D_00492F80 ((G378020*)&D_00492F80) /* merge_units */

/* Builds the index -> group map: -1 for gaps, the group number inside each range. */
void cVU1Man_BuildPageTable(O378020* o)
{
    int k;
int g;
G378020* gp;
int j;
    k = 0;
    for (g = 0, gp = D_00492F80; g < 5; g++, gp++) {
        for (j = 0; j < gp->count; j++) {
            int* fp = &gp->r[j].first;
            if (k != *fp) { do { o->map[k++] = -1; } while (k != *fp); }
            o->map[k++] = g;
        }
    }
}
#undef D_00492F80 /* merge_units */
static inline void merge_flush_func_00378020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00378020 */
