/*
 * Libs/SFOLib/Source/interface_element: 11 files, 003E7EB0-003E87D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E7EB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern float cTextArea_SetText(int, int);

void cInterfaceElement_SetGobj(Unk3E7EB0* self, int value) {
    self->unk78 = value;
}

float cInterfaceElement_SetText(Unk3E7EB0* self, int a1) {
    return cTextArea_SetText(self->unk74, a1);
}
static inline void merge_flush_func_003E7EB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7EB0 */

/* merge_units: begin func_003E7ED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "interface_element_types.h"

extern int cInterfaceModel_NumFrames(int owner);

/* Forward to cInterfaceModel_NumFrames on the element's owner. */
int cInterfaceElement_NumFrames(IfElement* elem) {
    return cInterfaceModel_NumFrames(elem->owner);
}
static inline void merge_flush_func_003E7ED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E7ED0 */

/* merge_units: begin func_003E7EE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x1A]; unsigned char r, g, b, a; } O_E7EE0;
void cInterfaceElement_SetFilterColor(O_E7EE0* o, float* c)
{
    unsigned char g = (unsigned int)(255.0f * c[1]);
    unsigned char b = (unsigned int)(255.0f * c[2]);
    unsigned char a = (unsigned int)(255.0f * c[3]);
    o->r = (unsigned int)(255.0f * c[0]);
    o->g = g;
    o->b = b;
    o->a = a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E7EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E7EE0 */

/* merge_units: begin func_003E8040 */
#pragma push /* merge_units */
typedef struct { __int128 a, b, c, d; } M_8040;
typedef struct { char pad[0x30]; M_8040 m; } S_8040;
#pragma peephole off
void cInterfaceElement_SetView(S_8040* s, M_8040* m)
{
    M_8040* d = &s->m;
    __int128 t0, t1;
    t0 = m->a; t1 = m->b;
    d->a = t0; t0 = m->c;
    d->b = t1; t1 = m->d;
    d->c = t0;
    d->d = t1;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E8040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E8040 */

/* merge_units: begin func_003E8070 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M4_E070;
typedef struct { char pad[0x30]; M4_E070 m; } Elem_E070;
extern "C" {
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(M4_E070* m, float, float, float, float, float, float, float, float, float);
void cInterfaceElement_SetRotation(Elem_E070* e, float* r);
}
static inline void GQR(void* d0, void* s0) { void* d = d0; __int128 qa; __int128 qb; void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
void cInterfaceElement_SetRotation(Elem_E070* e, float* r)
{
    M4_E070 m;
    float y = r[1];
    float z = r[2];
    float x = r[0];
    float cy = COS(y);
    float sy = SIN(y);
    float cz = COS(z);
    float sz = SIN(z);
    float cx = COS(x);
    float sx = SIN(x);
    cMatrix_Set_ColumnMajorForm(&m, cy * cz, -sz, sy * cz, sz * (cx * cy) + sx * sy, cx * cz, sz * (cx * sy) - sx * cy, cy * (sx * sz) - cx * sy, sx * cz, sz * (sx * sy) + cx * cy);
    GQR(&e->m, &m);
}
static inline void merge_flush_func_003E8070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8070 */

/* merge_units: begin func_003E8180 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct { char pad[0x20]; Q v; } Obj20;

/* Copies a quadword into the object's field at +0x20. */
void cInterfaceElement_SetLocation(Obj20* obj, Q* v)
{
    obj->v = *v;
}
static inline void merge_flush_func_003E8180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8180 */

/* merge_units: begin func_003E8190 */
#pragma push /* merge_units */
/* 003E8190 cInterfaceElement::DrawText() const (interface_element.cc), rebuilt from the prototype DWARF/.line data.
 * Positions the text area at the current view's origin, then draws mDrawMe scaled to fit the parent's text area
 * (gXLib view stack push / set / append / pop inlined). */
#pragma cplusplus on
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    /* 128-bit lq/sq quadword copy: MW splits a C struct copy into words */
    V(const V& o) { const void* xx = this; __int128 t; V* pd = this; const V* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(pd) } }
} __attribute__((aligned(16)));

/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline void AddM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void SubM(V* d, const V* p, const V* q) { asm volatile { lqc2 vf1, 0x0(p); lqc2 vf2, 0x0(q); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline void MulT(V* d, const V* p, float s) { float k = s; __int128 t = 0; asm volatile { .set noreorder; lqc2 vf1, 0(p); mfc1 t, k; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0(d); .set reorder } }
/* min.s (EE FPU min/max), not expressible in C */
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

static inline V operator+(const V& a, const V& b) { V r; V* pd = &r; AddM(pd, &a, &b); return r; }
static inline V operator-(const V& a, const V& b) { V r; V* pd = &r; const V* pa = &a; const V* pb = &b; SubM(pd, pa, pb); return r; }
static inline V operator*(const V& v, float s) { V r; const V* pv = &v; MulT(&r, pv, s); return r; }
static inline V operator*(float s, const V& v) { return v * s; }
static inline V Scaled(const V& v, float s) { V r; V* pd = &r; const V* pv = &v; MulT(pd, pv, s); return r; }

struct M {
    float m[4][4];
    M() {}
    V& R(int i) { return *(V*)m[i]; }
    M(float a0, float a1, float a2, float a3, float b0, float b1, float b2, float b3,
      float c0, float c1, float c2, float c3, float d0, float d1, float d2, float d3)
    {
        m[0][0] = a0; m[0][1] = a1; m[0][2] = a2; m[0][3] = a3;
        m[1][0] = b0; m[1][1] = b1; m[1][2] = b2; m[1][3] = b3;
        m[2][0] = c0; m[2][1] = c1; m[2][2] = c2; m[2][3] = c3;
        m[3][0] = d0; m[3][1] = d1; m[3][2] = d2; m[3][3] = d3;
    }
    M(const M& o) { const void* xx = this; M* pd = this; const M* ps = &o; __int128 a, b; asm volatile { lq a, 0(ps); lq b, 16(ps); sq a, 0(pd); lq a, 32(ps); sq b, 16(pd); lq b, 48(ps); sq a, 32(pd); sq b, 48(pd) } }
    M& operator=(const M& o) { __int128 a, b; M* pd = this; const M* ps = &o; asm volatile { lq a, 0(ps); lq b, 16(ps); sq a, 0(pd); lq a, 32(ps); sq b, 16(pd); lq b, 48(ps); sq a, 32(pd); sq b, 48(pd) } return *this; }
    void SetOrientation(const M& o)
    {
        m[0][0] = o.m[0][0]; m[0][1] = o.m[0][1]; m[0][2] = o.m[0][2]; m[1][0] = o.m[1][0]; m[1][1] = o.m[1][1]; m[1][2] = o.m[1][2]; m[2][0] = o.m[2][0]; m[2][1] = o.m[2][1]; m[2][2] = o.m[2][2]; m[0][3] = o.m[0][3]; m[1][3] = o.m[1][3]; m[2][3] = o.m[2][3];
    }
    void Translate(const V& v) { const void* xx = this; M* t = this; const V* p = &v; asm volatile { lqc2 vf1, 0x30(t); lqc2 vf2, 0x0(p); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x30(t) } }
} __attribute__((aligned(16)));
static inline void MulMM(M* d, const M* s)
{
    asm volatile {
        lqc2 vf4, 0x0(d)
        lqc2 vf5, 0x10(d)
        lqc2 vf6, 0x20(d)
        lqc2 vf7, 0x30(d)
        lqc2 vf8, 0x0(s)
        lqc2 vf9, 0x10(s)
        lqc2 vf10, 0x20(s)
        lqc2 vf11, 0x30(s)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(d)
        sqc2 vf13, 0x10(d)
        sqc2 vf14, 0x20(d)
        sqc2 vf15, 0x30(d)
    }
}

struct cBox {
    V min, max;
    bool IsValid() const { return min.x <= max.x; }
    unsigned char IsEmptyB() const { return min.x > max.x; }
    V Center() const { V r = (min + max) * 0.5f; return r; }
    V Dimensions() const { return IsEmptyB() ? V(0.0f, 0.0f, 0.0f, 0.0f) : max - min; }
};
struct cGOBJ {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void Render(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual cBox* GetBBox() const;
};
struct tRGBA { float r, g, b, a; };
struct cTextArea { int x, y; void SetPosition(int ax, int ay) { x = ax; y = ay; } };
struct cInterfaceModel { char pad0[0xD0]; V* area; };
struct cInterfaceElement {
    char pad0[0x19];
    unsigned char mUseGlobalColor;
    char pad1A[0x70 - 0x1A];
    cInterfaceModel* mParent;
    cTextArea* mTextArea;
    cGOBJ* mDrawMe;
};

extern "C" {
extern char g_Video[];
extern int D_00538C64;
extern unsigned char D_00538C68;
extern tRGBA g_TextColourBlock;
void cTextArea_SetColor(cTextArea*, const tRGBA*);
}
#define TOP() (*(M*)(g_Video + 0xA80 + D_00538C64 * 0x40))
#define STACK(i) (*(M*)(g_Video + 0xA80 + (i) * 0x40))

static inline void PushView() { STACK(D_00538C64 + 1) = TOP(); D_00538C64++; }
static inline void SetView(const M& m) { TOP() = m; D_00538C68 = 1; }
static inline void AppendView(const M& m) { M* t = &TOP(); MulMM(t, &m); D_00538C68 = 1; }
static inline void PopView() { int n = D_00538C64; D_00538C68 = 1; D_00538C64 = n - 1; }

extern "C" void cInterfaceElement_DrawText(const cInterfaceElement* self)
{
    if (!self->mTextArea) return;
    {
        M& top = TOP();
        V& location = top.R(3);
        if (location.z > 0.0f) {
            V* area = self->mParent->area;
            self->mTextArea->SetPosition((int)(location.x + area->x), (int)(location.y + area->y));
            if (self->mUseGlobalColor)
                cTextArea_SetColor(self->mTextArea, &g_TextColourBlock);
        } else {
            self->mTextArea->SetPosition(1000, 1000);
        }
    }
    if (!self->mDrawMe) return;
    {
        cBox* box = self->mDrawMe->GetBBox();
        if (!box->IsValid()) return;
        V boxCenter = box->Center();
        V* area = self->mParent->area;
        float areaWidth = area[1].x - area[0].x;
        float areaHeight = area[0].y - area[1].y;
        const V& boxSize = box->Dimensions();
        float scaleX = areaWidth / boxSize.x;
        float scaleY = areaHeight / boxSize.y;
        float minScale = Min(scaleX, scaleY);
        PushView();
        const V& areaCenter = 0.5f * (area[0] + area[1]);
        boxCenter.z *= -1.0f;
        M view = TOP();
        view.SetOrientation(M(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
        view.Translate(areaCenter);
        view.Translate(Scaled(boxCenter, -minScale));
        SetView(view);
        AppendView(M(minScale, 0.0f, 0.0f, 0.0f, 0.0f, minScale, 0.0f, 0.0f, 0.0f, 0.0f, minScale, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
        self->mDrawMe->Render();
        PopView();
    }
}
static inline void merge_flush_func_003E8190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8190 */

/* merge_units: begin func_003E87D0 */
#pragma push /* merge_units */
/* Declared as char[] and accessed through casts: typed scalars let the
 * compiler sink the counter load below the flag store, which breaks the match. */
#if 0 /* merge_units */
extern char D_00538C64[];   /* int counter */
#endif /* merge_units */
#define D_00538C64 ((char*)&D_00538C64) /* merge_units */

#if 0 /* merge_units */
extern char D_00538C68[];   /* char flag */
#endif /* merge_units */
#define D_00538C68 ((char*)&D_00538C68) /* merge_units */


/* Decrement the global counter and set the companion flag. */
void cInterfaceElement_UnsetupView(void) {
    int count;

    count = *(int*)D_00538C64;
    *(char*)D_00538C68 = 1;
    *(int*)D_00538C64 = count - 1;
}
#undef D_00538C64 /* merge_units */
#undef D_00538C68 /* merge_units */
static inline void merge_flush_func_003E87D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E87D0 */

/* merge_units: begin func_003E8800 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M4_E88;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_E88;
typedef struct { char pad[0xA80]; M4_E88 m[1]; } MStack_E88;
typedef struct { char pad[0x62]; unsigned char b62; } Info_E88;
typedef struct { char pad[0x20]; V4_E88 v20; float m30[16]; Info_E88* p70; } Elem_E88;
extern "C" {
#if 0 /* merge_units */
extern MStack_E88 g_Video;
#endif /* merge_units */
#define g_Video (*(MStack_E88*)&g_Video) /* merge_units */


#if 0 /* merge_units */
extern char D_00538C68;
#endif /* merge_units */
#define D_00538C68 (*(char*)&D_00538C68) /* merge_units */


}
static inline void GQR_003E8800(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void GV(void* d, void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
static inline void M4Mul(void* o, void* a, void* b) {
    asm {
        lqc2 vf4, 0x0(a)
        lqc2 vf5, 0x10(a)
        lqc2 vf6, 0x20(a)
        lqc2 vf7, 0x30(a)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(o)
        sqc2 vf13, 0x10(o)
        sqc2 vf14, 0x20(o)
        sqc2 vf15, 0x30(o)
    }
}
static inline bool IsIdent(float* m) {
    return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
           m[4] == 0.0f && m[5] == 1.0f && m[6] == 0.0f && m[7] == 0.0f &&
           m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
           m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
}

extern "C" void cInterfaceElement_SetupView(Elem_E88* e)
{
    M4_E88 a;
    M4_E88 r;
    M4_E88 t;
    {
        GQR_003E8800(&g_Video.m[D_00538C64 + 1], &g_Video.m[D_00538C64]);
        void* x0 = &a; /* dead on purpose */
        D_00538C64++;
    }
    UM(&a);
    {
        void* x1 = &a.q[3]; /* dead on purpose */
        GV(&a.q[3], &e->v20);
    }
    if (e->p70->b62) {
        M4Mul(&t, &a, &g_Video.m[D_00538C64]);
        {
            M4_E88* pr = &r;
            void* x2 = &r; /* dead on purpose */
            GQR_003E8800(&r, &t);
            GQR_003E8800(&g_Video.m[D_00538C64], pr);
        }
        D_00538C68 = 1;
    } else {
        M4_E88* c = &g_Video.m[D_00538C64];
        M4Mul(c, c, &a);
        D_00538C68 = 1;
    }
    if (!IsIdent(e->m30)) {
        M4_E88* c = &g_Video.m[D_00538C64];
        M4Mul(c, c, e->m30);
        D_00538C68 = 1;
    }
}
#undef g_Video /* merge_units */
#undef D_00538C68 /* merge_units */
static inline void merge_flush_func_003E8800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8800 */

/* merge_units: begin func_003E8DC0 */
#pragma push /* merge_units */
extern int cInterfaceModel_RenderInstance(int owner, IfElement* elem, int a2);

/* Forward (elem, a1) to cInterfaceModel_RenderInstance on the element's owner. */
int cInterfaceElement_Render(IfElement* elem, int a1) {
    return cInterfaceModel_RenderInstance(elem->owner, elem, a1);
}
static inline void merge_flush_func_003E8DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8DC0 */

/* merge_units: begin func_003E8DE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Eq_8DE0 {};
struct Pred_8DE0 { Eq_8DE0 op; int* ref; Pred_8DE0(Eq_8DE0 o, int* r) : op(o), ref(r) {} };
extern "C" {
void std_list_imp_voidPtr_remove_if(void* list, Pred_8DE0 p);
char* GetTextSystem(unsigned char);
void cLList_cTextAreaPtr_PushBackActual(void*, int*);
}
struct O_8DE0 { char pad[0x18]; unsigned char on; char pad2[0x74 - 0x19]; int id; };
extern "C" void cInterfaceElement_Activate(O_8DE0* o, int on) {
    unsigned char cur = o->on;
    if ((unsigned char)on != cur) {
        if (cur) {
            if (o->id) {
                int id = o->id;
                Eq_8DE0 e;
                char* x = GetTextSystem(cur);
                std_list_imp_voidPtr_remove_if(x + 0x10, Pred_8DE0(e, &id));
            }
            o->on = 0;
        } else {
            if (o->id) {
                int id = o->id;
                cLList_cTextAreaPtr_PushBackActual(GetTextSystem(cur) + 0x10, &id);
            }
            o->on = 1;
        }
    }
}
static inline void merge_flush_func_003E8DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E8DE0 */
