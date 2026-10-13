/* SegPair from two Segs: member-wise copies; pointer-temp placement steers mw38 register coloring. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
#pragma peephole off
#pragma opt_propagation off
SegPair* func_001DBAD0(SegPair* d, const Seg* a, const Seg* b)
{
    const V4* sbq;
    V4* daq;
    V4* dbp;
    V4* dbq;
    const V4* saq;
    d->a.p = a->p;
    daq = &d->a.q;
    dbp = &d->b.p;
    dbq = &d->b.q;
    saq = &a->q;
    *daq = *saq;
    sbq = &b->q;
    d->a.f = a->f;
    *dbp = b->p;
    *dbq = *sbq;
    d->b.f = b->f;
    return d;
}

