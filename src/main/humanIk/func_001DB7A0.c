/* func_001DB7A0 (humanIk, mw38): map<IkBytePair,SegPair>::insert(make_pair(*k,*v)).second.
   Inlined SegPair copy via volatile lq/sq asm + a dead address local. */
typedef struct { __int128 a; __int128 b; signed char f; } Seg;
typedef struct { Seg s0; Seg s1; } SegPair;
typedef struct { signed char a; signed char b; } IkBytePair;
typedef struct { IkBytePair bp; SegPair sp; } IkPose;
typedef struct { void* node; unsigned char inserted; } InsRes;
void func_001DB8C0(IkPose* d, IkBytePair bp, SegPair* s);
void func_001DB8A0(IkBytePair* d, IkBytePair* s);
void func_001DB850(SegPair* d, SegPair* s);
void func_001DF650(InsRes* out, void* t, IkPose* k);
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s) : "memory"); return q; }
static inline void GS(void* d, __int128 q) { __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(d) : "memory"); }
#pragma peephole off
unsigned char func_001DB7A0(void* m, IkBytePair* k, SegPair* v)
{
    InsRes r;
    IkPose p2;
    IkPose p1;
    SegPair tmp;
    void* d0;
    __int128 q0;
    void* x1;
    d0 = &tmp.s0.a;
    q0 = GL(&v->s0.a);
    x1 = &tmp; /* dead */
    GS(d0, q0);
    GQ(&tmp.s0.b, &v->s0.b);
    tmp.s0.f = v->s0.f;
    GQ(&tmp.s1.a, &v->s1.a);
    GQ(&tmp.s1.b, &v->s1.b);
    tmp.s1.f = v->s1.f;
    func_001DB8C0(&p1, *k, &tmp);
    func_001DB8A0(&p2.bp, &p1.bp);
    func_001DB850(&p2.sp, &p1.sp);
    func_001DF650(&r, m, &p2);
    return r.inserted;
}

