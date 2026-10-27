#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* cHud_SetAimCursorPosition: places the grenade-throw marker element in camera
 * space at pos (pushed 0.3 along dir when a direction is given, and turned to
 * face along it), scaled by D_0048AE50. Euler matrix as in cInterfaceElement_SetRotation. */
struct M;
extern "C" void cMatrix_Set_ColumnMajorForm(M* m, float, float, float, float, float, float, float, float, float);
struct V {
    float x, y, z, w;
    V() {}
    V(float ax, float ay, float az) { __int128 tt = 0; /* dead: retail's paddub zero */ x = ax; y = ay; z = az; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
} __attribute__((aligned(16)));
struct Hud { char pad[0x58]; void* node; char pad5C[0x68 - 0x5C]; void* marker; };
extern "C" {
extern char g_CameraObject[];
extern float D_0048AE50;
void cInterfaceModel_SetPerspective(void* n, int f);
int func_00159570(void* l);
void** cLList_cCAMERA_GOBJPtr_Front(void* l);
void* cGOBJ_GetXform_void(void* o);
void cXform_GetInverseMatrix(M* out, void* xf);
void cInterfaceElement_SetLocation(void* e, const V& p);
void cInterfaceElement_SetView(void* e, M* m);
float Libc_Atan2f(float y, float x);
float COS(float);
float SIN(float);
void cHud_SetAimCursorPosition(Hud* self, V* pos, V* dir);
}
static inline void* GetCam() { if (func_00159570(g_CameraObject)) return *cLList_cCAMERA_GOBJPtr_Front(g_CameraObject); return 0; }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline void Apply33(V* v, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); vmulax.xyz ACC, vf4, vf8x; vmadday.xyz ACC, vf5, vf8y; vmaddz.xyz vf8, vf6, vf8z; sqc2 vf8, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
static inline void ScaleV(V* r, const V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline void AddV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void NegV(V* r, const V* a) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(a), "r"(r) : "memory"); }
static inline V operator*(const V& a, float k) { V r; ScaleV(&r, &a, k); return r; }
static inline V operator+(const V& a, V b) { V r; AddV(&r, &a, &b); return r; }
static inline V operator-(V a) { V r; NegV(&r, &a); return r; }
static inline float Length(const V& v)
{
    float r = 0.0f;
    int t;
    const V* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline V Xf(const V& v, M* m) { const V* pv = &v; V t = *pv; V* p = &t; MulM(p, m); return *p; }
static inline V Rot2(const V& v, M* m) { V t = v; V* p = &t; Apply33(p, m); return *p; }
static inline V Rot(const V& v, M* m) { return Rot2(v, m); }
static inline float LenYZ3(const V& d) { V h = d; h.x = 0.0f; return Length(h); }
static inline float LenYZ2(const V& d) { return LenYZ3(d); }
static inline float LenYZ(const V& d) { return LenYZ2(d); }
void cHud_SetAimCursorPosition(Hud* self, V* pos, V* dir)
{
    M inv;
    V ang;
    M* pi;
    if (!self->marker)
        return;
    cInterfaceModel_SetPerspective(self->node, 1);
    cXform_GetInverseMatrix(&inv, cGOBJ_GetXform_void(GetCam()));
    pi = &inv;
    ang.x = 0.0f; ang.y = 0.0f; ang.z = 0.0f;
    if (dir) {
        cInterfaceElement_SetLocation(self->marker, Xf(*pos + *dir * 0.3f, pi));
        V d = -Rot(*dir, pi);
        V* pd = &d;
        {
            float ax = Libc_Atan2f(-pd->x, LenYZ(*pd));
            float dy = pd->y;
            float ay = Libc_Atan2f(pd->z, dy);
            ang = V(ay, 0.0f, ax);
        }
    } else {
        cInterfaceElement_SetLocation(self->marker, Xf(*pos, pi));
    }
    M m;
    {
        float y = ang.y;
        float z = ang.z;
        float x = ang.x;
        float cy = COS(y);
        float sy = SIN(y);
        float cz = COS(z);
        float sz = SIN(z);
        float cx = COS(x);
        float sx = SIN(x);
        cMatrix_Set_ColumnMajorForm(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    }
    {
        float k = D_0048AE50;
        m.m[0][0] *= k; m.m[0][1] *= k; m.m[0][2] *= k;
        m.m[1][0] *= k; m.m[1][1] *= k; m.m[1][2] *= k;
        m.m[2][0] *= k; m.m[2][1] *= k; m.m[2][2] *= k;
    }
    cInterfaceElement_SetView(self->marker, &m);
}
