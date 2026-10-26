#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* Shadow_AddProjectorSlot: registers an object as a shadow receiver and gives it a projector looking
 * along dir from pos (pushed back by 3x the size), with a fixed 2/7 perspective scale. VU0 math and
 * quad copies are inline asm (as in Shadow_BuildProjection, Shadow_BuildProjection.c). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));
struct Obj;
struct Recv { Obj* obj; int proj[24]; int nProj; char pad68[0x18]; };
struct Proj { Obj* actor; float x4; float fov; short x0C; unsigned char type; char padF; M view; M x50; float x90; float x94; char pad98[8]; float xA0[4]; V dir; };
struct Renderer;
struct Shadow {
    char pad0[8];
    int maxSlots;           /* 0x8 */
    char padC[0x4D0 - 0xC];
    Recv recv[0x200];       /* 0x4D0 */
    char pad104D0[4];
    int nSlots;             /* 0x104D4 */
    char pad104D8[0x10540 - 0x104D8];
    Proj proj[24];          /* 0x10540 */
    int nProj;              /* 0x11740 */
};
extern "C" {
float Math_Atan(float);
int Shadow_AddReceiver(Shadow* sh, Obj* o, int force);
float Shadow_FogFactor(Renderer* r, const V* p);
void Shadow_LookAt(V* pos, V* dir, M* m);
void Shadow_Perspective(M* out, float* a, float* b, float fov, float f13, float f14, float f15, float f16, float n, float f, float f19, float s0, float s8);
extern char g_Video[];
extern M D_00539070;
int Shadow_AddProjectorSlot(Shadow* sh, Obj* o, V* pos, V* dir, int id, float size, float strength);
}
static inline void Add(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void MulS_(V* pr, const V* pv, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pv), "r"(pr), "f"(k) : "memory"); }
static inline V MulVS0(const V& v, float k) { V r; V* rp = &r; MulS_(rp, &v, k); return r; }
static inline V operator*(const V& v, float k) { return MulVS0(v, k); }
static inline V operator+(const V& a, const V& b) { V r; Add(&r, &a, &b); return r; }
static inline void Neg_(V* r, const V* a) { __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a) : "memory"); }
static inline V operator-(const V& a) { V r; Neg_(&r, &a); return r; }
static inline void GMul(void* o, const void* a, const void* b) {
    __asm__ volatile("lqc2 vf4, 0x0(%2); lqc2 vf5, 0x10(%2); lqc2 vf6, 0x20(%2); lqc2 vf7, 0x30(%2); lqc2 vf8, 0x0(%1); lqc2 vf9, 0x10(%1); lqc2 vf10, 0x20(%1); lqc2 vf11, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(o), "r"(b), "r"(a) : "memory");
}
static inline void GMul2(void* o, const void* a, const void* b) {
    __asm__ volatile("lqc2 vf4, 0x0(%0); lqc2 vf5, 0x10(%0); lqc2 vf6, 0x20(%0); lqc2 vf7, 0x30(%0); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%1); sqc2 vf13, 0x10(%1); sqc2 vf14, 0x20(%1); sqc2 vf15, 0x30(%1)" : : "r"(a), "r"(o), "r"(b) : "memory");
}
static inline M MulM2(M a, const M& b) { M r; GMul2(&r, &a, &b); return r; }
static inline M operator*(const M& a, const M& b) { M r; GMul(&r, &a, &b); return r; }

static inline void LookAt(V* pos, V dir, M* m) { Shadow_LookAt(pos, &dir, m); }
extern "C" int Shadow_AddProjectorSlot(Shadow* sh, Obj* o, V* pos, V* dir, int id, float size, float strength)
{
    if (sh->nSlots < sh->maxSlots) {
        int r = Shadow_AddReceiver(sh, o, 1);
        if (r >= 0) {
            Recv* rc = &sh->recv[r];
            if (rc->nProj < 24 && sh->nProj < 24) {
                float back;
                float dist;
                float far;
                float fov;
                Proj* p;
                rc->proj[rc->nProj] = sh->nProj;
                back = 2.0f * size;
                rc->nProj++;
                dist = size + back;
                far = dist + back;
                fov = Math_Atan(size / dist);
                {
                    float fog = Shadow_FogFactor((Renderer*)g_Video, pos);
                    p = &sh->proj[sh->nProj];
                    p->actor = 0;
                    p->fov = fov;
                    { float k = 1.0f / 255.0f; /* a local keeps retail's fog-first mul.s operand order */ p->x4 = strength * (fog * k); }
                }
                {
                    V lpos = *pos + *dir * dist;
                    LookAt(&lpos, -*dir, &p->view);
                }
                {
                    M persp;
                    Shadow_Perspective(&persp, &p->x90, p->xA0, p->fov, 0.0f, 1.0f, 0.0f, 1.0f, size, far, 1.0f, 1.0f, 0.0f);
                    persp.m[0][0] *= 1.0f / 3.5f;
                    persp.m[1][1] *= 1.0f / 3.5f;
                    p->x90 *= 3.5f;
                    p->x94 *= 3.5f;
                    p->x50 = MulM2(persp * D_00539070, p->view);
                }
                p->dir = -*dir;
                p->type = 3;
                p->x0C = (short)id;
                sh->nProj++;
                sh->nSlots++;
                return 1;
            }
        }
    }
    return 0;
}
