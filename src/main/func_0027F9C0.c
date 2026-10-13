/* Scale writes the result through a GCC-style quad copy with a "+r" destination operand (register choice as retail). */
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(s) : "memory"); }
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline float Dot3(const V4* a, const V4* b)
{
    int rv0;
    float ret;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
static inline void Scale(V4* out, const V4* b, float s)
{
    int t;
    V4 r;
    V4* pr = &r;
asm {
        .set noreorder
        lqc2 vf1, 0x0(b)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
    GQ(out, pr);
}
static inline V4* SubEq(V4* a, const V4* b)
{
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
    return a;
}
#pragma peephole off
#pragma opt_common_subs off
V4* func_0027F9C0(V4* a, const V4* b)
{
    float w = a->w;
    float d = Dot3(a, b);
    V4 t;
    Scale(&t, b, d);
    SubEq(a, &t);
    a->w = w;
    return a;
}

