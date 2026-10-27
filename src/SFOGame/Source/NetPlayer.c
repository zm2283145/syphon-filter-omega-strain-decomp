/*
 * SFOGame/Source/NetPlayer: 4 files, 002D7C80-002D7E50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D7C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "player_ctl_level.h"

/* Controller level of the player, -1 without an active controller. */
DEFINE_PLAYER_CTL_LEVEL(cNetPlayer_Team)
static inline void merge_flush_func_002D7C80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7C80 */

/* merge_units: begin func_002D7D10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "cmessage.h"
typedef struct V4 { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Msg : CMsg { int a24; unsigned char a28; char p29[7]; };
struct Msg2 : Msg { int val; int id; unsigned char m38; char p39[7]; V4 v; float f50; char p54[0xC]; };
struct Info { unsigned char dead; char p1[7]; int val; signed char id; };
struct Obj { char p0[0x44]; Info* info; char p48[4]; void* target; };
extern "C" {
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0200[];
extern signed char D_004E1D88;
extern V4 D_004E1D90;
}
static inline const V4& Zero()
{
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return D_004E1D90;
}
/* GCC-style volatile lq/sq quad copy (c57da idiom): keeps the unfolded addiu address regs */
static inline void V4_Copy(V4* d, const V4* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void cNetPlayer_WeaponShoot(Obj* o)
{
    Info* in = o->info;
    if (in) {
        Msg2* m; int id = in->id;
        int val[1]; val[0] = in->dead ? -1 : in->val;
        Msg2 msg;
        m = &msg;
        cMessage_ctor_cMessageNameR(m, g_ActorActionMsgClass);
        m->vtable = D_004E0840;
        m->a24 = 0x3B;
        m->a28 = 0xB;
        m->vtable = D_004E0200;
        {
            const V4* z = &Zero();
            m->val = val[0];
            m->id = id;
            m->m38 = 0;
            V4_Copy(&m->v, z);
            m->f50 = 0.0f;
        }
        QueueMessage_cMessageR_cSystemP_int(&msg, o->target, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}
static inline void merge_flush_func_002D7D10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7D10 */

/* merge_units: begin func_002D7E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cNetPlayer_NoticeDeath(void) {
}
static inline void merge_flush_func_002D7E40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7E40 */

/* merge_units: begin func_002D7E50 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M_7E50;
typedef struct { char pad[0x4C]; char* p30; } N_7E50;
extern "C" void cMan_GetGunBarrelMatrix(M_7E50* out, void* p, unsigned char f);

extern "C" int func_002D7E50(N_7E50* self, M_7E50* out, int flag)
{
    M_7E50 tmp; int r;
    __int128 qa; __int128 qb; M_7E50* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; cMan_GetGunBarrelMatrix(&tmp, self->p30 + 0x60, f); }
    s = &tmp; r = 1;
    asm {
        .set noreorder
        lq qa, 0x0(s)
        lq qb, 0x10(s)
        sq qa, 0x0(out)
        lq qa, 0x20(s)
        sq qb, 0x10(out)
        lq qb, 0x30(s)
        sq qa, 0x20(out)
        sq qb, 0x30(out)
        .set reorder
    }
    return r;
}
static inline void merge_flush_func_002D7E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7E50 */
