#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void QEB80(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ QEB80(this, &o); }
    V& operator+=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%0); lqc2 vf2, 0x0(%1); vadd.xyz vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Xform {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void SetPos(V p); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0x3C];
    V pos;
    unsigned char dirty;
    V GetPos() { if (dirty) Update(); const V& p = pos; return p; }
};
extern "C" void Xform_Translate(Xform* x, const V* d)
{
    x->SetPos(x->GetPos() += *d);
}


