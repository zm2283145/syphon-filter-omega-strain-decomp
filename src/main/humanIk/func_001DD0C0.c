/* Bounded push of a SegPair into a 6-entry list; member-wise copies (pointer-temp placement steers mw38 coloring). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
typedef struct SegList { unsigned int n; SegPair e[6]; } SegList;
#pragma peephole off
#pragma opt_propagation off
void func_001DD0C0(SegList* l, const SegPair* s)
{
    if (l->n < 6) {
        SegPair* e;
        V4* dbq;
        const V4* sbq;
        V4* daq;
        const V4* saq;
        V4* dbp;
        const V4* sbp;
        e = &l->e[l->n];
        asm { .set reorder } /* scheduling barrier */
        e->a.p = s->a.p;
        daq = &e->a.q;
        saq = &s->a.q;
        *daq = *saq;
        dbp = &e->b.p;
        sbp = &s->b.p;
        e->a.f = s->a.f;
        dbq = &e->b.q;
        sbq = &s->b.q;
        *dbp = *sbp;
        *dbq = *sbq;
        e->b.f = s->b.f;
        l->n++;
    }
}

