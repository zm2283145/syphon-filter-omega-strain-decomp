typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct S { V4 a; V4 b; V4 c; V4 d; V4 e; unsigned char f; unsigned char g; unsigned char h; V4 i; } S;
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
S* func_0013B0E0(S* d, const S* s)
{
    V4_Copy(&d->a, &s->a);
    V4_Copy(&d->b, &s->b);
    V4_Copy(&d->c, &s->c);
    V4_Copy(&d->d, &s->d);
    d->f = s->f;
    V4_Copy(&d->e, &s->e);
    V4_Copy(&d->i, &s->i);
    d->g = s->g;
    d->h = s->h;
    return d;
}


