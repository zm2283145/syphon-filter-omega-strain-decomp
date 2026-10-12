
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* NpcAi_IsAliveOrEligible: false while the actor is in state 2/3 and the NPC is busy */
struct Pt1SbActor {
    VPAD32(a) VPAD32(b)
    virtual unsigned char GetMoveState();
};
struct Pt1SbNpc {
    VPAD32(a) VPAD32(b) VPAD16(c) VPAD4(d) VPAD2(e) VPAD1(f)
    virtual int IsBusy();
    char pad4[0x30 - 4];
    Pt1SbActor* actor;
};
static inline unsigned char Pt1Sb_Moving(Pt1SbNpc* n)
{
    unsigned char s = n->actor->GetMoveState();
    return s == 2 || s == 3;
}
static inline int Pt1Sb_Not(bool x) { return x ^ 1; }
static inline int Pt1Sb_NotI(int x) { return (x != 0) ^ 1; }
extern "C" unsigned char NpcAi_IsAliveOrEligible(Pt1SbNpc* n)
{
    unsigned char r = 1;
    if (!Pt1Sb_Not(Pt1Sb_Moving(n)))
        if (!Pt1Sb_NotI(n->IsBusy()))
            r = 0;
    return r;
}