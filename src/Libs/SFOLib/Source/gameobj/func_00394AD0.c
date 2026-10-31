#pragma cplusplus on
#include "types.h"
#include "vc_copy.h"
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma opt_rebuildconditionals off

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { __int128 t; cVector* d = this; const cVector* s = &o; void* xx = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    cVector& Asg(const cVector& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
} __attribute__((aligned(16)));

class cMatrix { public: cVector m[4]; };
class cBox {
public:
    cVector min;
    cVector max;
    cBox(const cVector& a, const cVector& b) : min(a), max(b) {}
};

static inline int VEq(const cVector* a, const cVector* b) {
    int k, fl;
    unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni fl, vi17
        bne k, fl, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline bool operator!=(const cVector& a, const cVector& b) { return !VEq(&a, &b); }

static inline cVector operator*(const cMatrix& m, const cVector& v) {
    cVector r = v;
    cVector* p = &r;
    const cMatrix* mm = &m;
    asm {
        lqc2 vf8, 0(p)
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf7, 0x30(mm)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0(p)
    }
    return *p;
}

static inline cVector K0_0(const cMatrix& m, const cVector& v) { cVector r = v; cVector* p = &r; const cMatrix* mm = &m; asm { lqc2 vf8, 0(p); lqc2 vf4, 0x0(mm); lqc2 vf5, 0x10(mm); lqc2 vf6, 0x20(mm); lqc2 vf7, 0x30(mm); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0(p) } return *p; }
static inline cVector J0_0(const cMatrix& m, const cVector& v) { cVector r = v; cVector* p = &r; const cMatrix* mm = &m; asm { lqc2 vf8, 0(p); lqc2 vf4, 0x0(mm); lqc2 vf5, 0x10(mm); lqc2 vf6, 0x20(mm); lqc2 vf7, 0x30(mm); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0(p) } return *p; }
static inline cVector K0_1(const cMatrix& m, const cVector& v) { return K0_0(m, v); }
static inline cVector K0_2(const cMatrix& m, const cVector& v) { return K0_1(m, v); }
static inline cVector K0_3(const cMatrix& m, const cVector& v) { return K0_2(m, v); }
class cParent {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char p4[0xC];
    cMatrix mtx;
    unsigned char dirty;
    cMatrix* GetMatrix() { if (dirty) Update(); return &mtx; }
};

struct cModelInfo { char p0[0x30]; cVector bmin; cVector bmax; };
struct cVU1Model {
    void* data;
    cModelInfo* info;
    char p8[0x1C];
    unsigned int flags;
    int IsLoaded() { if (data) return 1; else return 0; }
};

struct cVUM_GOBJ {
    char p0[0x38];
    unsigned int x38;
    char p3C[0x14];
    cParent* parent;
    char p54[0x14];
    cVU1Model* mModel;
    char p6C[0x184];
    unsigned char isLit;
    unsigned char isShadowed;
};

extern "C" {
extern unsigned int g_DrawMode;
extern cVector D_00535D40;
extern cVector D_00535D50;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
extern char D_00543790[];
void cShadowMan_PreRenderReceiver(void* r, cVUM_GOBJ* o);
void cVU1Model_Render(cVU1Model* m, unsigned int a, cMatrix* mtx);
}

static inline void SetLightBox(const cVector& bmin, const cVector& bmax) {
    if (D_00535D40 != bmin || D_00535D50 != bmax) {
        D_00535D40 = bmin;
        D_00535D50.Asg(bmax);
        D_00535D61 = 1;
        D_00535D60 = 0;
    }
}

extern "C" void cVUM_GOBJ_Render(cVUM_GOBJ* self)
{
    if (self->mModel->IsLoaded()) {
        unsigned int resCtxt = g_DrawMode;
        unsigned int setCtxt = resCtxt;
        cMatrix* pMat = 0;
        if (self->parent) {
            pMat = self->parent->GetMatrix();
            if (self->isLit) {
                cVector& bmin = self->mModel->info->bmin;
                cVector& bmax = (&bmin)[1];
                cBox wbox(K0_1(*pMat, bmin), J0_0(*pMat, bmax));
                SetLightBox(wbox.min, wbox.max);
            }
            if (self->isShadowed && (self->mModel->flags & 0x60))
                cShadowMan_PreRenderReceiver(D_00543790, self);
        } else {
            if (self->isLit) {
                cVector& bmin = self->mModel->info->bmin;
                SetLightBox(bmin, (&bmin)[1]);
            }
            if (self->isShadowed && (self->mModel->flags & 0x60))
                cShadowMan_PreRenderReceiver(D_00543790, self);
        }
        if (!self->isLit) setCtxt &= ~0x10;
        if (!self->isShadowed) setCtxt &= ~0x60;
        g_DrawMode = setCtxt;
        cVU1Model_Render(self->mModel, self->x38, pMat);
        g_DrawMode = resCtxt;
    }
}