#pragma cplusplus on
#include "types.h"
/* EnvController_ActivateFirst: switch to a new environment, capturing the old/new fog and colour settings for the blend */
struct EV3 { float x, y, z; };
struct EnvObj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void SetOn(int on);
    virtual void Show(int hide);
};
struct Env {
    char pad[0x60];
    float f60;
    char pad64[4];
    float f68;
    float f6C;
    EV3 c70;
    char pad7C[4];
    float f80;
    EV3 c84;
    EnvObj* lights[4];
    char padA0[4];
    EnvObj* sky;
};
struct EnvCtl {
    char pad[0xC];
    Env* cur;
    unsigned char blending;
    char pad11[3];
    float time;
    float rate;
    float x1C;
    float a20, b24, a28, b2C, a30, b34, a38, b3C;
    EV3 c40, c4C, c58, c64;
};
struct V4E { float x, y, z, w; void Set(const EV3& v) { float a, b, c; b = v.y; c = v.z; a = v.x; x = a; y = b; z = c; w = 0.0f; }
    void Set2(const EV3& v) { float a, b, c; c = v.z; b = v.y; a = v.x; x = a; y = b; z = c; w = 0.0f; } } __attribute__((aligned(16)));
struct Light_ { char pad[0x18]; float invLen2; char pad1C[4]; V4E dir; };
extern "C" {
extern char D_00535D20[];
extern float D_00554ED4;
EV3* func_00178420(EV3* dst, EV3* src);
Light_* LightMgr_FindByTypeAndId(void* mgr, int type, int id);
void EnvController_ActivateFirst(EnvCtl* c, Env* e);
}
// VU0 macro-mode squared length (COP2), not expressible in C
static inline float LenSq(const V4E* a) { int t; float r = 0.0f; __asm__ ("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
/* blend-rate scale (kept as a call-site multiply by 1, as retail) */
static inline float Mul1(float a, float k) { return a * k; }
void EnvController_ActivateFirst(EnvCtl* c, Env* e)
{
    int i;
    int j;
    if (c->cur == e) return;
    if (c->cur) {
        Env* old;
        for (i = 0; i < 4; i++) {
            EnvObj* o = c->cur->lights[i];
            if (o) o->Show(1);
        }
        if (c->cur->sky) c->cur->sky->Show(1);
        old = c->cur;
        c->time = 0.0f;
        c->rate = c->blending ? Mul1(c->x1C, 1.0f) : 1.0f;
        c->x1C = 0.0f;
        c->a20 = old->f80;
        c->a28 = old->f60;
        c->a30 = old->f68;
        c->a38 = old->f6C;
        func_00178420(&c->c40, &old->c70);
        func_00178420(&c->c58, &old->c84);
        c->b24 = e->f80;
        c->b2C = e->f60;
        c->b34 = e->f68;
        c->b3C = e->f6C;
        func_00178420(&c->c4C, &e->c70);
        func_00178420(&c->c64, &e->c84);
        c->blending = 1;
    }
    c->cur = e;
    for (j = 0; j < 4; j++) {
        EnvObj* o = c->cur->lights[j];
        if (o) o->SetOn(1);
    }
    {
        Light_* l = LightMgr_FindByTypeAndId(D_00535D20, 1, 1);
        if (l) {
            V4E d;
            EV3* v = &c->cur->c84;
            l->dir.Set(*v);
            d.Set2(*v);
            l->invLen2 = 1.0f / LenSq(&d);
        }
    }
    if (c->cur->sky) c->cur->sky->SetOn(1);
    {
        float f = c->cur->f80;
        if (!(f < 0.0f)) D_00554ED4 = f;
    }
}
