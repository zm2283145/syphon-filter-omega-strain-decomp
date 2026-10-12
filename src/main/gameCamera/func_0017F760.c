/* func_0017F760: sub-object ctor (2 x {V4 p,q}) filled from two by-pointer V4s. Hand-matched (auto1 family seed).
 * The empty asm block is a scheduling barrier reproducing retail order. */
#pragma cplusplus on
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct V4_F5E0 { float x, y, z, w; } __attribute__((aligned(16)));
struct E_F5E0 { V4_F5E0 p; V4_F5E0 q; E_F5E0() {} };
struct M_F5E0 { E_F5E0 e[2]; };
#pragma opt_rotateloops off
#pragma opt_unroll_loops off
extern "C" M_F5E0* func_0017F760(M_F5E0* m, const V4_F5E0* a, const V4_F5E0* b)
{
    V4_F5E0 tb; V4_F5E0 ta;
    V4_F5E0* pa; E_F5E0* pe; V4_F5E0* pb;
    pa = &ta;
    VCopyF(pa, a);
    pb = &tb;
    asm { .set noreorder; .set reorder }
    pe = m->e;
    VCopyF(pb, b);
    do { new (pe) E_F5E0; } while (++pe != m->e + 2);
    {
    int i = 0;
    while (i <= 1) {
        E_F5E0* e = &m->e[i++];
        VCopyF(&e->p, &ta);
        VCopyF(&e->q, &tb);
    }
    }
    return m;
}
