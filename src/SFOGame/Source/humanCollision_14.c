/*
 * SFOGame/Source/humanCollision: 1 file, 001E54D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E54D0 */
#pragma push /* merge_units */
/* RayProbe implicit operator=: V members via asm lq/sq op=, the POD 16-aligned pair at 0x30 copied by the compiler (lq/sq). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct P { float a, b; } __attribute__((aligned(16)));
struct S {
    signed char a;
    V v10;
    V v20;
    P v30;
    V v40;
    V v50;
    unsigned char c60;
    unsigned char c61;
    unsigned char c62;
    int i64;
};
extern "C" S* cCollisionProbe_Ray_opAssign(S* d, const S* s)
{
    *d = *s; return d;
}
static inline void merge_flush_func_001E54D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E54D0 */
