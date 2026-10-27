/*
 * main/npc: range (3 files, 0014F380-0014F460)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0014F380 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { __int128 q[4]; } M_F380;
typedef struct { char pad[0x30]; char* p30; } N_F380;
extern "C" void cMan_GetGunBarrelMatrix(M_F380* out, void* p, unsigned char f);
extern "C" int cNPC_GetBulletDir(N_F380* self, M_F380* out, int flag)
{
    M_F380 tmp; int r;
    __int128 qa; __int128 qb; M_F380* s;
    /* asm { .set reorder } is an empty barrier that keeps the branchy bool (known trick) */
    { char* p = self->p30; unsigned short f; if (flag) { f = 1; asm { .set reorder } } else f = 0; { char* q = p + 0x60; cMan_GetGunBarrelMatrix(&tmp, q, f); } }
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014F380 */

/* merge_units: begin func_0014F3F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int id; } Ai_F3F0;
typedef struct { char pad[0x78]; int x78; } Obj_F3F0;
typedef struct { char pad[0x1B0]; Ai_F3F0* ai; } NPC_F3F0;
extern Obj_F3F0* cAIPathData_GetNodeLinkType(int id, int kind);
extern int cPathNavigator_FallToNode(Ai_F3F0* ai, int v);
int cNPC_DetermineDeathType(NPC_F3F0* self, int r)
{
    int id = self->ai->id;
    if (id >= 0) {
        Obj_F3F0* o = cAIPathData_GetNodeLinkType(id, 7);
        if (o && cPathNavigator_FallToNode(self->ai, o->x78))
            r = 2;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F3F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014F3F0 */

/* merge_units: begin func_0014F460 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNPC_WeaponFired: count shots, notify listeners of weapon fire, tick burst timers */
typedef struct Pt1FnMsg { void* vtable; char body[0x3C]; } Pt1FnMsg;
typedef struct Pt1FnFire { char pad[0xC]; int shots; int lastTime; } Pt1FnFire;
typedef struct Pt1FnOwner { char pad0[0xC]; unsigned int flags; char pad10[0x3524 - 0x10]; int weaponId; } Pt1FnOwner;
typedef struct Pt1FnSelf Pt1FnSelf;

struct Pt1FnSelf {
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD8(d) VPAD1(e) virtual void Release(int id);
    char pad4[0x30 - 0x4];
    Pt1FnOwner* owner;
    char pad34[0x84 - 0x34];
    float burstDelay;
    float timer;
    float timerReset;
    char pad90[0xA8 - 0x90];
    int burstCount;
    char padAC[0x12C - 0xAC];
    int pending;
    int holdFrames;
    int holdTime;
    char pad138[0x1B8 - 0x138];
    Pt1FnFire* fire;
};
extern unsigned int g_VideoFrameCounter; /* frame clock */
static inline int Pt1Fn_Diff(int a, int b) { int d = a - b; return d > 0 ? d : -d; }
extern "C" void cAIGOBJMsg_dtor();
extern "C" void cAIGOBJMsg_getSOBJClassId();
extern "C" void cAIGOBJMsg_Pack();
void * const D_004DCD70[6] = { (void*)0x0, (void*)0x0, (void*)cAIGOBJMsg_dtor, (void*)0x0, (void*)cAIGOBJMsg_Pack, (void*)cAIGOBJMsg_getSOBJClassId };
extern "C" void cAIWeaponFiredMsg_ctor(Pt1FnMsg* msg, int unused, int weapon, int shots);
extern "C" void QueueMessage_cMessageR_cSystemP_int(Pt1FnMsg* msg, void* target, int flags);
extern "C" void cMessage_dtor(Pt1FnMsg* msg, int flags);

extern "C" void cNPC_WeaponFired(Pt1FnSelf* self, int unused, int quiet)
{
    if (!quiet) {
        self->fire->shots++;
        if (Pt1Fn_Diff(g_VideoFrameCounter, self->fire->lastTime) > 0x5A) {
            Pt1FnMsg msg;
            cAIWeaponFiredMsg_ctor(&msg, unused, self->owner->weaponId, self->fire->shots);
            QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
            msg.vtable = ((char*)D_004DCD70);
            cMessage_dtor(&msg, 0);
            self->fire->shots = 0;
            self->fire->lastTime = g_VideoFrameCounter;
        }
    }
    if (self->holdFrames > 0) {
        self->holdFrames--;
        self->timer = (float)self->holdTime;
        if (self->holdFrames <= 0 && self->pending >= 0) {
            self->Release(self->pending);
            self->pending = -1;
        }
    } else {
        self->burstCount--;
        if (self->burstCount == 0)
            self->burstDelay = 4.0f * (0.2f + 0.01f * (float)(self->owner->flags & 0xF));
        self->timer = self->timerReset;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F460(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014F460 */
