#pragma cplusplus on
#include "types.h"
/* NpcRoute_ScoreNodes: restart the route walk when dirty, then report the chosen node to the owner */
typedef struct Pt1SnObj { char pad0[0xC]; int serial; char pad10[0x58 - 0x10]; struct Pt1SnObj* owner; } Pt1SnObj;
typedef struct Pt1SnNode { char pad0[0x10]; int a; int b; } Pt1SnNode;
typedef struct Pt1SnMsg {
    void* vt;
    char pad4[0x20];
    unsigned char found;
    char pad25[3];
    int node;
    int node2;
} Pt1SnMsg;
typedef struct Pt1SnSelf {
    Pt1SnObj* owner;
    int ownerSerial;
    char pad8[0xD - 0x8];
    unsigned char dirty;
    unsigned char reported;
    char padF[0x10 - 0xF];
    char list[0x4];
    char sentinel[0x4];
    void* head;
    void* tail;
    char nodes[0x4];
    void* first;
    void* last;
    int count;
    char pad30[0x468 - 0x30];
    int mask;
    unsigned char mode;
    char pad46D[0x474 - 0x46D];
    unsigned char status;
    char pad475[3];
    int target;
    int target2;
    unsigned char reverse;
    unsigned char retry;
    unsigned char crouched;
} Pt1SnSelf;
extern char D_004ED9B8[];
extern char D_004D9760[];
extern "C" void Event_Construct(void* msg, void* name);
extern "C" void Event_Send(void* msg, void* target, int immediate);
extern "C" void cMessage_dtor(void* msg, int flags);
extern "C" void func_0015E110(Pt1SnSelf* self, int mode);
extern "C" Pt1SnNode* func_001647B0(void* list);
extern "C" void func_00161BC0(Pt1SnSelf* self, int id, int mask);

static inline Pt1SnObj* Pt1Sn_Owner(Pt1SnSelf* self)
{
    Pt1SnObj* t = self->owner;
    bool isNull = !t;
    bool ok = true;
    if (!isNull)
        if (t->serial != self->ownerSerial)
            ok = false;
    t = ok ? t : 0;
    Pt1SnObj* o=t->owner; return o == 0 ? t : o;
}

extern "C" unsigned char NpcRoute_ScoreNodes(Pt1SnSelf* self)
{
    unsigned char done = 0;
    if (self->dirty) {
        self->dirty = 0;
        self->head = self->nodes;
        self->tail = self->sentinel;
        self->first = self->nodes;
        self->last = self->sentinel;
        self->count = 0;
        if (!self->crouched)
            func_0015E110(self, 2);
        else
            func_0015E110(self, 0);
        self->target = -1;
        self->target2 = -1;
        self->status = 0;
        if (self->count) {
            if (!self->mode) {
                Pt1SnNode* n = func_001647B0(self->list);
                self->target = n->a;
                self->target2 = n->b;
            } else {
                func_00161BC0(self, ((Pt1SnNode*)self->head)->a, self->mask);
            }
        }
    }
    if (self->status == 2)
        self->status = 0;
    if (self->retry) {
        if (!self->count)
            done = 1;
    } else if (self->target >= 0) {
        Pt1SnMsg m;
        int a;
        int b;
        self->reported = 1;
        b = self->target2;
        a = self->target;
        Event_Construct(&m, D_004ED9B8);
        m.node = a;
        m.node2 = b;
        m.vt = D_004D9760;
        m.found = 0;
        Event_Send(&m, Pt1Sn_Owner(self), 1);
        m.vt = D_004D9760;
        cMessage_dtor(&m, 0);
        done = 1;
    } else if (!self->count) {
        Pt1SnMsg m;
        self->reported = 1;
        Event_Construct(&m, D_004ED9B8);
        m.vt = D_004D9760;
        m.found = 1;
        m.node = -1;
        Event_Send(&m, Pt1Sn_Owner(self), 1);
        m.vt = D_004D9760;
        cMessage_dtor(&m, 0);
        done = 1;
    }
    return done;
}