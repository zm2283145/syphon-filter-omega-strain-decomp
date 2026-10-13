/* GCC-style VU0 asm (operand form) lets MW schedule the p->x/y/z loads in retail order. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline float Dot3(const V4* a, const V4* b)
{
    int rv0;
    float ret;
    __asm__ volatile("lqc2 vf1, 0x0(%2); lqc2 vf2, 0x0(%3); vmul.xyzw vf3, vf1, vf2; mtsah zero, 0x6; vmulax.w ACC, vf0, vf3x; vmadday.w ACC, vf0, vf3y; vmaddz.w vf4, vf0, vf3z; qmfc2.ni %0, vf4; qfsrv %0, %0, %0; mtc1 %0, %1" : "=&r"(rv0), "=f"(ret) : "r"(a), "r"(b) : "memory");
    return ret;
}
static inline void MK(V4* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
#pragma peephole off
#pragma opt_propagation off
void func_003E5E80(V4* out, const V4* n, const V4* p)
{
    V4 t;
    float d = Dot3(p, n);
    MK(&t, p->x, p->y, p->z, -d);
    *out = t;
}

