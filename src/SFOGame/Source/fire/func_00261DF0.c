#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float ix, float iy, float iz, float iw) : x(ix), y(iy), z(iz), w(iw) {}
    cVector(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } }
    cVector& operator=(const cVector& o) { __int128 t; const cVector* ps = &o; asm volatile { lq t, 0(ps); sq t, 0(this) } return *this; }
} __attribute__((aligned(16)));

static inline void SubV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
static inline void AddV(cVector* r, const cVector* a, const cVector* b) {
    cVector* pr = r; const cVector* pa = a; const cVector* pb = b;
    asm volatile { lqc2 vf1, 0x0(pa); lqc2 vf2, 0x0(pb); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(pr) }
}
// .set noreorder: retail has no assembler-inserted nop between mfc1 and qmtc2 (same idiom as func_003E4720.c)
static inline void ScaleV(cVector* r, const cVector* a, float s) {
    int t; const cVector* pa = a; cVector* pr = r;
    asm volatile { .set noreorder; lqc2 vf1, 0x0(pa); mfc1 t, s; qmtc2.ni t, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(pr); .set reorder }
}
static inline cVector ScaleR(const cVector& a, float s) { cVector r; cVector* p = &r; const cVector* q = &a; ScaleV(p, q, s); return r; }
static inline cVector operator*(const cVector& a, float s) { return ScaleR(a, s); }
static inline cVector operator+(const cVector& a, const cVector& b) { cVector r; AddV(&r, &a, &b); return r; }
static inline cVector& operator-=(cVector& a, const cVector& b) { SubV(&a, &a, &b); return a; }

static inline float Abs_FO(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline float Max_FO(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Min_FO(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

struct cSubclassId { int id; bool operator==(const cSubclassId& o) const { int k = o.id; return id == k; } };

struct cGobjController {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7();
    virtual void c0(); virtual void c1(); virtual void c2();
    virtual bool IsDangerAware();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void NearFire(float pct, void* src);
};

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

struct cGOBJ {
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6();
    virtual cVector GetPosition();
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5();
    virtual void Damage(void* src, int a, int b, int c, int d, int e, float amt);
    virtual void i0();
    virtual unsigned char GetState();
    char pad4[8];
    int mSerial;
    char pad10[4];
    unsigned char mVisible;
    char pad15[0x2C - 0x15];
    unsigned char mEnabled;
    unsigned char mActiveFlag;
    unsigned char mStreamingFlag;
    char pad2F[0x4C - 0x2F];
    cSubclassId mSubclassId;
    char pad50[8];
    cGobjController* mController;
    cGOBJ* m_AllAboard;
    bool IsNotStreaming() const { return !(bool)mStreamingFlag; }
    bool IsActive() const {
        bool r = false;
        bool a = false;
        if (mActiveFlag && mEnabled) a = true;
        if (a && IsNotStreaming()) r = true;
        return r;
    }
};

struct cHuman : cGOBJ {
    char pad60[0x33A5 - 0x60];
    unsigned char mFlag33A5;
};

struct cSafePtr {
    cGOBJ* mPtr;
    int mSerial;
    bool SerialOK() const { return mPtr->mSerial == mSerial; }
    bool IsValid() const { return !(bool)mPtr || SerialOK(); }
    cGOBJ* Get() const { return IsValid() ? mPtr : 0; }
};

struct cLListNode {
    cLListNode* prev;
    cLListNode* next;
    cSafePtr data;
};

struct cConstLListIterator {
    cLListNode* n;
    cConstLListIterator() {}
    cConstLListIterator(cLListNode* p) : n(p) {}
    const cSafePtr& operator*() const { return n->data; }
    bool operator!=(const cConstLListIterator& o) const { return n != o.n; }
    cConstLListIterator PostInc() { cConstLListIterator t = *this; n = n->next; return t; }
    cConstLListIterator operator++(int) { cConstLListIterator r = PostInc(); return r; }
};

extern "C" cLListNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void*);

struct cLList {
    char pad0[4];
    char mImpl[4];
    cConstLListIterator begin() { cConstLListIterator it(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(mImpl)->next); return it; }
    cConstLListIterator end() { cConstLListIterator it(details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(mImpl)); return it; }
};

struct cFireObj : cGOBJ {
    int mDamagePerSecond;
    char pad64[0xC];
    cVector mCenter;
    cVector mRad;
    cSafePtr mOwner;
};

extern "C" {
extern float D_0048B0E8;
extern cSubclassId g_HumanActorClassKey;
extern cLList D_004F78DC;
}

static inline const cSubclassId& HumanKey() { return g_HumanActorClassKey; }
extern "C" void cFireObj_NextFrame(cFireObj* self, float timeStep)
{
    if (self->mEnabled) {
        if (self->mOwner.Get() && !self->mOwner.Get()->IsActive()) return;
        if (self->mOwner.Get()) {
            self->mCenter = self->mOwner.Get()->GetPosition();
            self->mCenter.z += 2.0f;
        }
        cLList& targets = D_004F78DC;
        cConstLListIterator targ = targets.begin();
        cConstLListIterator end = targets.end();
        cVector halfRad = self->mRad * 0.5f;
        cVector dangerRad = self->mRad + cVector(D_0048B0E8, D_0048B0E8, D_0048B0E8, 0.0f);
        for (; targ != end; targ++) {
            cGOBJ* gobj = (*targ).Get();
            if (!gobj) continue;
            if (!gobj->IsActive()) continue;
            if (gobj == self->mOwner.Get()) continue;
            if (!gobj->mVisible) continue;
            if (gobj->mSubclassId == HumanKey()) {
                cHuman* human = (cHuman*)gobj;
                if (human->GetState() == 3 && !human->mFlag33A5) continue;
            }
            cVector loc = gobj->GetPosition();
            loc -= self->mCenter;
            float pct = 1.0f;
            loc.x = Abs_FO(loc.x);
            loc.y = Abs_FO(loc.y);
            loc.z = Abs_FO(loc.z);
            if (loc.x < self->mRad.x && loc.y < self->mRad.y && loc.z < self->mRad.z) {
                int dmg = pct * ((float)self->mDamagePerSecond * timeStep);
                gobj->Damage(self, 3, 4, 0, 0, 0, dmg);
                if (gobj->mController) gobj->mController->NearFire(pct, self);
            } else if (gobj->mVisible) {
                bool aware = false;
                if (gobj->mController && gobj->mController->IsDangerAware()) aware = true;
                if (aware && loc.x < dangerRad.x && loc.y < dangerRad.y && loc.z < dangerRad.z) {
                    loc -= self->mRad;
                    float val = Max_FO(loc.x, loc.y);
                    val = Max_FO(val, loc.z);
                    val = Min_FO(val, D_0048B0E8);
                    float pct = (D_0048B0E8 - val) / D_0048B0E8;
                    gobj->mController->NearFire(pct, self);
                }
            }
        }
    }
}

