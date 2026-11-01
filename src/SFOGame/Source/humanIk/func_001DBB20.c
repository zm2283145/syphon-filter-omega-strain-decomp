/* 001DBB20 nHumanIk::cDrawAndHolsterWeapon_ActionManager::InitWeaponSlotIkTargetTable() (humanIk.cc).
 * k4's b4.c with the prototype's quaternion helpers: identity via a GetIdentity() that returns a
 * named temporary (stack-slot order), Rotate = `*this = delta * *this`, and operator* through a
 * static VU0 multiply helper (q1, cc, b) with pointer locals (delta materialised first).
 * The VU0/quadword operations are inline asm (no C equivalent). */
#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

extern "C" {
extern float Libc_Cosf(float);
extern float Libc_Sinf(float);
}

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));

class cEulerAngle_T {
public:
    float x, y, z;
    unsigned int pad;
    cEulerAngle_T(float rotX, float rotY, float rotZ) { x = rotX; y = rotY; z = rotZ; }
} __attribute__((aligned(16)));

class cAxisAngle {
public:
    float x, y, z, angle;
    cAxisAngle(float ax, float ay, float az, float ANGLE) { x = ax; y = ay; z = az; angle = ANGLE; }
};

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { cQuaternion* d = this; const cQuaternion* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cQuaternion& operator=(const cQuaternion& o) { cQuaternion* d = this; const cQuaternion* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
    cQuaternion(const cEulerAngle_T& eulerAngle)
    {
        float halfAngleX = 0.5f * eulerAngle.x;
        float halfAngleY = 0.5f * eulerAngle.y;
        float halfAngleZ = 0.5f * eulerAngle.z;
        float cosHalfX = Libc_Cosf(halfAngleX);
        float cosHalfY = Libc_Cosf(halfAngleY);
        float cosHalfZ = Libc_Cosf(halfAngleZ);
        float sinHalfX = Libc_Sinf(halfAngleX);
        float sinHalfY = Libc_Sinf(halfAngleY);
        float sinHalfZ = Libc_Sinf(halfAngleZ);
        float cosHalfY_x_cosHalfZ = cosHalfY * cosHalfZ;
        float sinHalfY_x_sinHalfZ = sinHalfY * sinHalfZ;
        float sinHalfY_x_cosHalfZ = sinHalfY * cosHalfZ;
        float cosHalfY_x_sinHalfZ = cosHalfY * sinHalfZ;
        w = cosHalfX * cosHalfY_x_cosHalfZ - sinHalfX * sinHalfY_x_sinHalfZ;
        x = sinHalfX * cosHalfY_x_cosHalfZ - cosHalfX * sinHalfY_x_sinHalfZ;
        y = cosHalfX * sinHalfY_x_cosHalfZ + sinHalfX * cosHalfY_x_sinHalfZ;
        z = cosHalfX * cosHalfY_x_sinHalfZ + sinHalfX * sinHalfY_x_cosHalfZ;
    }
    cQuaternion(const cAxisAngle& angleAxis)
    {
        float halfAngle = 0.5f * angleAxis.angle;
        float c = Libc_Cosf(halfAngle);
        float s = Libc_Sinf(halfAngle);
        x = s * angleAxis.x;
        y = s * angleAxis.y;
        z = s * angleAxis.z;
        w = c;
    }
    static void MulTo(cQuaternion* q1, const cQuaternion* cc, const cQuaternion* b)
    {
        const cQuaternion* B = b; const cQuaternion* C = cc;
        asm volatile {
            lqc2 vf1, 0x0(B)
            lqc2 vf2, 0x0(C)
            vmul.xyzw vf3, vf1, vf2
            vopmula.xyz ACC, vf1, vf2
            vmaddaw.xyz ACC, vf1, vf2w
            vmaddaw.xyz ACC, vf2, vf1w
            vopmsub.xyz vf4, vf2, vf1
            vsubaz.w ACC, vf3, vf3z
            vmsubay.w ACC, vf0, vf3y
            vmsubx.w vf4, vf0, vf3x
            sqc2 vf4, 0x0(q1)
        }
    }
    cQuaternion& SetMul(const cQuaternion& a, const cQuaternion& c) { MulTo(this, &c, &a); return *this; }
    cQuaternion operator*(const cQuaternion& c) const { cQuaternion l0; l0.SetMul(*this, c); return l0; }
    cQuaternion& Rotate(const cQuaternion& q) { *this = q * *this; return *this; }
    cQuaternion(int) { cQuaternion* p = this; asm volatile { sqc2 vf0, 0(p) } }
    static cQuaternion GetIdentity() { cQuaternion r(0); return r; }
} __attribute__((aligned(16)));


class cQuatVec {
public:
    cQuaternion rot;
    cVector trans;
    cQuatVec(const cQuaternion& iRot, const cVector& iTrans) : rot(iRot), trans(iTrans) {}
};

class cIkTarget {
public:
    cQuatVec mTransform;
    signed char mParentBoneId;
    cIkTarget(const cQuatVec& transform, signed char parentBoneId) : mTransform(transform), mParentBoneId(parentBoneId) {}
};

class cIkTarget_LeftRight {
public:
    cIkTarget mLeft;
    cIkTarget mRight;
    cIkTarget_LeftRight(const cIkTarget& left, const cIkTarget& right) : mLeft(left), mRight(right) {}
};

class cWeaponSlotIkTargetTable;

extern "C" {
cWeaponSlotIkTargetTable* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotIkTargetTable_PushBack_WithIndexCheck(cWeaponSlotIkTargetTable* self, int index, const cIkTarget_LeftRight& target);
void cArray_FixedCapacity_cIkTarget_LeftRight_6_PushBackActual(cWeaponSlotIkTargetTable* self, const cIkTarget_LeftRight& target);
extern cWeaponSlotIkTargetTable* D_004F2D80;
}

#define PI 3.1415927f
#define H 1.5707964f
#define H3 4.712389f
#define A35 0.61086524f
#define PB cDrawAndHolsterWeapon_ActionManager_cWeaponSlotIkTargetTable_PushBack_WithIndexCheck
#define ET(ex, ey, ez, vx, vy, vz, bone) cIkTarget(cQuatVec(cQuaternion(cEulerAngle_T(ex, ey, ez)), cVector(vx, vy, vz, 1.0f)), bone)

extern "C" void cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotIkTargetTable(void)
{
    cArray_FixedCapacity_cIkTarget_LeftRight_6_PushBackActual(
        PB(PB(PB(PB(PB(D_004F2D80,
            0, cIkTarget_LeftRight(ET(0.0f, -H, 0.0f, -0.5f, 0.0f, 0.0f, 1), ET(0.0f, H, 0.0f, 0.5f, 0.0f, 0.0f, 3))),
            1, cIkTarget_LeftRight(ET(0.0f, -H, 0.0f, -0.5f, 0.0f, 0.0f, 1), ET(0.0f, H, 0.0f, 0.5f, 0.0f, 0.0f, 3))),
            2, cIkTarget_LeftRight(ET(0.0f, -H, -H3, 0.5f, -1.0f, 1.5f, 5), ET(0.0f, H, H3, 0.5f, -1.0f, 1.5f, 5))),
            3, cIkTarget_LeftRight(
                cIkTarget(cQuatVec(cQuaternion::GetIdentity().Rotate(cQuaternion(cAxisAngle(1.0f, 0.0f, 0.0f, H))).Rotate(cQuaternion(cAxisAngle(0.0f, 1.0f, 0.0f, -A35))).Rotate(cQuaternion(cAxisAngle(0.0f, 0.0f, 1.0f, -PI))), cVector(0.5f, 0.75f, 0.5f, 1.0f)), 2),
                cIkTarget(cQuatVec(cQuaternion::GetIdentity().Rotate(cQuaternion(cAxisAngle(1.0f, 0.0f, 0.0f, H))).Rotate(cQuaternion(cAxisAngle(0.0f, 1.0f, 0.0f, A35))).Rotate(cQuaternion(cAxisAngle(0.0f, 0.0f, 1.0f, PI))), cVector(0.5f, 0.75f, 0.5f, 1.0f)), 2))),
            4, cIkTarget_LeftRight(ET(H, 0.0f, -PI, -0.5f, 0.75f, 0.0f, 0), ET(H, 0.0f, PI, 0.5f, 0.75f, 0.0f, 0))),
        cIkTarget_LeftRight(ET(H, 0.0f, -PI, -0.5f, 0.75f, 0.0f, 0), ET(H, 0.0f, PI, 0.5f, 0.75f, 0.0f, 0)));
}
