/*
 * SFOGame/Source/hud_radar: 2 files, 00261360-00261540
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00261360 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* HudBlip_Place: place a radar blip from its object's view-space position and heading */
struct M;
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
} __attribute__((aligned(16)));
struct M { V r0, r1, r2, r3; M() {} const V& Row1() const { return r1; } };
// VU0 macro-mode matrix * vector (COP2), not expressible in C
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode 3x3 rotate (COP2), not expressible in C
static inline void Rotate(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// sqrt.s: no C equivalent
static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float Sq(float x) { return x * x; }
struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36();
    virtual V GetPos(); /* 0xE4 */
    virtual void v38(); virtual void v39(); virtual void v3A();
    virtual M GetMtx(); /* 0xF4 */
};
struct Blip { char pad[0x60]; void* elem; char pad64[4]; int ref; char pad6C[4]; V pos; };
struct V3 { float x, y, z; V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
extern "C" {
extern M D_004F82B0;
extern float D_0048B0C8;
extern int D_0048B0C0;
extern float D_0048B0D0;
Obj* nGobjManager_LookupGOBJ_cObjectIdR(int* ref);
void cInterfaceElement_SetLocation(void* e, V* p);
void cInterfaceElement_SetRotation(void* e, V3* r);
float Libc_Atan2f(float y, float x);
void HudBlip_Place(Blip* b);
}
void HudBlip_Place(Blip* b)
{
    if (b->elem) {
        Obj* o = nGobjManager_LookupGOBJ_cObjectIdR(&b->ref);
        if (o) {
            V p = o->GetPos();
            Apply(&p, &D_004F82B0, &p);
            float d = Sqrt(Sq(p.x) + Sq(p.y));
            float s;
            if (!(d <= D_0048B0C8)) s = (float)D_0048B0C0 / d;
            else s = (float)D_0048B0C0 * D_0048B0D0 / (D_0048B0C8 + d * (D_0048B0D0 - 1.0f));
            b->pos = V(p.x * s, 0.0f, p.y * s, 1.0f);
            cInterfaceElement_SetLocation(b->elem, &b->pos);
            V dir = o->GetMtx().Row1();
            Rotate(&dir, &D_004F82B0, &dir);
            cInterfaceElement_SetRotation(b->elem, &V3(0.0f, -Libc_Atan2f(-dir.x, dir.y), 0.0f));
        }
    }
}
static inline void merge_flush_func_00261360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261360 */

/* merge_units: begin func_00261540 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; float f30; } O_1540;
typedef struct { int pad0; float cur; } M_1540;
typedef struct { O_1540* obj; int pad4; M_1540* a; M_1540* b; } S_1540;
extern float cHudTargetManager_GetDangerMag(O_1540* o);
extern void cAnimator_StartAnimation(M_1540* m, float lo, float hi, unsigned char fl);
extern void cAnimator_AnimateTo(M_1540* m, float v);
extern int D_0048B0B0;
extern int D_0048B0B8;
extern int D_004F8260;

static inline float fmin_(float a, float b)
{
    float r;
    /* EE minimum has no equivalent CodeWarrior C intrinsic. */
    asm { min.s r, a, b }
    return r;
}

void cHudRadar_SetDanger(S_1540* s, int sel, float scale)
{
    M_1540* m;
    float f;
    if (sel) {
        m = s->b;
    } else {
        m = s->a;
    }
    f = scale * cHudTargetManager_GetDangerMag(s->obj);
    f = fmin_(f, 1.0f);
    if (!sel) {
        s->obj->f30 = 1.0f;
    }
    if (m) {
        if (f > 0.98f) {
            cAnimator_StartAnimation(m, (float)D_0048B0B0, (float)D_0048B0B8, 1);
            if (!sel) {
                s->obj->f30 = ((float)D_0048B0B8 - *(volatile float*)&m->cur) / (float)(D_0048B0B8 - D_0048B0B0);
            }
        } else {
            float delta = (float)(D_0048B0B0 - D_004F8260);
            delta *= f;
            cAnimator_AnimateTo(m, (float)(int)((float)D_004F8260 + delta));
        }
    }
}
static inline void merge_flush_func_00261540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261540 */
