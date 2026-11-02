/*
 * SFOGame/Source/gameSound_msg: 5 files, 0020E660-0020E950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020E660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMessage_ctor_cMessageR(void* self, void* src);
#if 0 /* merge_units */
void cSndFx_ctor_cSndFxR(void* dst, void* src);
#endif /* merge_units */
struct Outer; /* merge_units */
Outer* cSndFx_ctor_cSndFxR(Outer* d, const Outer* s); /* merge_units */
#define cSndFx_ctor_cSndFxR(a0, a1) ((void)cSndFx_ctor_cSndFxR((Outer *)(a0), (const Outer *)(a1))) /* merge_units */

extern char D_004DADF0[];
}
struct Msg0E660 { void* vtable; char pad[0x2C]; char payload[0x190]; unsigned char b1C0; };
extern "C" Msg0E660* func_0020E660(Msg0E660* src)
{
    Msg0E660* p;
    {
        AllocGuard guard;
        p = (Msg0E660*)cMemMan_Allocate(0, 0x1D0, "gameSound_msg.hh", 0x7E);
    }
    if (p) {
        cMessage_ctor_cMessageR(p, src);
        p->vtable = D_004DADF0;
        cSndFx_ctor_cSndFxR(p->payload, src->payload);
        p->b1C0 = src->b1C0;
    }
    return p;
}
#undef cSndFx_ctor_cSndFxR /* merge_units */
static inline void merge_flush_func_0020E660(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E660 */

/* merge_units: begin func_0020E730 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s)); *(__int128*)d = q; }
struct V4 { int x, y, z, w; } __attribute__((aligned(16)));
struct V4b {
    __int128 q;
    V4b& operator=(const V4b& o) { V4b* t = this; GQ(t, &o); return *this; }
};
struct I32 { int v; I32& operator=(const I32& o) { v = o.v; return *this; } };
/* Head's implicit op= is non-trivial (I32), so MW copies name[] with its own 2x-unrolled byte loop. */
struct Head { I32 m0; signed char name[0x80]; };
struct Sub : Head {
    short m84;
    int m88;
    int m8C;
    int m90;
    unsigned char m94;
    int m98;
    Sub& operator=(const Sub& o) {
        Sub* t = this;
        t->Head::operator=(o);
        t->m84 = o.m84;
        t->m88 = o.m88;
        t->m8C = o.m8C;
        t->m90 = o.m90;
        t->m94 = o.m94;
        t->m98 = o.m98;
        return *this;
    }
};
struct Outer {
    int m0;
    V4 m10;
    int m20;
    int m24;
    V4b m30;
    int m40;
    signed char m44;
    Sub s48;
    Sub sE4;
    int m180;
    short m184;
    unsigned char m186;
};
#pragma inline_depth(8)
extern "C" Outer* cSndFx_ctor_cSndFxR(Outer* d, const Outer* s)
{
    *d = *s;
    return d;
}
static inline void merge_flush_func_0020E730(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E730 */

/* merge_units: begin func_0020E860 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

extern void* D_004D97F0;
extern char D_004F53E8[];
extern ByteEvent* cMessage_ctor_cMessageNameR(ByteEvent*, char*);

ByteEvent* cPauseMusicMsg_ctor(ByteEvent* self, int value) {
    cMessage_ctor_cMessageNameR(self, D_004F53E8);
    self->vtable = &D_004D97F0;
    self->value = value;
    return self;
}
static inline void merge_flush_func_0020E860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E860 */

/* merge_units: begin func_0020E8B0 */
#pragma push /* merge_units */
#include "queue_two_member_msg.h"

DEFINE_QUEUE_TWO_MEMBER_MSG(cStopSoundMsg_NetStopSoundMsgCallback, 0x1E0, cStopSoundMsg_ctor_netStopSoundMsgR, D_004DADF0)
static inline void merge_flush_func_0020E8B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E8B0 */

/* merge_units: begin func_0020E950 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { int a; int pad; int b[4]; int c; char d; } Proto_0020E950;
extern char D_004F53E0[];
#if 0 /* merge_units */
extern void cStopSoundMsg_NetStopSoundMsgCallback(void);
#endif /* merge_units */


NETREG_BEGIN(cStopSoundMsg_InitNet, Proto_0020E950)
NETREG_FIELD(a, 4, 1)
NETREG_FIELD(b, 0x10, 1)
NETREG_FIELD(c, 4, 1)
NETREG_FIELD(d, 1, 1)
NETREG_END(D_004F53E0, cStopSoundMsg_NetStopSoundMsgCallback)
static inline void merge_flush_func_0020E950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E950 */
