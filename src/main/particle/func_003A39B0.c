/* func_003A39B0 (particle, mw38): copy two V4s and a {xyz,(float)count} V4 into a particle emitter.
   GCC-style volatile lq/sq copy + dead address locals give retail's duplicate addius (LESSONS c57da). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { float x, y, z; } V3;
typedef struct P39 { char pad0[0x900]; V4 m900; char pad910[0x40]; V4 m950; V4 m960; char pad970[0xCC]; unsigned int nA3C; } P39;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline V4* VA(V4* d, const V4* s) { GQ(d, s); return d; }
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
void func_003A39B0(P39* p, const V4* a, const V4* b, const V3* c)
{
    V4 t;
    void* xx;
    void* yy;
    VA(&p->m900, a);
    xx = &p->m950; /* dead on purpose */
    VA(&p->m950, b);
    MK(&t, c->x, c->y, c->z, (float)p->nA3C);
    yy = &p->m960; /* dead on purpose */
    VA(&p->m960, &t);
}

