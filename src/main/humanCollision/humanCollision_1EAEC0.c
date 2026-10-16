typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct F1 { unsigned char v; } F1;
typedef struct EA { V4 a; V4 b; V4 c; F1 f; float g; V4 d; V4 e; } EA;
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
EA* func_001EAEC0(EA* d, const EA* s)
{
    V4_Copy(&d->a, &s->a);
    V4_Copy(&d->b, &s->b);
    V4_Copy(&d->c, &s->c);
    d->f = s->f;
    d->g = s->g;
    V4_Copy(&d->d, &s->d);
    V4_Copy(&d->e, &s->e);
    return d;
}

