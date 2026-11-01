/* 003E8190 cInterfaceElement::DrawText() const (interface_element.cc), rebuilt from the prototype DWARF/.line data.
 * Positions the text area at the current view's origin, then draws mDrawMe scaled to fit the parent's text area
 * (gXLib view stack push / set / append / pop inlined). */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

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
