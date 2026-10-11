#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* NpcAttack_FireNotice: count shots, notify listeners of weapon fire, tick burst timers */
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
extern unsigned int D_005383C8; /* frame clock */
static inline int Pt1Fn_Diff(int a, int b) { int d = a - b; return d > 0 ? d : -d; }
extern char D_004DCD70[];
extern "C" void cAIWeaponFiredMsg_ctor(Pt1FnMsg* msg, int unused, int weapon, int shots);
extern "C" void Event_Send(Pt1FnMsg* msg, void* target, int flags);
extern "C" void cMessage_dtor(Pt1FnMsg* msg, int flags);

extern "C" void func_0014F460(Pt1FnSelf* self, int unused, int quiet)
{
    if (!quiet) {
        self->fire->shots++;
        if (Pt1Fn_Diff(D_005383C8, self->fire->lastTime) > 0x5A) {
            Pt1FnMsg msg;
            cAIWeaponFiredMsg_ctor(&msg, unused, self->owner->weaponId, self->fire->shots);
            Event_Send(&msg, self, 0);
            msg.vtable = D_004DCD70;
            cMessage_dtor(&msg, 0);
            self->fire->shots = 0;
            self->fire->lastTime = D_005383C8;
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