/* 001710A0 @unnamed@hotbox_cc@::CalculateInteractBoxDimensionsAndLocation(const cGOBJ*, bool) */
#pragma cplusplus on
#include "types.h"

struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V& operator=(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const { V r; V* rp = &r; const V* tp = this; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V operator+(const V& o) const { V r; AddV(&r, this, &o); return r; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V& operator*=(float k) { V* tp = this; int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(tp), "f"(k) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct cBox {
    V min;
    V max;
    cBox() {}
    cBox(const V& a, const V& b) : min(a), max(b) {}
};

// max.s (EE FPU min/max), not expressible in C
static inline float Max(float a, float b) { float r; asm { max.s r, a, b } return r; }

struct cXform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0x40 - 4];
    V pos;
    unsigned char dirty;
    const V& GetPos() { if (dirty) Update(); return pos; }
};

struct cGOBJ {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual cBox* GetBBox() const;
    char pad4[0x50 - 4];
    cXform* mXform;
};

extern "C" cBox CalculateInteractBoxDimensionsAndLocation(const cGOBJ* target, bool superSize);

cBox CalculateInteractBoxDimensionsAndLocation(const cGOBJ* target, bool superSize)
{
    V pos = target->mXform->GetPos();
    cBox* bbox = target->GetBBox();
    V diff = bbox->max - bbox->min;
    if (!superSize) {
        diff *= 0.5f;
    } else {
        diff.z /= 2.0f;
    }
    diff.x = Max(diff.x, 2.5f);
    diff.y = Max(diff.y, 2.5f);
    diff.z = Max(diff.z, 4.0f);
    V min = pos - diff;
    V max = pos + diff;
    cBox resultBox(min, max);
    return resultBox;
}