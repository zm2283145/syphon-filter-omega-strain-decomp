#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { const V* s = &o; V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Mtx { __int128 q[4]; Mtx() {} V* T() { Mtx* p = this; return (V*)&p->q[3]; } Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); return *this; } };
struct Pair { V a, b; };
static inline V& Unit(V& v) { V* p = &v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return v; }
static inline void Ident(Mtx* m) { Mtx* p = m; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
struct Ctl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsActive();
};
struct Cam {
    VPAD32(a) VPAD16(b) VPAD4(c)
    virtual Mtx GetAxes();
};
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual Mtx GetMtx();
    char pad4[0x54];
    Ctl* ctl;
};
extern "C" {
extern int D_004F82A0;
extern Mtx D_004F82B0;
extern char g_CameraObject[];
Obj* Object_LookupById(int*);
int func_00159570(void*);
Cam** List_Front(void*);
void Mtx_FromRowsAndTranslation(Mtx* m, V* a, V* b, V* c, V* t);
void Mtx_Transpose3x3(Mtx* m);
int Mtx_IsTranslationZero(Mtx* m);
V* func_00133EC0(Mtx* m);
void Vec4_Assign(V* d, V* s);
void Vec3_Negate(V* v);
void Mtx_TransformByTranspose(V* v, Mtx* m);
void Mtx_SetTranslation(Mtx* m, V* t);
}
static inline Cam* GetCam() { return func_00159570(g_CameraObject) ? *List_Front(g_CameraObject) : 0; }

extern "C" void HudRadar_ComputeMarkerMatrix(void)
{
    Obj* o = Object_LookupById(&D_004F82A0);
    if (o) {
        bool ok = 0;
        Ctl* c = o->ctl;
        if (c && c->IsActive()) ok = 1;
        if (ok) {
            Mtx p = GetCam()->GetAxes();
            V fwd = *(V*)&p;
            V up = *((V*)&p + 1);
            V z(0.0f, 0.0f, 1.0f, 0.0f);
            fwd.z = 0.0f;
            up.z = 0.0f;
            Unit(fwd);
            Unit(up);
            Mtx m;
            Mtx om = o->GetMtx();
            Mtx_FromRowsAndTranslation(&m, &fwd, &up, &z, om.T());
            Mtx_Transpose3x3(&m);
            if (!Mtx_IsTranslationZero(&m)) {
                V t;
                Vec4_Assign(&t, func_00133EC0(&m));
                Vec3_Negate(&t);
                Mtx_TransformByTranspose(&t, &m);
                Mtx_SetTranslation(&m, &t);
            }
            D_004F82B0 = m;
            return;
        }
    }
    Ident(&D_004F82B0);
}
