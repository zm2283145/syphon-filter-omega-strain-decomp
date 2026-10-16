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
extern char D_005381F0[];
extern int D_00538C60;
extern V4f D_00493320;
extern float D_00538258[];
extern float D_00538268[];
extern int D_00538278;
extern char D_00537F80[];
extern Mtx4 D_005390F0;
extern Mtx4 D_005390B0;
extern void Renderer_UpdateCameraMatrices(void* r);
extern void Renderer_RefreshCamera(Cam* c);
extern void* func_00375C30(void* q, int a, int b, int n, int c, int d);
}
typedef struct { char pad[0x150]; __int128 q150; } Obj7C70;
static inline Cam* CurCam() { return (Cam*)(D_005381F0 + D_00538C60 * 0x110 + 0x1F0); }
static inline __int128* CamQ(Cam* c) { Renderer_RefreshCamera(c); if (c->useA) return &c->qB0; return &c->qD0; }
static inline float* CamMtx(Cam* c) { Renderer_RefreshCamera(c); if (c->useA) return c->mA; return c->mB; }

/* Refreshes camera matrices and uploads view/projection matrices, camera vectors, the object's
   vector at +0x150 and the viewport scale as a 14-qword VU packet. */
extern "C" void func_00377C70(Obj7C70* o) {
    Renderer_UpdateCameraMatrices(D_005381F0);
    Mtx4* view = &D_005390F0;
    Renderer_UpdateCameraMatrices(D_005381F0);
    Mtx4* proj = &D_005390B0;
    Cam* c;
    c = CurCam(); Renderer_RefreshCamera(c); __int128* p90 = &c->q90;
    c = CurCam(); Renderer_RefreshCamera(c); __int128* pA0 = &c->qA0;
    __int128* pB0 = CamQ(CurCam());
    V4f k = D_00493320;
    float wa = D_00538258[D_00538278];
    float sx = 1.0f / wa;
    float sy = 1.0f / D_00538268[D_00538278];
    float* m = CamMtx(CurCam());
    V4f v(m[0] * sx, m[5] * sy, m[10], m[15]);
    __int128* pkt = (__int128*)func_00375C30(D_00537F80, 1, 1, 14, 0, 1);
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

