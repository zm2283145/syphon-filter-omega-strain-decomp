/*
 * SFOGame/Source/gameSound_msg: 3 files, 0020E730-0020E8B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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

#include "types.h"
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
