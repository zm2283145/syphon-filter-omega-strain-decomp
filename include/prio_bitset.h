#ifndef PRIO_BITSET_H
#define PRIO_BITSET_H
/* Priority bitset { int top; int w[W]; }: set/reset/test bits, track highest set bit in top. */
#define PB_DEFINE(T, W) \
typedef struct { int top; int w[W]; } T; \
static inline void T##_Set(T* p, int i) { p->w[i / 32] |= 1 << (i & 31); } \
static inline void T##_Clr(T* p, unsigned int i) { p->w[(int)i / 32] &= ~(1 << (i & 31)); } \
static inline unsigned char T##_Test(T* p, int i) { return ((p->w[i / 32] >> (i & 31)) & 1) != 0; }
/* recompute top: highest set bit below N, or -1 (needs #pragma opt_rotateloops off) */
#define PB_FIND_TOP(T, p, i, N) \
    for (i = (N) - 1; i >= 0 && !T##_Test(p, i); i--) ; \
    if (!T##_Test(p, i)) (p)->top = -1; else (p)->top = i;
#endif