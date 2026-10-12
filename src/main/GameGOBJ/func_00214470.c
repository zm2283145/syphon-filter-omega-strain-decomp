#pragma cplusplus on
#include "types.h"
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
extern char D_004F5440[];
extern char D_004DAF10[];
extern char D_004FFB50[];
extern char D_004DADF0[];
extern int D_004F5468;
void func_0020EBA0(ElevatorMsg214470* msg, int* floors, Lift214470* self);
void func_0036E220(void* member, int flag);
Ent214470** func_00172990(void* list, int i);
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
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




