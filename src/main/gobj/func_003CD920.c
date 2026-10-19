#pragma cplusplus on
#include "types.h"
#include "vslot_classes.h"
#include "v4_asm_copy.h"

/* GCC-style volatile asm quad copy: MW treats it as an opaque barrier, so the dead
   address local after it (xx) is neither CSE-merged nor removed by the peephole. */
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* m) { int t; void* p = m; asm { .set noreorder; sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p); .set reorder } }
struct V4_920 { int x, y, z, w; V4_920(int a, int b, int c, int d) : x(a), y(b), z(c), w(d) {} };
class Recv_920 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(const V4_920*);
};
typedef struct Node_920 { unsigned char flag; char pad[15]; char m[0x40]; char xf[0x40]; __int128 v90; __int128 vA0; } Node_920;
typedef struct Xf_920 { void* vt; char pad[0xC]; char m[0x40]; unsigned char dirty; } Xf_920;
extern "C" { extern signed char D_004E1D88; extern V4_920 D_004E1D90; }
struct Obj_920 { char pad[0x50]; Xf_920* xf; Node_920* node; Recv_920* recv; };

extern "C" void cNode_v2A(Obj_920* o)
{
    if (o->xf) {
        ((VSlots67*)o->xf)->slot2();
        if (o->node) {
            Xf_920* x = o->xf;
            if (x) {
                if (x->dirty)
                    ((VSlots67*)x)->slot20();
                Node_920* n; void* s; s = x->m; n = o->node; n->flag = 0; void* d = n->m; QR(d, s);
                void* xx = n->xf; /* dead on purpose: retail keeps this addiu */
                UM(n->xf); V4StoreZero(&n->v90); V4StoreZero(&n->vA0);
            }
        }
        if (!D_004E1D88) { D_004E1D88 = 1; D_004E1D90.x = 0; D_004E1D90.y = 0; D_004E1D90.z = 0; D_004E1D90.w = 0; }
        Recv_920* r = o->recv; const V4_920* z = &D_004E1D90;
        if (r) r->s18(z);
    }
}



