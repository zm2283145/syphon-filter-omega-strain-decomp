#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
struct V4u { __int128 q; };
struct M4u { __int128 r0, r1, r2, r3; M4u() {} };
struct Ang { float x, y, z; };
struct Fv { float x, y, z, w; };
struct Pt { char pad[0x44]; float x, y, z; };
struct VObj { VPAD16(a) VPAD4(b) VPAD1(c) virtual int IsAlive(); };
struct Obj {
    VPAD16(a) VPAD8(b) VPAD4(c) VPAD1(d) virtual int Slot29();
    VPAD16(e) VPAD8(f) VPAD4(g) VPAD1(h) virtual M4u GetMtx();
    char pad4[0x28];
    unsigned char b2C, b2D; unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    VObj* obj;
    char pad5C[0x3584 - 0x5C];
    Pt* pt;
};
extern "C" {
extern float Math_CosThunk(float);
extern float Math_SinThunk(float);
extern void* Mtx44_SetRotation(M4u* m, float a, float b, float c, float d, float e, float f,
                               float g, float h, float i);
extern signed char D_004EED90;
extern Ang D_004EEDA0;
extern signed char D_004EEDB0;
extern M4u D_004EEDC0;
extern V4u D_004EEDF0;
}
static inline bool Not(unsigned char v) { return !(v != 0); }
/* plain asm sq: lets the delay-slot filler move later code past it */
static inline void StR(void* d, __int128 t) { asm { sq t, 0(d) } }
#pragma opt_propagation off
extern "C" void func_001A32A0(M4u* out, Obj* o)
{
    if (!D_004EED90) {
        D_004EEDA0.y = 0.0f;
        D_004EEDA0.z = 0.0f;
        D_004EEDA0.x = 1.5707964f;
        D_004EED90 = 1;
    }
    if (!D_004EEDB0) {
        float y = D_004EEDA0.y;
        float x = D_004EEDA0.x;
        float z = D_004EEDA0.z;
        float cy = Math_CosThunk(y);
        float sy = Math_SinThunk(y);
        float cx = Math_CosThunk(x);
        float sx = Math_SinThunk(x);
        float cz = Math_CosThunk(z);
        float sz = Math_SinThunk(z);
        float czcy = cz * cy;
        float czsy = cz * sy;
        float szcy = sz * cy;
        float szsy = sz * sy;
        Mtx44_SetRotation(&D_004EEDC0,
                          czcy - szsy * sx, -sz * cx, czsy + szcy * sx,
                          szcy + czsy * sx, cz * cx, szsy - czcy * sx,
                          -cx * sy, sx, cx * cy);
        D_004EEDB0 = 1;
    }
    {
        V4u pos;
        V4u* pp;
        bool b;
        bool a;
        {
            M4u m = o->GetMtx();
            M4u* mp = &m;
            pp = &pos;
            __int128 t = VLoadF(&mp->r3);
            b = false;
            a = false;
            StR(pp, t);
        }
        if (!(o->b2D == 0) && !(o->b2C == 0))
            a = true;
        if (a && Not(o->b2E))
            b = true;
        if (!b && o->Slot29()) {
            bool alive = false;
            if (o->obj && o->obj->IsAlive())
                alive = true;
            if (alive) {
                Pt* p = o->pt;
                if (p) {
                    ((Fv*)&pos)->x = p->x;
                    ((Fv*)&pos)->y = p->y;
                    ((Fv*)&pos)->z = p->z;
                }
            }
        }
        V4u* d;
        __int128 tp = V4Load(&pos);
        d = &D_004EEDF0;
        asm { .set reorder } /* barrier: keeps the two address loads paired */
        {
            M4u* s = &D_004EEDC0;
            V4Store(d, tp);
            __int128 t0;
            __int128 t1;
            t0 = s->r0; t1 = s->r1; out->r0 = t0;
            t0 = s->r2; out->r1 = t1;
            t1 = s->r3; out->r2 = t0;
            out->r3 = t1;
        }
    }
}
























