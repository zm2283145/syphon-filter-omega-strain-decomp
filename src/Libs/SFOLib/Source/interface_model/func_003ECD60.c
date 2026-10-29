#pragma cplusplus on
#pragma inline_depth(8)

struct cMatrix { float m[4][4]; };
struct cEulerAngle_T { float x, y, z, w; };
struct tPackedRGBA { unsigned char r, g, b, a; };
struct tRGBA {
    float r, g, b, a;
    tRGBA() {}
    tRGBA(float ir, float ig, float ib, float ia) : r(ir), g(ig), b(ib), a(ia) {}
    tRGBA(const tPackedRGBA& c) { float fa = (float)(int)c.a; float fb = (float)(int)c.b; float fg = (float)(int)c.g; float fr = (float)(int)c.r; *this = tRGBA(fr, fg, fb, fa) * 0.003921568f; }
    tRGBA operator*(float k) const { return tRGBA(k * r, k * g, k * b, k * a); }
    tRGBA operator*(const tRGBA& o) const { return tRGBA(r * o.r, g * o.g, b * o.b, a * o.a); }
    tRGBA operator*(const tPackedRGBA& p) const { return tRGBA(r * (0.003921568f * (float)(int)p.r), (float)(int)p.g * 0.003921568f * g, (float)(int)p.b * 0.003921568f * b, (float)(int)p.a * 0.003921568f * a); }
};
static inline tRGBA ToF(const tPackedRGBA& p) { float a = (int)p.a; float b = (int)p.b; float g = (int)p.g; float r = (int)p.r; return tRGBA(r, g, b, a); }
static inline tRGBA operator*(float k, const tRGBA& y) { tRGBA t; t.r = k * y.r; t.g = k * y.g; t.b = k * y.b; t.a = k * y.a; return t; }

struct cXViewport {
    char pad[0x104];
    unsigned char mOrtho;
    unsigned char mTag;
    unsigned char mDirty;
    char pad2[0x110 - 0x107];
    void SetOrtho() { mDirty = 1; mOrtho = 1; }
};

struct XLib {
    char pad[0x1F0];
    cXViewport mViewports[8];
    int mCurViewport;
    int mTop;
    unsigned char mViewDirty;
    cXViewport& CurViewport() { return mViewports[mCurViewport]; }
    void PopView() { int t = mTop; mViewDirty = 1; mTop = t - 1; }
};
extern XLib g_Video;
extern int g_DrawMode;
struct cTexMan;
extern cTexMan* g_TextureMgr;
extern cMatrix D_0055C0C0;
extern unsigned char D_0055C100;

extern "C" {
void cTexMan_SetActive(cTexMan*, int);
void XLib_PushView(XLib*);
void XLib_SetView(XLib*, cMatrix*);
cXViewport* XLib_EditViewport(XLib*);
void cXViewport_SetPersp(cXViewport*);
void XLib_AppendView(XLib*, cMatrix*);
int cEulerAngle_T_1_2_IsZero(cEulerAngle_T*);
cMatrix* cMatrix_ctor_cEulerAngleTR_2(cMatrix*, cEulerAngle_T*);
}

struct cInterfaceModel;
struct cInterfaceElement {
    void* vt;
    float mFrame;
    char pad8[0x18 - 8];
    unsigned char mActive;
    unsigned char mUseGlobalColor;
    tPackedRGBA mFilterColor;
};
extern "C" {
void cInterfaceElement_SetupView(cInterfaceElement*);
void cInterfaceElement_UnsetupView(cInterfaceElement*);
void cInterfaceElement_DrawText(cInterfaceElement*);
void cInterfaceModel_FilterChildren(cInterfaceModel*, const tRGBA&);
void cInterfaceModel_SetFrame(cInterfaceModel*, float);
void cInterfaceModel_ActuallyDraw(cInterfaceModel*, const tRGBA&);
}

struct cInterfaceModel {
    char pad0[0x18];
    int mTexture;
    char pad1c[4];
    cMatrix mView;
    unsigned char mActive;
    unsigned char mPerspective;
    unsigned char mPrependView;
    unsigned char mHasAlpha;
    char pad64[0xA0 - 0x64];
    tRGBA mFilterColor;
    cEulerAngle_T mRotation;
    char padc0[0x10];
    void* mTextArea;
};

static inline void AppendRot(cInterfaceModel* self) {
        if (!cEulerAngle_T_1_2_IsZero(&self->mRotation)) {
            cMatrix m;
            XLib_AppendView(&g_Video, cMatrix_ctor_cEulerAngleTR_2(&m, &self->mRotation));
        }
}
extern "C" unsigned char cInterfaceModel_RenderInstance(cInterfaceModel* self, cInterfaceElement* instance, unsigned char applyModelView)
{
    if (!instance->mActive) return 1;
    int mode = 4;
    if (self->mTexture >= 0) {
        mode |= 1;
        cTexMan_SetActive(g_TextureMgr, self->mTexture);
    } else if (!self->mHasAlpha && self->mFilterColor.a == 1.0f) {
        mode |= 0x200;
    }
    g_DrawMode = mode;
    if (applyModelView) {
        XLib_PushView(&g_Video);
        if (self->mPerspective) {
            XLib_SetView(&g_Video, &D_0055C0C0);
            cXViewport_SetPersp(XLib_EditViewport(&g_Video));
        }
        if (!self->mPerspective || !D_0055C100) XLib_AppendView(&g_Video, &self->mView);
        AppendRot(self);
    }
    cInterfaceElement_SetupView(instance);
    cInterfaceModel_FilterChildren(self, tRGBA(instance->mFilterColor));
    cInterfaceModel_SetFrame(self, instance->mFrame);
    cInterfaceModel_ActuallyDraw(self, self->mFilterColor * (0.003921568f * ToF(instance->mFilterColor)));
    if (self->mTextArea) cInterfaceElement_DrawText(instance);
    cInterfaceElement_UnsetupView(instance);
    if (applyModelView) {
        if (self->mPerspective) g_Video.CurViewport().SetOrtho();
        g_Video.PopView();
    }
    return 1;
}




