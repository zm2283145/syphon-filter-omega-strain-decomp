/* RootCollection_Reset (ska.cc): reset every root entry's accumulation state.
 * The asm zero stores (VZeroF) keep the iterators in stack slots like retail. */
#include "types.h"
#include "vc_copy.h"
#pragma cplusplus on
#pragma bool on
typedef int Q128 __attribute__((mode(TI)));
struct RSub_3AEBA0 { char pad[0xE0]; Q128 a; Q128 b; float w; int pad2[3]; Q128 q[4]; char pad3[0x20]; };
struct REnt_3AEBA0 { int pad0[4]; RSub_3AEBA0 sub; };
struct RColl_3AEBA0 { int pad0; int count; };
struct RIt_3AEBA0;
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b);
struct RIt_3AEBA0 {
    REnt_3AEBA0* p;
    RIt_3AEBA0(REnt_3AEBA0* x) : p(x) {}
    RIt_3AEBA0(const RIt_3AEBA0& o) : p(o.p) {}
    bool operator==(const RIt_3AEBA0& o) const { return REq(this, &o); }
    bool operator!=(const RIt_3AEBA0& o) const { return !(*this == o); }
    REnt_3AEBA0* operator->() const { return p; }
    RIt_3AEBA0& operator++() { p++; return *this; }
};
static inline bool REq(const RIt_3AEBA0* a, const RIt_3AEBA0* b) { REnt_3AEBA0* bp = b->p; return a->p == bp; }
extern "C" REnt_3AEBA0** func_00393680(RColl_3AEBA0*);
static inline RIt_3AEBA0 RBegin(RColl_3AEBA0* c) { RIt_3AEBA0 r(*func_00393680(c)); return r; }
static inline RIt_3AEBA0 REnd(RColl_3AEBA0* c) { RIt_3AEBA0 r(*func_00393680(c) + c->count); return r; }
static inline void RSubReset(RSub_3AEBA0* s, float z) {
    *(int*)((char*)s + 0xD0) = 0;
    VZeroF(&s->a);
    VZeroF(&s->b);
    s->w = z;
    for (Q128* q = s->q; q != s->q + 4; q++) VZeroF(q);
}
#pragma opt_rotateloops off
#pragma opt_propagation off
extern "C" void RootCollection_Reset(RColl_3AEBA0* self) {
    RIt_3AEBA0 it = RBegin(self);
    RIt_3AEBA0 end = REnd(self);
    for (; it != end; ++it) {
        RSubReset(&it->sub, 0.0f);
    }
}
