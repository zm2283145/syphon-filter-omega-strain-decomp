#pragma cplusplus on
#pragma enumsalwaysint off
enum eMode_L { EM_0 = 0, EM_MAX = 0xFF }; enum eAS_L { AS_0 = 0, AS_5 = 5, AS_6 = 6, AS_X = 0x7F };
#pragma always_inline on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_common_subs on
#pragma opt_propagation off
/* cHumanIkRoutine_NextFrame (0x001CB160) draft - prefix only (through ~CB9D0). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Q_L;
typedef struct { Q_L q; Q_L p; } Plc_L;
typedef struct { Q_L r[4]; } __attribute__((aligned(16))) Mtx_L;

struct Sec_L;
extern "C" {
void cHumanIkRoutine_InitializeStaticDataAndWorkspaceIfNotInitialized(void*);
void cHumanIkRoutine_InitializeWorkspaceAtStartOfNextFrame(void*);
Mtx_L* cMatrix_ctor_cMatrixR(Mtx_L* d, const Mtx_L* s);
Mtx_L* cMatrix_InvertRotTrans(Mtx_L* m);
void* cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(void* layers, int i);
void cIkTargetWithSplinedTransition_NextFrame(void* layer, void* s3, float dt, float inv);
int cIkTargetWithSplinedTransition_HasTransitionEnded(void* layer);
Q_L* cQuaternion_ctor_cQuaternionR(Q_L* d, const Q_L* s);
Q_L* cQuaternion_ctor_void(Q_L* q);
void cQuaternion_VU0Multiply(Q_L* a, const Q_L* b, const Q_L* c);
Q_L* cVector_ctor_cVectorR(Q_L* d, const Q_L* s);
Q_L* cQuaternion_Conjugate(Q_L* q);
Q_L* cQuaternion_opMul_cQuaternionR(Q_L* out, const Q_L* a, const Q_L* b);
Q_L* cQuatVec_Rotation(Plc_L* p);
Q_L* cQuatVec_Translation(Plc_L* p);
Q_L* cVector_Transform_cQuaternionR_cVectorR(Q_L* v, const Q_L* q, const Q_L* p);
Q_L* cVector_Transform_cMatrixR(Q_L* v, const Mtx_L* m);
Q_L* cVector_Translate(Q_L* v, const Q_L* d);
void* cVector_ctor_void(void* p);
Q_L* cVector_VU0Add(Q_L* out, const Q_L* a, const Q_L* b);
void cQuaternion_GetConjugate(Q_L* out, Q_L* in);
void cHermiteSplineWithScaledDuration_cQuaternion_Reset_float(void* c, float t);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Restart(void* c);
void cHumanIkRoutine_ResetAnimationIterators(Sec_L* s, bool a, bool b, bool c);
void cHumanIkRoutine_CalculateBaseIkPose(Sec_L* s, Q_L* q, float dt);
void cMatrix_GetRotated(Mtx_L* out, const Mtx_L* a, const Mtx_L* b);
void cMatrix_GetRotation(Mtx_L* out, const Mtx_L* in);
Q_L* cVector_Rotate_cMatrixR(Q_L* v, const Mtx_L* m);
Q_L* cVector_opMul(Q_L* out, const Q_L* in, float s);
Q_L* cVector_opAdd(Q_L* out, const Q_L* a, const Q_L* b);
void cVector_GetRotated(Q_L* out, const Q_L* a, const Mtx_L* m);
void cMatrix_Translate(Mtx_L* m, const Q_L* t);
float Libc_Atan2f(float y, float x);
void cHumanIkRoutine_SendEndOfUpperBodyAnimMessage(Sec_L* s, float t);
void cHumanIkRoutine_SendEndOfUpperBodyAnimWithRightHandLookatMessage(Sec_L* s, float t);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(void* c, float t);
int func_0017D510(void* c);
void cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(Q_L* out, void* c);
bool cHumanIkRoutine_ApplyGunRecoil_cQuaternionR_float(Sec_L* s, Q_L* q, float t);

void cHermiteSplineWithScaledDuration_cQuaternion_Reset_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(void* a, void* b, void* c, void* d, void* e);Q_L* cQuaternion_opAssign(Q_L* d, const Q_L* s);
Q_L* cVector_ctor_float_float_float_float(Q_L* d, float x, float y, float z, float w);
Q_L* cVector_Normalize_void(Q_L* v);
float cQuaternion_W_void_2(Q_L* v);
float cQuaternion_X_void_2(Q_L* v);
float cQuaternion_Y_void_2(Q_L* v);
float cQuaternion_Z_void_2(Q_L* v);
float* cQuaternion_W_void(Q_L* v);
float* cQuaternion_X_void(Q_L* v);
float* cQuaternion_Y_void(Q_L* v);
float* cQuaternion_Z_void(Q_L* v);
float cVector_X_void(Q_L* v);
float cVector_Y_void(Q_L* v);
float cVector_Z_void(Q_L* v);
Q_L* cQuaternion_GetInverseUnitQuat(Q_L* out, const Q_L* q);
Q_L* cQuaternion_Rotate(Q_L* q, const Q_L* r);Q_L* cVector_VU0Subtract(Q_L* out, const Q_L* a, const Q_L* b);
void Mtx_LookAt(Mtx_L* out, const Q_L* dir, const Q_L* up, const void* ref, float lim);
extern char g_IdentityMatrix[];
struct Tab_L { char pad[0x40]; eAS_L* f40; char pad44[4]; float* f48; char pad4C; unsigned char b4D; unsigned char b4E; unsigned char b4F; };
struct P2_L { eAS_L a; eAS_L b; P2_L() {} P2_L(eAS_L x, eAS_L y) { a = x; b = y; } };
static inline bool IsK_L(unsigned char k) { return k == 5 || k == 6; }
struct E2_L { char pad[0xB0]; P2_L fB0; char padB2[2]; float fB4; char padB8[0x100 - 0xB8]; };
extern E2_L UpperBodyNodeTable[21];
Q_L* cVector_Rotate_cQuaternionR(Q_L* a, const void* b);
void cHumanIkRoutine_CalculateIntermediatePose(Sec_L* s, Q_L* q);
void cAimComponent_NextFrame(void* p, Mtx_L* m, float dt, char* sys, E2_L* e);
bool cHumanIkRoutine_CalculateRightWristTargetPos_SkelSpace(Sec_L* s, Q_L* q, signed char k);
bool cHumanIkRoutine_CalculateLeftWristTargetPos_SkelSpace(Sec_L* s, Q_L* q, signed char k);
void cHumanIkRoutine_PositionArm(Sec_L* s, Q_L* q, int n, float f);
bool UpperBody_HandRotation(Sec_L* s, Q_L* q, signed char k, Q_L* a, Q_L* b, Q_L* c, Q_L* d);
bool cHumanIkRoutine_CalculateLeftWristTargetRot_Local(Sec_L* s, Q_L* q, signed char k, Q_L* a, Q_L* b, Q_L* d);
void cHumanIkRoutine_OrientHand(Sec_L* s, Q_L* q, int n);
void cHumanIkRoutine_UpdateHipBeforeDoingLegIk(Sec_L* s, int n);
void cHumanIkRoutine_PositionLegAndOrientFoot(Sec_L* s, Q_L* a, Q_L* b, int n, bool f);
void cHumanIkRoutine_AimHeadIndependently(Sec_L* s, void* a, void* b, int n, float f);
void cHumanIkRoutine_CalculateResultPose(Sec_L* s);
struct It_L { char* p; };
It_L std_vector_cBone_begin(void* s);
void cArray_cBone_Iterator_ctor(It_L* o, const It_L& i);
It_L std_vector_cBone_end(void* s);
void cDrawAndHolsterWeapon_ActionManager_StartTransitionIfNecessary(void* a, void* b);
int cHandIkTargetList_HasTransitionJustEndedForBothHands(void* a);
float cHandIkTargetList_GetTransitionTimeLeftForBothHands(void* a);
void cDrawAndHolsterWeapon_ActionManager_SwitchStage(void* a, int n);
void cDrawAndHolsterWeapon_ActionManager_TriggerCallback(void* a);
extern float D_0049F718;
extern Tab_L SecondaryStateTable[];
static inline Tab_L* Tab_P(unsigned char k) { return &SecondaryStateTable[k]; }
}
struct Ret_L { char d[0x10]; Ret_L() {} } __attribute__((aligned(16)));
struct SM_L { Q_L r[4]; SM_L() {} };
class Sub_L {
public:
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual Ret_L u3();
    virtual void u4();
    virtual void u5();
    virtual void u6(float a, float b);
};
class Obj_L {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual SM_L v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(Mtx_L* m);
    virtual void v13(Q_L* q);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
};
struct Ent_L { char pad[8]; float f8; char padC[4]; Q_L v; float f20; char pad24[0xC]; };
static inline unsigned char Valid_L(Ent_L* e) { return e->f20 > 0.0f; }
struct SQ_L { float x, y, z, w; SQ_L() {} } __attribute__((aligned(16)));
class VObj_L {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual SQ_L w10();
};
struct ObjD_L { char pad[0x10]; Mtx_L m; unsigned char f50; };
struct Sys_L { char pad[0x28]; Obj_L* obj; };
struct Node_L { char pad[0x10]; Mtx_L m; unsigned char f50; char pad51[0x1D0 - 0x51]; };
struct Sec_L {
    char pad0[4];
    char* sys;
    char pad8[4];
    char* fC;
    char* f10;
    char pad14[0x140 - 0x14];
    Q_L q140;
    Q_L q150;
    char sub[4];
    char pad164[0x170 - 0x164];
    Q_L q170;
    Q_L q180;
    Q_L q190;
    Q_L q1A0;
    float f1B0;
    char pad1B4[0x1C0 - 0x1B4];
    char c1C0[0x210 - 0x1C0];
    char c210[0x230 - 0x210];
    char sub2[4];
    char pad234[0x240 - 0x234];
    Q_L q240;
    Q_L q250;
    char pad260[0x270 - 0x260];
    Q_L q270;
    float f280;
    char pad284[0x290 - 0x284];
    char c290[0x2E0 - 0x290];
    char c2E0[0x300 - 0x2E0];
    float f300;
    float f304;
    float f308;
    float f30C;
    unsigned char f310;
    unsigned char f311;
    eMode_L f312;
    char f313;
    unsigned char f314;
    char pad315[3];
    float f318;
    float f31C;
    float f320;
    char pad324[0x328 - 0x324];
    float f328;
    char pad32C[0x3A0 - 0x32C];
    char f3A0[0x4A0 - 0x3A0];
    char layers[0x820 - 0x4A0];
    unsigned char f820;
    unsigned char f821;
    char pad822[0x830 - 0x822];
    unsigned char f830;
};

static inline void XformW_L(Q_L* v, const Mtx_L* m)
{
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(v)
    }
}
static inline void MCopy_L(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 a; __int128 b; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void MCopy2_L(void* d0, const void* s0) { void* d = d0; __int128 a; __int128 b; const void* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(a), "=&r"(b) : "r"(d), "r"(s) : "memory"); }
static inline void V4Copy(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void V4CopyB(void* d0, const void* s0) { const void* s = s0; __int128 q; void* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void V4CopyC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

static inline void V4StoreVF0(void* d) { asm { sqc2 vf0, 0(d) } }
static inline void NegXYZ_L(Q_L* v) { asm { lqc2 vf1, 0x0(v); vsub.xyz vf1, vf0, vf1; sqc2 vf1, 0x0(v) } }
static inline void MtxToQuat(const void* m, void* out) {
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(out)
        .set reorder
    }
}
static inline void QHZ_16(Q_L* q, const Q_L* ref0) { const Q_L* ref = ref0;
    int f;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(ref)
        vmul.xyzw vf3, vf1, vf2
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf5, vf1, vf0w
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x10
        beql f, zero, skip
        sqc2 vf5, 0x0(q)
    skip:
    }
}
static inline void QHemi_L(Q_L* q, const Q_L* ref) {
    int f;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(ref)
        vmul.xyzw vf3, vf1, vf2
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf5, vf1, vf0w
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf3w
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x10
        beql f, zero, skip
        sqc2 vf5, 0x0(q)
    skip:
    }
}
static inline void VZ_3(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void QRZ_3(Q_L* v0, const Q_L* q) { Q_L* v = v0;
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void QRotV_L(Q_L* v, const Q_L* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void Xform3_L(Q_L* v, const Mtx_L* m) {
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(v)
    }
}static inline void NegQ2_L(Q_L* d, const Q_L* v) { asm { lqc2 vf1, 0x0(v); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(d) } }
static inline void NegQ_L(Q_L* v) { asm { lqc2 vf1, 0x0(v); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(v) } }
static inline float Dot4_L(const Q_L* a, const Q_L* b) { float ret = 0.0f; int r; __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah $0, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddaz.w ACC, vf0, vf3z; vmaddw.w vf4, vf0, vf3w; qmfc2.ni %1, vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(ret), "=&r"(r) : "r"(a), "r"(b) : "memory"); return ret; }
static inline bool LimitQ_L_I_I(Q_L* q, float c, float s)
{
    float tt; Q_L* pp;
    if ((tt = cQuaternion_W_void_2(q), pp = q, tt < c) && !((tt = cQuaternion_X_void_2(pp), pp = q, tt == 0.0f) && (tt = cQuaternion_Y_void_2(pp), pp = q, tt == 0.0f) && cQuaternion_Z_void_2(pp) == 0.0f)) {
        Q_L ax;
        {
            float x = cQuaternion_X_void_2(q);
            float y = cQuaternion_Y_void_2(q);
            Q_L t;
            cVector_ctor_cVectorR(&ax, cVector_Normalize_void(cVector_ctor_float_float_float_float(&t, x, y, cQuaternion_Z_void_2(q), 0.0f)));
        }
        *cQuaternion_W_void(q) = c;
        *cQuaternion_X_void(q) = s * cVector_X_void(&ax);
        *cQuaternion_Y_void(q) = s * cVector_Y_void(&ax);
        *cQuaternion_Z_void(q) = s * cVector_Z_void(&ax);
        return 1;
    }
    cQuaternion_opAssign(q, q);
    return 0;
}
static inline bool LimitQ_L_I(Q_L* q, float c, float s) { return LimitQ_L_I_I(q, c, s); }
static inline bool LimitQ_L(Q_L* q, float c, float s) { return LimitQ_L_I(q, c, s); }static inline float Clamp_L(float v, float lo, float hi) { float r = 0.0f; asm { max.s r, v, lo; min.s r, r, hi } return r; }
static inline void ArcQ_L(const Q_L* a0, const Q_L* b0, Q_L* out0) {
    int f;
    const Q_L* a = a0; Q_L* out = out0; const Q_L* b = b0;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        vadd.w vf10, vf0, vf0
        lui f, 0x3F00
        qmtc2.ni f, vf11
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        vaddax.w ACC, vf10, vf0x
        vmaddw.w vf5, vf10, vf4w
        vsqrt Q, vf5w
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf6, vf2, vf1
        vwaitq
        vmulq.w vf7, vf0, Q
        vdiv Q, vf0w, vf7w
        vmulx.w vf8, vf7, vf11x
        vwaitq
        vmulq.xyz vf8, vf6, Q
        j done
        nop
    L1:
        vaddw.x vf8, vf0, vf0w
        vmulx.yzw vf8, vf0, vf0x
    done:
        sqc2 vf8, 0x0(out)
        .set reorder
    }
}
static inline void QToM_L(Mtx_L* m, const Q_L* q) {
    Mtx_L* d = m;
    const Q_L* s = q;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x; vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x; vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w; vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w; vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y; sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)" : : "r"(d), "r"(s) : "memory");
}
static inline void QToMa_L(Mtx_L* m, const Q_L* q) {
    Mtx_L* d;
    const Q_L* s;
    s = q;
    d = m;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x; vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x; vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w; vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w; vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y; sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)" : : "r"(d), "r"(s) : "memory");
}static inline float Max_L(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline void Lerp3_L(Q_L* d0, const Q_L* b0, const Q_L* c0, float s) { Q_L* d = d0; const Q_L* b = b0; const Q_L* c = c0; int rv; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(c); mfc1 rv, s; qmtc2.ni rv, vf3; vaddax.xyz ACC, vf1, vf0x; vmaddax.xyz ACC, vf2, vf3x; vmsubx.xyz vf1, vf1, vf3x; sqc2 vf1, 0x0(d) } }
static inline void Lerp4_L(Q_L* d0, const Q_L* b0, const Q_L* c0, float s) { Q_L* d = d0; const Q_L* b = b0; const Q_L* c = c0; int rv; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(c); mfc1 rv, s; qmtc2.ni rv, vf3; vaddax.xyzw ACC, vf1, vf0x; vmaddax.xyzw ACC, vf2, vf3x; vmsubx.xyzw vf4, vf1, vf3x; sqc2 vf4, 0x0(d) } }
static inline int ItEq_L(It_L* a, It_L* b) { char* x = a->p; char* y = b->p; return y == x; }
static inline bool ItNe_L(It_L* a, It_L* b) { return !(bool)ItEq_L(b, a); }
static inline void QZero_L(void* p) { __asm__ volatile("sq $0, 0(%0)" : : "r"(p) : "memory"); }
static inline unsigned char MaxU8_L(unsigned char a, unsigned char b) { return b < a ? a : b; }
static inline float Min_L(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float Abs_L(float a) { float r = 0.0f; asm { abs.s r, a } return r; }
static inline char* Off_L(char* p, int o) { return p + o; }
static inline char* Nodes_L(void* s3) { return *(char**)Off_L((char*)s3, 8); }
static inline float Smooth_L(float x) { float x2 = x * x; float x3 = x * x2; return 3.0f * x2 - 2.0f * x3; }

static inline bool HasD_L(Sec_L* s) { return Tab_P(s->f310)->b4D || Tab_P(s->f311)->b4D; }
static inline eAS_L MaxZ_L(eAS_L x, eAS_L y) { return ((unsigned char)x > (unsigned char)y) ? x : y; } static inline void AimH_L(Sec_L* s0, void* a0, void* b0, float f) { void* b = b0; void* a = a0; Sec_L* s = s0; cHumanIkRoutine_AimHeadIndependently(s, a, b, 0xE, f); }
static inline int MaxS_L(int a, int b) { return (unsigned char)b < (unsigned char)a ? a : b; } static inline eAS_L MaxR_L(eAS_L b, eAS_L a) { return ((unsigned char)b < (unsigned char)a) ? a : b; } static inline eAS_L MaxQ_L(eAS_L b, eAS_L a) { return ((unsigned char)a < (unsigned char)b) ? b : a; }
static inline void InvR2_L_I(Mtx_L* d, Mtx_L* s) { Mtx_L t; cMatrix_ctor_cMatrixR(d, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, s))); }
static inline void InvR2_L(Mtx_L* d, Mtx_L* s) { InvR2_L_I(d, s); }
static inline void InvR_L(Mtx_L* d, Mtx_L* s) { InvR2_L(d, s); }
static inline void Fwd_L(Q_L* d, Mtx_L* m) { Q_L v; const Mtx_L* mm; Q_L* pv; v.z = 1.0f; mm = m; pv = &v; float zz = 0.0f; v.x = zz; v.y = 0.0f; v.w = 0.0f; XformW_L(pv, m); V4Copy(d, pv); }
static inline void NegTo_L(Q_L* d, const Q_L* s) { Q_L t; Q_L* pt = &t; V4Copy(&t, s); NegXYZ_L(pt); V4Copy(d, pt); }
static inline void Xf3_L(Q_L* d, const Q_L* v, const Mtx_L* m) {
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(d)
    }
}
static inline void Xf3_L_v1(Q_L* d, const Q_L* v0, const Mtx_L* m) { const Q_L* v = v0; 
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        sqc2 vf8, 0x0(d)
    }
}

static inline void QInvPlc_L_I_I(Q_L* d, const Q_L* s) { Q_L t0; cQuaternion_ctor_cQuaternionR(d, cQuaternion_Conjugate(cQuaternion_ctor_cQuaternionR(&t0, s))); }
static inline void QInvPlc_L_I(Q_L* d, const Q_L* s) { QInvPlc_L_I_I(d, s); }
static inline void QInvPlc_L(Q_L* d, const Q_L* s) { QInvPlc_L_I(d, s); }
static inline void QFromWP_L_I_I(Q_L* d, const Q_L* q, const Q_L* p) { Q_L t1; cQuaternion_ctor_void(&t1); cQuaternion_VU0Multiply(&t1, q, p); cQuaternion_ctor_cQuaternionR(d, &t1); }
static inline void QFromWP_L_I(Q_L* d, const Q_L* q, const Q_L* p) { QFromWP_L_I_I(d, q, p); }
static inline void QFromWP_L(Q_L* d, const Q_L* q, const Q_L* p) { QFromWP_L_I(d, q, p); }
static inline void QMulTo_L_I(Q_L* d, const Q_L* a) { Q_L t2; cQuaternion_opMul_cQuaternionR(&t2, a, d); V4Copy(d, &t2); }
static inline void QMulTo_L(Q_L* d, const Q_L* a) { QMulTo_L_I(d, a); }
static inline void Set4_L(Q_L* v, float x, float y, float z, float w) { v->w = w; v->z = z; v->y = y; v->x = x; }
static inline void QA_L(Q_L* qa, Plc_L* plc, Mtx_L* wm, Q_L* pos)
{
    Q_L q2;
    Q_L q1;
    Q_L q0;
    QInvPlc_L(&q0, &plc->q);
    MtxToQuat(wm, &q1);
    QFromWP_L(&q2, &q1, pos);
    Q_L* p2 = &q2;
    QMulTo_L(p2, &q0);
    V4Copy(qa, p2);
}
static inline void QAZ_16(Q_L* qa, Plc_L* plc, Mtx_L* wm, Q_L* pos, const Q_L* ref)
{
    Q_L q2;
    Q_L q1;
    Q_L q0;
    QInvPlc_L(&q0, &plc->q);
    MtxToQuat(wm, &q1);
    QFromWP_L(&q2, &q1, pos);
    Q_L* p2 = &q2;
    QMulTo_L(p2, &q0);
    V4Copy(qa, p2);
    QHZ_16(qa, ref);
}
struct ZQ_L { Q_L q; ZQ_L() { V4StoreVF0(&q); } const Q_L* p() const { return &q; } };
static inline void Zero_L(Q_L* d) { V4Copy(d, ZQ_L().p()); }
static inline void Zero2_L(Q_L* d) { Q_L t; Q_L* pt = &t; V4StoreVF0(pt); __int128 q; asm { lq q, 0x0(pt); sq q, 0x0(d) } }
static inline Q_L* Zero3_L(Q_L* v) { Q_L t; Q_L* pt = &t; V4StoreVF0(pt); Q_L* d = v; asm { lq v1, 0x0(pt) } return d; }
static inline void Aim_L(Sec_L* self, Plc_L* plc)
{
    Q_L v;
    Q_L* d = Zero3_L(&v);
    const Q_L* q;
    Q_L* pv = &v;
    Plc_L* pp = plc;
    Q_L* pw = &v;
    asm { sq v1, 0x0(d) }
    pv->y = 2000.0f;
    q = cQuatVec_Rotation(pp);
    const Q_L* r = cVector_Transform_cQuaternionR_cVectorR(pv, q, cQuatVec_Translation(plc));
    char* f = self->f3A0;
    V4Copy(f + 0x10, r);
    f[5] = 1;
}
static inline void MulM_L_I_I(Q_L* d, const Q_L* s, Mtx_L* m) { Q_L t; cVector_ctor_cVectorR(d, cVector_Transform_cMatrixR(cVector_ctor_cVectorR(&t, s), m)); }
static inline void MulM_L_I(Q_L* d, const Q_L* s, Mtx_L* m) { MulM_L_I_I(d, s, m); }
static inline void MulM_L(Q_L* d, const Q_L* s, Mtx_L* m) { MulM_L_I(d, s, m); }
static inline void ToLocal_L(Q_L* d, const Q_L* s, Mtx_L* m) { Q_L v; MulM_L(&v, s, m); Q_L* pw = &v; V4Copy(d, &v); }
static inline void AddT_L_I_I(Q_L* d, const Q_L* s, Q_L* o) { Q_L t; cVector_ctor_cVectorR(d, cVector_Translate(cVector_ctor_cVectorR(&t, s), o)); }
static inline void AddT_L_I(Q_L* d, const Q_L* s, Q_L* o) { AddT_L_I_I(d, s, o); }
static inline void AddT_L(Q_L* d, const Q_L* s, Q_L* o) { AddT_L_I(d, s, o); }
static inline void Eye_L(Q_L* d, const Q_L* s, Q_L* o) { Q_L v; AddT_L(&v, s, o); Q_L* pw = &v; V4Copy(d, &v); }
static inline void VSub2_L_I_I(Q_L* d, Q_L* a, Q_L* b) { Q_L t; cVector_ctor_void(&t); cVector_VU0Subtract(&t, a, b); cVector_ctor_cVectorR(d, &t); }
static inline void VSub2_L_I(Q_L* d, Q_L* a, Q_L* b) { VSub2_L_I_I(d, a, b); }
static inline void VSub2_L(Q_L* d, Q_L* a, Q_L* b) { VSub2_L_I(d, a, b); }
static inline void VSub_L(Q_L* d, Q_L* a, Q_L* b) { VSub2_L(d, a, b); }
static inline void OffC_L(Q_L* off, Plc_L* plc, Mtx_L* im)
{
    Q_L v;
    v.x = 1.45f;
    v.w = 1.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    VZ_3(off, &v);
    QRZ_3(off, &plc->q);
    Xf3_L_v1(off, off, im);
}
static inline void PreMul2_L_I_I(Q_L* d, const Q_L* a, const Q_L* b) { Q_L t; cQuaternion_opMul_cQuaternionR(&t, a, b); cQuaternion_opAssign(d, &t); }
static inline void PreMul2_L_I(Q_L* d, const Q_L* a, const Q_L* b) { PreMul2_L_I_I(d, a, b); }
static inline void PreMul2_L(Q_L* d, const Q_L* a, const Q_L* b) { PreMul2_L_I(d, a, b); }
static inline void PreMul_L(Q_L* d, const Q_L* a, const Q_L* b) { PreMul2_L(d, a, b); }
static inline bool LimitQ1_L(Q_L* q, float c, float s) { return LimitQ_L(q, c, s); }
static inline void QC_L(Q_L* qc, Q_L* qa, Q_L* q140, float cw, float sw)
{
    Q_L t;
    cQuaternion_GetInverseUnitQuat(&t, qa);
    cQuaternion_opMul_cQuaternionR(qc, &t, q140);
    LimitQ_L(qc, cw, sw);
}
static inline void Sub2_L_I_I(Q_L* d, Q_L* a, Q_L* b) { Q_L t; cVector_ctor_void(&t); cVector_VU0Subtract(&t, a, b); cVector_ctor_cVectorR(d, &t); }
static inline void Sub2_L_I(Q_L* d, Q_L* a, Q_L* b) { Sub2_L_I_I(d, a, b); }
static inline void Sub2_L(Q_L* d, Q_L* a, Q_L* b) { Sub2_L_I(d, a, b); }
static inline void SubB2_L_I_I(Q_L* d, Q_L* a, Q_L* b) { Q_L t; cVector_ctor_void(&t); cVector_VU0Add(&t, a, b); cVector_ctor_cVectorR(d, &t); }
static inline void SubB2_L_I(Q_L* d, Q_L* a, Q_L* b) { SubB2_L_I_I(d, a, b); }
static inline void SubB2_L(Q_L* d, Q_L* a, Q_L* b) { SubB2_L_I(d, a, b); }
static inline void Turn_L(Q_L* qd, Q_L* qb, Q_L* qe, Q_L* pos, Q_L* tgt, Q_L* eye)
{
    Q_L e;
    Q_L d;
    Q_L r;
    Q_L* pd;
    Q_L* pr;
    PreMul2_L(qd, pos, qd);
    V4Copy(qb, qd);
    cQuaternion_GetConjugate(&r, qe);
    pr = &r;
    PreMul2_L(pr, qb, pr);
    Sub2_L(&d, tgt, eye);
    pd = &d;
    QRotV_L(pd, pr);
    SubB2_L(&e, eye, pd);
    Q_L* pw = &e;
    V4Copy(tgt, &e);
}
static inline void U3_L_I_I(Sec_L* self) { Ret_L t = ((Sub_L*)self->sub)->u3(); cHermiteSplineWithScaledDuration_cQuaternion_Reset_cQuaternionR_cQuaternionR_cQuaternionR_cQuaternionR(self->c1C0, &self->q180, &self->q190, &self->q1A0, &t); }
static inline void U3_L_I(Sec_L* self) { U3_L_I_I(self); }
static inline void U3_L(Sec_L* self) { U3_L_I(self); }
static inline void U5_L_I_I(Sec_L* self)
{
    if (func_0017D510(self->sub)) {
        Q_L t;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(&t, self->c210);
        cQuaternion_opAssign(&self->q180, &t);
        ((Sub_L*)self->sub)->u5();
    } else {
        cQuaternion_opAssign(&self->q180, &self->q1A0);
    }
}
static inline void U5_L_I(Sec_L* self) { U5_L_I_I(self); }
static inline void U5_L(Sec_L* self) { U5_L_I(self); }
static inline void Upd1_L(Sec_L* self, Q_L* qd, Q_L* qc, float dt, float inv)
{
    self->f1B0 = 10.0f;
    {
        int k = Tab_P(self->f310)->b4D || Tab_P(self->f311)->b4D;
        float f = k ? 0.15f : 0.0f;
        void* pc = self->c1C0;
        if (!(f < 0.0f)) {
            cHermiteSplineWithScaledDuration_cQuaternion_Reset_float(pc, f);
            cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Restart(self->c210);
        }
    }
    V4Copy(&self->q1A0, qd);
    cQuaternion_opAssign(&self->q180, qc);
    U3_L(self);
    cQuaternion_opAssign(&self->q170, &self->q180);
    ((Sub_L*)self->sub)->u4();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(self->c210, dt);
    U5_L(self);
    ((Sub_L*)self->sub)->u6(dt, inv);
}
static inline void QI_L(Q_L* qi, Q_L* qb, Q_L* qh)
{
    Q_L rq;
    cQuaternion_GetConjugate(&rq, qb);
    Q_L* prq = &rq;
    PreMul2_L(prq, qh, prq);
    V4Copy(qi, prq);
}
static inline void Up_L(Q_L* up2, Q_L* qd)
{
    Q_L v;
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    v.w = 0.0f;
    QRotV_L(&v, qd);
    V4Copy(up2, &v);
}
static inline void Lim072_L_I_I(Q_L* qb)
{
        float tt; Q_L* pp;
        if ((tt = cQuaternion_W_void_2(qb), pp = qb, tt < 0.7071f) &&
            !((tt = cQuaternion_X_void_2(pp), pp = qb, tt == 0.0f) && (tt = cQuaternion_Y_void_2(pp), pp = qb, tt == 0.0f) && cQuaternion_Z_void_2(pp) == 0.0f)) {
            Q_L ax;
            {
                float x = cQuaternion_X_void_2(qb);
                float y = cQuaternion_Y_void_2(qb);
                Q_L t;
                cVector_ctor_cVectorR(&ax, cVector_Normalize_void(cVector_ctor_float_float_float_float(&t, x, y, cQuaternion_Z_void_2(qb), 0.0f)));
            }
            *cQuaternion_W_void(qb) = 0.7071f;
            *cQuaternion_X_void(qb) = 0.7071f * cVector_X_void(&ax);
            *cQuaternion_Y_void(qb) = 0.7071f * cVector_Y_void(&ax);
            *cQuaternion_Z_void(qb) = 0.7071f * cVector_Z_void(&ax);
        } else {
            cQuaternion_opAssign(qb, qb);
        }
}
static inline void Lim072_L_I(Q_L* qb) { Lim072_L_I_I(qb); }
static inline void Lim072_L(Q_L* qb) { Lim072_L_I(qb); }
static inline void Lim07_L(Q_L* qb) { Lim072_L(qb); }
static inline void ConjMul2_L_I_I(Q_L* qb, Q_L* qa) { Q_L t; cQuaternion_GetInverseUnitQuat(&t, qa); cQuaternion_Rotate(qb, &t); }
static inline void ConjMul2_L_I(Q_L* qb, Q_L* qa) { ConjMul2_L_I_I(qb, qa); }
static inline void ConjMul2_L(Q_L* qb, Q_L* qa) { ConjMul2_L_I(qb, qa); }
static inline void ConjMul_L(Q_L* qb, Q_L* qa) { ConjMul2_L(qb, qa); }
static inline void U5b_L_I_I(Sec_L* self)
{
    if (func_0017D510(self->sub2)) {
        Q_L t;
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Evaluate(&t, self->c2E0);
        cQuaternion_opAssign(&self->q250, &t);
        ((Sub_L*)self->sub2)->u5();
    } else {
        cQuaternion_opAssign(&self->q250, &self->q270);
    }
}
static inline void U5b_L_I(Sec_L* self) { U5b_L_I_I(self); }
static inline void U5b_L(Sec_L* self) { U5b_L_I(self); }
static inline float MA_L(float x, float m, float b) { float t = x * m; return t + b; }
static inline float MB_L(const float* x, float m, float b) { float t = *x * m; return t + b; }
static inline void Loop1_L(Sec_L* self, Q_L* q, bool r, bool k, float step)
{
    float f;
    if (k) {
        f = r ? MB_L(&self->f328, 0.049f, 0.02f) : MA_L(1.0f - self->f328, 0.15f, 0.05f);
    } else {
        f = 0.15f;
    }
    void* pc = self->c290;
    if (!(f < 0.0f)) {
        cHermiteSplineWithScaledDuration_cQuaternion_Reset_float(pc, f);
        cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_Restart(self->c2E0);
    }
    Q_L* p;
    Q_L n;
    Q_L z;
    if (k) {
        p = r ? q : (cQuaternion_GetConjugate(&n, q), &n);
    } else {
        Zero_L(&z);
        p = &z;
    }
    V4Copy(&self->q270, p);
    cQuaternion_opAssign(&self->q240, &self->q250);
    ((Sub_L*)self->sub2)->u4();
    cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cQuaternion_cQuaternion_NextFrame(self->c2E0, step);
    U5b_L(self);
    ((Sub_L*)self->sub2)->u6(step, 1.0f / step);
}
static inline void TT2_L_I_I(Q_L* d, const Q_L* s, Mtx_L* m) { Q_L t; cVector_ctor_cVectorR(d, cVector_Rotate_cMatrixR(cVector_ctor_cVectorR(&t, s), m)); }
static inline void TT2_L_I(Q_L* d, const Q_L* s, Mtx_L* m) { TT2_L_I_I(d, s, m); }
static inline void TT2_L(Q_L* d, const Q_L* s, Mtx_L* m) { TT2_L_I(d, s, m); }
static inline void Dir_L(Q_L* d, Ent_L* e, Mtx_L* im)
{
    Q_L r;
    Q_L z;
    Q_L* p;
    unsigned char va = Valid_L(e);
    const Q_L* sv = &e->v;
    if (va) {
        TT2_L(&r, sv, im);
        p = &r;
    } else {
        z.z = 1.0f;
        z.x = 0.0f;
        z.y = 0.0f;
        z.w = 0.0f;
        p = &z;
    }
    V4Copy(d, p);
}
static inline void CF2_L_I_I(Mtx_L* m, const Q_L* a) { Q_L t; cVector_GetRotated(&t, a, m); cMatrix_Translate(m, &t); }
static inline void CF2_L_I(Mtx_L* m, const Q_L* a) { CF2_L_I_I(m, a); }
static inline void CF2_L(Mtx_L* m, const Q_L* a) { CF2_L_I(m, a); }
static inline void KAdj_L(Mtx_L* m, SQ_L* g)
{
    Q_L a;
    Q_L s;
    Q_L k;
    k.z = 0.2f;
    k.x = 0.0f;
    k.y = 0.0f;
    k.w = 0.0f;
    { const Q_L& rk = k; cVector_opMul(&s, &rk, 0.0f); }
    cVector_opAdd(&a, (Q_L*)g, &s);
    CF2_L(m, &a);
}
static inline void MulW_L(Q_L* d, const Q_L* s, Mtx_L* m) { MulM_L(d, s, m); }
static inline void AQ_L(Q_L* out, Mtx_L* n, Q_L* d)
{
    Mtx_L r;
    Mtx_L rm;
    Q_L q;
    Q_L arc;
    ArcQ_L(&n->r[2], d, &arc);
    cQuaternion_ctor_cQuaternionR(&q, &arc);
    QToMa_L(&rm, &q);
    { Mtx_L* pb = &rm; cMatrix_GetRotated(&r, n, pb); }
    MtxToQuat(&r, out);
}
static inline void SMLoop_L(void* s3, SM_L* s_m)
{
    for (int i = 0; i < *(int*)((char*)s3 + 4); i++) {
        SM_L t = ((Obj_L*)((Node_L*)(*(char**)((char*)s3 + 8)) + i))->v9();
        MCopy2_L(&s_m[i], &t);
    }
}
static inline void A73_L_I_I(Q_L* d, const Q_L* s, const void* p) { Q_L t; cVector_ctor_cVectorR(d, cVector_Rotate_cQuaternionR(cVector_ctor_cVectorR(&t, s), p)); }
static inline void A73_L_I(Q_L* d, const Q_L* s, const void* p) { A73_L_I_I(d, s, p); }
static inline void A73_L(Q_L* d, const Q_L* s, const void* p) { A73_L_I(d, s, p); }
static inline void A73W_L(Q_L* d, const Q_L* s, const void* p) { A73_L(d, s, p); }
static inline void TTW_L(Q_L* d, const Q_L* s, Mtx_L* m) { TT2_L(d, s, m); }
static inline void Lerp2_L_I_I(Q_L* d, const Q_L* a, const Q_L* b, float w) { Q_L l; cVector_ctor_void(&l); Lerp3_L(&l, a, b, w); cVector_ctor_cVectorR(d, &l); }
static inline void Lerp2_L_I(Q_L* d, const Q_L* a, const Q_L* b, float w) { Lerp2_L_I_I(d, a, b, w); }
static inline void Lerp2_L(Q_L* d, const Q_L* a, const Q_L* b, float w) { Lerp2_L_I(d, a, b, w); }
static inline void LerpN_L(void* s3, const Q_L* pa, const Q_L* pb, float w)
{
    Q_L l2;
    Lerp2_L(&l2, pa, pb, w);
    Q_L* pw = &l2;
    char* n0 = Nodes_L(s3);
    V4Copy(n0 + 0x1B0, &l2);
    *(float*)(n0 + 0x1BC) = 1.0f;
    ((Obj_L*)n0)->v13((Q_L*)(n0 + 0x1B0));
}
static inline void LerpG_L(Q_L* gr, const Q_L* ga, const Q_L* gb, float s) { Q_L l2; Lerp2_L(&l2, ga, gb, s); Q_L* pw = &l2; V4Copy(gr, &l2); }
static inline void Lerp4x_L(Q_L* d, const Q_L* b, const Q_L* c, float s) { int rv; asm { lqc2 vf1, 0x0(b); lqc2 vf2, 0x0(c); mfc1 rv, s; qmtc2.ni rv, vf3; vaddax.xyzw ACC, vf1, vf0x; vmaddax.xyzw ACC, vf2, vf3x; vmsubx.xyzw vf4, vf1, vf3x; sqc2 vf4, 0x0(d) } }
static inline void L4b_L_I_I(Q_L* r, const Q_L* a, const Q_L* b, float s) { Q_L t; cQuaternion_ctor_void(&t); { Q_L* pd = &t; asm { .set at } const Q_L* pa = a; const Q_L* pb = b; Lerp4x_L(pd, pa, pb, s); } cQuaternion_ctor_cQuaternionR(r, &t); }
static inline void L4b_L_I(Q_L* r, const Q_L* a, const Q_L* b, float s) { L4b_L_I_I(r, a, b, s); }
static inline void L4b_L(Q_L* r, const Q_L* a, const Q_L* b, float s) { L4b_L_I(r, a, b, s); }
static inline void L4_L(Q_L* mr, const Q_L* a, const Q_L* b, float s) { Q_L r; L4b_L(&r, a, b, s); Q_L* pw = &r; V4Copy(mr, &r); }
static inline void NodeM_L(char* np) { Mtx_L m; QToM_L(&m, (Q_L*)(np + 0x1C0)); ((Obj_L*)np)->v12(&m); }
static inline void LookQ_L(Q_L* qb, Q_L* dir, Q_L* fwd)
{
    Q_L t;
    Mtx_L look;
    { Q_L* dd = dir; Mtx_LookAt(&look, dd, fwd, g_IdentityMatrix, 0.9999985f); }
    MtxToQuat(&look, &t);
    V4Copy(qb, &t);
}
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" signed char D_004F47D8;
extern "C" SQ_L D_004F47E0[42];
extern "C" signed char D_004F4A80;
extern "C" SM_L D_004F4A90[21];
static inline float Max2_L(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Clamp4_L(float v, float lo, float hi) { float r = 0.0f; float a = v; float b = lo; asm { max.s r, a, b; min.s r, r, hi } return r; }
extern "C" void cHumanIkRoutine_NextFrame(Sec_L* self, float dt)
{
    float inv = 1.0f / dt;
    char* sys = self->sys;
    void* s3 = sys + 0x18;
    cHumanIkRoutine_InitializeStaticDataAndWorkspaceIfNotInitialized(s3);
    cHumanIkRoutine_InitializeWorkspaceAtStartOfNextFrame(self);
    Obj_L* o = ((Sys_L*)sys)->obj;
    if (((ObjD_L*)o)->f50) o->v20();
    Mtx_L wm;
    MCopy_L(&wm, &((ObjD_L*)o)->m);
    Mtx_L im;
    InvR_L(&im, &wm);
    Q_L fwd;
    Fwd_L(&fwd, &im);
    {
        float r0 = 1.8f * dt;
        float r1 = 3.0f * dt;
        self->f308 += Clamp_L(self->f304 - self->f308, -r0, r0);
        self->f30C += Clamp_L(self->f304 - self->f30C, -r1, r1);
        float sm0 = Smooth_L(self->f308);
        float sm1 = Smooth_L(self->f30C);
    }
    cIkTargetWithSplinedTransition_NextFrame(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(self->layers, 0), s3, dt, inv);
    cIkTargetWithSplinedTransition_NextFrame(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(self->layers, 1), s3, dt, inv);
    self->f820 = self->f821;
    self->f821 = cIkTargetWithSplinedTransition_HasTransitionEnded(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(self->layers, 0)) && cIkTargetWithSplinedTransition_HasTransitionEnded(cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(self->layers, 1));
    Q_L pos;
    { char* n = Nodes_L(s3); V4Copy(&pos, n + 0x1A0); }
    Q_L npos;
    NegTo_L(&npos, &pos);
    Plc_L plc;
    {
        Plc_L* src = (Plc_L*)(Off_L(self->fC, 0xB0) + 0x30);
        cQuaternion_ctor_cQuaternionR(&plc.q, &src->q);
        cVector_ctor_cVectorR(&plc.p, &src->p);
    }
    Q_L qa;
    QAZ_16(&qa, &plc, &wm, &pos, &self->q150);
    if (*(volatile unsigned char*)&self->f311 == 0x10 || !HasD_L(self)) {
        Aim_L(self, &plc);
    }
    Q_L qb;
    Q_L eye;
    Q_L tgt;
    {
        char* f2 = self->f3A0;
        ToLocal_L(&tgt, (Q_L*)(f2 + 0x10), &im);
    }
    Q_L off;
    int idx;
    int k = self->f311;
    if (k == 0xC || k == 0x10 || k == 6 || k == 7) {
        idx = 0;
        if (self->f311 == 0xC || self->f311 == 0x10) {
            OffC_L(&off, &plc, &im);
        } else {
            V4StoreVF0(&off);
        }
    } else {
        idx = 0xE;
        V4StoreVF0(&off);
    }
    {
        Node_L* nd = *(Node_L**)((char*)s3 + 8) + (signed char)idx;
        if (nd->f50) ((Obj_L*)nd)->v20();
        Mtx_L* m = &nd->m;
        Eye_L(&eye, &m->r[3], &off);
    }
    Q_L dir;
    VSub_L(&dir, &tgt, &eye);
    LookQ_L(&qb, &dir, &fwd);
    if (self->f311 == 0xC) {
        PreMul_L(&qb, &qa, &qb);
        if (qb.w < 0.0f) NegQ2_L(&qb, &qb);
        Lim07_L(&qb);
        ConjMul_L(&qb, &qa);
    }
    float cw, sw;
    if (self->f310 == 0xA || self->f311 == 0xA) {
        cw = 0.3827f;
        sw = 0.9239f;
    } else if (self->f310 == 0x17 || self->f311 == 0x17) {
        cw = 0.4226f;
        sw = 0.9063f;
    } else {
        cw = 0.01745f;
        sw = 0.9998f;
    }
    Q_L qc;
    QC_L(&qc, &qa, &self->q140, cw, sw);
    Q_L qd;
    cQuaternion_opMul_cQuaternionR(&qd, &npos, &qb);
    Q_L* pw = &qd;
    if (Dot4_L(&qd, &qc) <= 0.0f) NegQ2_L(&qd, &qd);
    if (qd.w < 0.0f) {
        if (qd.w <= -0.342f || !(self->f300 <= 0.25f)) NegQ2_L(&qd, &qd);
        self->f300 += dt;
    } else {
        self->f300 = 0.0f;
    }
    bool lim = LimitQ1_L(&qd, cw, sw);
    if (lim) {
        Q_L qe;
        V4Copy(&qe, &qb);
        Turn_L(&qd, &qb, &qe, &pos, &tgt, &eye);
    }
    Upd1_L(self, &qd, &qc, dt, inv);
    Q_L qf;
    V4Copy(&qf, &self->q180);
    LimitQ1_L(&qf, cw, sw);
    Q_L qg;
    cQuaternion_opMul_cQuaternionR(&qg, &qa, &qf);
    Q_L qh;
    cQuaternion_opMul_cQuaternionR(&qh, &pos, &qf);
    {
        bool k = Tab_P(self->f310)->b4D || Tab_P(self->f311)->b4D;
        self->f280 = 5.0f;
        float c60 = 0.016666668f;
        float rem = dt;
        float step;
        for (; !(rem <= 0.0f); rem -= step) {
            step = Min_L(c60, rem);
            Q_L q;
            V4Copy(&q, &self->q250);
            bool r = cHumanIkRoutine_ApplyGunRecoil_cQuaternionR_float(self, &q, step);
            Loop1_L(self, &q, r, k, step);
        }
    }
    {
        const Q_L& rq = self->q250;
        if (!(Abs_L(1.0f - rq.w) <= 1e-7f)) {
            PreMul_L(&qh, &qh, &rq);
        }
    }
    V4Copy(&self->q140, &qg);
    V4Copy(&self->q150, &qa);
    Q_L qi;
    QI_L(&qi, &qb, &qh);
    Q_L up2;
    Up_L(&up2, &qd);
    float ang = Libc_Atan2f(-up2.x, up2.y);
    bool k2 = self->f310 == 0 || self->f311 == 0;
    eMode_L mode = self->f312;
    bool c1 = 0;
    bool c2 = 0;
    if (mode == 2) {
        if (!(ang <= 1.3089969f) || ang < -0.2617994f) mode = (eMode_L)4;
        else mode = (eMode_L)3;
    } else if (mode == 8 || mode == 9) {
        float lim;
        if (self->f314 == 4) lim = -0.2617994f;
        else lim = -0.7853982f;
        if (ang < lim) mode = (eMode_L)4;
        else if (mode == 9) mode = (eMode_L)0xB;
        else mode = (eMode_L)0xA;
    }
    self->f314 = mode;
    if (k2) {
        self->f310 = mode;
        c1 = 1;
        self->f311 = mode;
        c2 = c1;
    } else if (self->f310 != self->f311) {
        float sp;
        if (self->f311 != mode && mode == 1) {
            sp = 0.5f;
        } else if (self->f311 == 0x16 && (self->f310 == 0x11 || self->f310 == 0x12 || self->f310 == 0x13 || self->f310 == 0x14 || self->f310 == 7)) {
            sp = 0.5f;
        } else {
            sp = 1.0f;
        }
        self->f318 += dt / (self->f320 * sp);
        if (!(self->f318 < 1.0f)) {
            if (self->f310 == 0x15) cHumanIkRoutine_SendEndOfUpperBodyAnimMessage(self, dt);
            else if (self->f310 == 0x16) cHumanIkRoutine_SendEndOfUpperBodyAnimWithRightHandLookatMessage(self, dt);
            c1 = 1;
            c2 = c1;
            self->f310 = *(signed char*)&self->f311;
            self->f311 = mode;
            self->f318 = 0.0f;
        }
    } else if (self->f311 != mode) {
        self->f311 = mode;
        c2 = 1;
    }
    {
        float x = self->f318;
        float x2 = x * x;
        float x3 = x * x2;
        float v = 3.0f * x2 - 2.0f * x3;
        self->f31C = Clamp4_L(v, 0.0f, 1.0f);
    }
    char* f10 = self->f10;
    Ent_L* ea = (Ent_L*)(f10 + 0x40);
    Ent_L* eb = (Ent_L*)(f10 + 0x70);
    float ha = ea->f8;
    float hb = eb->f8;
    Q_L da;
    Dir_L(&da, ea, &im);
    Q_L db;
    Dir_L(&db, eb, &im);
    Mtx_L m1;
    {
        Obj_L* o = (Obj_L*)(Nodes_L(s3) + 0x13F0);
        if (((ObjD_L*)o)->f50) o->v20();
        MCopy_L(&m1, &((ObjD_L*)o)->m);
    }
    Mtx_L m2;
    {
        Obj_L* o = (Obj_L*)(Nodes_L(s3) + 0xCB0);
        if (((ObjD_L*)o)->f50) o->v20();
        MCopy_L(&m2, &((ObjD_L*)o)->m);
    }
    bool e1 = 1;
    bool e2 = 1;
    SQ_L g1 = ((VObj_L*)(Nodes_L(s3) + 0x1D00))->w10();
    SQ_L g2 = ((VObj_L*)(Nodes_L(s3) + 0x15C0))->w10();
    if (!e1) {
        g1.x = 0.0f;
        g1.y = 0.0f;
    }
    if (!e2) {
        g2.x = 0.0f;
        g2.y = 0.0f;
    }
    KAdj_L(&m1, &g1);
    KAdj_L(&m2, &g2);
    Q_L p1;
    V4Copy(&p1, &m1.r[3]);
    Q_L p2;
    V4Copy(&p2, &m2.r[3]);
    Q_L w1;
    MulW_L(&w1, &p1, &wm);
    Q_L w2;
    MulW_L(&w2, &p2, &wm);
    bool b1 = Valid_L(eb) && hb >= w1.z;
    bool b2 = Valid_L(ea) && ha >= w2.z;
    float zz;
    if (b1) zz = hb;
    else zz = w1.z;
    Q_L bb;
    Set4_L(&bb, w1.x, w1.y, zz, 1.0f);
    float zz2;
    if (b2) zz2 = ha;
    else zz2 = w2.z;
    Q_L ba;
    Set4_L(&ba, w2.x, w2.y, zz2, 1.0f);
    Q_L v1;
    MulW_L(&v1, &bb, &im);
    Q_L v2;
    MulW_L(&v2, &ba, &im);
    Mtx_L n11;
    {
        Node_L* nd = (Node_L*)(Nodes_L(s3)) + 11;
        if (nd->f50) ((Obj_L*)nd)->v20();
        cMatrix_GetRotation(&n11, &nd->m);
    }
    Mtx_L n7;
    {
        Node_L* nd = (Node_L*)(Nodes_L(s3)) + 7;
        if (nd->f50) ((Obj_L*)nd)->v20();
        cMatrix_GetRotation(&n7, &nd->m);
    }
    Mtx_L n16;
    {
        Node_L* nd = (Node_L*)(Nodes_L(s3)) + 16;
        if (nd->f50) ((Obj_L*)nd)->v20();
        cMatrix_GetRotation(&n16, &nd->m);
    }
    Mtx_L n12;
    {
        Node_L* nd = (Node_L*)(Nodes_L(s3)) + 12;
        if (nd->f50) ((Obj_L*)nd)->v20();
        cMatrix_GetRotation(&n12, &nd->m);
    }
    Q_L aq1;
    AQ_L(&aq1, &n11, &db);
    Q_L aq2;
    AQ_L(&aq2, &n7, &da);
    Q_L aq3;
    AQ_L(&aq3, &n16, &db);    Q_L aq4;
    AQ_L(&aq4, &n12, &da);    Q_L sa;
    {
        Q_L* d = &sa;
        Q_L* p;
        if (e1) p = &aq3;
        else p = &aq1;
        V4Copy(d, p);
    }
    Q_L sb;
    {
        Q_L* d = &sb;
        Q_L* p;
        if (e2) p = &aq4;
        else p = &aq2;
        V4Copy(d, p);
    }
    if (!D_004F47D8) {
        SQ_L* q = D_004F47E0;
        do { q++; asm("nop"); } while (q != D_004F47E0 + 42);
        D_004F47D8 = 1;
    }
    if (!D_004F4A80) {
        SM_L* q = D_004F4A90;
        do { q++; asm("nop"); } while (q != D_004F4A90 + 21);
        D_004F4A80 = 1;
    }
    SMLoop_L(s3, D_004F4A90);
    { int which = 1; eMode_L thisMode; if (which != 1) { if (which != 0) thisMode = (eMode_L)2; else thisMode = (eMode_L)1; } else thisMode = (eMode_L)0; }
    cHumanIkRoutine_ResetAnimationIterators(self, c1, c2, k2);
    if (k2) return;
    cHumanIkRoutine_CalculateBaseIkPose(self, &qh, dt);
    float w = self->f31C;
    {
        Tab_L* ta = &SecondaryStateTable[self->f310];
        Tab_L* tb = &SecondaryStateTable[self->f311];
        float iw = 1.0f - w;
        float* fa = ta->f48;
        float* fb = tb->f48;
        eAS_L* ba = ta->f40;
        eAS_L* bb = tb->f40;
        unsigned int i = 0;
        E2_L* e = UpperBodyNodeTable;
        for (; e != UpperBodyNodeTable + 21; i++, fa++, fb++, ba++, bb++, e++) {
            { float v = *fa; *fa = Max2_L(0.0f, v); }
            { float v = *fb; *fb = Max2_L(0.0f, v); }
            float r = 0.0f;
            if (!(w <= 0.0f) && (*ba == 5 || *ba == 6) && (*bb == 5 || *bb == 6)) r = iw * *fa + w * *fb;
            else if (*ba == 5 || *ba == 6) r = *fa;
            else if (*bb == 5 || *bb == 6) r = *fb;
            e->fB4 = r;
            e->fB0 = P2_L(*ba, *bb);
        }
    }
    if (self->f310 == 12 || self->f310 == 16 || self->f311 == 12 || self->f311 == 16) {
        Q_L k;
        k.x = 0.3f;
        k.y = 0.0f;
        k.z = 0.0f;
        k.w = 0.0f;
        Q_L r;
        A73W_L(&r, &k, &plc);
        Q_L off;
        { const Q_L& rr = r; TTW_L(&off, &rr, &im); }
        Q_L* pw = &off;
        Q_L nq;
        V4Copy(&nq, Nodes_L(s3) + 0x1B0);
        Q_L& pa = (self->f310 == 12 || self->f310 == 16) ? off : nq;
        Q_L& pb = (self->f311 == 12 || self->f311 == 16) ? off : nq;
        LerpN_L(s3, &pa, &pb, w);
    }
    {
        Q_L t;
        V4Copy(&t, &qh);
        cHumanIkRoutine_CalculateIntermediatePose(self, &t);
    }
    {
        char* p = self->f3A0;
        char* pe = self->f3A0 + 0xE0;
        for (; p != pe; p += 0x70) cAimComponent_NextFrame(p, &wm, dt, sys, UpperBodyNodeTable);
    }
    bool kb4F = Tab_P(self->f310)->b4F || Tab_P(self->f311)->b4F;
    if (kb4F) {
        {
            Q_L gr;
            Q_L ga;
            Q_L gb;

            bool ka = cHumanIkRoutine_CalculateRightWristTargetPos_SkelSpace(self, &ga, *(signed char*)&self->f310);
            bool kb;
            if (self->f310 != self->f311) kb = cHumanIkRoutine_CalculateRightWristTargetPos_SkelSpace(self, &gb, *(signed char*)&self->f311);
            else kb = 0;
            if (ka && kb) {
                float s = self->f31C;
                LerpG_L(&gr, &ga, &gb, s);
                self->f308 = 1.0f;
            } else if (ka) {
                V4Copy(&gr, &ga);
                self->f308 = 1.0f - self->f31C;
            } else if (kb) {
                V4Copy(&gr, &gb);
                self->f308 = self->f31C;
            } else {
                QZero_L(&gr);
                self->f308 = 0.0f;
            }
            cHumanIkRoutine_PositionArm(self, &gr, 0x14, self->f308);
        }
        {
            Q_L mr;
            Q_L ma;
            Q_L mb;
            bool ka;
            bool kb;
            {
                Q_L& pt = tgt;
                Q_L& pq = qi;
                ka = UpperBody_HandRotation(self, &ma, *(signed char*)&self->f310, &pt, &fwd, &qb, &pq);
                if (self->f310 != self->f311) kb = UpperBody_HandRotation(self, &mb, *(signed char*)&self->f311, &pt, &fwd, &qb, &pq);
                else kb = 0;
            }
            if (ka && kb) {
                { Q_L* pa = &ma; const Q_L* rf = &mb; QHemi_L(pa, rf); }
                float s = self->f31C;
                L4_L(&mr, &ma, &mb, s);
            } else if (ka) {
                V4Copy(&mr, &ma);
            } else if (kb) {
                V4Copy(&mr, &mb);
            }
            cHumanIkRoutine_OrientHand(self, &mr, 0x14);
        }
    }
    bool kb4E = Tab_P(self->f310)->b4E || Tab_P(self->f311)->b4E;
    if (kb4E) {
        {
            Q_L gr;
            Q_L ga;
            Q_L gb;

            bool ka = cHumanIkRoutine_CalculateLeftWristTargetPos_SkelSpace(self, &ga, *(signed char*)&self->f310);
            bool kb;
            if (self->f310 != self->f311) kb = cHumanIkRoutine_CalculateLeftWristTargetPos_SkelSpace(self, &gb, *(signed char*)&self->f311);
            else kb = 0;
            if (ka && kb) {
                float s = self->f31C;
                LerpG_L(&gr, &ga, &gb, s);
                self->f308 = 1.0f;
            } else if (ka) {
                V4Copy(&gr, &ga);
                self->f308 = 1.0f - self->f31C;
            } else if (kb) {
                V4Copy(&gr, &gb);
                self->f308 = self->f31C;
            } else {
                QZero_L(&gr);
                self->f308 = 0.0f;
            }
            cHumanIkRoutine_PositionArm(self, &gr, 0x13, self->f308);
        }
        {
            Q_L mr;
            Q_L ma;
            Q_L mb;
            bool ka;
            bool kb;
            {
                Q_L& pt = tgt;
                Q_L& pq = qi;
                ka = cHumanIkRoutine_CalculateLeftWristTargetRot_Local(self, &ma, *(signed char*)&self->f310, &pt, &fwd, &pq);
                if (self->f310 != self->f311) kb = cHumanIkRoutine_CalculateLeftWristTargetRot_Local(self, &mb, *(signed char*)&self->f311, &pt, &fwd, &pq);
                else kb = 0;
            }
            if (ka && kb) {
                { Q_L* pa = &ma; const Q_L* rf = &mb; QHemi_L(pa, rf); }
                float s = self->f31C;
                L4_L(&mr, &ma, &mb, s);
            } else if (ka) {
                V4Copy(&mr, &ma);
            } else if (kb) {
                V4Copy(&mr, &mb);
            }
            cHumanIkRoutine_OrientHand(self, &mr, 0x13);
        }
    }
    cHumanIkRoutine_UpdateHipBeforeDoingLegIk(self, 0);
    {
        E2_L* e = UpperBodyNodeTable;
        Q_L* pv1 = &v1;
        Q_L* pv2 = &v2;
        Q_L* psa = &sa;
        Q_L* psb = &sb;
        bool s0 = MaxZ_L(e->fB0.a, e->fB0.b) != 2;
        cHumanIkRoutine_PositionLegAndOrientFoot(self, pv1, psa, 0x10, b1 || s0);
        cHumanIkRoutine_PositionLegAndOrientFoot(self, pv2, psb, 0xC, b2 || s0);
    }
    {
        char* q = (char*)self + 0x410;
        AimH_L(self, q + 0x30, q + 0x50, *(float*)((char*)self + 0x470));
    }
    cHumanIkRoutine_CalculateResultPose(self);
    {
        It_L it;
        cArray_cBone_Iterator_ctor(&it, std_vector_cBone_begin(s3));
        It_L end;
        cArray_cBone_Iterator_ctor(&end, std_vector_cBone_end(s3));
        while (ItNe_L(&it, &end)) {
            char* np = it.p;
            NodeM_L(np);
            it.p += 0x1D0;
        }
    }
    {
        bool done = 0;
        switch (self->f830) {
        case 0:
            break;
        case 2:
            cDrawAndHolsterWeapon_ActionManager_StartTransitionIfNecessary(&self->f830, self->layers);
            if (cHandIkTargetList_GetTransitionTimeLeftForBothHands(self->layers) <= D_0049F718) cDrawAndHolsterWeapon_ActionManager_SwitchStage(&self->f830, 3);
            break;
        case 1:
        case 3:
            cDrawAndHolsterWeapon_ActionManager_StartTransitionIfNecessary(&self->f830, self->layers);
            {
            int r = cHandIkTargetList_HasTransitionJustEndedForBothHands(self->layers);
            void* p = &self->f830;
            if (r) {
                cDrawAndHolsterWeapon_ActionManager_TriggerCallback(p);
                if (self->f830 == 0) done = 1;
            }
            }
            break;
        }
        if (done != 0) self->f312 = (eMode_L)self->f313;
    }}
