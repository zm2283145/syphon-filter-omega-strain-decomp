/* First quad copy uses a "+r" destination operand (G1) so the dest gets t0 and q gets v1 as in retail. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { float x, y, z; } V3;
typedef struct P3E { char pad0[0x60]; unsigned int n60; char pad64[0x8FC]; V4 m960; V4 m970; V4 m980; } P3E;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void G1(void* d, const void* s) { __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(s) : "memory"); }
static inline V4* VA(V4* d, const V4* s) { GQ(d, s); return d; }
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
void func_003A3EF0(P3E* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    G1(&p->m960, b);
    MK(&t, c->x, c->y, c->z, (float)p->n60);
    xx = &p->m970; /* dead on purpose */
    yy = &p->m980; /* dead on purpose */
    VA(&p->m970, &t);
    VA(&p->m980, a);
}

