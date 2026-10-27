/*
 * Libs/SFOLib/Source/man: 3 files, 00385130-00385230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00385130 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
#include "v4_asm_copy.h"

#pragma cplusplus on
#pragma inline_depth(8)
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
extern "C" V cMan_GetGun2ndHandOrient(Weapon* w)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00385130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00385130 */

/* merge_units: begin func_003851C0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char pad[0x170]; V4 a; char pad2[0x10]; V4 b; } O_3851C0;
typedef struct { char pad[0x2410]; O_3851C0* o; } S_3851C0;
static inline void Add3_(V4* a, V4* d, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
V4 cMan_GetGun2ndHand(S_3851C0* s) {
    V4 r;
    O_3851C0* o = s->o;
    if (o) {
        V4* pc = &r; V4* pd = &r; V4* pa = &r;
        VCopyF(pc, &o->a);
        Add3_(pa, pd, &s->o->b);
        return r;
    }
    { V4* z = &r; V4StoreZero(z); }
    return r;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003851C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003851C0 */

/* merge_units: begin func_00385230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * True when equipment slot 0 is occupied.
 */

#include "man_types.h"

int ActorModel_FindAttachedModel(ManEquipOwner* self) {
    return (unsigned int)self->slots[0] > 0u;
}
static inline void merge_flush_func_00385230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00385230 */
