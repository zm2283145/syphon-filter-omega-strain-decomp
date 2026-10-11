#ifndef COPY_ASSIGN_RET_H
#define COPY_ASSIGN_RET_H
/* Member-wise copy assignment whose 16-byte members have an inline operator=
 * returning this. Retail keeps each dead return value (addiu v0, d, off).
 * Assign every result to one `void* r` and finish with `r = d; return r;` under
 * #pragma peephole off / opt_dead_assignments off / opt_propagation off /
 * opt_common_subs off (vc1, 003E5E40 family). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) CAQ4;
static inline void* CAQ4Asg(void* d, const void* s) { *(CAQ4*)d = *(const CAQ4*)s; return d; }
#endif