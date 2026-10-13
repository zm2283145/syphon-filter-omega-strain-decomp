#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
static inline void Q5130(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ Q5130(this, &o); }
    V& operator=(const V& o) { V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o)); void* xx = this; /* dead */ __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
    void SetUnit() { __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(this) : "memory"); }
    int IsZero() const {
        int k, f, r = 0;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            vaddx.xyzw vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xF
            vnop
            vnop
            vnop
            vnop
            cfc2.ni f, vi17
            bne k, f, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return (unsigned char)r;
    }
} __attribute__((aligned(16)));
struct Muzzle { char pad[0x180]; V v; };
struct Weapon { char pad[0x2410]; Muzzle* muzzle; };
extern "C" V func_00385130(Weapon* w)
{
    V v;
    if (w->muzzle) {
        v = w->muzzle->v;
        if (v.IsZero()) v.SetUnit();
    } else {
        v.SetUnit();
    }
    return v;
}



