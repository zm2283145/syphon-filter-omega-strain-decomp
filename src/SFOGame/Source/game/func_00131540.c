#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
#pragma inline_depth(8)
static inline void ScaleV(void* rp, const void* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(float a, float b, float c, float d, int) { V* t = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator-() const { V t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    float GetLength() const { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory"); return r; }
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
    static void VU0Subtract(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator-(const V& vector) const { V result; VU0Subtract(result, *this, vector); return result; }
    static void VU0Add(V& vecOut, const V& vecIn0, const V& vecIn1) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&vecOut), "r"(&vecIn0), "r"(&vecIn1) : "memory"); }
    V operator+(const V& vector) const { V result; VU0Add(result, *this, vector); return result; }
    V operator/(float scale) const { return *this * (1.0f / scale); }

} __attribute__((aligned(16)));


static inline float PiMinus(float a) { float p = 3.1415927f; return p - a; }
static inline float Deg(float d) { return 0.017453292f * d; }
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct M { V r0, r1, r2, r3; };
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
static inline void Translate(M* d, V* s) { __asm__ volatile("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" : : "r"(d), "r"(s) : "memory"); }

struct LosHit {
    VP arr[3];
    V normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0x1D];
    int x60;
    void* x64;
    char pad68[0x18];
    void Init() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct LosRes {
    bool hit;
    char pad1[0xF];
    V pt;
    LosHit h;
    LosRes() { LosRes* p = this; p->h.Init(); }
};
struct Svc { VPAD1(a) virtual void Post(void* m); };
struct E { float x, y, z; unsigned int pad; };
struct H {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    VPAD2(f) VPAD1(g)
    virtual M GetMtx();
};
struct XNode { VPAD1(a) virtual void SetMatrix(M* m); };
struct Cam { char pad0[0x50]; XNode* node; };
struct G { char pad[0xD4]; Cam* weaponCam; unsigned char pushed; };

extern "C" {
extern signed char g_HeadNodeCode;
extern float D_00489BD8, D_00489BC8, D_00489BD0;
extern char g_LosRequestMsgClass[], D_004D9180[], g_Game[], g_LosCheckService[];
void* cSKM_GOBJ_GetSkeleton_void(H*);
V cSkeleton_GetBoneToWorldTranslation(void*, int);
float Libc_Sinf(float);
float Libc_Asinf(float);
void GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(H*, H*, E*);
float cVector_X_void(V*);
float cVector_Y_void(V*);
float cVector_Z_void(V*);
void cMatrix_SetWithAxisAngle(M*, float, float, float, float);
void cMessage_ctor_cMessageNameR(void*, void*);
void cMessage_dtor(void*, int);
Svc* cSystemContainer_GetSystem(void*, void*);
V cVector_Cross(V*, V*);
int cVector_IsZeroXYZ(V*);
V cVector_GetNormalized_void(V*);
V* cVector_Normalize_void(V*);
void cVector_ctor_cVectorR(V*, V*);
V* cVector_ctor_float_float_float_float(V*, float, float, float, float);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M*, V*, V*, V*, V*);
void cMatrix_MakeLookAtMatrix_cVectorR(M*, V*);
void cMatrix_SetUnit(M*);
void cGameSystem_PushCamera(G*, Cam*);
}
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB {
    void* vtable; void* type; int pad8[5]; int flags; unsigned char kind; char pad21[3];
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct LosMsg : MsgB {
    int x24;
    int x28;
    LosRes* res;
    V from;
    V dir;
    void* self;
    int x54;
    int mask;
    unsigned char b5C;
    LosMsg(LosRes* r, const V& f, V d, void* o, int mask)
    {
        LosMsg* m = this;
        cMessage_ctor_cMessageNameR(m, g_LosRequestMsgClass);
        m->vtable = D_004D9180;
        m->x24 = 0;
        m->x28 = 0;
        m->res = r;
        m->from = f;
        m->dir = d;
        m->self = o;
        m->x54 = 0;
        m->mask = mask;
        m->b5C = 0;
        m->from.w = 1.0f;
        m->dir.w = 0.0f;
    }
    __declspec(weak) __declspec(MSG_DTOR) ~LosMsg() { vtable = D_004D9180; }
};

static inline void SetAxisAngle(M* m, V axis, float a) { cMatrix_SetWithAxisAngle(m, cVector_X_void(&axis), cVector_Y_void(&axis), cVector_Z_void(&axis), a); }

static inline void LookAt2(M* mat, V& dir, V& up)
{
    V side = cVector_Cross(&dir, &up);
    if (!cVector_IsZeroXYZ(&side)) {
        V fwd = cVector_GetNormalized_void(&dir);
        V right; cVector_ctor_cVectorR(&right, cVector_Normalize_void(&side));
        V up2 = cVector_Cross(&right, &fwd);
        V w;
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(mat, &right, &fwd, &up2, cVector_ctor_float_float_float_float(&w, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(&dir)) {
        cMatrix_MakeLookAtMatrix_cVectorR(mat, &dir);
    } else {
        cMatrix_SetUnit(mat);
    }
}

static inline void LookAt3(M* mat, V& dir, V& up) { LookAt2(mat, dir, up); }
static inline void LookAt4(M* mat, V& dir, V& up) { LookAt3(mat, dir, up); }
static inline void LookAt(M* mat, V& dir, V up) { V* pu = &up; LookAt4(mat, dir, *pu); }

extern "C" void cGameSystem_PushWeaponCam(G* self, H* nearHuman, H* farHuman)
{
    V nearHeadPos = cSkeleton_GetBoneToWorldTranslation(cSKM_GOBJ_GetSkeleton_void(nearHuman), g_HeadNodeCode);
    float camAngz;
    float camHeight;
    if (farHuman) {
        V farpos = farHuman->GetPos();
        float angB = Deg(D_00489BD8);
        float lenB = (farpos - nearHeadPos).GetLength();
        float lenA = D_00489BC8;
        float numer = lenA * Libc_Sinf(angB);
        float angA = Libc_Asinf(numer / lenB);
        float angC = PiMinus(angA + angB);
        E result;
        GetTargetAngle_cHumanP_cGOBJP_cEulerAngleTP(nearHuman, farHuman, &result);
        camAngz = result.z + angC;
        camHeight = D_00489BC8 * (nearHuman->GetPos().z - farpos.z) / lenB;
    } else {
        camAngz = Deg(D_00489BD8);
        camHeight = D_00489BD0;
    }
    M mat = nearHuman->GetMtx();
    mat.r3 = nearHeadPos;
    V off(0.0f, D_00489BC8, camHeight, 1.0f);
    M rotMat;
    SetAxisAngle(&rotMat, V(0.0f, 0.0f, 1.0f, 1.0f, 0), camAngz);
    Apply(&off, &rotMat, &off);
    Apply(&off, &mat, &off);
    V dir = nearHeadPos - off;
    LosRes result;
    LosMsg msg(&result, nearHeadPos, -dir, nearHuman, 4);
    cSystemContainer_GetSystem(g_Game, g_LosCheckService)->Post(&msg);
    if (result.hit) {
        off = (result.pt * 8.0f + nearHeadPos) / 9.0f;
    }
    LookAt(&mat, dir, V(0.0f, 0.0f, 1.0f, 1.0f));
    Translate(&mat, &off);
    self->weaponCam->node->SetMatrix(&mat);
    cGameSystem_PushCamera(self, self->weaponCam);
    self->pushed = 1;
}





