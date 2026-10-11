#pragma cplusplus on
#include "types.h"
struct Ctl_00214640 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int IsPlayer();
};
struct Obj_00214640 { char pad0[0xC]; int id; char pad10[4]; unsigned char b14; char pad15[0x58 - 0x15]; Ctl_00214640* ctl; };
struct LiftMsg_00214640 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[4]; };
struct In_00214640 { char pad[0x20]; unsigned char b20; char pad21[3]; unsigned char kind; char pad25[3]; int floor; char pad2C[4]; int id; };
struct In2_00214640 { char pad[0x24]; Obj_00214640* who; int floor; };
struct State_00214640 { int cur; int dir; char pad8[0x18]; int target; char pad24[4]; int busy; };
struct Snd_00214640 { int pad0; void* h; };
struct Lift_00214640 {
    char pad0[0xC]; int id; char pad10[0x128 - 0x10]; State_00214640* state; int queue[5]; int nQueue;
    char pad144[0x790 - 0x144]; Snd_00214640* snd;
};
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern int D_004F5440;
extern int D_004F7E48;
extern char D_004DAF10[];
int* Event_GetType(void* ev);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
Obj_00214640* Object_LookupById(int* id);
void Lift_SeekFloor(Lift_00214640* l, int floor, unsigned char a2, int a3);
void Lift_SetFloorLock(Lift_00214640* l, int floor, int lock);
int PathObj_Receive(Lift_00214640* l, void* ev);
void Transport_Send(int target, LiftMsg_00214640* msg, int a, int b);
void func_00214BC0();
void func_002EC460(void* h);
}
static inline int IsAuth_00214640(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline int ObjId_00214640(Obj_00214640* o) { return o ? o->id : 0; }
static inline unsigned char IsPlayerCtl_00214640(Obj_00214640* o)
{
    unsigned char r = 0;
    Ctl_00214640* c = o->ctl;
    if (c && c->IsPlayer())
        r = 1;
    return r;
}
static inline void Enqueue_00214640(Lift_00214640* l, int floor)
{
    if (l->state->target != floor && floor != -1) {
        unsigned char found;
        int i;
        int* q;
        int n = l->nQueue;
        if (n < 5) {
            found = 0;
            i = 0;
            if (0 < n) {
                q = (int*)l;
                do {
                    if (q[0x12C / 4] == floor) {
                        found = 1;
                        break;
                    }
                    i++;
                    q++;
                } while (i < n);
            }
            if (!found) {
                l->queue[n] = floor;
                l->nQueue++;
            }
        }
    }
}
extern "C" int Lift_Receive(Lift_00214640* l, In_00214640* m)
{
    int floor;
    Obj_00214640* o;
    int id1;
    int id10;
    LiftMsg_00214640 msgB;
    LiftMsg_00214640 msg;
    int t = *Event_GetType(m);
    if (t == D_004F5440) {
        switch (m->kind) {
        case 4:
        case 1:
            if (D_005721C8) {
                unsigned char isPlayer;
                id1 = m->id;
                o = Object_LookupById(&id1);
                isPlayer = 0;
                if (o->b14 && IsPlayerCtl_00214640(o))
                    isPlayer = 1;
                floor = m->floor;
                if (floor >= 0 && l->state->busy) {
                    Enqueue_00214640(l, floor);
                } else {
                    Lift_SeekFloor(l, floor, isPlayer, 0);
                    if (floor >= 0)
                        l->state->busy = 1;
                }
                if (IsAuth_00214640()) {
                    m->b20 = 4;
                    Event_Send(m, l, 0);
                }
            } else {
                floor = m->floor;
                if (floor >= 0 && l->state->busy) {
                    Enqueue_00214640(l, floor);
                } else {
                    Lift_SeekFloor(l, floor, 1, 0);
                    if (floor >= 0)
                        l->state->busy = 1;
                }
            }
            break;
        case 5:
            Lift_SetFloorLock(l, m->floor, 1);
            break;
        case 6:
            Lift_SetFloorLock(l, m->floor, 0);
            break;
        case 10: {
            id10 = m->id;
            o = Object_LookupById(&id10);
            if (o) {
                if (o->b14 && IsPlayerCtl_00214640(o)) {
                    Lift_SeekFloor(l, -1, 1, 0);
                } else {
                    LiftMsg_00214640* p = &msg;
                    int dest;
                    int tid;
                    Event_Construct(p, &D_004F5440);
                    msg.vtable = D_004DAF10;
                    msg.kind = 1;
                    msg.floor = -1;
                    p->to = ObjId_00214640(o);
                    p->from = ObjId_00214640(0);
                    tid = l->id;
                    if (D_005721C8) {
                        if (IsPlayerCtl_00214640(o))
                            dest = ((unsigned int)(o->id & 0x7F000000) >> 24) - 1;
                        else
                            dest = -1;
                    } else {
                        dest = 0;
                    }
                    Transport_Send(tid, &msg, 0, dest);
                    msg.vtable = D_004DAF10;
                    cMessage_dtor(&msg, 0);
                }
            }
            break;
        }
        default:
            return PathObj_Receive(l, m);
        }
        return 1;
    }
    t = *Event_GetType(m);
    if (t == D_004F7E48) {
        if (func_00214BC0 && l->snd && ((In2_00214640*)m)->floor == -0xFF) {
            func_002EC460(l->snd->h);
            return 1;
        }
        {
            floor = ((In2_00214640*)m)->floor;
            if (floor != -0xFF) {
                Obj_00214640* who = ((In2_00214640*)m)->who;
                LiftMsg_00214640* p = &msgB;
                Event_Construct(p, &D_004F5440);
                msgB.floor = floor;
                msgB.vtable = D_004DAF10;
                msgB.kind = 1;
                p->to = ObjId_00214640(who);
                p->from = ObjId_00214640(0);
                Event_Send(&msgB, l, 0);
                msgB.vtable = D_004DAF10;
                cMessage_dtor(&msgB, 0);
            }
        }
        return 1;
    }
    return PathObj_Receive(l, m);
}