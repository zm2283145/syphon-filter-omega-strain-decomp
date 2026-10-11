
#include "types.h"
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; signed char b24; char pad25[3]; int id; int hp; } Msg_3CC5C0;
typedef struct { char pad[0xC]; int id; char pad10[0x30]; float hp; } Obj_3CC5C0;
extern unsigned char D_005721C8;
extern char D_00582750[];
extern char D_004E0EE0[];
extern void Event_Construct(Msg_3CC5C0* m, void* type);
extern void Event_Send(Msg_3CC5C0* m, void* target, int x);
extern void cMessage_dtor(Msg_3CC5C0* m, int f);

int Script_cGOBJ_SetHitpoints(int* args) {
    volatile int hp;
    int v;
    Obj_3CC5C0* o;
    hp = args[1];
    v = hp;
    o = (Obj_3CC5C0*)args[0];
    o->hp = v;
    if (D_005721C8) {
        Msg_3CC5C0 m;
        Event_Construct(&m, D_00582750);
        m.b24 = 0;
        m.vt = D_004E0EE0;
        m.id = o->id;
        m.kind = 4;
        m.hp = v;
        Event_Send(&m, o, 0);
        m.vt = D_004E0EE0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
