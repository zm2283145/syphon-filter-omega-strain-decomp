/*
 * main/npc: range (5 files, 00152B10-00152FD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00152B10 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIDestinationReachedMsg_dtor, D_004DCCB0, D_004DCD50, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00152B10 */

/* merge_units: begin func_00152B80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cAIWaypointReachedMsg_dtor, D_004DCCD0, D_004DCD50, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00152B80 */

/* merge_units: begin func_00152BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cAINodeMsg_dtor, D_004DCD50, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00152BF0 */

/* merge_units: begin func_00152C50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cNPC_SoundHeard: react to a heard event (raise awareness of the source, start an investigate slot) */
struct Pt1HrActor;
struct Pt1HrPerc;
struct Pt1HrCtrl {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsPlayerControlled();
    virtual int IsAiControlled();
};
struct Pt1HrHandle { Pt1HrActor* target; int serial; };
struct Pt1HrPerc {
    char pad0[0x1C];
    int alertLevel;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    char pad21[0x40 - 0x21];
    Pt1HrHandle focus;
};
struct Pt1HrActor {
    char pad0[0xC];
    int serial;
    char pad10[0x58 - 0x10];
    Pt1HrCtrl* ctrl;
};
struct Pt1HrCtrlData { char pad0[0x1AC]; Pt1HrPerc* perc; };
struct Pt1HrSlot {
    Pt1HrActor* target;
    int serial;
    float weight;
    int prio;
    unsigned char active;
    unsigned char fresh;
    char pad12[2];
};
struct Pt1HrReaction { char pad0[0x39]; unsigned char investigate; };
struct Pt1HrNpc {
    VPAD16(a) VPAD8(b) VPAD2(c)
    virtual int CanSee(Pt1HrActor* a);
    VPAD8(d) VPAD4(e) VPAD1(f)
    virtual int ReleaseSlot(int slot);
    VPAD16(g) VPAD8(h) VPAD4(k) VPAD2(i) VPAD1(j)
    virtual void Investigate(Pt1HrActor* a, int prio, float weight);
    char pad4[0x30 - 4];
    Pt1HrActor* actor;
    char pad34[0x80 - 0x34];
    float hearing;
    char pad84[0x164 - 0x84];
    unsigned char curSlot;
    char pad165[0x16C - 0x165];
    Pt1HrSlot slots[2];
    char pad194[0x1AC - 0x194];
    Pt1HrPerc* perc;
};
extern "C" {
extern void* g_LocalPlayer;
Pt1HrActor* cGobjController_GetTarget(void* players);
void cAITarget_AddAwareness(Pt1HrPerc* p, Pt1HrActor* a, int kind, float amount);
float cAITarget_GetAwarenessThreat(Pt1HrPerc* p, Pt1HrActor* a);
Pt1HrReaction* cAITarget_GetAwareness(Pt1HrPerc* p, Pt1HrActor* a);
}
static inline Pt1HrActor* Pt1Hr_GetB(Pt1HrPerc* p)
{
    Pt1HrActor* t = p->focus.target;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != p->focus.serial)
            ok = false;
    return ok ? t : 0;
}

static inline Pt1HrActor* Pt1Hr_GetC(Pt1HrPerc* p)
{
    Pt1HrActor* t = p->focus.target;
    if (t && t->serial != p->focus.serial)
        t = 0;
    return t;
}
extern "C" void cNPC_SoundHeard(Pt1HrNpc* self, unsigned char kind, Pt1HrActor* src)
{
    Pt1HrActor* who;
    Pt1HrActor* tgt;
    Pt1HrPerc* p;
    int none;
    if (!src)
        return;
    who = 0;
    if (kind == 4 && src->ctrl) {
        if (src->ctrl->IsPlayerControlled()) {
            who = cGobjController_GetTarget(g_LocalPlayer);
            if (who && who != self->actor)
                cAITarget_AddAwareness(self->perc, who, 2, 0.0f);
        } else if (src->ctrl->IsAiControlled()) {
            who = Pt1Hr_GetB(((Pt1HrCtrlData*)src->ctrl)->perc);
            if (who && who != self->actor)
                cAITarget_AddAwareness(self->perc, who, 2, 0.0f);
        }
    }
    p = self->perc;
    if (!(p->alertLevel < 0x32 && (!Pt1Hr_GetB(p) || cAITarget_GetAwarenessThreat(p, Pt1Hr_GetC(p)) <= 0.1f)) && kind != 7)
        return;
    tgt = 0;
    if (self->CanSee(src))
        tgt = src;
    else if (who && self->CanSee(who))
        tgt = who;
    if (!tgt)
        return;
    p = self->perc;
    {
        bool busy = p->bit0 && p->bit2;
        if (busy)
            return;
    }
    if (!(self->hearing > 5.0f))
        return;
    {
        Pt1HrReaction* r = cAITarget_GetAwareness(p, tgt);
        if (r && r->investigate) {
            if (self->slots[self->curSlot].prio < 0x15) {
                if (self->ReleaseSlot(*(signed char*)&self->curSlot)) {
                    int* pp;
                    int off = self->curSlot * (int)sizeof(Pt1HrSlot);
                    char* b = (char*)(off + (int)self);
                    pp = (int*)(b + 0x178);
                    if (*pp < 0x15) {
                        b[0x17C] = 0;
                        *pp = 0;
                    }
                }
                self->curSlot = 1;
                self->slots[1].target = tgt;
                self->slots[1].serial = *(tgt ? &tgt->serial : (none = -1, &none));
                self->slots[1].active = 1;
                self->slots[1].fresh = 1;
                self->slots[1].weight = 1.0f;
                self->slots[1].prio = 0x14;
            }
        } else {
            self->Investigate(tgt, 0x14, 1.0f);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00152C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00152C50 */

/* merge_units: begin func_00152FD0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int serial; char pad10[0x1C]; unsigned char f2C; unsigned char f2D; unsigned char f2E; } Tgt_52FD0;
typedef struct { char pad[0xC]; int id; char pad10[0x114]; Tgt_52FD0* target; int serial; } Src_52FD0;
typedef struct { char pad[0x30]; Tgt_52FD0* f30; char pad34[0x10]; int mode; char pad48[0xAC]; int fF4; char padF8[0xB4]; void* perc; } Npc_52FD0;
#if 0 /* merge_units */
extern void cAITarget_AddAwareness(void* p, void* src, int kind, float amt);
#endif /* merge_units */
#define cAITarget_AddAwareness(a0, a1, a2, a3) (cAITarget_AddAwareness((void *)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

extern unsigned char cGrenade_GetDamageType(Src_52FD0* s);
extern void cNPC_DoAction(Npc_52FD0* n, int a, int b, float t);
extern unsigned char cStateMachine_ChangeState(int* p, int v, int pri);
static inline void Notice_52FD0(Npc_52FD0* self, Src_52FD0* src)
{
    Tgt_52FD0* t;
    unsigned char ok;
    unsigned char isNull;
    Tgt_52FD0* p;
    t = src->target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != src->serial)
            ok = 0;
    p = ok ? t : 0;
    if (p) {
        int v = p->f2D && p->f2C && !p->f2E;
        if (v) {
            if ((isNull || t->serial == src->serial ? t : 0) != self->f30)
                cAITarget_AddAwareness(self->perc, p, 2, 0.0f);
        }
    }
}
void cNPC_Sound(Npc_52FD0* self, int kind, Src_52FD0* src, float amt)
{
    if (!src)
        return;
    if ((unsigned char)kind == 5) {
        if (self->mode != 10) {
            Notice_52FD0(self, src);
            if (cGrenade_GetDamageType(src) == 3) {
                cNPC_DoAction(self, 8, 0, 5.0f);
                return;
            }
            if (cStateMachine_ChangeState(&self->mode, 10, 50))
                self->fF4 = src->id;
        }
    } else {
        cAITarget_AddAwareness(self->perc, src, kind, amt);
    }
}
#undef cAITarget_AddAwareness /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00152FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00152FD0 */
