#ifndef VU0_ADDEQ_H
#define VU0_ADDEQ_H
/* *D += *P with VU0 (lqc2/vadd.xyzw/sqc2), each operand in its own pointer
 * local so retail's per-use addiu survives. Use under #pragma peephole off,
 * opt_propagation off, opt_common_subs off (vc1, 00176FF0 family).
 * ADDEQ1: one pointer for load and store; ADDEQ2: separate load/store pointers;
 * ADDEQ3: like ADDEQ2 plus a recomputed pointer for P. P in 1/2 must be a variable. */
#define VU0_ADDEQ1(T, D, P) { T* d_ = D; asm { lqc2 vf1, 0x0(d_); lqc2 vf2, 0x0(P); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#define VU0_ADDEQ2(T, D, P) { T* d_; T* e_; d_ = D; e_ = D; asm { lqc2 vf1, 0x0(e_); lqc2 vf2, 0x0(P); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#define VU0_ADDEQ3(T, D, P) { T* d_; T* e_; T* p_; d_ = D; e_ = D; p_ = P; asm { lqc2 vf1, 0x0(e_); lqc2 vf2, 0x0(p_); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(d_) } }
#endif