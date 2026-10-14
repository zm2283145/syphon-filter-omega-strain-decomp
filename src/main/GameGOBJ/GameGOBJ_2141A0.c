/*
 * main/GameGOBJ: range (5 files, 002141A0-00214640)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002141A0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
typedef struct { char pad[0x68]; int type; char pad2[0x64]; int* p; char pad3[0x8]; unsigned char flag; } LObj_c7;
typedef struct { char pad[0xEC]; int count; LObj_c7** objs; char pad2[0x34]; int* index; } Lift_c7;
unsigned char func_002141A0(Lift_c7* self) {
    int idx = *self->index;
    unsigned char r = 1;
    int i;
    int count;
    if (idx < 0) {
        r = 0;
    } else {
        count = self->count;
        idx = idx * 2;
        i = idx;
        idx = idx + 1;
        for (; i < count && i <= idx; i++) {
            LObj_c7* o = self->objs[i];
            if (o->type == 2) {
                if (!o->flag || *o->p != 0) { r = 0; break; }
            }
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002141A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002141A0 */

/* merge_units: begin func_00214240 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; int type; } F214Def;
typedef struct { F214Def* def; } F214Ent;
typedef struct { char pad[0xD0]; int* state; char padd4[8]; unsigned char active; } F214Obj;
typedef struct { char pad[0x68]; int kind; } F214Hdr;
typedef struct {
    char pad0[0x70];
    int count;
    char list[8];
    F214Obj** objs;
} F214Mgr;
extern F214Ent* func_00172990(void*, int);
extern int D_004F5468;
#pragma opt_strength_reduction off
unsigned char func_00214240(F214Mgr* m)
{
    unsigned char result = 1;
    int i;
    for (i = 0; i < m->count; i++) {
        F214Ent* e = func_00172990(m->list, i);
        if (e->def->type == D_004F5468) {
            F214Obj* o = m->objs[i];
            if (((F214Hdr*)o)->kind == 2) {
                if (!o->active || *o->state) {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214240(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214240 */

/* merge_units: begin func_00214310 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj214310 { char pad0[0xC]; int id; };
struct Car214310 { char p[0x68]; int kind; };
struct Msg214310 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[4]; };
struct State214310 { int cur; };
struct Lift214310 { char p[0xEC]; int count; Car214310** cars; char pF4[0x34]; State214310* state; };
extern "C" {
extern char D_004F5440[];
extern char D_004DAF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int ObjId214310(Obj214310* o) { return o ? o->id : 0; }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off

extern "C" unsigned char func_00214310(Lift214310* l)
{
    unsigned char found = 0;
    int base = l->state->cur * 2;
    int i;
    for (i = base; i < l->count && i <= base + 1; i++) {
        found = 1;
        if (l->cars[i]->kind == 2) {
            Msg214310 m;
            Msg214310* p = &m;
            Event_Construct(&m, D_004F5440);
            m.vtable = D_004DAF10;
            m.kind = 0;
            m.floor = 0;
            p->to = ObjId214310(0);
            p->from = ObjId214310(0);
            m.b20 = 1;
            Event_Send(&m, l->cars[i], 0);
            m.vtable = D_004DAF10;
            cMessage_dtor(&m, 0);
        }
    }
    return found;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214310 */

/* merge_units: begin func_00214470 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj214470 { char pad0[0xC]; int id; };
struct Car214470 { char p[0x68]; int kind; };
struct Ent214470 { char p[0x4C]; int type; };
struct Msg214470 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[4]; };
typedef struct ElevatorMsg214470 {
    void* vtable;
    char pad004[0x78 - 4];
    char memberA[0x114 - 0x78];
    char memberB[0x1D0 - 0x114];
} ElevatorMsg214470;
struct Lift214470 { char p[0x70]; int count; char list[8]; Car214470** cars; char p80[0x2E0 - 0x80]; int floors; };
extern "C" {
extern char D_004FFB50[];
extern char D_004DADF0[];
void func_0020EBA0(ElevatorMsg214470* msg, int* floors, Lift214470* self);
void func_0036E220(void* member, int flag);
#if 0 /* merge_units */
Ent214470** func_00172990(void* list, int i);
#endif /* merge_units */
#define func_00172990(a0, a1) ((Ent214470 * *)func_00172990((a0), (a1))) /* merge_units */

}
static inline int ObjId214470(Obj214470* o) { return o ? o->id : 0; }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off

extern "C" unsigned char func_00214470(Lift214470* l)
{
    unsigned char found = 0;
    int i;
    Msg214470 m;
    {
        ElevatorMsg214470 msg;
        func_0020EBA0(&msg, &l->floors, l);
        Event_Send(&msg, D_004FFB50, 1);
        msg.vtable = D_004DADF0;
        func_0036E220(msg.memberB, -1);
        func_0036E220(msg.memberA, -1);
        cMessage_dtor(&msg, 0);
    }
    for (i = 0; i < l->count; i++) {
        found = 1;
        Ent214470* e = *func_00172990(l->list, i); if (e->type == D_004F5468) {
            if (l->cars[i]->kind == 2) {
                Msg214470* p = &m;
                Event_Construct(&m, D_004F5440);
                m.vtable = D_004DAF10;
                m.kind = 0;
                m.floor = 0;
                p->to = ObjId214470(0);
                p->from = ObjId214470(0);
                m.b20 = 1;
                Event_Send(&m, l->cars[i], 0);
                m.vtable = D_004DAF10;
                cMessage_dtor(&m, 0);
            }
        }
    }
    return found;
}
#pragma pop
#undef func_00172990 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214470 */

/* merge_units: begin func_00214640 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#if 0 /* merge_units */
extern int D_004F5440;
#endif /* merge_units */
#define D_004F5440 (*(int*)&D_004F5440) /* merge_units */

extern int D_004F7E48;
int* Event_GetType(void* ev);
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
#undef D_004F5440 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00214640(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00214640 */
