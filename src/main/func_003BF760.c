#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } Mtx;
typedef struct { int cap; int n; } VecE;
extern void* func_003C0200(VecE* v, int index);
extern void* Ptr_Identity(void* p);
extern V4* Array16_At(void* base, int i);
extern V4* Vec4_Copy(V4* d, V4* s);
extern V4 Mtx_MulVec4(V4* vp, Mtx* m);
extern int func_003C01E0(V4* p, float x);
extern void func_003BFAB0(void* e, VecE* v, int i, float f, V4* t);
extern void func_003BF900(void* e, V4* t);
#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_003BF760(VecE* v, Mtx* mtx, float f) {
    int i;
    for (i = v->n - 1; i >= 0; i--) {
        Mtx m;
        void* e;
        V4 t[3];
        V4 r0;
        V4 r1;
        V4 r2;
        Mtx* pm;
        Mtx* d;
        __int128 qa;
        __int128 qb;
        d = &m;
        asm { .set reorder; lq qa, 0x0(mtx); lq qb, 0x10(mtx); sq qa, 0x0(d); lq qa, 0x20(mtx); sq qb, 0x10(d); lq qb, 0x30(mtx); sq qa, 0x20(d); sq qb, 0x30(d) }
        pm = &m;
        e = func_003C0200(v, i);
        Ptr_Identity(&t[0]);
        Ptr_Identity(&t[1]);
        Ptr_Identity(&t[2]);
        r0 = Mtx_MulVec4(Array16_At(e, 0), pm);
        Vec4_Copy(&t[0], &r0);
        r1 = Mtx_MulVec4(Array16_At(e, 1), pm);
        Vec4_Copy(&t[1], &r1);
        r2 = Mtx_MulVec4(Array16_At(e, 2), pm);
        Vec4_Copy(&t[2], &r2);
        if (func_003C01E0(&t[0], f) || func_003C01E0(&t[1], f) || func_003C01E0(&t[2], f)) {
            func_003BFAB0(e, v, i, f, t);
        } else {
            func_003BF900(e, t);
        }
    }
}
