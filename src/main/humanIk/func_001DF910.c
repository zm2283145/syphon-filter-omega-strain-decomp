typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
typedef struct IkBytePair { signed char a; signed char b; } IkBytePair;
typedef struct IkPose { IkBytePair bp; SegPair sp; } IkPose;
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
IkPose* std_pair_cWeaponSlotPair_cIkTarget_LeftRight_ctor_pairR_2(IkPose* d, const IkPose* s)
{
    V4* dp = &d->sp.a.p;
    d->bp.a = s->bp.a;
    d->bp.b = s->bp.b;
    V4_Copy(dp, &s->sp.a.p);
    V4_Copy(&d->sp.a.q, &s->sp.a.q);
    d->sp.a.f = s->sp.a.f;
    V4_Copy(&d->sp.b.p, &s->sp.b.p);
    V4_Copy(&d->sp.b.q, &s->sp.b.q);
    d->sp.b.f = s->sp.b.f;
    return d;
}
