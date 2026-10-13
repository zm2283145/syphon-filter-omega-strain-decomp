/* func_001DB8C0 (humanIk, mw38): IkPose ctor - byte pair + SegPair copy.
   Volatile lq/sq asm copies + dead address locals reproduce retail's duplicate addius. */
typedef struct { __int128 a; __int128 b; signed char f; } Seg;
typedef struct { Seg s0; Seg s1; } SegPair;
typedef struct { signed char a; signed char b; } IkBytePair;
typedef struct { IkBytePair bp; SegPair sp; } IkPose;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s) : "memory"); return q; }
static inline void GS(void* d, __int128 q) { __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(d) : "memory"); }
#pragma peephole off
void func_001DB8C0(IkPose* d, IkBytePair bp, SegPair* s)
{
    void* d0;
    __int128 q0;
    void *x1, *x2, *x3, *x4, *x5;
    d0 = &d->sp.s0.a;
    d->bp.a = bp.a;
    d->bp.b = bp.b;
    q0 = GL(&s->s0.a);
    x1 = &d->sp; /* dead */
    x2 = &d->sp.s0; /* dead */
    x3 = &d->sp.s1; /* dead */
    x4 = &d->sp.s1; /* dead */
    x5 = &d->sp; /* dead */
    GS(d0, q0);
    GQ(&d->sp.s0.b, &s->s0.b);
    d->sp.s0.f = s->s0.f;
    GQ(&d->sp.s1.a, &s->s1.a);
    GQ(&d->sp.s1.b, &s->s1.b);
    d->sp.s1.f = s->s1.f;
}

