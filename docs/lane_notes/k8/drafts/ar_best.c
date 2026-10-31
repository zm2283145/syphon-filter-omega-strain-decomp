#pragma cplusplus on
#pragma always_inline on
#include "types.h"
#include "vslot_pad.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#define QC(d, s) Q1_L(&(d), &(s))
extern "C" { void cVector_ctor_void(void*); V4* cVector_ctor_cVectorR(V4*, V4*); void cVector_VU0Add(V4*, V4*, V4*); }
static inline void Q1D_L(void* d0, const void* s0) { const void* xx = s0; void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Q1E_L(void* d0, const void* s0) { void* xx = d0; void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
class VV { public: float x, y, z, w; VV() { cVector_ctor_void(this); } VV(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } VV(const VV& o) { cVector_ctor_cVectorR((V4*)this, (V4*)&o); } VV& operator=(const VV& o) { Q1D_L(this, &o); return *this; } } __attribute__((aligned(16)));
static inline VV operator-(const VV& a, const VV& b) { VV t; cVector_VU0Add((V4*)&t, (V4*)&a, (V4*)&b); return t; }
#define AV(v) (*(VV*)&(v))
class Ctl_L {
public:
    VPAD2(a) VPAD1(c)
    virtual void F14(void*);
    VPAD16(d)
    virtual void Upd58();
};
typedef struct { char p0[0x38]; float f38; char p3C[0x50 - 0x3C]; unsigned char b50; } CtlD_L;
typedef struct { char p0[0x20]; char* p20; char p24[4]; void* ctl; char p2C[0x50 - 0x2C]; char m50[0x10]; } Mdl_L;
typedef struct { char p0[0xB0]; int iB0; char pB4[0xD0 - 0xB4]; float fD0; } Root_L;
typedef struct { char p0[0x8]; float z; } Pos_L;
typedef struct {
    char p0[0x8]; Mdl_L* mdl; char* owner;
    char p10; unsigned char b11; unsigned char b12; unsigned char b13; unsigned char b14; char p15[0x20 - 0x15];
    int i20; char p24[0x34 - 0x24]; int flags; char p38[0x40 - 0x38];
    V4 v40; V4 v50; float f60; char p64[0x70 - 0x64]; V4 v70; V4 v80; float f90; char p94[0xDC - 0x94];
    unsigned char bDC; unsigned char bDD; unsigned char bDE; char pDF;
    union { float fE0; int iE0; }; int iE4; unsigned char bE8; char pE9[0x1E0 - 0xE9];
    V4 v1E0; char p1F0[0x2C4 - 0x1F0];
    union { float f2C4; int i2C4; }; union { float f2C8; int i2C8; }; unsigned char b2CC; char p2CD[0x2E0 - 0x2CD];
    char o2E0[0x10]; V4 v2F0; V4 v300; char p310[0x318 - 0x310]; float f318; char p31C[0x370 - 0x31C];
    float f370; char p374[0x380 - 0x374]; V4 v380; float f390; float f394; char p398[0x9C0 - 0x398];
    unsigned char b9C0; char p9C1[0x9F0 - 0x9C1]; V4 v9F0; char pA00[0x20]; float fA20;
} Phys_L;
extern "C" {
Root_L* RootCollection_FindByKey(void*, void*);
void cVector_ctor_void(void*);
void cVector_VU0Scale(float, V4*, V4*);
VV cVector_opMul(const VV&, float);
V4* cVector_ctor_cVectorR(V4*, V4*);
void cVector_VU0Add(V4*, V4*, V4*);
VV cSkeleton_GetCenterOfMass(Mdl_L*);
VV cVector_opSub(const VV&, const VV&);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(Root_L*);
Pos_L* cQuatVec_Translation(void*);
float ActorPhys_ResponseHeightDelta(int, float, float, float, float);
void* cXform_GetMatrix(void*);
VV cVector_GetTransformed(void*, void*);
void cPointMass_ClearForce(void*);
void cPointMass_ClearAcceleration(void*);
void cPointMass_ClearVelocity(void*);
void cCollisionProbe_SphereSweptRay_ctor(void*);
void cVector_VU0Subtract(V4*, V4*, V4*);
VV cPointMass_GetDisplacement(void*);
unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans(Phys_L*, V4*, V4*, float);
VV opMul(float, V4*);
}
extern char D_004A03C8[], D_004A03D0[], D_004A03D8[];
extern V4 D_004A03F0;
extern float D_004A0348, D_004A0350;
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4I;
typedef struct { unsigned char b0; char p1[0x2F]; V4 v30; char p40[0x10]; V4 v50; char o60[0x20]; V4 v80; char p90[0x110 - 0x90]; unsigned char b110; char p111[3]; float f114; unsigned char b118; char p119[0x1E0 - 0x119]; } Res_L;
extern "C" {
void ActorBody_CalcQueryHeight(float, float, float, float, float*, float*, unsigned char);
V4* cVector_SetZ(V4*, float);
void* cSkaAnimAnchor_GetTransform(Root_L*);
void cQuatVec_Copy_Invert(void*, void*);
void* cMatrix_ctor_cQuatVecR(void*, void*);
VV cVector_opAdd(const VV&, const VV&);
VV* cVector_Transform_cMatrixR(VV*, void*);
VV* cVector_SetY(float, VV*);
void ColQuery_InitTransformedThunk(Res_L*, V4*, V4*, V4*, int, void*, V4*, float, float, float, float, float);
void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(Res_L*, V4*, float, float, float, float, float, V4*, V4*, int);
void ColQuery_ExecuteThunk(Res_L*, int, int);
void cHumanCollisionRoutine_HandleAnyLethalCollisions(Phys_L*, int, Res_L*);
}
extern "C" {
VV cSkeleton_GetBoneToWorldTranslation(Mdl_L*, int);
void* cQuatVec_ctor_cQuatVecR(void*, const void*);
void* cQuatVec_Invert(void*);
void* cQuatVec_Rotation(void*);
V4* cVector_Transform_cQuaternionR_cVectorR(const VV&, void*, void*);
void* cSkaAnimAnchor_GetPosition(Root_L*);
void cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(Root_L*, const VV&);
void* cSkaAnimAnchor_GetSkeletonTargetTransform(Root_L*);
V4* cSkaAnimAnchor_GetDeltaPos(Root_L*);
V4* cVector_Normalize_floatR(V4*, float*);
float cPointMass_GetMass(void*);
void cVector_opAddAssign(void*, const VV&);
void cHumanCollisionRoutine_DetectForWater(Phys_L*, V4*, V4*, V4*);
}
class PL { public: V4 r, q; PL(const PL& o) { cQuatVec_ctor_cQuatVecR(this, &o); } };
static inline PL* InvP_L(const PL& p) { V4 t[2]; return (PL*)cQuatVec_Invert(cQuatVec_ctor_cQuatVecR(t, &p)); }
static inline float MinZ_L(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline VV Lerp_L(const VV& a, const VV& b, float k)
{
    VV t; int tk;
    const VV* pa = &a; const VV* pb = &b; VV* pt = &t;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        mfc1 tk, k
        qmtc2.ni tk, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(pt)
    }
    return t;
}
static inline void QM_L(void* m, void* q) { __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(m), "r"(q) : "memory"); }
static inline float Dot3_L(V4* a, V4* b)
{
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
static inline VV SubV_L(const VV& a, const VV& b) { VV t; cVector_VU0Subtract((V4*)&t, (V4*)&a, (V4*)&b); return t; }
extern V4 g_GameGravity;
static inline unsigned char IsZero4_L(V4* v)
{
    int k, fl; int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
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
static inline float Dot3N_L(V4* a, V4* b)
{
    int rv0;
    float ret;
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
static inline VV* NodePos_L(void* n) { if (((CtlD_L*)n)->b50) ((Ctl_L*)n)->Upd58(); return (VV*)((char*)n + 0x40); }
static inline void* CtlMtx_L(void* c) { if (((CtlD_L*)c)->b50) ((Ctl_L*)c)->Upd58(); return (char*)c + 0x10; }
static inline void AddScaled_L(void* o, float m, const VV& v) { cVector_opAddAssign(o, cVector_opMul(v, m)); }
static inline VV WithZ_L(const VV& v, float z) { V4 t; return *(VV*)cVector_SetZ(cVector_ctor_cVectorR(&t, (V4*)&v), z); }
static inline V4* NZ_L(const VV& v, float* len) { V4 t; return cVector_Normalize_floatR(cVector_ctor_cVectorR(&t, (V4*)&v), len); }
static inline VV* MM_L(const VV& v, void* m) { V4 t; return cVector_Transform_cMatrixR((VV*)cVector_ctor_cVectorR(&t, (V4*)&v), m); }
struct PLc { char b[0x20]; PLc(void* s) { cQuatVec_Copy_Invert(b, s); } };
struct MXc { char b[0x40]; MXc() {} MXc(const PLc& i) { cMatrix_ctor_cQuatVecR(b, (void*)i.b); } MXc(const void* pl) { cMatrix_ctor_cQuatVecR(b, (void*)pl); } };
static inline VV* MMR_L(const VV& v, const MXc& m) { return MM_L(v, (void*)m.b); }
struct M50_L { char b[0x10]; VV Mul(void* m) const { return cVector_GetTransformed((void*)this, m); } };
static inline void* INV_L(void* o, void* s) { cQuatVec_Copy_Invert(o, s); return o; }
static inline void* QMR_L(void* m, void* q) { QM_L(m, q); return m; }
static inline void* TMA_L(void* o, void* s) { cMatrix_ctor_cQuatVecR(o, s); return o; }
static inline VV* F57_L(float k, const VV& v) { V4 t; return cVector_SetY(k, (VV*)cVector_ctor_cVectorR(&t, (V4*)&v)); }
static inline void UM_L(void* m) { int t; __asm__ volatile("sqc2 vf0, 0x30(%1); qmfc2.ni %0, vf0; pcpyud %0, %0, zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(m) : "memory"); }
static inline float MinF_L(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline float MaxF_L(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float SqrtF_L(float a) { float r; asm { sqrt.s r, a } return r; }
static inline float OffSel_L(unsigned char c) { float r; if (c) r = 0.35f; else r = 1.25f; return r; }
static inline float SqrtZ_L(float a) { float r = 0.0f; asm { sqrt.s r, a } return r; }
extern signed char D_004E1D88;
extern V4I D_004E1D90;
#define D_004E1D90F (*(V4*)&D_004E1D90)
extern V4I D_004E1D90;
static inline V4* ZeroF_L() { if (!D_004E1D88) { D_004E1D90F.x = 0.0f; D_004E1D88 = 1; D_004E1D90F.y = 0.0f; D_004E1D90F.z = 0.0f; D_004E1D90F.w = 0.0f; } return &D_004E1D90F; }
typedef struct { unsigned char hit; V4 a; V4 b; char part30[0x10]; V4 to; V4 from; unsigned char b60; unsigned char b61; unsigned char b62; void* p64; } RayQ_L;
typedef struct { char p[0x70]; } RayP_L;
extern "C" {
V4* cVector_GetZero(void);
void cVector_Get0001(V4*);
void cCollisionModel_FaceLocator_ctor(void*);
void cCollisionProbe_Ray_ctor(RayP_L*, V4*, V4*);
void cCollisionProbe_Ray_opAssign(RayQ_L*, RayP_L*);
void cCollisionProbe_Ray_dtor(RayP_L*, int);
unsigned char cCollisionProbe_Ray_DetectForCollision_cArrayR_bool(RayQ_L*, V4*, int);
void Los_CombineResult(Res_L*, RayQ_L*, V4*);
}
typedef struct { char p[0x10]; } Tmp270_L;
extern "C" {
void cPlane_ctor_cVectorR_cVectorR(Tmp270_L*, V4*, V4*);
void cPlane_opAssign(void*, Tmp270_L*);
void cPlane_dtor(Tmp270_L*, int);
void* cCollisionModel_FaceLocator_ParentModel(void*);
void* cCollisionModel_FaceLocator_FaceIndex(void*);
void* cCollisionModel_GetFace(void*, void*);
void* cCollisionModel_Face_GetPropertiesIndex(void*);
void* cCollisionModel_GetFaceProperties(void*, void*);
void cCollisionFace_Set_cCollisionModelFaceR_uint_cCollisionModelFacePropertiesR_cCollisionModelR(void*, void*, void*, void*, void*);
}
static inline float MaxZ_L(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float MinZ2_L(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float AbsZ_L(float a) { float r = 0.0f; asm { abs.s r, a } return r; }
static inline float ClampZ_L(float x, float lo, float hi) { float r = 0.0f; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline void VAdd_L(void* d, void* a, void* b) { asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(b); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d) } }
static inline unsigned char Bit_L(int f, int s) { return ((f >> s) & 1) != 0; }
static inline unsigned char NotB_L(unsigned char x) { return !x; }
class Crv_L {
public:
    VPAD4(a)
    virtual void F18();
    virtual void F1C();
    virtual void F20(float, float);
};
extern "C" {
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame(void*, float);
int cSplinedMotion_float_IsTransitionInProgress(void*);
float cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate(void*);
int cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(Root_L*);
void cSkaAnimAnchor_TreeNode_UpdateTransform(Root_L*);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(Root_L*);
void cVector_Rotate_cQuaternionR(V4*, void*);
float* cVector_W(V4*);
void cVector_Translate(V4*, V4*);
float func_001E5260(VV*);
void cVector_opAssign(void*, void*);
void cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(Root_L*, void*);
void cQuatVec_ctor_cQuaternionR_cVectorR(void*, V4*, VV*);
void Physical_SetChildOffsets(Root_L*, void*);
float func_001E50E0(void*, void*);
void LerpAndNormalize(float, void*, void*, void*);
void cQuaternion_opSub(V4*, void*);
void cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(Root_L*, void*);
}
extern "C" {
V4* Quat_InverseTransformPoint(VV*, void*, V4*);
void* cSkaAnimAnchor_GetRotation(Root_L*);
void AnimScalar_RescaleSlopes(void*, float);
void AnimScalar_RestartTimer(void*);
}
extern "C" {
float cVector_X_void(V4*);
float cVector_Y_void(V4*);
float cVector_Z_void(V4*);
float cVector_Dot(V4*, V4*);
V4* cVector_ctor_float_float_float_float(V4*, float, float, float, float);
float cPlane_C(V4*);
float Plane_HeightAt(V4*, V4*);
void cVector_Copy_WSet0(V4*, V4*);
void func_001E53F0(float, V4*, void*, V4*, V4*);
}
typedef struct { V4 a, b; } VP_L;
struct St_L { VV a; VV b; float c; };
static inline void ZQ_L(void* v) { asm { sq zero, 0(v) } }
static inline float AbsF_L(float a) { float r; asm { abs.s r, a } return r; }
static inline float PlaneH_L(V4* pl, float px, float py) { float d, z, c = cPlane_C(pl); z = 0.0f; if (z != c) { V4 t; float h = -Plane_HeightAt(pl, cVector_ctor_float_float_float_float(&t, px, py, z, 1.0f)); d = h / cPlane_C(pl); } else d = z; return d; }
static inline float PlaneH_old(V4* pl, float px, float py)
{
    float d;
    if (cPlane_C(pl) != 0.0f) {
        V4 t;
        float h = -Plane_HeightAt(pl, cVector_ctor_float_float_float_float(&t, px, py, 0.0f, 1.0f));
        d = h / cPlane_C(pl);
    } else d = 0.0f;
    return d;
}
static inline unsigned char Steep_L(V4* pl) { V4 t; cVector_Copy_WSet0(&t, pl); V4* tp = &t; return AbsF_L(tp->z) > 0.5f; }
static inline unsigned char Steep_old(V4* pl)
{
    V4 t;
    cVector_Copy_WSet0(&t, pl);
    V4* tp = &t;
    int r = 1;
    if (AbsF_L(tp->z) <= 0.5f) r = 0;
    return r;
}
static inline unsigned char Lt_L(float a, float b) { return a < b; }
static inline unsigned char LtR_L(float b, float a) { return a < b; }
static inline unsigned char GtR_L(float b, float a) { return a > b; }
static inline unsigned char NLe_L(float a, float b) { return a > b; }
static inline unsigned char NLt0_L(float a) { return a >= 0.0f; }
static inline void InitSphZ_L(Res_L* r, V4* a, V4* b, V4* d, float x, float y, float z) { float xx = x, yy = y; cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(r, a, xx, yy, yy, z, xx, b, d, 0); }
static inline V4* ZeroFZ_L(float z) { if (!D_004E1D88) { D_004E1D90F.x = z; D_004E1D88 = 1; D_004E1D90F.y = z; D_004E1D90F.z = z; D_004E1D90F.w = z; } return &D_004E1D90F; }
static inline void InitSph_L(Res_L* r, V4* a, V4* b, const VV& d, float x, float y) { float xx = x, yy = y; cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(r, a, xx, yy, yy, 0.0f, xx, b, (V4*)&d, 0); }
static inline VV* QInv_L(const VV& v, void* q, V4* p) { V4 t; return (VV*)Quat_InverseTransformPoint((VV*)cVector_ctor_cVectorR(&t, (V4*)&v), q, p); }
static inline VV* PTP_L(const VV& v, void* q, V4* p) { V4 t; return (VV*)cVector_Transform_cQuaternionR_cVectorR(*(VV*)cVector_ctor_cVectorR(&t, (V4*)&v), q, p); }
static inline void RayQInit_L(RayQ_L* q, V4* to, V4* from) {
    V4 org;
    q->hit = 0;
    cVector_ctor_cVectorR(&q->a, cVector_GetZero());
    cVector_Get0001(&org);
    cVector_ctor_cVectorR(&q->b, &org);
    cCollisionModel_FaceLocator_ctor(q->part30);
    cVector_ctor_cVectorR(&q->to, to);
    cVector_ctor_cVectorR(&q->from, from);
    q->b60 = 0;
    q->b61 = 0;
    q->b62 = 0;
    q->p64 = 0;
}
static inline V4I* Zero_L() { if (!D_004E1D88) { D_004E1D90.x = 0; D_004E1D88 = 1; D_004E1D90.y = 0; D_004E1D90.z = 0; D_004E1D90.w = 0; } return &D_004E1D90; }
static inline float GetZ_L(const VV& v) { const VV* pv = &v; return pv->z; }
static inline unsigned char Gt0_L(float x) { int r = 1; if (x <= 0.0f) r = 0; return r; }
static inline unsigned char Both_L(float a, float b) { float z = 0.0f; unsigned char r = 0; if (!(a <= z) && !(b <= z)) r = 1; return r; }
static inline unsigned char Nz_L(unsigned char x) { return x != 0; }
static inline unsigned char Fl_L(Phys_L* p) { unsigned char r = 0; if (p->bDD && NotB_L(p->b9C0)) r = 1; return r; }
static inline VV ScaleV(float f, VV* v) { VV t; cVector_VU0Scale(f, (V4*)&t, (V4*)v); return t; }
static inline void SubtractTo_L(V4* out, V4* a, V4* b) { V4 t; cVector_ctor_void(&t); cVector_VU0Subtract(&t, a, b); cVector_ctor_cVectorR(out, &t); }
static inline VV LerpV_L(V4* a, V4* b, float k)
{
    V4 t; V4* pt; int tk;
    cVector_ctor_void(&t);
    V4* pa = a; V4* pb = b;
    pt = &t;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        mfc1 tk, k
        qmtc2.ni tk, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(pt)
    }
    return *(VV*)&t;
}
static inline VV LerpR_L(V4* a, const VV& b, float k) { return LerpV_L(a, (V4*)&b, k); }
static inline VV SubV2_L(V4* a, V4* b) { V4 t; cVector_ctor_void(&t); cVector_VU0Add(&t, a, b); return *(VV*)&t; }
static inline VV SubR2_L(V4* a, const VV& b) { return SubV2_L(a, (V4*)&b); }
static inline const VV* P_L(const VV& v) { return &v; }
static inline VV SubtractV_L(V4* a, V4* b) { V4 t; cVector_ctor_void(&t); cVector_VU0Subtract(&t, a, b); return *(VV*)&t; }
static inline void LerpTo_L(V4* out, V4* a, V4* b, float k)
{
    V4 t; V4* pt; int tk;
    cVector_ctor_void(&t);
    V4* pa = a; V4* pb = b;
    pt = &t;
    asm {
        lqc2 vf1, 0x0(pa)
        lqc2 vf2, 0x0(pb)
        mfc1 tk, k
        qmtc2.ni tk, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(pt)
    }
    cVector_ctor_cVectorR(out, &t);
}

static inline float ClampX_L(float x, float lo, float hi) { float r = 0.0f; float l = lo; float xx = x; float h = hi; asm { max.s r, xx, l; min.s r, r, h } return r; }
static inline float ClampY_L(float x, float lo, float hi) { float r = 0.0f; float xx = x; float l = lo; asm { max.s r, xx, l; min.s r, r, hi } return r; }
static inline float ClampF_L(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float ClampW_L(float x, float lo, float hi) { float r = lo; float xx = x; float h = hi; asm { max.s r, xx, r; min.s r, r, h } return r; }
static inline float Remap_L(float x, float lo, float hi, float a, float b) { float one = 1.0f; float z = a; float t = ClampW_L((one / (hi - lo)) * (x - lo), z, one); return z + t * (b - z); }
static inline unsigned char HasB0_L(Root_L* r) { return r->iB0 != 0; }
static inline void ScaleTo_L(V4* out, float f, V4* v) { V4 t; cVector_ctor_void(&t); cVector_VU0Scale(f, &t, v); cVector_ctor_cVectorR(out, &t); }
static inline void SubTo_L(V4* out, V4* a, V4* b) { V4 t; cVector_ctor_void(&t); cVector_VU0Add(&t, a, b); cVector_ctor_cVectorR(out, &t); }
static inline void Q1_L(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline unsigned char IsZero3_L(V4* v)
{
    int k, fl; unsigned char r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
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
static inline void Norm3_L(V4* v)
{
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}
static inline void ObjUpd_L(void* o) { cPointMass_ClearForce(o); cPointMass_ClearAcceleration(o); cPointMass_ClearVelocity(o); }

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
static inline VV SubR_L(const VV& a, const VV& b) { const VV* pa = &a; return *pa - b; }
static inline void SW1_L(V4* d, VV v) { VV* pv = &v; pv->w = 1.0f; Q1_L(d, pv); }
static inline void CtlUpd_L(Phys_L* p, V4* b0) { void* c = p->mdl->ctl; V4 l7D0; if (((CtlD_L*)c)->b50) ((Ctl_L*)c)->Upd58(); Q1_L(&l7D0, (char*)c + 0x40); VV l7E0 = AV(l7D0) - AV(*b0); ((Ctl_L*)p->mdl->ctl)->F14(&l7E0); }
static inline void Grav_L(Phys_L* p) { V4 l7C0; Q1_L(&l7C0, &g_GameGravity); { const VV& vv = AV(l7C0); AddScaled_L((char*)p + 0x330, cPointMass_GetMass(p->o2E0), vv); } }
static inline void Water_L(Phys_L* p, V4* a2, V4* c0, V4* e0) { VV l7B0 = AV(*c0) - VV(0.0f, 0.0f, 6.0f, 0.0f); cHumanCollisionRoutine_DetectForWater(p, a2, (V4*)&l7B0, e0); }
static inline void RayRun_L(RayQ_L* qp, V4* c0, V4* f40) { RayP_L t; cCollisionProbe_Ray_ctor(&t, c0, f40); cCollisionProbe_Ray_opAssign(qp, &t); cCollisionProbe_Ray_dtor(&t, -1); }
static inline void T270_L(Phys_L* p, Res_L* res) { Tmp270_L t; cPlane_ctor_cVectorR_cVectorR(&t, &res->v50, &res->v30); cPlane_opAssign((char*)p + 0xF0, &t); cPlane_dtor(&t, -1); }
static inline void ScaleToR_L(V4* out, float f, const VV& v) { V4 t; cVector_ctor_void(&t); cVector_VU0Scale(f, &t, (V4*)&v); cVector_ctor_cVectorR(out, &t); }
static inline V4* PV_L(const VV& v) { return (V4*)&v; }
static inline void Q1V_L(V4* d, const VV& v) { Q1_L(d, &v); }
static inline VV SubP_L(const VV& a, const VV& b) { const VV* pa; const VV* pb; pb = &b; pa = &a; VV t; cVector_VU0Add((V4*)&t, (V4*)pa, (V4*)pb); return t; }
static inline unsigned char IsZero3i_L(V4* v)
{
    int k, fl; int r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyz vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xE
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
static inline void Tele_L(Root_L* r0, V4* e0, V4* e90, const VV& v)
{
    char* id;
    if (cTreeNode_cSkaAnimAnchor_TreeNodeData_Parent_void(r0)) {
        cSkaAnimAnchor_TreeNode_UpdateTransform(r0);
        id = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r0);
    } else {
        id = cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void(r0) + 0x50;
    }
    cVector_Rotate_cQuaternionR((V4*)&v, id);
    if (*cVector_W((V4*)&v) == 1.0f) {
        cVector_Translate((V4*)&v, e0);
    } else {
        VV l200 = cVector_opMul(AV(*e0), *cVector_W((V4*)&v));
        cVector_Translate((V4*)&v, (V4*)&l200);
        float s = func_001E5260(&l200);
        *cVector_W((V4*)&v) = s;
    }
    {
        const V4* pp = (const V4*)&v;
        e90->z = pp->z;
    }
}
struct Z4c { V4 v; Z4c() { V4* pz = &v; asm { sqc2 vf0, 0(pz) } } };
struct C4c { V4 v; C4c(const Z4c& z) { Q1_L(&v, &z.v); } };
static inline void AddQ_L(void* d, V4* s0) { V4 t; Q1D_L(&t, s0); VAdd_L(d, d, &t); }
static inline void Cp2_L(void* d, V4* s0) { V4 t; Q1_L(&t, s0); Q1_L(d, &t); }
static inline void ChildOff_L(Root_L* r0, float f) { V4 a; V4 b; char c[0x20]; V4* pz = &a; asm { sqc2 vf0, 0(pz) } Q1E_L(&b, &a); cQuatVec_ctor_cQuaternionR_cVectorR(c, &b, (VV*)PV_L(VV(0.0f, 0.0f, f, 1.0f))); Physical_SetChildOffsets(r0, c); }
static inline void QSub_L(float d3, void* out, void* q, void* tq2) { V4 t; cQuaternion_opSub(&t, tq2); LerpAndNormalize(d3, out, q, &t); }
static inline void SetT_L(V4* d, const VV* s0) { VV t = *s0; AV(*d) = t; }
static inline void F53_L(float f, V4* out, void* o, V4* p70, V4* pv30, V4* a3) { V4 t; func_001E53F0(f, &t, o, p70, pv30); { V4* pa = &t; SubTo_L(out, pa, a3); } }
static inline V4* CP_L(const C4c& c) { return (V4*)&c.v; }extern "C" void ActorPhys_RunResponse(Phys_L* p, float dt, int a1, float f13, V4* a2, V4* a3, V4* ground)
{
    Root_L* r0;
    Root_L* r1;
    Root_L* r2;
    float h;
    float oldE0;
    V4 old380;
    V4 base;
    V4 cur300;
    unsigned char wasDC;
    void* ctl;
    float sc;
    float s;

    r0 = RootCollection_FindByKey(p->owner + 0xB0, D_004A03C8);
    r1 = RootCollection_FindByKey(p->owner + 0xB0, D_004A03D0);
    r2 = RootCollection_FindByKey(p->owner + 0xB0, D_004A03D8);
    oldE0 = p->fE0;
    if (HasB0_L(r0)) h = 0.0f; else h = p->f394;
    { void* d = &old380; int m = 0xFF7FFFFF; p->iE0 = m; p->iE4 = m;
    p->bE8 = 0;
    Q1_L(d, &p->v380); }
    ctl = p->mdl->ctl;
    if (((CtlD_L*)ctl)->b50) ((Ctl_L*)ctl)->Upd58();
    sc = ((CtlD_L*)ctl)->f38;
    *(VV*)&p->v380 = ScaleV(sc, (VV*)&D_004A03F0);
    if (p->b11) Q1_L(&base, &p->v380); else Q1_L(&base, &old380);
    Q1_L(&cur300, &p->v300);
    V4* pv = &p->v300;
    VV d1480 = AV(*pv) - AV(base);
    if (p->b14 >= 2) {
        float k, lim, one;
        if (p->flags & 1) { one = 0.75f; lim = D_004A0348 * dt; }
        else { lim = D_004A0350 * dt; one = 1.0f; }
        p->f390 = p->f390 + ClampZ_L(one - p->f390, -lim, lim);
    }
    s = r0->fD0;
    VV d1470 = SubR_L(cVector_opSub(cSkeleton_GetCenterOfMass(p->mdl), cVector_opMul(VV(0.0f, 0.0f, h, 0.0f), s)), AV(*a3));
    VV d1460 = d1470 - AV(p->v380);
    if (!(r0->fD0 <= 0.0f)) {
        float dh;
        if (p->b14 >= 2) {
            float y = h + d1460.z;
            Pos_L* pp = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r0));
            dh = ActorPhys_ResponseHeightDelta(((p->flags >> 1) & 1) != 0, y, pp->z + a3->z, p->f370, p->f390);
        } else {
            Pos_L* pp = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r0));
            float y = h + d1460.z;
            dh = (y - p->f370) - (pp->z + a3->z);
        }
        if (dh < 0.0f) {
            float m = dh * r0->fD0;
            d1460.z -= m;
            if (p->b11) d1480.z -= m;
            p->v380.z -= m;
        }
    }
    {
        St_L s40 = *(St_L*)&p->v40;
        St_L s70 = *(St_L*)&p->v70;
        wasDC = p->bDC;
        if (!p->b9C0) {
            ZQ_L(&p->v40);
            ZQ_L(&p->v50);
            p->f60 = 0.0f;
            ZQ_L(&p->v70);
            ZQ_L(&p->v80);
            p->f90 = 0.0f;
        }
        p->i2C4 = 0x7F7FFFFF;
        p->i2C8 = 0;
        p->b2CC = 0;
        if (p->b12 && p->i20 != 0xC) {
            Res_L res;
            V4 g1210, g1200, d11F0, s11E0, s11D0, s11C0, pos11B0;
            char m1170[0x40];
            V4 sc1160;
            V4 p1150, l1140, l1130, l1120, l1110, l1100, l10F0;
            V4 l10E0, l10D0, l10C0, l10B0, l10A0, l1090, l1080, l1070, l1060;
            int n, i;
            unsigned char moveAdj, hasSum, both, fl;
            float sum;

            unsigned char hit;
            float lo;
            cCollisionProbe_SphereSweptRay_ctor(&res);
            QC(g1210, *Zero_L());
            QC(g1200, *Zero_L());
            moveAdj = 0;
            sum = r2->fD0 + r1->fD0;
            hasSum = Gt0_L(sum);
            both = Both_L(sum, r0->fD0);
            fl = Fl_L(p);
            SubtractTo_L(&d11F0, (V4*)&d1460, (V4*)&d1480);
            if (hasSum && !both) {
                QC(g1210, d11F0);
            } else if (fl) {
                float cz;
                QC(g1210, d11F0);
                QC(s11E0, s40.b);
                cz = GetZ_L(cVector_opSub(AV(p->v2F0), AV(p->v300)));
                if (cz - a3->z <= 0.0f && cz < g1210.z) goto set;
                { float z0 = 0.0f; if (!(cz - a3->z < z0) && !(cz <= g1210.z) && !(h <= z0)) { set: g1210.z = cz; } }
                if (both) { AV(g1210) = LerpV_L(&d11F0, &g1210, r0->fD0); }
                AV(g1200) = SubtractV_L(&g1210, &d11F0);
            } else if (both) {
                float k = r0->fD0;
                AV(g1210) = LerpR_L(&d11F0, cPointMass_GetDisplacement(p->o2E0), k);
            } else {
                AV(g1210) = cVector_opSub(AV(p->v2F0), AV(p->v300));
            }
            V4* sd;
            {
                moveAdj = cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans(p, &s11C0, (V4*)&SubV2_L((V4*)&d1480, &g1210), dt);
                *(VV*)(sd = &s11D0) = SubR2_L(&g1210, opMul(r0->fD0, &s11C0));
            }
            if (p->b14 >= 2 || hasSum) {
                if (!hasSum) {
                    float hz, hs;
                    unsigned char fb = ((p->flags >> 1) & 1) != 0;
                    Pos_L* pp = cQuatVec_Translation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r0));
                    ActorBody_CalcQueryHeight(d1480.z, pp->z, p->f370, p->f390, &hz, &hs, fb);
                    AV(pos11B0) = WithZ_L(d1480, hz);
                    UM_L(m1170);
                    Q1V_L(&sc1160, VV(1.0f, 1.0f, hs, 0.0f));
                } else {
                    Q1_L(&p1150, &d1480);
                    if (!(r2->fD0 <= 0.0f)) {
                        cVector_ctor_cVectorR(&l1140, (V4*)MMR_L(cVector_opAdd(d1480, AV(s11D0)), MXc(PLc(cSkaAnimAnchor_GetTransform(r2)))));
                        Q1D_L(&l1130, &l1140);
                        if (!(-l1140.y <= l1140.z)) { float a = -p->f370; l1130.y = MinZ_L(a, l1130.y); }
                        SubtractTo_L(&l1120, (V4*)&cVector_GetTransformed(&l1130, cMatrix_ctor_cQuatVecR(MXc().b, cSkaAnimAnchor_GetTransform(r2))), &s11D0);
                        AV(p1150) = LerpV_L(&p1150, &l1120, r2->fD0);
                    }
                    if (!(r1->fD0 <= 0.0f)) {
                        cVector_ctor_cVectorR(&l1110, (V4*)MMR_L(cVector_opAdd(d1480, AV(s11D0)), MXc(PLc(cSkaAnimAnchor_GetTransform(r1)))));
                        Q1D_L(&l1100, &l1110);
                        float z0 = 0.0f;
                        if (l1110.y <= z0 && !(l1110.z < z0)) {
                            float yy = l1110.y, zz = l1110.z;
                            float d = SqrtZ_L(yy * yy + zz * zz);
                            float r = p->f370;
                            if (d < r) { float k = r / d; l1100.y *= k; l1100.z *= k; }
                        } else if (!(-l1110.y <= l1110.z)) {
                            float a = -p->f370; l1100.y = MinZ_L(a, l1100.y);
                        } else {
                            float b = l1100.z; float a = p->f370; l1100.z = MaxZ_L(a, b);
                        }
                        SubtractTo_L(&l10F0, (V4*)&cVector_GetTransformed(&l1100, cMatrix_ctor_cQuatVecR(MXc().b, cSkaAnimAnchor_GetTransform(r1))), &s11D0);
                        AV(p1150) = LerpV_L(&p1150, &l10F0, r1->fD0);
                    }
                    Q1_L(&pos11B0, &p1150);
                    UM_L(m1170);
                    Q1_L(&sc1160, P_L(VV(1.0f, 1.0f, 1.0f, 0.0f)));
                }
                float rr = p->f370; ColQuery_InitTransformedThunk(&res, a2, &pos11B0, &s11D0, 1, m1170, &sc1160, rr, -0.1f, 2.0f, 0.0f, rr);
            } else {
                float rr = p->f370; cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(&res, a2, rr, -0.1f, 2.0f, 0.0f, rr, (V4*)&d1480, sd, 1);
            }
            if (fl || ((p->flags >> 1) & 1)) {
                res.b110 = 5;
                if (p->b14 >= 3) res.b118 = 1; else res.b118 = 0;
            } else {
                res.b118 = 0;
                res.b110 = 4;
            }
            res.f114 = 1.0f - (1.0f - p->fA20);
            res.f114 = ClampY_L(res.f114, 0.0f, 1.0f);
            if (p->b14 >= 3) n = 2; else n = 1;
            for (i = 0; i < n; i++) ColQuery_ExecuteThunk(&res, 0, 0x80);
            cHumanCollisionRoutine_HandleAnyLethalCollisions(p, a1, &res);
            if (hasSum) {
                float m;
                SubtractTo_L(&l1060, &res.v80, &g1210);
                AV(l1070) = AV(l1060) - AV(*a3);
                AV(l1090) = cVector_opAdd(d1470, AV(g1200)) - AV(l1060);
                VV l1050 = cSkeleton_GetBoneToWorldTranslation(p->mdl, 0xC) - AV(l1070);
                VV l1040 = cSkeleton_GetBoneToWorldTranslation(p->mdl, 0x10) - AV(l1070);
                { float a = l1050.z; const VV* pb = &l1040; m = MinZ_L(a, l1040.z); }
                VV l1030 = cSkeleton_GetBoneToWorldTranslation(p->mdl, 0) - AV(l1070);
                oldE0 = (m - oldE0 < 1.25f) ? oldE0 : m;
                AV(l10A0) = WithZ_L(l1030, oldE0);
                Q1_L(&l1080, &l10A0);
                if (!(r1->fD0 <= 0.0f)) {
                    void* plc;
                    PL l1010 = *InvP_L(*(PL*)cSkaAnimAnchor_GetTransform(r1));
                    VV l1000 = *MMR_L(l1050, MXc(&l1010));
                    VV lFF0 = *MMR_L(l1040, MXc(&l1010));
                    VV lFE0 = *MMR_L(AV(l10A0), MXc(&l1010));
                    V4 lFD0;
                    { float c = l1000.y; float a = lFF0.y; const VV* pe = &lFE0; float b = lFE0.y; m = MinZ_L(c, MinZ_L(a, b)); }
                    plc = cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r1);
                    Q1_L(&lFD0, cVector_Transform_cQuaternionR_cVectorR(VV(*F57_L(m, lFE0)), cQuatVec_Rotation(plc), cQuatVec_Translation(plc)));
                    AV(l1080) = Lerp_L(AV(l1080), AV(lFD0), r1->fD0);
                }
                l1080.z = ((d1460 - AV(g1200)) - AV(l1060)).z;
                if (res.b0 && r1->iB0 == 0) {
                    V4 lFC0;
                    switch (p->i20) {
                    case 5:
                    case 1: {
                        V4 lFB0;
                        float d;
                        Q1_L(&lFB0, QMR_L(MXc().b, cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(r1))));
                        d = Dot3_L(&l1060, &lFB0);
                        AV(lFC0) = cVector_opMul(AV(lFB0), d);
                        break;
                    }
                    case 11:
                        ZQ_L(&lFC0);
                        break;
                    case 9:
                        ZQ_L(&lFC0);
                        break;
                    case 10:
                    default:
                        Q1_L(&lFC0, &l1060);
                        break;
                    }
                    cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(r1, cVector_opAdd(*(VV*)cSkaAnimAnchor_GetPosition(r1), AV(lFC0)));
                }
                { int k = p->i20; if (k == 0 || k == 10 || k == 11) cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(r1, cVector_opAdd(*(VV*)cSkaAnimAnchor_GetPosition(r1), AV(*a3))); }
            }
            if (hasSum && !both) {
                Q1_L(&l10E0, &l10A0);
                Q1_L(&l10D0, &l1090);
                Q1_L(&l10C0, &l1080);
                Q1_L(&l10B0, &l1070);
            } else if (fl) {
                VV lFA0 = SubV_L(AV(res.v80), AV(g1210));
                AV(l10E0) = cVector_opAdd(cVector_opSub(cVector_opAdd(*(VV*)cSkaAnimAnchor_GetPosition(r0), AV(*a3)), VV(0.0f, 0.0f, h, 0.0f)), AV(g1200)) - lFA0;
                AV(l10D0) = cVector_opAdd(d1470, AV(g1200)) - lFA0;
                Q1_L(&l10C0, &l10E0);
                l10C0.z = ((d1460 - AV(g1200)) - lFA0).z;
                AV(l10B0) = SubV_L(AV(l10E0), *(VV*)cSkaAnimAnchor_GetPosition(r0));
            } else {
                AV(l10D0) = AV(cur300) - AV(res.v80);
                VV v860(0.0f, 0.0f, h, 0.0f);
                void* m50 = p->mdl->m50;
                VV lF90 = SubV_L(cVector_opSub(AV(l10D0), cVector_GetTransformed(m50, cMatrix_ctor_cQuatVecR(MXc().b, cSkaAnimAnchor_GetSkeletonTargetTransform(r0)))), v860);
                AV(l10E0) = *(VV*)cSkaAnimAnchor_GetPosition(r0) - lF90;
                Q1_L(&l10C0, &l10E0);
                l10C0.z = (d1480 - AV(res.v80)).z;
                AV(l10B0) = SubV_L(AV(l10E0), *(VV*)cSkaAnimAnchor_GetPosition(r0));
            }
            if (both) {
                SW1_L(&l10E0, Lerp_L(AV(l10A0), AV(l10E0), r0->fD0));
                SW1_L(&l10D0, Lerp_L(AV(l1090), AV(l10D0), r0->fD0));
                SW1_L(&l10C0, Lerp_L(AV(l1080), AV(l10C0), r0->fD0));
                AV(l10B0) = Lerp_L(AV(l1070), AV(l10B0), r0->fD0);
            }
            if ((res.b0 || moveAdj) && fl) {
                V4* gp = cSkaAnimAnchor_GetDeltaPos(r0);
                VV lF80 = AV(*gp) - AV(*a3);
                if (!IsZero4_L((V4*)&lF80)) {
                    float len;
                    VV lF70 = *(VV*)NZ_L(lF80, &len);
                    float l = len, z = 0.0f;
                    if (l != z) {
                        float d = Dot3N_L((V4*)&lF70, &res.v80) / l;
                        float one = 1.0f;
                        float t = one - d;
                        p->f2C8 = t;
                        p->f2C8 = ClampF_L(t, z, one);
                        p->b2CC = res.b0 != 0;
                    }
                }
            }
            CtlUpd_L(p, &l10B0);
            if (!(r0->fD0 <= 0.0f)) {
                Grav_L(p);
            }
            Water_L(p, a2, &l10C0, &l10E0);
            hit = 0;
            {
                Mdl_L* m = p->mdl;
                void* c = m->ctl;
                VV* pp = NodePos_L(m->p20 + 0x15C0);
                VV lF60 = *MM_L(*pp, CtlMtx_L(c));
            }
            {
                Mdl_L* m = p->mdl;
                void* c = m->ctl;
                VV* pp = NodePos_L(m->p20 + 0x1D00);
                VV lF50 = *MM_L(*pp, CtlMtx_L(c));
            }
            {
                V4 lF40;
                lF40.x = 0.0f;
                lF40.y = 0.0f;
                lF40.z = -15.5f;
                lF40.w = 0.0f;
                float z0 = 0.0f;
                if (p->b14 >= 3) {
                    InitSphZ_L(&res, a2, &l10C0, &lF40, 0.1f, 0.05f, z0);
                    res.b110 = 0;
                    ColQuery_ExecuteThunk(&res, 0, 0x80);
                } else {
                    RayQ_L q;
                    V4* fromp = CP_L(C4c(Z4c()));
                    V4* zp = ZeroFZ_L(z0);
                    RayQ_L* qp = &q;
                    RayQInit_L(qp, zp, fromp);
                    RayRun_L(qp, &l10C0, (V4*)&lF40);
                    q.b61 = 0x80;
                    q.b60 = 0;
                    cCollisionProbe_Ray_DetectForCollision_cArrayR_bool(qp, a2, 0);
                    Los_CombineResult(&res, qp, a2);
                }
            }
            float zc = 0.0f;
            if (r1->fD0 == zc && r2->fD0 == zc) {
                p->bDC = 1;
                p->bDD = 0;
            } else {
                p->bDC = 0;
                p->bDD = 0;
            }
            p->fA20 = 0;
            if (res.b0) {
                float off, hi, top;
                V4 lEC0, lEB0;
                p->bE8 = 1;
                T270_L(p, &res);
                {
                    void* s0 = cCollisionModel_FaceLocator_ParentModel(res.o60);
                    void* s7 = cCollisionModel_FaceLocator_FaceIndex(res.o60);
                    void* tri = cCollisionModel_GetFace(s0, s7);
                    cCollisionFace_Set_cCollisionModelFaceR_uint_cCollisionModelFacePropertiesR_cCollisionModelR((char*)p + 0x100, tri, s7, cCollisionModel_GetFaceProperties(s0, cCollisionModel_Face_GetPropertiesIndex(tri)), s0);
                }
                Q1_L(&lEC0, &res.v50);
                Q1_L(&lEB0, &res.v50);
                if (fl) {
                    unsigned char c = 0;
                    int f = p->flags;
                    if (Bit_L(f, 1) && NotB_L(Bit_L(f, 2))) c = 1;
                    off = OffSel_L(c);
                } else {
                    off = -0.1f;
                }
                {
                    float c2, d;
                    float a = lEC0.z, b = lEB0.z;
                    c2 = lEC0.z; d = lEB0.z;
                    hi = MaxZ_L(a, b);
                    lo = MinZ2_L(c2, d);
                }
                hit = 1;
                top = l10E0.z - 0.2f;
                if (top - off <= lo && !(res.v30.z <= 0.5f)) {
                    if (top <= lo) {
                        float v = (0.2f + (lo - l10E0.z)) * 180.0f - 30.0f * (((V4*)((char*)p + 0x310))->z - ground->z);
                        float lim = AbsZ_L(5.0f * g_GameGravity.z);
                        if (!(r0->fD0 <= 0.0f) && !p->b9C0) {
                            V4 lEA0;
                            ScaleToR_L(&lEA0, *(float*)p->o2E0, VV(0.0f, 0.0f, ClampX_L(v, -lim, lim), 0.0f));
                            AddQ_L((char*)p + 0x330, &lEA0);
                        }
                    }
                    p->bDC = 0;
                    if (!(r0->fD0 <= 0.0f) || !p->b13) p->bDD = 1;
                }
                p->f2C4 = l10E0.z - lo;
                p->fA20 = ClampX_L(AbsZ_L((hi - l10E0.z) + 0.2f) / 2.5f, 0.0f, 1.0f);
            }
            if (p->b14 >= 3 && p->bDC && !hasSum) {
                InitSph_L(&res, a2, &l10C0, VV(0.0f, 0.0f, -15.5f, 0.0f), 1.0f, 0.05f);
                res.b110 = 0;
                ColQuery_ExecuteThunk(&res, 0, 0x80);
            }
            {
            V4 lE90, lE80, lE70;
            float c03 = 0.3f, c05 = 0.5f, c02 = 0.2f, k = -1.0f;
            if (res.b0) {
                V4 lE60, lE50;
                { float a = 1.0f; MinZ_L(a, 6.0f * dt); }
                float c015, n025, n10, n20;
                n025 = -0.25f; n10 = -10.0f;
                Q1_L(&lE60, &res.v50);
                c015 = 0.15f; n20 = -20.0f;
                Q1_L(&lE90, &lE60);
                V4* p70 = &lE70; V4* pv30 = &res.v30;
                Q1_L(p70, pv30);
                F53_L(*(float*)((char*)p + 0xD8), &lE50, &s40, p70, pv30, a3);
                V4* n = (V4*)&s40.b;
                if (!IsZero4_L(n)) {
                    V4 pl1, pl2;
                    float h1, h2;
                    unsigned char s1, s2;
                    {
                        float x = cVector_X_void(&lE70), y = cVector_Y_void(&lE70), z = cVector_Z_void(&lE70);
                        cVector_ctor_float_float_float_float(&pl1, x, y, z, -cVector_Dot(&lE70, &lE90));
                    }
                    h1 = lE50.z - PlaneH_L(&pl1, lE50.x, lE50.y);
                    {

                        float x = cVector_X_void(n), y = cVector_Y_void(n), z = cVector_Z_void(n);
                        cVector_ctor_float_float_float_float(&pl2, x, y, z, -cVector_Dot(n, &lE50));
                    }
                    h2 = lE90.z - PlaneH_L(&pl2, lE90.x, lE90.y);
                    s1 = Steep_L(&pl1);
                    s2 = Steep_L(&pl2);
                    {
                        unsigned char a1 = LtR_L(lE50.z, lE90.z);
                        unsigned char a0 = GtR_L(lE50.z, lE90.z);
                        unsigned char v1 = NLt0_L(0.2f + (lE90.z - l10E0.z));
                        float f318;
                        if (*((unsigned char*)p + 0x3D4) && a0) {
                        } else if (wasDC && !p->bDC && (f318 = p->f318) < n10) {
                            k = Remap_L(f318, n20, n10, 0.0f, c02);
                        } else if (h1 < c015 && h2 < c015 && s1 && s2 && !p->bDC) {
                        } else if ((h1 < n025 && a0) || (!s2 && s1)) {
                            k = c03;
                        } else if ((h2 < n025 && a1) || (!s1 && s2)) {
                            k = c05;
                        } else if (p->bDC && !wasDC && v1 && a0) {
                            k = c05;
                        }
                    }
                }
                SetT_L(&lE80, QInv_L(AV(lE90), cSkaAnimAnchor_GetRotation(r0), &l10E0));
            } else {
                V4* pz = &lE80;
                asm { sqc2 vf0, 0(pz) }
                { V4* q = &lE80; q->z = -0.2f; }
                SetT_L(&lE90, PTP_L(AV(lE80), cSkaAnimAnchor_GetRotation(r0), &l10E0));
                k = c02;
                lE70.x = 0.0f;
                lE70.y = 0.0f;
                lE70.z = 1.0f;
            }
            *(float*)((char*)p + 0xB4) = 15.0f;
            if (!(k < 0.0f)) {
                AnimScalar_RescaleSlopes((char*)p + 0xB8, k);
                AnimScalar_RestartTimer((char*)p + 0xD0);
            }
            {
                float* zz = &lE80.z;
                *(float*)((char*)p + 0xB0) = *zz;
            }
            *(float*)((char*)p + 0xA4) = *(float*)((char*)p + 0xA8);
            ((Crv_L*)((char*)p + 0xA0))->F18();
            cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_NextFrame((char*)p + 0xD0, dt);
            if (cSplinedMotion_float_IsTransitionInProgress((char*)p + 0xA0)) {
                *(float*)((char*)p + 0xA8) = cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_Evaluate((char*)p + 0xD0);
                ((Crv_L*)((char*)p + 0xA0))->F1C();
            } else {
                *(float*)((char*)p + 0xA8) = *(float*)((char*)p + 0xB0);
            }
            ((Crv_L*)((char*)p + 0xA0))->F20(dt, f13);
            *(float*)((char*)p + 0xD8) = lE90.z;
            Tele_L(r0, &l10E0, &lE90, VV(0.0f, 0.0f, *(float*)((char*)p + 0xA8), 1.0f));
            {
                float h = 0.2f + (lE90.z - l10E0.z);
                cVector_opAssign(&p->v40, &lE90);
                cVector_opAssign(&p->v50, &lE70);
                p->f60 = h;
                cVector_opAssign(&p->v70, &p->v40);
                cVector_opAssign(&p->v80, &p->v50);
                p->f90 = p->f60;
            }
            {
                Cp2_L(&p->v2F0, &l10D0);
            }
            if (hit && !p->bDC) {
                p->fE0 = lo;
                if (!r0->iB0) p->f394 = lo - l10E0.z;
                else p->f394 = -*(float*)((char*)r0 + 0x68);
                float z0 = 0.0f;
                if (p->f394 < z0) p->f394 = z0;
                else if (!r0->iB0) l10E0.z += p->f394;
            } else {
                p->f394 = 0.0f;
            }
            if (!r0->iB0) {
                if (!((p->flags >> 3) & 1)) {
                    cSkaAnimAnchor_TreeNode_SetTransformPosition_WorldSpace(r0, AV(l10E0));
                } else {
                    cSkaAnimAnchor_TreeNode_SetTransform_WorldSpace(r0, cSkaAnimAnchor_GetTransform(r1));
                    *(int*)((char*)r0 + 0x160) = 0;
                }
            }
            {
                ChildOff_L(r0, -p->f394);
            }
            if ((*(int*)((char*)p + 0x24) >> 1) & 1 && *((unsigned char*)p + 0x7A2)) {
                char* o = (char*)p + 0x7A0;
                char lE20[0x10];
                void* tq2 = o + 0x80;
                float d3 = 3.0f * dt;
                void* q = cSkaAnimAnchor_GetRotation(r1);
                if (!(func_001E50E0(q, tq2) < 0.0f)) {
                    LerpAndNormalize(d3, lE20, q, tq2);
                } else {
                    QSub_L(d3, lE20, q, tq2);
                }
                cSkaAnimAnchor_TreeNode_SetTransformRotation_WorldSpace(r1, lE20);
                *(int*)((char*)r1 + 0x160) = 0;
            }
            }
            goto tail;
        }
        p->bDC = 0;
        p->bDD = 1;
        p->i2C4 = 0;
        {
            Mdl_L* m = p->mdl;
            Q1_L(&p->v2F0, &cVector_GetTransformed(m->m50, cXform_GetMatrix(m->ctl)));
        }
        ObjUpd_L(p->o2E0);
        p->f394 = 0.0f;
    }
tail:
    {
        unsigned char v = 1;
        unsigned char c = 0;
        if (wasDC && (Nz_L(p->bDC) ^ 1)) c = v;
        if (!c) {
            unsigned char d = 0;
            if (p->bDE && p->f318 - ground->z < 0.0f) d = 1;
            if (!d) v = 0;
        }
        p->bDE = v;
    }
    {

        VV dv = SubP_L(AV(p->v50), AV(p->v80));
        if (!IsZero3i_L((V4*)&dv)) {
            Norm3_L((V4*)&dv);
            Q1_L(&p->v9F0, &dv);
        } else if (!IsZero3i_L(&p->v1E0)) {
            Q1_L(&p->v9F0, &p->v1E0);
        } else {
            Q1V_L(&p->v9F0, VV(0.0f, 0.0f, 1.0f, 0.0f));
        }
    }
    if (!p->b13) ObjUpd_L(p->o2E0);
}
#pragma pop




