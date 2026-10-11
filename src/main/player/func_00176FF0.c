#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { char p0[0x10]; V4 a; V4 b; char p1[0x10]; V4 c; char p2[0x10]; V4 d; char p3[0x10]; V4 e; } O_6FF0;
#define ADD1(D) { V4* d_ = D; asm { lqc2 vf1, 0x0(d_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#define ADD2(D) { V4* d_; V4* e_; e_ = D; d_ = D; asm { lqc2 vf1, 0x0(e_); lqc2 vf2, 0x0(v); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void func_00176FF0(O_6FF0* o, V4* v) {
    ADD1(&o->a)
    ADD2(&o->b)
    ADD2(&o->c)
    ADD1(&o->d)
    ADD1(&o->e)
}
#pragma pop