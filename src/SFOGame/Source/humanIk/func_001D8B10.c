#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

extern "C" {
float COS(float);
float SIN(float);
}

class cVector {
public:
    float x, y, z, w;
    cVector() {}
    cVector(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    cVector(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector& operator=(const cVector& o) { cVector* d = this; const cVector* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));

class cEulerAngle_T {
public:
    float x, y, z;
    unsigned pad;
    cEulerAngle_T(float ax, float ay, float az) { x = ax; y = ay; z = az; }
} __attribute__((aligned(16)));

class cQuaternion {
public:
    float x, y, z, w;
    cQuaternion() {}
    cQuaternion(const cQuaternion& o) { cQuaternion* d = this; const cQuaternion* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cQuaternion& operator=(const cQuaternion& o) { cQuaternion* d = this; const cQuaternion* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%0); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "0"(s) : "memory"); return *this; }
    cQuaternion(const cEulerAngle_T& e)
    {
        float hx = 0.5f * e.x;
        float hy = 0.5f * e.y;
        float hz = 0.5f * e.z;
        float cx = COS(hx);
        float cy = COS(hy);
        float cz = COS(hz);
        float sx = SIN(hx);
        float sy = SIN(hy);
        float sz = SIN(hz);
        float cycz = cy * cz;
        float sysz = sy * sz;
        float sycz = sy * cz;
        float cysz = cy * sz;
        w = cx * cycz - sx * sysz;
        x = sx * cycz - cx * sysz;
        y = cx * sycz + sx * cysz;
        z = cx * cysz + sx * sycz;
    }
} __attribute__((aligned(16)));

class cQuatVec {
public:
    cQuaternion rot;
    cVector trans;
    cQuatVec(const cQuaternion& r, const cVector& t) : rot(r), trans(t) {}
};

class cIkTarget {
public:
    cQuatVec mTransform;
    signed char mParentBoneId;
    cIkTarget(const cQuatVec& t, signed char bone) : mTransform(t), mParentBoneId(bone) {}
};

class cIkTarget_LeftRight {
public:
    cIkTarget mLeft;
    cIkTarget mRight;
};

class cWeaponSlotPair {
public:
    signed char a, b;
    cWeaponSlotPair(signed char x, signed char y) { a = x; b = y; }
};

class cWeaponSlotTransitionTable;
struct cIter { int n; };

extern "C" {
void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Find(cIter* out, cWeaponSlotTransitionTable* m, const cWeaponSlotPair* k);
void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_End(cIter* out, cWeaponSlotTransitionTable* m);
int cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_opEq(const cIter* a, const cIter* b);
void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Add(cWeaponSlotTransitionTable* m, const cWeaponSlotPair* k, const cIkTarget_LeftRight* v);
extern cWeaponSlotTransitionTable* D_004F2D88;
}

class cWeaponSlotTransitionTable;

#define H 1.5707964f
#define H3 4.712389f
#define T cIkTarget(cQuatVec(cQuaternion(cEulerAngle_T(0.0f, -H, H3)), cVector(0.0f, 2.0f, 1.5f, 1.0f)), 5)
struct cIkTarget_LeftRight_Mem;
extern "C" cIkTarget_LeftRight* cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetR_cIkTargetR(cIkTarget_LeftRight_Mem* self, const cIkTarget& l, const cIkTarget& r);
struct cIkTarget_LeftRight_Mem {
    char b[0x60];
    cIkTarget_LeftRight_Mem() {}
    cIkTarget_LeftRight_Mem* Self() { return this; }
    cIkTarget_LeftRight_Mem(int) { cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetR_cIkTargetR(this, T, T); }
} __attribute__((aligned(16)));
#define P (*cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetR_cIkTargetR(cIkTarget_LeftRight_Mem().Self(), T, T))
#define K cWeaponSlotPair

extern "C" cWeaponSlotTransitionTable* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotTransitionTable_Add_WithRedundancyCheck(cWeaponSlotTransitionTable* t, const cWeaponSlotPair& k, const cIkTarget_LeftRight& v);
static inline cWeaponSlotTransitionTable* Fin(cWeaponSlotTransitionTable* t, const cWeaponSlotPair& k, const cIkTarget_LeftRight_Mem& v)
{
    cIter i1;
    cIter i2;
    cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Find(&i1, t, &k);
    cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_End(&i2, t);
    if (cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_opEq(&i1, &i2)) {
        cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Add(t, &k, (const cIkTarget_LeftRight*)&v);
    }
    return t;
}
#define AW cDrawAndHolsterWeapon_ActionManager_cWeaponSlotTransitionTable_Add_WithRedundancyCheck

extern "C" void cDrawAndHolsterWeapon_ActionManager_InitWeaponSlotTransitionTable(void)
{
    (void)Fin(AW(AW(AW(AW(AW(AW(AW(AW(AW(AW(AW(AW(AW(AW(D_004F2D88,
        K(0, 6), P), K(2, 6), P), K(3, 6), P), K(4, 6), P), K(5, 6), P), K(0, 2), P), K(0, 3), P), K(0, 4), P),
        K(0, 5), P), K(2, 3), P), K(2, 4), P), K(2, 5), P), K(3, 4), P), K(3, 5), P), K(4, 5), cIkTarget_LeftRight_Mem(0));
}
