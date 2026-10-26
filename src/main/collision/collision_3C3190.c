/*
 * main/collision: range (2 files, 003C3190-003C3220)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop

/* merge_units: begin func_003C3190 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_RESIZE_ELEMENT(Elem96_3190, 96)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(std_vector_imp_cCollisionEdge_resize, Elem96_3190, std_vector_imp_cCollisionEdge_insert, std_vector_imp_cCollisionEdge_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_003C3190 */

/* merge_units: begin func_003C3220 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies, sq zero and VU0 math as GCC-style volatile asm; the unused xx locals keep retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float& X() { return x; }
    float& Y() { return y; }
    float& Z() { return z; }
    void Clear() { __asm__ volatile("sq $0, 0x0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M { V a, b, c, d; };
extern "C" void Ptr_Identity(void* p);
static inline void Xform(V* d, const V* s, const M* m) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(d), "r"(m), "r"(s) : "memory"); }
static inline void Fix(V& v, const M& m) { v.X() *= v.Y(); v.Z() *= v.Y(); Xform(&v, &v, &m); }
struct CQ {
    unsigned char b0; char pad1[0xF];
    V v10; V v20; V v30; V v40; V v50; V v60; V v70; V v80;
    char pad90[0x40];
    int xD0; char padD4[0x45];
    unsigned char b119; unsigned char b11A; char pad11B[5];
    M m120;
};
struct PV { float x, y, z, w; } __attribute__((aligned(16)));
struct ATri {
    PV v[3];
    V n;
    char x40[0x20];
    char x60[0x10];
    ATri(V* src);
};
extern "C" {
unsigned char ColQuery_ExecuteMoving(CQ* q, int a, int b);
unsigned char ColQuery_ExecuteStatic(CQ* q, int a, int b);
void cCollisionModel_FaceProperties_ctor(void* p);
void cCollisionModel_FaceLocator_ctor(void* p);
void Col_ReconstructSourceTriangle(ATri* t, V* src);
}
inline ATri::ATri(V* src) { ATri* p = this; PV* it = p->v; do { Ptr_Identity(it); it++; } while (it != p->v + 3); Ptr_Identity(&p->n); cCollisionModel_FaceProperties_ctor(p->x40); cCollisionModel_FaceLocator_ctor(p->x60); Col_ReconstructSourceTriangle(p, src); }
extern "C" unsigned char ColQuery_ExecuteSweep(CQ* q, int a, int b)
{
    unsigned char hit;
    if (q->xD0) {
    if (q->b119) hit = ColQuery_ExecuteMoving(q, a, b);
    else hit = ColQuery_ExecuteStatic(q, a, b);
    if (hit) {
        q->v20 = q->v10;
        q->v50 = q->v40;
    }
    q->v80 = q->v70;
    if (q->b11A) {
        if (hit) {
            q->v20.Clear();
            Fix(q->v50, q->m120);
        }
        Fix(q->v80, q->m120);
    }
    if (hit) {
        if (q->b0 == 1) q->v30 = q->v20;
        else {
            ATri t(&q->v60);
            const V& r = t.n;
            q->v30 = r;
        }
    }
    } else hit = 0;
    return hit;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3220(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3220 */
