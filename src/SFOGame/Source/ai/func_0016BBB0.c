/* cAITarget_UpdateLOS: per-frame sight check of one object: line of
 * sight (unless the object is a hidden player or our owner is blinded),
 * head/body view-cone tests, the cached flags for the current target (and
 * the "seen" message when head+line state changes), then the sighting
 * record; a human seen only by his flashlight spot still registers. */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"
struct V { int a, b, c, d; V() {} };
struct Ctl { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); virtual int Busy(); virtual int Blind(); char p04[0x154]; unsigned char awake; };
struct AObj {
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual V GetPos(int i);
    VPAD8(e)
    virtual V GetPos2();
    char p04[8]; int id; char p10[4]; unsigned char hidden14; char p15[0x17];
    unsigned char enabled, activated, removed; char p2F[0x15];
    int mode; char p48[4]; int team; char p50[8]; Ctl* ctrl;
    char p5C[0x3034 - 0x5C]; int x3034; char p3038[0x3470 - 0x3038]; unsigned char net;
};
struct Comp { char p0[0x30]; AObj* owner; };
struct Handle { AObj* object; int id; };
struct Perc {
    char p0[0x20];
    unsigned char head : 1, body : 1, clear : 1, b3 : 1, b4 : 1, b5 : 1, both : 1, b7 : 1;
    char p21[0x1B]; Comp* component; Handle target;
};
extern "C" {
extern int g_HumanActorClassKey;
extern char g_TargetVisMgr[];
extern char D_004EE550[], D_004D9340[];
int cTargetManager_IsLosBlocked(void* mgr, AObj* a, AObj* b, int c, int d);
unsigned char cAITarget_TestPointInViewCone(Perc* self, V* p, int x, int mode);
void cAITarget_SetAwarenessVisible(Perc* self, AObj* o, unsigned char a, unsigned char b);
AObj* cHuman_GetFlashlightGobj(AObj* o);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
void cMessage_dtor(void*, int);
void cAITarget_UpdateLOS(Perc* self, AObj* obj);
}
/* weak message destructors in a dropped section: inlined at the call sites, no body emitted */
#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX
struct MsgB { void* vt;
    MsgB(void* k) { cMessage_ctor_cMessageNameR(this, k); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); } };
struct Msg4 : MsgB { char p04[0x20]; unsigned char kind; char p25[3]; int id;
    Msg4(int i) : MsgB(D_004EE550) { vt = D_004D9340; kind = 4; id = i; }
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg4() { vt = D_004D9340; } };
static inline bool Active(AObj* p) { return p->activated && p->enabled && !p->removed; }
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline AObj* WGet(Handle* h) { unsigned char ok = 1; if (!IsNullNV(h->object) && h->object->id != h->id) ok = 0; return ok ? h->object : 0; }
static inline int InView1(Perc* self, AObj* o, int x, int*& m)
{
    V r = o->GetPos(-1);
    m = &o->mode;
    int mode = *m;
    if (self->component->owner->net == 1)
        mode = 0;
    return cAITarget_TestPointInViewCone(self, &r, x, mode);
}
static inline unsigned char InView(Perc* self, AObj* o, int x, int* m)
{
    V r = o->GetPos(-1);
    int mode = *m;
    if (self->component->owner->net == 1)
        mode = 0;
    return cAITarget_TestPointInViewCone(self, &r, x, mode);
}
static inline bool NotVis(AObj* a, AObj* b) { return !cTargetManager_IsLosBlocked(g_TargetVisMgr, a, b, 0, 0); }
static inline unsigned char Both(Perc* p) { unsigned char r = 0; if (p->head && p->clear) r = 1; return r; }
static inline bool Player(Ctl* c) { bool yes = false; if (c) if (c->IsPlayer()) yes = true; return yes; }

void cAITarget_UpdateLOS(Perc* self, AObj* obj)
{
    unsigned char vis = 0;
    if (Active(obj)) {
        unsigned char hidden = 0;
        if (obj->ctrl && (obj->ctrl->Busy() || obj->ctrl->Blind())) hidden = !obj->ctrl->awake;
        if (!hidden) {
            if (self->component->owner->ctrl && self->component->owner->ctrl->Busy()) hidden = !self->component->owner->ctrl->awake;
        }
        if (!hidden) {
            unsigned char pl = 0;
            if (obj->ctrl && obj->ctrl->IsPlayer()) pl = 1;
            if (pl && !obj->hidden14) hidden = (obj->x3034 & 1) != 0;
        }
        if (!hidden) vis = !cTargetManager_IsLosBlocked(g_TargetVisMgr, self->component->owner, obj, 0, 0);
    }
    unsigned char los;
    int* pm;
    los = InView1(self, obj, 1, pm);
    if (obj == WGet(&self->target)) {
        self->clear = vis;
        self->head = los;
        self->body = InView(self, obj, 0, pm);
        /* volatile read: retail reloads the flags byte instead of CSE-ing it */
        if (Both(self) != ((volatile Perc*)self)->both) {
            {
                Msg4 msg(self->head && self->clear);
                msg.Send(self->component);
            }
            self->both = self->head && self->clear;
        }
    }
    cAITarget_SetAwarenessVisible(self, obj, vis, los);
    if (!vis || !los) {
        if (obj->team == g_HumanActorClassKey) {
            AObj* lit = cHuman_GetFlashlightGobj(obj);
            if (lit && NotVis(self->component->owner, lit)) {
                V p = lit->GetPos2();
                if (cAITarget_TestPointInViewCone(self, &p, 1, 0))
                    cAITarget_SetAwarenessVisible(self, obj, 1, 1);
            }
        }
    }
}

/* cAITarget_SetTargetPositionLastSeen: record where a target was last seen and its route region */
struct V_C030 { float x, y, z, w; } __attribute__((aligned(16)));
struct RouteRef_C030 { char pad[0x5C]; int region; };
class Ctl_C030 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual bool IsA();
    virtual bool IsB();
    virtual bool IsC();
    char pad4[0x1B0 - 4];
    RouteRef_C030* route;
};
struct Actor_C030 { char pad0[0x58]; Ctl_C030* ctl; char pad5C[0x3204 - 0x5C]; int flags; };
struct Known_C030 { V_C030 pos; char pad10[8]; int region; char pad1C[4]; unsigned char lo : 3; unsigned char extra : 1; unsigned char valid : 1; };
extern "C" {
extern int g_NpcRegionTable[];
int cGOBJ_Team(Actor_C030* a);
int cAIPathData_GetGroupIndex(Known_C030* k, int r);
void cAITarget_SetTargetPositionLastSeen(Known_C030* k, Actor_C030* a, V_C030* pos, int extra);
}
void cAITarget_SetTargetPositionLastSeen(Known_C030* k, Actor_C030* a, V_C030* pos, int extra)
{
    int region = -1;
    bool ok = 1;
    if (a) {
        bool human = 0;
        if (a->ctl && a->ctl->IsA()) human = true;
        if (human) {
                { bool h = (a->flags >> 7) & 1; ok = !(h != 0); }
            region = g_NpcRegionTable[cGOBJ_Team(a)];
        } else if (a->ctl && a->ctl->IsB()) {
            region = a->ctl->route->region;
        } else if (a->ctl && a->ctl->IsC()) {
            region = a->ctl->route->region;
        }
    }
    if (ok) {
        if (region < 0) region = cAIPathData_GetGroupIndex(k, k->region);
        k->region = region;
        /* 128-bit lq/sq quadword copy idiom; the GCC-style asm also keeps MW's
         * unfolded "li 1; andi" for the bitfield stores below */
        { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(pos)); *(__int128*)&k->pos = t; }
        k->valid = 1;
        if (extra) k->extra = 1;
    }
}
