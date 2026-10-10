#include "types.h"
typedef struct HudObjMsg_e1 {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int id;
    char pad2[8];
} HudObjMsg_e1;
typedef struct { char pad[0xC]; int id; } GObjId_e1;
extern unsigned char D_005721C8;
extern char D_0052ACF8[];
extern char D_004DE650[];
extern char* D_004FFC2C;
extern GObjId_e1* GObj_IdentityB(int);
extern void Event_Construct(HudObjMsg_e1* msg, void* name);
extern void Transport_Send(int target, HudObjMsg_e1* msg, int a, int b);
extern void cMessage_dtor(HudObjMsg_e1* msg, int flags);
extern void ObjMarkerMgr_Remove(void*, int*, int);
int Game_RemoveHudObjective(int* args)
{
    HudObjMsg_e1 msg;
    GObjId_e1* obj = GObj_IdentityB(args[0]);
    if (D_005721C8) {
        int id = obj->id;
        Event_Construct(&msg, D_0052ACF8);
        msg.vtable = D_004DE650;
        msg.kind = 4;
        msg.id = id;
        Transport_Send(0, &msg, -1, -1);
        msg.vtable = D_004DE650;
        cMessage_dtor(&msg, 0);
    }
    ObjMarkerMgr_Remove(D_004FFC2C + 0x90, &obj->id, 1);
    return 0;
}