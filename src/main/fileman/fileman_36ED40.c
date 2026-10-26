/*
 * main/fileman: 2 files, 0036ED40-0036EE10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036ED40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
static inline void QR_ED40(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MM_ED40(void* d, void* a, void* b) { __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
typedef struct Xform_ED40 {
    void* vt; char pad4[0xC];
    char world[0x40];
    char pad50[0x10];
    char local[0x40];
    struct Xform_ED40* parent;
} Xform_ED40;
extern "C" void Xform_ComputeWorld(Xform_ED40* x)
{
    if (x->parent) {
        MM_ED40(x->world, x->parent->world, x->local);
    } else {
        void* xx = x->world; /* dead on purpose: retail keeps this addiu */
        QR_ED40(x->world, x->local);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036ED40 */

/* merge_units: begin func_0036EE10 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void QR_EE10(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void MM_EE10(void* d, void* a, void* b) { __asm__ volatile("lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf11, 0x30(%2); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddaz.xyzw ACC, vf6, vf9z; vmaddw.xyzw vf13, vf7, vf9w; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddaz.xyzw ACC, vf6, vf10z; vmaddw.xyzw vf14, vf7, vf10w; vmulax.xyzw ACC, vf4, vf11x; vmadday.xyzw ACC, vf5, vf11y; vmaddaz.xyzw ACC, vf6, vf11z; vmaddw.xyzw vf15, vf7, vf11w; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
typedef struct Xform_EE10 {
    void* vt; char pad4[0xC];
    char world[0x40];
    unsigned char dirty; char pad51[0xF];
    char local[0x40];
    struct Xform_EE10* parent;
} Xform_EE10;
#if 0 /* merge_units */
extern "C" void Xform_ComputeWorld(Xform_EE10* x);
#endif /* merge_units */
#define Xform_ComputeWorld(a0) (Xform_ComputeWorld((Xform_ED40 *)(a0))) /* merge_units */

extern "C" void nMatrix_Multiply_NonTransposedMatrices(void* a, void* b, void* c);
extern "C" void func_0036F090(void* a, void* b, void* c);
extern "C" void Mtx_Copy_23E150(void* d, void* s);
extern "C" void Xform_EvalAncestors(Xform_EE10* x)
{
    if (x->dirty) {
        Xform_EE10* p = x->parent;
        if (p && p->dirty) {
            Xform_EE10* g = p->parent;
            if (g && g->dirty) {
                Xform_EE10* h = g->parent;
                if (h && h->dirty) {
                    if (h->parent) Xform_EvalAncestors(h->parent);
                    Xform_ComputeWorld(h);
                    h->dirty = 0;
                }
                if (g->parent) func_0036F090(g->world, g->local, g->parent->world);
                else Mtx_Copy_23E150(g->world, g->local);
                g->dirty = 0;
            }
            if (p->parent) nMatrix_Multiply_NonTransposedMatrices(p->world, p->local, p->parent->world);
            else {
                /* declaration order sets the copy registers */
                void* d = p->world;
                __int128 qa;
                __int128 qb;
                void* s = p->local;
                __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
            p->dirty = 0;
        }
        if (x->parent) {
            MM_EE10(x->world, x->parent->world, x->local);
        } else {
            void* xx = x->world; /* dead on purpose: retail keeps this addiu */
            QR_EE10(x->world, x->local);
        }
        x->dirty = 0;
    }
}
#undef Xform_ComputeWorld /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036EE10 */
