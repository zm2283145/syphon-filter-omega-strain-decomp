#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"

struct V_3C1 {
    float x, y, z, w;
    V_3C1() {}
    // 128-bit lq/sq quadword copy idiom
    // (dead xx local reproduces retail's duplicated addiu of the destination)
    V_3C1& operator=(const V_3C1& o) { V_3C1* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Tri_3C1 { V_3C1 p0; V_3C1 p1; V_3C1 p2; V_3C1 n; char pad40[0x30]; };
struct It_3C1 {
    Tri_3C1* p;
    It_3C1() {}
    It_3C1(const It_3C1& o) : p(o.p) {}
    Tri_3C1* Get() const { return p; }
    bool operator==(const It_3C1& o) const { return Get() == o.Get(); }
    bool operator!=(const It_3C1& o) const { return !(*this == o); }
    Tri_3C1* Next() { Tri_3C1* r = p; p++; return r; }
};
struct Gath;
struct Scene_3C1;
extern "C" Tri_3C1** std_vector_deleter_cCollisionFace_data_void_2(Scene_3C1* s);
struct Scene_3C1 {
    int cap;
    int count;
    Tri_3C1* data;
    It_3C1 Begin() { It_3C1 r; r.p = *std_vector_deleter_cCollisionFace_data_void_2(this); return r; }
    It_3C1 End() { It_3C1 r; r.p = *std_vector_deleter_cCollisionFace_data_void_2(this) + count; return r; }
};
// VU0 macro-mode: load triangle corners + scale into a fixed vf register group
#define LOADTRI(t, S) { int tmp; __asm__ volatile(S : "=&r"(tmp) : "r"(&t->p0), "r"(&t->p1), "r"(&t->p2), "f"(t->n.w) : "memory"); }

extern "C" void cCollisionModelList_CalculateFaceNormals(Gath* self, Scene_3C1* scene)
{
    It_3C1 it = scene->Begin();
    It_3C1 end = scene->End();
    V_3C1 n0;
    V_3C1 n1;
    V_3C1 n2;
    V_3C1 n3;
    // VU0 macro-mode: clear w of the normal accumulators
    __asm__ volatile("vmulx.w $vf25, $vf0, $vf0x; vmulx.w $vf26, $vf0, $vf0x; vmulx.w $vf27, $vf0, $vf0x; vmulx.w $vf28, $vf0, $vf0x");
    while (it != end) {
        Tri_3C1* t0 = it.Next();
        LOADTRI(t0, "lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); lqc2 $vf3, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf4");
        if (it != end) {
            Tri_3C1* t1 = it.Next();
            LOADTRI(t1, "lqc2 $vf5, 0x0(%1); lqc2 $vf6, 0x0(%2); lqc2 $vf7, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf8");
            if (it != end) {
                Tri_3C1* t2 = it.Next();
                LOADTRI(t2, "lqc2 $vf9, 0x0(%1); lqc2 $vf10, 0x0(%2); lqc2 $vf11, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf12");
                if (it != end) {
                    Tri_3C1* t3 = it.Next();
                    LOADTRI(t3, "lqc2 $vf13, 0x0(%1); lqc2 $vf14, 0x0(%2); lqc2 $vf15, 0x0(%3); mfc1 %0, %4; qmtc2.ni %0, $vf16");
                    // VU0 macro-mode: four cross products scaled by w
                    __asm__ volatile(
                        "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vsub.xyzw $vf21, $vf10, $vf9; vsub.xyzw $vf22, $vf11, $vf9; vsub.xyzw $vf23, $vf14, $vf13; vsub.xyzw $vf24, $vf15, $vf13; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vopmula.xyz $ACC, $vf21, $vf22; vopmsub.xyz $vf27, $vf22, $vf21; vopmula.xyz $ACC, $vf23, $vf24; vopmsub.xyz $vf28, $vf24, $vf23; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; vmulx.xyz $vf27, $vf27, $vf12x; vmulx.xyz $vf28, $vf28, $vf16x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1); sqc2 $vf27, 0x0(%2); sqc2 $vf28, 0x0(%3)"
                        : : "r"(&n0), "r"(&n1), "r"(&n2), "r"(&n3) : "memory");
                    t3->n = n3;
                } else {
                    // VU0 macro-mode: three cross products scaled by w
                    __asm__ volatile(
                        "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vsub.xyzw $vf21, $vf10, $vf9; vsub.xyzw $vf22, $vf11, $vf9; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vopmula.xyz $ACC, $vf21, $vf22; vopmsub.xyz $vf27, $vf22, $vf21; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; vmulx.xyz $vf27, $vf27, $vf12x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1); sqc2 $vf27, 0x0(%2)"
                        : : "r"(&n0), "r"(&n1), "r"(&n2) : "memory");
                }
                t2->n = n2;
            } else {
                // VU0 macro-mode: two cross products scaled by w
                __asm__ volatile(
                    "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vsub.xyzw $vf19, $vf6, $vf5; vsub.xyzw $vf20, $vf7, $vf5; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vopmula.xyz $ACC, $vf19, $vf20; vopmsub.xyz $vf26, $vf20, $vf19; vmulx.xyz $vf25, $vf25, $vf4x; vmulx.xyz $vf26, $vf26, $vf8x; sqc2 $vf25, 0x0(%0); sqc2 $vf26, 0x0(%1)"
                    : : "r"(&n0), "r"(&n1) : "memory");
            }
            t1->n = n1;
        } else {
            // VU0 macro-mode: one cross product scaled by w
            __asm__ volatile(
                "vsub.xyzw $vf17, $vf2, $vf1; vsub.xyzw $vf18, $vf3, $vf1; vopmula.xyz $ACC, $vf17, $vf18; vopmsub.xyz $vf25, $vf18, $vf17; vmulx.xyz $vf25, $vf25, $vf4x; sqc2 $vf25, 0x0(%0)"
                : : "r"(&n0) : "memory");
        }
        t0->n = n0;
    }
}
