#pragma opt_strength_reduction off

#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" void AnimChannel_SetDirect(void* self, int i, float v);

struct ChanInit {
    signed char ch;
    float v;
    ChanInit() {}
    void Set(signed char c, float f) { ch = c; v = f; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ChanInit() {}
};

struct Chan {
    unsigned char ch;
    float v;
    Chan() : ch(0x17), v(0.0f) {}
};

struct ChanList {
    unsigned int n;
    Chan e[23];
    ChanList() : n(0) {}
    ChanList& Add(const ChanInit& x) {
        if (n < 23) {
            Chan& d = e[n];
            d.ch = x.ch;
            d.v = x.v;
            n++;
        }
        return *this;
    }
};

struct ActorAnim { char pad[0x10]; char chan[1]; };
struct Actor_8CAF0 { char pad[0x2EC0]; ActorAnim anim; };

extern "C" void Actor_ResetAnimChannels(Actor_8CAF0* a)
{
    ActorAnim* an = &a->anim;
    ChanList l;
    int i;
    ChanInit c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22;
    c22.Set(22, 0.5f);
    c21.Set(21, 1.0f);
    c20.Set(20, 0.0f);
    c19.Set(19, 0.0f);
    c18.Set(18, 0.0f);
    c17.Set(17, 0.5f);
    c16.Set(16, 0.5f);
    c15.Set(15, 0.5f);
    c14.Set(14, 0.5f);
    c13.Set(13, 0.0f);
    c12.Set(12, 0.0f);
    c11.Set(11, 0.0f);
    c10.Set(10, 0.0f);
    c9.Set(9, 0.5f);
    c8.Set(8, 0.0f);
    c7.Set(7, 0.0f);
    c6.Set(6, 0.5f);
    c5.Set(5, 0.5f);
    c4.Set(4, 0.0f);
    c3.Set(3, 0.0f);
    c2.Set(2, 0.0f);
    c1.Set(1, 0.5f);
    c0.Set(0, 0.5f);
    l.Add(c0).Add(c1).Add(c2).Add(c3).Add(c4).Add(c5).Add(c6).Add(c7).Add(c8).Add(c9).Add(c10).Add(c11).Add(c12).Add(c13).Add(c14).Add(c15).Add(c16).Add(c17).Add(c18).Add(c19).Add(c20).Add(c21).Add(c22);
    for (i = 0; i < 23; i++)
    {
        Chan& c = l.e[i];
        AnimChannel_SetDirect(an->chan, c.ch, c.v);
    }
}
