#pragma cplusplus on
#include "types.h"
struct V4 {
    __int128 q;
    V4() {}
};
struct Scr {
    char pad[0x100];
    V4 last;
    unsigned char have;
};
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void func_0045BF80(Scr* s);
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void func_0045BD30(Scr* s, V4* p)
{
    if (!s->have) {
        GQ(&s->last, p);
        s->have = 1;
        return;
    }
    {
        V4 d;
        V4 r;
        float ret;
        {
            V4* pr = &r; V4* pa = &s->last;
            asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(p); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
        }
        {
V4* dd; V4* ss; int t; __int128 x; V4* pv;
ss = &r; pv = &d; asm { mtc1 $zero, ret } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
            asm {
                lqc2 vf1, 0(pv)
                vmul.xyz vf2, vf1, vf1
                vmulax.w ACC, vf0, vf2x
                vmadday.w ACC, vf0, vf2y
                vmaddz.w vf3, vf0, vf2z
                vsqrt Q, vf3w
                vwaitq
                vaddq.x vf4, vf0, Q
                qmfc2.ni t, vf4
                mtc1 t, ret
            }
        }
        if (!(ret <= 3.0f))
            func_0045BF80(s);
    }
}

