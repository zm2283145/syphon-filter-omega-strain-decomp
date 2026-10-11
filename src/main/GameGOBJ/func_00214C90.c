#include "types.h"
typedef struct Obj_00214C90 { char pad[0xC]; int id; } Obj_00214C90;
typedef struct LiftMsg_00214C90 { void* vtable; char base[0x1C]; unsigned char b20; char pad21[3]; int kind; int floor; int from; int to; char pad34[0xC]; } LiftMsg_00214C90;
typedef struct Notice_00214C90 { void* vtable; char base[0x20]; int kind; int arg; char pad2C[4]; } Notice_00214C90;
typedef struct State_00214C90 { int cur; int dir; char pad8[0x18]; int target; } State_00214C90;
typedef struct Snd_00214C90 { int pad0; void* h; } Snd_00214C90;
typedef struct Lift_00214C90 {
    char pad0[0xC]; int id; char pad10[0x10C - 0x10]; int nFloors; int* locked;
    char pad114[0x128 - 0x114]; State_00214C90* state; char pad12C[0x790 - 0x12C]; Snd_00214C90* snd;
} Lift_00214C90;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004F5440[];
extern char D_004DAF10[];
extern char D_004F5448[];
extern char D_004DAED0[];
extern void Event_Construct(void* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void cElevatorGOBJ_ChooseFloor(Lift_00214C90* l);
extern void func_002EC3C8(void* h);
extern void func_00215430(Lift_00214C90* l);
extern unsigned char Lift_OpenDoors(Lift_00214C90* l);
static inline int IsAuth_00214C90(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline int ObjId_00214C90(Obj_00214C90* o) { return o ? o->id : 0; }
void Lift_SeekFloor(Lift_00214C90* l, int floor, int a2, int a3)
{
    if (D_005721C8 && IsAuth_00214C90()) {
        LiftMsg_00214C90 msg;
        LiftMsg_00214C90* m = &msg;
        Event_Construct(m, D_004F5440);
        msg.floor = floor;
        msg.vtable = D_004DAF10;
        msg.kind = 1;
        m->to = ObjId_00214C90((Obj_00214C90*)l);
        m->from = ObjId_00214C90(0);
        msg.b20 = 4;
        Event_Send(&msg, l, 0);
        msg.vtable = D_004DAF10;
        cMessage_dtor(&msg, 0);
    }
    if (a2 && floor < 0) {
        if (D_005721C8) {
            if (a3) {
                cElevatorGOBJ_ChooseFloor(l);
            } else {
                Snd_00214C90* s = l->snd;
                if (s)
                    func_002EC3C8(s->h);
            }
        } else {
            cElevatorGOBJ_ChooseFloor(l);
        }
    } else if (floor >= 0) {
        unsigned char blocked;
        if (floor >= 0 && floor < l->nFloors)
            blocked = l->locked[floor] != 0;
        else
            blocked = 1;
        if (!blocked) {
            State_00214C90* st;
            l->state->target = floor;
            st = l->state;
            if (st->target > st->cur) {
                Notice_00214C90 n;
                Event_Construct(&n, D_004F5448);
                n.vtable = D_004DAED0;
                n.kind = 1;
                n.arg = floor;
                Event_Send(&n, l, 0);
                n.vtable = D_004DAED0;
                cMessage_dtor(&n, 0);
                l->state->dir = 1;
                func_00215430(l);
            } else if (st->target < st->cur) {
                Notice_00214C90 n;
                Event_Construct(&n, D_004F5448);
                n.vtable = D_004DAED0;
                n.kind = 1;
                n.arg = floor;
                Event_Send(&n, l, 0);
                n.vtable = D_004DAED0;
                cMessage_dtor(&n, 0);
                l->state->dir = -1;
                func_00215430(l);
            } else {
                st->dir = 0;
                Lift_OpenDoors(l);
            }
        } else {
            Notice_00214C90 n;
            Event_Construct(&n, D_004F5448);
            n.vtable = D_004DAED0;
            n.kind = 4;
            n.arg = floor;
            Event_Send(&n, l, 0);
            n.vtable = D_004DAED0;
            cMessage_dtor(&n, 0);
        }
    }
}