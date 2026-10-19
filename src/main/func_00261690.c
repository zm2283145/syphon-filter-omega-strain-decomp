#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)
/* HudRadar_Update: radar heading, waypoint arrow (direction, fade by distance) and the player facing marker */
struct M;
struct V {
    V Minus(V o) const { V r; V* rp = &r; const V* ap = this; const V* bp = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
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
struct XNode {
    VPAD1(a)
    virtual void SetMatrix(M m);
    VPAD16(b) VPAD2(c)
    virtual void Update();
    char pad4[0xC];
    M m;
    unsigned char b50;
    const M& Mtx() { if (b50) Update(); return m; }
};
struct V3 { float x, y, z; V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
struct Player { char pad[0x50]; XNode* node; };
struct PObj : Obj {};
struct Cam { char pad[0x64]; float yaw; };
struct Radar { void* owner; char pad4[0xC]; void* face; void* ring; void* arrow; };
extern "C" {
extern char D_004FFC14[];
extern float D_0048B0C8;
extern int D_0048B0D8;
extern int D_004F8298;
int func_00159570(void*);
void** List_Front(void*);
Obj* HudTargets_GetWaypoint(void* o);
void IeElement_SetRotation(void* e, V3* r);
void IeElement_SetShown(void* e, int v);
void IeElement_Fade(void* e, float v);
float Math_Atan2f(float y, float x);
void* Camera_GetNode(void* c);
M Transform_GetInverseMatrix(void* n);
void HudRadar_Update(Radar* r, Obj* pl);
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V Sub(const V& a, const V& b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
static inline float Len1(V* a) { return Len(a); }
// min.s: no C equivalent
static inline float MinF(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline V SubV(V a, V b) { V r; V* rp = &r; const V* ap = &a; const V* bp = &b; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); return r; }
/* the unused xx reproduces retail's dead addiu of the matrix temporary's address */
static inline void RotBy(V* v, M m) { void* xx = &m; Rotate(v, &m, v); }
static inline void* GetCam() { if (func_00159570(D_004FFC14)) return *List_Front(D_004FFC14); return 0; }
void HudRadar_Update(Radar* r, Obj* pl)
{
    Cam* cam = (Cam*)GetCam();
    V3 rot(0.0f, -cam->yaw, 0.0f);
    IeElement_SetRotation(r->ring, &rot);
    if (r->arrow) {
        if (HudTargets_GetWaypoint(r->owner)) {
            V d = pl->GetPos().Minus(HudTargets_GetWaypoint(r->owner)->GetPos());
            float len = Len(&d);
            float rad = D_0048B0C8;
            if (!(len <= rad)) {
                { float ny = -d.y; float nx = -d.x; rot.y += Math_Atan2f(nx, ny); }
                IeElement_SetRotation(r->arrow, &rot);
                len -= rad;
                int k = D_0048B0D8 - D_004F8298;
                len = MinF(len, rad);
                float a = (float)D_0048B0D8 - len * (float)k / rad;
                IeElement_SetShown(r->arrow, 1);
                IeElement_Fade(r->arrow, a);
            } else {
                IeElement_SetShown(r->arrow, 0);
            }
        } else {
            IeElement_SetShown(r->arrow, 0);
        }
    }
    V fwd = ((Player*)pl)->node->Mtx().Row1();
    RotBy(&fwd, Transform_GetInverseMatrix(Camera_GetNode(cam)));
    IeElement_SetRotation(r->face, &V3(0.0f, -Math_Atan2f(-fwd.x, fwd.y), 0.0f));
}
