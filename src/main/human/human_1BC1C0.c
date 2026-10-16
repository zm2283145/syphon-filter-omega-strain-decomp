/*
 * main/human: range (2 files, 001BC1C0-001BC280)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001BC1C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& o) { V4* pd = this; const V4* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V4& operator=(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct R { char pad[0x80]; V4 q; char pad90[0x12]; unsigned char dirty; char padA3[0xD]; void* parent; };
extern "C" {
void* Root_GetParent(R*);
void* Root_GetWorldPlacement(void*);
V4* Placement_GetQuat(void*);
V4* Quat_Assign(V4*, V4*);
V4* func_0019D4E0(V4*);
}
static inline V4 QMul(const V4& a, const V4& b)
{
    V4 r;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%1)" : : "r"(&a), "r"(&r), "r"(&b) : "memory");
    return r;
}
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
#pragma peephole off
#pragma opt_propagation off
extern "C" void SceneRoot_SetPoseCacheRot(R* self, V4* q)
{
    V4 t;
    self->q = *q;
    if (self->parent) {
        Quat_Assign(&t, Placement_GetQuat(Root_GetWorldPlacement(Root_GetParent(self))));
        func_0019D4E0(&t);
        { V4* pt = &t; V4* pq = &self->q; *pq = QMul(*pt, *pq); }
    }
    self->dirty = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BC1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BC1C0 */

/* merge_units: begin func_001BC280 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
V4 Quat_Conjugate(V4 v) {
    V4* p = &v;
    asm {
        
        lqc2 vf1, 0x0(p)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(p)
        
    }
    return *p;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BC280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BC280 */
