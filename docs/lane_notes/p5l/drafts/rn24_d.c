#pragma opt_prelinearize off
/* cInterfaceModel_Render (proto cInterfaceModel::Render): draws an instanced model once per
 * active instance (texture/blend flags, instance view, filter colour, frame, tinted triangles,
 * text, and the cascade offset on the current view), or the model itself when not instanced. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct V {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct M {
    float m[4][4];
    M() {}
    M(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
    M& operator=(const M& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); return *this; }
    void Translate(const V* v) { void* xx = this; __asm__ volatile("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" : : "r"(this), "r"(v) : "memory"); }
} __attribute__((aligned(16)));
struct tPackedRGBA { unsigned char r, g, b, a; };
struct tRGBA {
    float r, g, b, a;
    tRGBA() {}
    tRGBA(float ar, float ag, float ab, float aa) { r = ar; g = ag; b = ab; a = aa; }
    tRGBA(const tPackedRGBA& p) { Set(p.r, p.g, p.b, p.a); }
    static float U8(int x) { float k = 0.003921568f; return k * x; }
    void Set(int ar, int ag, int ab, int aa) { a = U8(aa); b = U8(ab); g = U8(ag); r = U8(ar); }
};
static inline tRGBA operator*(const tRGBA& x, const tRGBA& y) { return tRGBA(x.r * y.r, x.g * y.g, x.b * y.b, x.a * y.a); }
struct ListNode { ListNode* prev; ListNode* next; void* data; };
struct RawIt { ListNode* p; };
struct cLListIterator;
extern "C" void cLListIterator_cInterfaceElementPtr_ctor(cLListIterator* out, const RawIt* in);
struct cLListIterator {
    ListNode* p;
    cLListIterator(const RawIt& r) { cLListIterator_cInterfaceElementPtr_ctor(this, &r); }
};
struct cConstLListIterator {
    ListNode* p;
    bool operator!=(const cConstLListIterator& o) const { return p != o.p; }
    void operator++() { p = p->next; }
    void* operator*() const { return p->data; }
};
struct CI : cConstLListIterator {
    CI(const cLListIterator& o) { p = o.p; }
};
struct cInterfaceModel;
struct cInterfaceElement {
    char pad0[4];
    float mTime;
    char pad8[0x18 - 8];
    unsigned char mActive;
    unsigned char mUseGlobalColor;
    tPackedRGBA mFilterColor;
};
struct cInterfaceModel {
    char pad0[0x18];
    int mTexture;
    char pad1C[4];
    M mView;
    unsigned char mActive;
    unsigned char mPerspective;
    unsigned char mPrependView;
    unsigned char mHasAlpha;
    char pad64[0x8C - 0x64];
    int mInstances;
    char pad90[0x98 - 0x90];
    cInterfaceModel* mParent;
    char pad9C[4];
    tRGBA mFilterColor;
    V mRotation;
    char padC0[0x10];
    void* mTextArea;
    V* mCascadePosition;
};
extern "C" {
extern char g_Video[];
extern int g_TextureMgr;
extern int g_DrawMode;
extern int D_00538C60;
extern int D_00538C64;
extern unsigned char D_00538C68;
extern char D_0055C0C0[];
extern unsigned char D_0055C100;
void cTexMan_SetActive(int mgr, int tex);
void XLib_PushView(char* x);
void XLib_SetView(char* x, void* m);
void* XLib_EditViewport(char* x);
void cXViewport_SetPersp(void* vp);
void XLib_AppendView(char* x, void* m);
unsigned char cEulerAngle_T_1_2_IsZero(V* e);
M* cMatrix_ctor_cEulerAngleTR_2(M* out, V* e);
void std_list_cInterfaceElementPtr_begin(RawIt* out, int* list);
void std_list_cInterfaceElementPtr_end(RawIt* out, int* list);
void cInterfaceElement_SetupView(cInterfaceElement* e);
void cInterfaceElement_UnsetupView(cInterfaceElement* e);
void cInterfaceElement_DrawText(cInterfaceElement* e);
void cInterfaceModel_FilterChildren(cInterfaceModel* self, tRGBA* c);
void cInterfaceModel_SetFrame(cInterfaceModel* self, float t);
void cInterfaceModel_ActuallyDraw(cInterfaceModel* self, const tRGBA* c);
unsigned char cInterfaceModel_Render(cInterfaceModel* self);
}
#define TOP() (*(M*)(g_Video + 0xA80 + D_00538C64 * 0x40))
#define SLOT(i) (g_Video + 0x1F0 + (i) * 0x110)

static inline cLListIterator Begin(cInterfaceModel* self) { RawIt r; std_list_cInterfaceElementPtr_begin(&r, &self->mInstances); return cLListIterator(r); }
static inline cLListIterator End(cInterfaceModel* self) { RawIt r; std_list_cInterfaceElementPtr_end(&r, &self->mInstances); return cLListIterator(r); }

static inline void PushModelView(cInterfaceModel* self)
{
    XLib_PushView(g_Video);
    if (self->mPerspective) {
        XLib_SetView(g_Video, D_0055C0C0);
        cXViewport_SetPersp(XLib_EditViewport(g_Video));
    }
    if (!self->mPerspective || !D_0055C100)
        XLib_AppendView(g_Video, &self->mView);
    if (!cEulerAngle_T_1_2_IsZero(&self->mRotation)) {
        M r;
        XLib_AppendView(g_Video, cMatrix_ctor_cEulerAngleTR_2(&r, &self->mRotation));
    }
}
static inline void PopModelView(cInterfaceModel* self)
{
    if (self->mPerspective) {
        char* s = SLOT(D_00538C60);
        s[0x106] = 1;
        s[0x104] = 1;
    }
    int n = D_00538C64;
    D_00538C68 = 1;
    D_00538C64 = n - 1;
}
static inline void SetDrawFlags(cInterfaceModel* self)
{
    int flags = 4;
    if (self->mTexture >= 0) {
        flags |= 1;
        cTexMan_SetActive(g_TextureMgr, self->mTexture);
    } else if (!self->mHasAlpha && self->mFilterColor.a == 1.0f) {
        flags |= 0x200;
    }
    g_DrawMode = flags;
}

unsigned char cInterfaceModel_Render(cInterfaceModel* self)
{
    if (self->mParent && self->mInstances > 0) {
        PushModelView(self);
        for (cConstLListIterator inst = CI(Begin(self)); inst != CI(End(self)); ++inst) {
            cInterfaceElement* instance = (cInterfaceElement*)*inst;
            M m;
            if (instance->mActive) {
            SetDrawFlags(self);
            cInterfaceElement_SetupView(instance);
            cInterfaceModel_FilterChildren(self, &tRGBA(instance->mFilterColor));
            cInterfaceModel_SetFrame(self, instance->mTime);
            cInterfaceModel_ActuallyDraw(self, &(self->mFilterColor * tRGBA(instance->mFilterColor)));
            if (self->mTextArea)
                cInterfaceElement_DrawText(instance);
            cInterfaceElement_UnsetupView(instance);
            if (self->mCascadePosition) {
                m = TOP();
                m.Translate(self->mCascadePosition);
                TOP() = m;
                D_00538C68 = 1;
            }
            }
        }
        PopModelView(self);
    } else if (self->mActive) {
        SetDrawFlags(self);
        PushModelView(self);
        cInterfaceModel_ActuallyDraw(self, &self->mFilterColor);
        PopModelView(self);
    }
    return 1;
}
