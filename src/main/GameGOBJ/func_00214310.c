#pragma cplusplus on
#include "types.h"
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
