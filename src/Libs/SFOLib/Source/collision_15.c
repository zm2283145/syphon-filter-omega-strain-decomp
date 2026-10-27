/*
 * Libs/SFOLib/Source/collision: 3 files, 003C13A0-003C14D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C13A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* std_vector_deleter_cCollisionFace_data_void_2(char* self) {
    return self + 8;
}

void* cCollisionEdge_Vertex1(char* self) {
    return self + 16;
}
static inline void merge_flush_func_003C13A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C13A0 */

/* merge_units: begin func_003C13C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* VU0 ops as GCC-style asm; `.set noreorder` drops the assembler mfc1 hazard nop (retail has none).
   Dead `x1`/`x2` address locals give retail's dead addiu before the named-local copies. */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
extern "C" float GetDistanceSquaredPointToLine(const V* a, const V* b, const V* dir);
float GetDistanceSquaredPointToLine(const V* a, const V* b, const V* dir)
{
    V d1 = *a - *b;
    void* x1 = &d1;
    float t = d1.Dot(*dir);
    V c = *b + *dir * t;
    void* x2 = &c;
    return (*a - c).LenSq();
}
static inline void merge_flush_func_003C13C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C13C0 */

/* merge_units: begin func_003C14D0 */
#pragma push /* merge_units */
void* cCollisionEdge_UnitEdgeVector(char* self) {
    return self + 64;
}

void* cCollisionEdge_Vertex0(void* self) {
    return self;
}
static inline void merge_flush_func_003C14D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C14D0 */
