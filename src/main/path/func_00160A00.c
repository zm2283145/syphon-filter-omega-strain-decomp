#pragma cplusplus on
#include "types.h"
struct RsActor { char pad[0x58]; RsActor* owner; };
struct RsRoute { char pad[0x10]; int last; char pad14[0xC]; int* segs; };
struct RsPath { char pad[0x48]; int count; int hold; int ev; char pad54[0x70 - 0x54]; RsActor* actor; RsRoute* route; };
struct RsMsg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
void Event_Construct(RsMsg* m, void* type);
void Event_Send(RsMsg* m, RsActor* to, int flags);
void cMessage_dtor(RsMsg* m, int flags);
unsigned char NpcPath_SetSegment(RsPath* p, int seg);
unsigned char NpcPath_SetSegmentToPoint(RsPath* p, RsRoute* r, int pt);
void NpcPath_HoldNode(RsPath* p, int node);
}
static inline RsActor* Root(RsActor* a) { RsActor* o = a->owner; return o == 0 ? a : o; }
static inline void Notify(RsPath* p, unsigned char kind, int id)
{
    RsMsg m;
    Event_Construct(&m, D_004ED9B8);
    m.vt = D_004D9760;
    m.kind = kind;
    m.id = id;
    Event_Send(&m, Root(p->actor), 0);
    m.vt = D_004D9760;
    cMessage_dtor(&m, 0);
}
extern "C" unsigned char NpcRoute_Step(RsPath* p)
{
    unsigned char r = 0;
    while (p->count > 0 && !r) {
        int ev = p->ev;
        if (ev >= 0)
            Notify(p, 5, ev);
        p->count--;
        r = NpcPath_SetSegment(p, p->route->segs[p->count]);
    }
    if (!r) {
        int ev = p->ev;
        if (ev >= 0 && ev != p->route->last)
            Notify(p, 5, ev);
        if (p->count >= 0) {
            p->count--;
            RsRoute* rt = p->route;
            int last = rt->last;
            if (last < 0)
                r = NpcPath_SetSegmentToPoint(p, rt, -1);
            else
                r = NpcPath_SetSegment(p, last);
        }
    }
    if (!r) {
        NpcPath_HoldNode(p, p->route->last);
        Notify(p, 6, p->hold);
    }
    return r;
}

