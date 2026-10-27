/*
 * SFOGame/Source/playerCamera: 6 files, 0027FF60-00280390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027FF60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

Vec3f* cEulerAngle_T_1_2_ctor_cEulerAngleTR(Vec3f* dst, Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

float cEulerAngle_T_1_2_Z_void(Vec3f* v) {
    return v->z;
}

float* cEulerAngle_T_1_2_Z_void_2(Vec3f* v) {
    return &v->z;
}

float cEulerAngle_T_1_2_Y_void(Vec3f* v) {
    return v->y;
}

float* cEulerAngle_T_1_2_Y_void_2(Vec3f* v) {
    return &v->y;
}
static inline void merge_flush_func_0027FF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027FF60 */

/* merge_units: begin func_0027FFC0 */
#pragma push /* merge_units */
float nSFOMath_ExpressAngleAsValueBetweenNegAndPos180_float(float a) {
    for (;;) {
        if (a > 3.1415927f) {
            a += -6.2831855f;
        } else if (a < -3.1415927f) {
            a += 6.2831855f;
        } else {
            return a;
        }
    }
}
static inline void merge_flush_func_0027FFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027FFC0 */

/* merge_units: begin func_00280040 */
#pragma push /* merge_units */
float cEulerAngle_T_1_2_X_void(char* self) {
    return *(float*)(self + 0);
}

void* cEulerAngle_T_1_2_X_void_2(void* self) {
    return self;
}

void* cEulerAngle_T_1_2_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_00280040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280040 */

/* merge_units: begin func_00280070 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cPlayerCamera::GetAngleToTarget: pitch/yaw from the pivot point (the camera position in
   third-person manual aim, else the given bone of the human) to the locked target's aim point;
   false when there is no live target. */
/* lq/sq quadword copies: 128-bit moves have no C equivalent */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector Flat() const { return cVector(x, y, 0.0f, 0.0f); }
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { const void* xx = &o; cVector* d = this; const cVector* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
/* VU0 macro-mode vector ops (COP2), not expressible in C */
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline float Length(const cVector& v) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&v) : "memory"); return r; }
struct cEulerAngle_T { float x, y, z; };
struct cGOBJ {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual cVector GetTargetPosition(int sub) const;
    int pad4[2];
    int id;
    char pad10[0x2C - 0x10];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x50 - 0x2F];
    void* mXform;
};
struct cSkeleton;
static inline bool IsNullNV(void* p) { return !(p != 0); }
static inline int SameRef(const int& a, const int& b) { return (unsigned)(a ^ b) < 1; }
struct cSafePtr {
    cGOBJ* ptr; int id;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(ptr) && !SameRef(ptr->id, id)) ok = 0; return ok; }
    cGOBJ* Get() { return IsValid() ? ptr : 0; }
};
struct cPlayerCamera { char pad[0xD04]; cSafePtr target; int subTarget; };
extern "C" {
extern signed char ActorNodeCodeTable[];
cSkeleton* cSKM_GOBJ_GetSkeleton_void(const cGOBJ* h);
cVector cSkeleton_GetBoneToWorldTranslation(cSkeleton* s, int node);
float Libc_Atan2f(float y, float x);
bool cPlayerCamera_GetAngleToTarget(cPlayerCamera* self, cEulerAngle_T& angle, const cGOBJ* human, unsigned char pivotPoint_BoneIndex, bool isInThirdPersonManualAim, const cVector& cameraCurrPos);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(cGOBJ* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }

bool cPlayerCamera_GetAngleToTarget(cPlayerCamera* self, cEulerAngle_T& angle, const cGOBJ* human, unsigned char pivotPoint_BoneIndex, bool isInThirdPersonManualAim, const cVector& cameraCurrPos)
{
    void* targetXform = self->target.Get() ? self->target.Get()->mXform : 0;
    if (targetXform && Ready(self->target.Get())) {
        cVector targetPoint = self->target.Get()->GetTargetPosition(self->subTarget);
        cVector targetFromPoint;
        if (isInThirdPersonManualAim)
            targetFromPoint = cameraCurrPos;
        else
            targetFromPoint = cSkeleton_GetBoneToWorldTranslation(cSKM_GOBJ_GetSkeleton_void(human), ActorNodeCodeTable[pivotPoint_BoneIndex]);
        {
            cVector targetDir = targetPoint - targetFromPoint;
            angle.x = Libc_Atan2f(targetDir.z, Length(targetDir.Flat()));
            angle.y = 0.0f;
            angle.z = Libc_Atan2f(-targetDir.x, targetDir.y);
        }
        return true;
    }
    return false;
}
static inline void merge_flush_func_00280070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280070 */

/* merge_units: begin func_00280390 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x320C];
    int x320C;
    char pad3210[0x3248 - 0x3210];
    int x3248;
} O_280390;
void ModifyCameraTrackingPoint_ForHuman(float* out, O_280390* o, signed char mode, int flag)
{
    switch (mode) {
    case 0:
        break;
    case 1:
        if (o->x320C == 16) {
            if ((o->x3248 >> 29) & 1)
                *out = -3.0f;
            else
                *out = -6.3f;
        } else if (flag) {
            *out = -0.5f;
        } else if (o->x320C == 1) {
            *out = -3.0f;
        } else if (o->x320C == 8 || o->x320C == 7) {
            *out = -7.0f;
        } else {
            return;
        }
        break;
    case 2:
        *out = -6.3f;
        break;
    case 3:
        break;
    }
}
static inline void merge_flush_func_00280390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280390 */

/* merge_units: begin func_00280470 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void Q16s(const void* s, void* d) { Q16(d, s); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { const V* s = &o;V* d = this;__int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { Q16s(&o, this); return *this; }
    V operator-() const { V t; __asm__ volatile("lqc2 vf1, 0x0(%1); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
} __attribute__((aligned(16)));
static inline void CPa(V* d0, const V* s0) { const V* s = s0;__int128 q;V* d = d0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
struct VR : V { VR() {} VR(const VR& o) { void* xx = this; CPa(this, &o); } };
static inline void ScaleI(V* pr, V* pa, float k)
{
    int t;__int128 tt = 0;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(k) : "memory");
}
static inline void ScaleJ(V* pr, V* pa, float k) { V* p2 = pa; ScaleI(pr, p2, k); }
static inline VR operator*(V a, float k)
{
    VR r;
    ScaleJ(&r, &a, k);
    return r;
}
struct M { float f[4][4]; V& R(int i) { return *(V*)f[i]; } } __attribute__((aligned(16)));
static inline M* QuatToMtx(M* a, V* b)
{
    __asm__ volatile("lqc2 vf1, 0x0(%1); vadd.xyzw vf2, vf1, vf1; vaddw.xyz vf3, vf0, vf0w; vmulx.w vf8, vf0, vf0x; vmulx.w vf9, vf0, vf0x; vmuly.xyzw vf5, vf1, vf2y; vmulz.xyzw vf6, vf1, vf2z; vmulx.xyzw vf4, vf1, vf2x; vmulx.w vf10, vf0, vf0x; vsubay.x ACC, vf3, vf5y; vmsubz.x vf8, vf3, vf6z; vsubw.x vf9, vf5, vf6w; vaddw.x vf10, vf6, vf5w; vaddw.y vf8, vf4, vf6w; vsubax.y ACC, vf3, vf4x; vmsubz.y vf9, vf3, vf6z; vsubw.y vf10, vf6, vf4w; vsubw.z vf8, vf4, vf5w; vaddw.z vf9, vf5, vf4w; vsubax.z ACC, vf3, vf4x; vmsuby.z vf10, vf3, vf5y; sqc2 vf0, 0x30(%0); sqc2 vf8, 0x0(%0); sqc2 vf9, 0x10(%0); sqc2 vf10, 0x20(%0)" : : "r"(a), "r"(b) : "memory");
    return a;
}
struct QM : M { QM(V* q) { QuatToMtx(this, q); } };
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern const char D_004A9338[];
void* cSkaAnimAnchorList_Find(void* self, void* key);
void* cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(void* r);
V* cQuatVec_Rotation(void* p);
}
struct Key {
    char c[4];
    Key(const char* s)
    {
        bool end = false;
        for (unsigned int i = 0; i < 4; i++) {
            if (!s[i]) end = true;
            c[i] = end ? 0 : s[i];
        }
    }
};
struct Sub { char pad[0xB0]; char coll[1]; void* Coll() { return coll; } };
struct Ctx { char pad[0x2EC0]; Sub sub; Sub* S() { return &sub; } };
struct Obj { char pad[0x100]; unsigned char b100; char pad101[0xF]; V v110; char pad120[0xBD4]; int flags; };
static inline V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0.0f; D_004E1D90.y = 0.0f; D_004E1D90.z = 0.0f; D_004E1D90.w = 0.0f;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
static inline void* RWr(void* c, const Key& k) { return cSkaAnimAnchorList_Find(c, (void*)&k); }
extern "C" void func_00280470(Obj* self, Ctx* ctx)
{
    int f = self->flags;
    if (((f >> 9) & 1) || ((f >> 6) & 1) || ((f >> 4) & 1)) {
        VR d = -QM(cQuatVec_Rotation(cSkaAnimAnchor_TreeNode_GetTransform_WorldSpace(RWr(ctx->S()->Coll(), Key(D_004A9338))))).R(1) * 1.25f;
        self->b100 = 1;
        self->v110 = d;
    } else {
        V* z = &Zero();
        self->b100 = 0;
        __asm__ volatile("sq $zero, 0x0(%0)" : : "r"(&self->v110), "r"(z) : "memory");
    }
}
static inline void merge_flush_func_00280470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00280470 */
