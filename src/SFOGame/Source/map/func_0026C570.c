#pragma inline_depth(8)
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct V {
    float x, y, z, w;
    V() {}
    float Length() const {
        float r = 0.0f; const V* p = this; int t;
        asm { lqc2 vf1, 0x0(p); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni t, vf4; mtc1 t, r }
        return r;
    }
    V operator-(const V& b) const {
        V r; V* pr = &r; const V* pa = this; const V* pb = &b;
        asm { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
        return r;
    }
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
} __attribute__((aligned(16)));
struct F4 { float x, y, z, w; F4(const F4& o) { x = o.x; y = o.y; z = o.z; w = o.w; } };

struct PosObj { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V GetPos(); };
struct CamT { char pad[0x30]; PosObj* target; };
struct Scr { char pad[0x60]; unsigned char b60; };
struct Ctx { Scr* scr; };
struct Self { int f0; int f4; Ctx* ctx; };

extern "C" {
extern int g_Hud;
extern char D_004FF090[];
extern char D_004A8800[];
extern CamT* g_LocalPlayer;
extern char g_Video[];
extern int D_00538C60;
extern float D_0048B278;
extern float D_0048B2B0;
extern float D_004FF084;
int cHudTargetManager_GetObjectiveTarget(int a);
char* cHudTargetInfo_GetObjectiveLocationString(int id, char* buf);
void cInfoBar_AddMessage(int list, char* text, void* color, int a, int b);
PosObj* nGobjManager_LookupGOBJ_cObjectIdR(int id);
void cHudTargetManager_SetWaypoint(int a, PosObj* o);
float Libc_Atanf(float x);
}

static inline V Sub(const V& a, const V& b) { V r; const V* ap = &a; V* rp = &r; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
static inline float AbsF(float a) { float r = 0.0f; asm { abs.s r, a } return r; }
static inline float Clamp(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "=&f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }

extern "C" void cMap_ObjectiveSelected(Self* self)
{
    if (self->ctx->scr->b60) {
        char buf[0x100];
        unsigned char done = 0;
        int id = cHudTargetManager_GetObjectiveTarget(self->f0);
        if (id) {
            char* name = cHudTargetInfo_GetObjectiveLocationString(id, buf);
            if (name) {
                cInfoBar_AddMessage(g_Hud + 0x100, name, D_004FF090, 2, 1);
                done = 1;
            }
        }
        if (!done)
            cInfoBar_AddMessage(g_Hud + 0x100, D_004A8800, D_004FF090, 2, 1);
    }
    if (cHudTargetManager_GetObjectiveTarget(self->f0))
        cHudTargetManager_SetWaypoint(self->f0, nGobjManager_LookupGOBJ_cObjectIdR(cHudTargetManager_GetObjectiveTarget(self->f0)));
    else
        cHudTargetManager_SetWaypoint(self->f0, 0);
    if (cHudTargetManager_GetObjectiveTarget(self->f0)) {
        PosObj* o = nGobjManager_LookupGOBJ_cObjectIdR(cHudTargetManager_GetObjectiveTarget(self->f0));
        CamT* c = g_LocalPlayer;
        if (c && c->target) {
            V offset = Sub(c->target->GetPos(), o->GetPos());
            float k = D_0048B278 * (20.0f + offset.Length());
            F4 vp = *(F4*)(g_Video + 0x1F0 + D_00538C60 * 0x110);
            float f = k * (vp.z / vp.w);
            float r = Libc_Atanf(f / AbsF(D_004FF084));
            D_0048B2B0 = Clamp(r, D_0048B2B0, 0.78539819f);
        }
    }
}
