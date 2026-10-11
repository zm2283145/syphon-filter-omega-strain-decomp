#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* NpcAlert_HearingReaction: react to a heard event (raise awareness of the source, start an investigate slot) */
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
extern void* D_004FFC0C;
Pt1HrActor* func_003EA550(void* players);
void func_0016C9D0(Pt1HrPerc* p, Pt1HrActor* a, int kind, float amount);
float func_0016C730(Pt1HrPerc* p, Pt1HrActor* a);
Pt1HrReaction* func_0016C6A0(Pt1HrPerc* p, Pt1HrActor* a);
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
extern "C" void func_00152C50(Pt1HrNpc* self, unsigned char kind, Pt1HrActor* src)
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
            who = func_003EA550(D_004FFC0C);
            if (who && who != self->actor)
                func_0016C9D0(self->perc, who, 2, 0.0f);
        } else if (src->ctrl->IsAiControlled()) {
            who = Pt1Hr_GetB(((Pt1HrCtrlData*)src->ctrl)->perc);
            if (who && who != self->actor)
                func_0016C9D0(self->perc, who, 2, 0.0f);
        }
    }
    p = self->perc;
    if (!(p->alertLevel < 0x32 && (!Pt1Hr_GetB(p) || func_0016C730(p, Pt1Hr_GetC(p)) <= 0.1f)) && kind != 7)
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
        Pt1HrReaction* r = func_0016C6A0(p, tgt);
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