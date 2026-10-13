#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "pp_quad_copy.h"
typedef PPMtx M44;
/* GCC-style volatile asm quad copy: MW treats it as an opaque barrier, so the dead
   address local after it (xx) is neither CSE-merged nor removed by the peephole. */
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UnitMtx_630(void* m) { int t; void* p = m; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
static inline M44* Ident_630(M44* m) { UnitMtx_630(m); return m; }
static inline void VZero_630(void* v) {
    asm { sq zero, 0(v) }
}
typedef struct Node_3CD630 { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; } Node_3CD630;
struct Obj_3CD630 { char pad[0x54]; Node_3CD630* node; };
extern "C" {
void* Mem_Alloc(int, int, char*, int);
void Mtx_Copy(void*, void*);
void* Mtx_GetIdentity(void);
void* Vec4_GetZero(void);
void Vec4_Assign(void*, void*);
extern char D_004BD228[];
}

extern "C" void func_003CD630(Obj_3CD630* o_, M44* m_)
{
    Node_3CD630* n = o_->node;
    Obj_3CD630* o = o_; M44* m = m_;
    if (n == 0) {
        Node_3CD630* p;
        {
            AllocGuard g;
            p = (Node_3CD630*)Mem_Alloc(0, 0xB0, D_004BD228, 0x1F7);
        }
        if (p) {
            p->flag = 0;
            Mtx_Copy(&p->m, m);
            Mtx_Copy(&p->xf, Mtx_GetIdentity());
            Vec4_Assign(&p->v90, Vec4_GetZero());
            Vec4_Assign(&p->vA0, Vec4_GetZero());
        }
        o->node = p;
    } else {
        n->flag = 0;
        M44* d = &n->m;
        QR(d, m);
        void* xx = &n->xf; /* dead on purpose: retail keeps this addiu */
        Ident_630(&n->xf);
        VZero_630(&n->v90);
        VZero_630(&n->vA0);
    }
}







