#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

struct V { float x, y, z, w; } __attribute__((aligned(16)));
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct VC {
    float x, y, z, w;
    VC() {}
    VC(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    VC(const VC& o) { Q16(this, &o); }
    VC& operator=(const VC& o) { Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Mtx { __int128 r[4]; };

static inline float Dot3(VC* a, VC* b) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline VC XForm(Mtx* m, const VC& v) {
    VC p = v;
    VC* pp = &p;
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
    return *pp;
}
static inline void XF(Mtx* m, VC* pp) {
    asm {
        lqc2 vf8, 0x0(pp)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(pp)
    }
}
static inline float Dot3B(VC* b, VC* a) {
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
struct Plane {
    VC n;
    Plane() {}
    Plane(float a, float b, float c, float d) { n.x = a; n.y = b; n.z = c; n.w = d; }
    void Set(float a, float b, float c, float d) { n.x = a; n.y = b; n.z = c; n.w = d; }
    Plane& operator=(const Plane& o) { Q16(this, &o); return *this; }
};

struct FP {
    VC pos; VC n; float d; char pad[0xC];
    void Set(const VC& p, const VC& nn, float dd) { Q16(&pos, &p); Q16(&n, &nn); d = dd; } void SetB(const VC& p, const VC& nn, float dd) { VC* a = &pos; Q16(a, &p); VC* b = &n; Q16(b, &nn); d = dd; }
};
struct Owner { char pad[0x50]; VC com; };
struct Ctx { char pad[0xB0]; char anchors[1]; };
struct HCR {
    char p0[8];
    Owner* owner;      /* 08 */
    Ctx* ctx;          /* 0C */
    char p10[0x30];
    FP fp0;            /* 40 */
    FP fp1;            /* 70 */
    char pA0[0xDC - 0xA0];
    unsigned char bDC; /* DC */
    unsigned char bDD; /* DD */
    char pDE[2];
    float zE0;         /* E0 */
    float zE4;         /* E4 */
    unsigned char bE8; /* E8 */
    char pE9[7];
    Plane plane;       /* F0 */
    char p100[0x2C4 - 0x100];
    float f2C4;
    char p2C8[0x2E0 - 0x2C8];
    char pm[0x394 - 0x2E0]; /* 2E0 */
    float f394;
};

extern char D_004A03C8[];
extern "C" {
void* RootCollection_FindByKey(void* list, void* name);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(void* a);
VC* cQuatVec_Rotation(void* t);
VC* cQuatVec_Translation(void* t);
Mtx* cMatrix_ctor_cQuaternionR(Mtx* m, VC* q);
void cMatrix_Set_cMatrixR_cVectorR(Mtx* m, Mtx* r, VC* t);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* a);
VC* cVector_ctor_cVectorR(VC* d, VC* s);
void cPointMass_Teleport(void* pm, VC* v);
void cPointMass_ClearPhysics(void* pm);
void cHumanCollisionRoutine_InitializePosition(HCR* self);
}
void cHumanCollisionRoutine_InitializePosition(HCR* self)
{
    VC com;
    VC floorPos;
    Mtx xf;
    VC comCopy;
    VC n0;
    VC n1;
    VC up;
    VC xl;
    Plane pl;
    Mtx rot;
    VC tmp;
    void* anchor = RootCollection_FindByKey(self->ctx->anchors, D_004A03C8);
    void* t = cSkaAnimAnchor_GetSkeletonTargetTransform(anchor);
    Mtx* r = cMatrix_ctor_cQuaternionR(&rot, cQuatVec_Rotation(t));
    cMatrix_Set_cMatrixR_cVectorR(&xf, r, cQuatVec_Translation(t));
    { VC* d = &xl; Q16(d, &self->owner->com); }
    { VC* pp = &xl; XF(&xf, pp); VC* c = &com; Q16(c, pp); }
    { VC* src = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(anchor)); VC* fp = &floorPos; Q16(fp, src); }
    comCopy = com;
    { VC* cp = &comCopy; cPointMass_Teleport(self->pm, cVector_ctor_cVectorR(&tmp, cp)); }
    cPointMass_ClearPhysics(self->pm);
    n0.Set(0.0f, 0.0f, 1.0f, 0.0f);
    self->fp0.SetB(floorPos, n0, 0.0f);
    n1.Set(0.0f, 0.0f, 1.0f, 0.0f);
    self->fp1.Set(floorPos, n1, 0.0f);
    self->bDC = 0;
    self->bDD = 1;
    self->bE8 = 0;
    self->zE0 = floorPos.z;
    self->zE4 = -3.4028235e38f;
    up.Set(0.0f, 0.0f, 1.0f, 0.0f);
    pl.Set(up.x, up.y, up.z, -Dot3B(&floorPos, &up));
    self->plane = pl;
    self->f2C4 = 0.0f;
    self->f394 = 0.0f;
}



