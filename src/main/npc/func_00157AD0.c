#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

class Actor_7AD0 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void Deactivate(int v);
    VPAD4(s) VPAD2(t)
    virtual int IsLinked();
    VPAD32(u) VPAD2(w)
    virtual unsigned char GetState();
    char pad[0x2C - 4];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    bool Busy() { return b2D && b2C && !b2E; }
};

typedef struct { char pad[4]; int begin; int end; char padC[8]; unsigned char b14; } Look_7AD0;

typedef struct { char pad[4]; unsigned int magic; } Obj_7AD0;

typedef struct { void* vtable; char pad[0x20]; Actor_7AD0* actor; unsigned char flag; } Msg_7AD0;

typedef struct cNPC_7AD0 {
    char pad[0x30];
    Actor_7AD0* actor;
    char pad34[0x150 - 0x34];
    int id;
    char pad154[0x159 - 0x154];
    unsigned char dead;
    char pad15A[0x1B0 - 0x15A];
    int route;
    char pad1B4[4];
    Look_7AD0* look;
} cNPC_7AD0;

struct Empty_7AD0 { char c; };
struct Pred_7AD0 {
    Empty_7AD0 e;
    cNPC_7AD0** self;
    Pred_7AD0(const Empty_7AD0& c, cNPC_7AD0** s) : e(c), self(s) {}
};

extern "C" {
extern char D_004A4A68[];
extern char D_004DB600[];
extern char D_004DB660[];
extern PtrVec D_004EA370;
extern char D_004FFB50[];
extern char g_NpcRouteMgr[];
extern int Service_Lookup(void* a, void* b);
extern void NpcRoute_Release(int mgr, Actor_7AD0* actor);
extern void NpcRoute_ReleaseBuffer(int route);
extern void cAI_v11(cNPC_7AD0* self);
extern void ActiveList_EraseMatching(PtrVec* v, Pred_7AD0 p);
extern void NpcThinkList_RemoveActor(Actor_7AD0* actor);
extern void LookSlot_Release(int* result, Look_7AD0* obj, int* end, int** begin);
extern Obj_7AD0* Object_LookupById(int* id);
extern void Event_Construct(Msg_7AD0* msg, void* name);
extern void Event_Send(Msg_7AD0* msg, void* target, int flags);
extern void cMessage_dtor(Msg_7AD0* msg, int flags);
extern void Object_ClosestPlayerDistSq(Actor_7AD0* actor, float* out);
}

inline void LookClear_7AD0(Look_7AD0* obj)
{
    int* begin = &obj->begin;
    int end = obj->end;
    int result;
    LookSlot_Release(&result, obj, &end, &begin);
}

extern "C" void cNPC_v11(cNPC_7AD0* self)
{
    float dist;
    int result;
    int end;
    int* begin;
    Empty_7AD0 e;
    unsigned char state;
    unsigned char ok;

    if (self->dead) {
        return;
    }
    if (self->actor && self->actor->Busy()) {
        self->actor->Deactivate(1);
        return;
    }
    {
        int mgr = Service_Lookup(D_004FFB50, g_NpcRouteMgr);
        NpcRoute_Release(mgr, self->actor);
    }
    NpcRoute_ReleaseBuffer(self->route);
    cAI_v11(self);
    ActiveList_EraseMatching(&D_004EA370, Pred_7AD0(e, &self));
    NpcThinkList_RemoveActor(self->actor);
    if (Look_7AD0* l = self->look) {
        begin = &l->begin;
        end = l->end;
        LookSlot_Release(&result, l, &end, &begin);
        self->look->b14 = 0;
    }
    if (self->actor->IsLinked()) {
        Obj_7AD0* o = Object_LookupById(&self->id);
        if (o && o->magic == 0xBEBAAFDE) {
            Actor_7AD0* a = self->actor;
            Msg_7AD0 msg;
            Event_Construct(&msg, D_004A4A68);
            msg.vtable = D_004DB600;
            msg.flag = 1;
            msg.actor = a;
            Event_Send(&msg, o, 0);
            msg.vtable = D_004DB660;
            cMessage_dtor(&msg, 0);
        }
    }
    if (self->actor) {
        state = self->actor->GetState();
        ok = state == 2 || state == 3;
        if (ok) {
            Object_ClosestPlayerDistSq(self->actor, &dist);
        }
    }
    self->dead = 1;
}



